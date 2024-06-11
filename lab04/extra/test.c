#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>

// Define BMP file header structure
#pragma pack(push, 1)
typedef struct
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

// Define a structure for RGB
typedef struct
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

// Function to read BMP file and get pixel data
RGB *read_bmp(const char *filename, int *width, int *height)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Error opening file");
        return NULL;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    if (fileHeader.bfType != 0x4D42)
    {
        fclose(file);
        fprintf(stderr, "Not a valid BMP file\n");
        return NULL;
    }

    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    *width = infoHeader.biWidth;
    *height = infoHeader.biHeight;

    RGB *pixelData = (RGB *)malloc(infoHeader.biWidth * infoHeader.biHeight * sizeof(RGB));
    if (!pixelData)
    {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    fread(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, file);
    fclose(file);

    return pixelData;
}

// Function to write JPEG file using libjpeg
void write_jpeg(const char *filename, RGB *pixelData, int width, int height, int quality)
{
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *outfile;
    JSAMPROW row_pointer[1];
    int row_stride;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    if ((outfile = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(1);
    }
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE);

    jpeg_start_compress(&cinfo, TRUE);

    row_stride = width * 3;

    while (cinfo.next_scanline < cinfo.image_height)
    {
        row_pointer[0] = (JSAMPROW)&pixelData[cinfo.next_scanline * width];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
    jpeg_destroy_compress(&cinfo);
}

int main(int argc, char *argv[])
{

    const char *bmp_filename = "image0.bmp";
    const char *jpeg_filename = "output_image2.jpg";
    int quality = 90;

    if (quality < 0 || quality > 100)
    {
        fprintf(stderr, "Quality should be between 0 and 100\n");
        return 1;
    }

    int width, height;
    RGB *pixelData = read_bmp(bmp_filename, &width, &height);
    if (!pixelData)
    {
        return 1;
    }

    write_jpeg(jpeg_filename, pixelData, width, height, quality);

    free(pixelData);
    return 0;
}
