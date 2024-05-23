#include <stdio.h>
#include <stdint.h>

typedef union
{
    struct
    {
        uint32_t BMPFileSize;
        uint32_t BMPUnused;
        uint32_t BMPDataOffset;
        uint32_t BMPRemainingDIBBytes;
        uint32_t BMPWidth;
        uint32_t BMPHeight;
        uint16_t BMPColourPlaneCount;
        uint16_t BMPBitsPerPixel;
        uint32_t BMPPixelCompression;
        uint32_t BMPDataSize;
        uint32_t BMPHozRes;
        uint32_t BMPVertRes;
        uint32_t BMPColours;
        uint32_t BMPImportantColours;
    };
    int8_t BMPRawData[52];
} Bmp_header;

typedef struct
{
    Bmp_header *header; // Structure unpacking the contents of the BMP header
    int8_t *buffer;     // Buffer containing the entire contents of the BMP file
    int8_t *bitmap;     // Buffer pointing to the start of the bitmap area of <buffer>.
} Bmp_data;

int bmp_extract(char *file_name, Bmp_data *pic_data);

int8_t g_file_buffer[67108864]; // Create and Enormous buffer to avoid dynamic memory allocation
Bmp_header g_input_file_header;

int bmp_extract_header(Bmp_data *pic_data)
{
    int i;

    if (pic_data->buffer[0] == 'B' && pic_data->buffer[1] == 'M')
    {
        for (i = 0; i < 52; i++)
        {
            pic_data->header->BMPRawData[i] = pic_data->buffer[i + 2];
        }

        // Calculate the effective size of the data field
        pic_data->header->BMPDataSize = pic_data->header->BMPHeight * pic_data->header->BMPWidth * (pic_data->header->BMPBitsPerPixel / 8);

        pic_data->bitmap = &pic_data->buffer[pic_data->header->BMPDataOffset];
        return 1;
    }
    return 0;
}

void bmp_rearrange_comps(Bmp_data *pic_data)
{
    // BMP images start from the bottom left, and its components are ordered
    // B - G - R. The jpeg encoder starts at the top left, and is ordered
    // R - G - B. This function puts all the bytes in their right place.

    int row, column;
    int8_t r, g, b, *row_ptr, *dest;

    // <*dest> starts from the top left of the image and moves downwards.
    // <*row_ptr> starts from the bottom left of the image and moves upwards.
    dest = pic_data->bitmap;

    for (row = pic_data->header->BMPHeight - 1; row >= pic_data->header->BMPHeight / 2; row--)
    {
        // We loop until <*dest> and <*row_ptr> meet in the middle of the image.

        row_ptr = &(pic_data->bitmap[row * pic_data->header->BMPWidth * 3]);
        for (column = 0; column < pic_data->header->BMPWidth * 3; column += 3)
        {
            // Not only do we move data from <*dest> to <*row_ptr> and vice-versa,
            // we also need to reshuffle RGB components.
            r = dest[2];
            g = dest[1];
            b = dest[0];

            *dest++ = row_ptr[column + 2];
            *dest++ = row_ptr[column + 1];
            *dest++ = row_ptr[column];

            row_ptr[column] = r;
            row_ptr[column + 1] = g;
            row_ptr[column + 2] = b;
        }
    }
}

int bmp_extract(char *file_name, Bmp_data *pic_data)
{
    FILE *bmp_file = NULL;
    int bmp_file_size, bytes_read;

    bmp_file = fopen(file_name, "rb");
    if (bmp_file == NULL)
    {
        printf("Error opening the file %s\n", file_name);
        return 1;
    }

    // Get the size of the file
    fseek(bmp_file, 0, SEEK_END);
    bmp_file_size = ftell(bmp_file);
    rewind(bmp_file);

    pic_data->buffer = g_file_buffer; // (int8_t *)malloc(bmp_file_size);

    // Read the whole file into the buffer
    bytes_read = fread((void *)pic_data->buffer, sizeof(int8_t), bmp_file_size, bmp_file);

    fclose(bmp_file);

    if (bytes_read != bmp_file_size)
    {
        printf("Error occurred while reading the file\n\n");
        return 2;
    }

    pic_data->header = &g_input_file_header; // (Bmp_header *)malloc(sizeof(Bmp_header));

    bmp_extract_header(pic_data);
    bmp_rearrange_comps(pic_data);

    printf("Size of the file: %d\n", (int)pic_data->header->BMPFileSize);
    printf("Size of the height: %d\n", (int)pic_data->header->BMPHeight);
    printf("Size of the width: %d\n", (int)pic_data->header->BMPWidth);
    printf("Size of the offset: %d\n", (int)pic_data->header->BMPDataOffset);
    printf("Data pointer: 0x%08x\n\n", (unsigned int)pic_data->bitmap);

    return 0;
}

#define MAX_BMP_SIZE (1024 * 1024 * 10) // Maximum allowed BMP file size (adjustable)

int main(int argc, char *argv[])
{

    Bmp_data pic_data;

    // Allocate memory for the BMP header
    pic_data.header = (Bmp_header *)malloc(sizeof(Bmp_header));
    if (pic_data.header == NULL)
    {
        printf("Memory allocation failed for header\n");
        return 1;
    }

    // Avoid dynamic memory allocation for the entire image data
    pic_data.buffer = g_file_buffer;
    if (bmp_extract("resized_image.bmp", &pic_data) != 0)
    {
        printf("Error reading BMP file\n");
        free(pic_data.header);
        return 1;
    }

    // Check for valid image dimensions and color depth
    if (pic_data.header->BMPBitsPerPixel != 24 || pic_data.header->BMPHeight <= 0 || pic_data.header->BMPWidth <= 0)
    {
        printf("Unsupported image format (only 24-bit RGB with positive dimensions)\n");
        free(pic_data.header);
        return 1;
    }

    // Print image information
    printf("Image size: %d x %d\n", pic_data.header->BMPWidth, pic_data.header->BMPHeight);

    // Print RGB values in a grid format
    int row, col;
    for (row = pic_data.header->BMPHeight - 1; row >= 0; row--)
    {
        // Access each pixel based on row and column
        for (col = 0; col < pic_data.header->BMPWidth; col++)
        {
            int pixel_offset = row * pic_data.header->BMPWidth * 3 + col * 3;
            uint8_t blue = pic_data.bitmap[pixel_offset];
            uint8_t green = pic_data.bitmap[pixel_offset + 1];
            uint8_t red = pic_data.bitmap[pixel_offset + 2];
            printf("(%3d,%3d,%3d) ", red, green, blue);
        }
        printf("\n");
    }

    free(pic_data.header);
    return 0;
}
