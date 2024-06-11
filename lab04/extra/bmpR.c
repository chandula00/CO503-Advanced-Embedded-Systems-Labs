#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    // File pointer to the BMP file
    FILE *file;
    // Open the BMP file
    file = fopen("resized_image.bmp", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read the file header
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    // Read the info header
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    // Ensure the file is a BMP file by checking bitmap signature
    if (fileHeader.bfType != 0x4D42)
    {
        fclose(file);
        fprintf(stderr, "Not a valid BMP file\n");
        return 1;
    }

    // Move file pointer to the beginning of bitmap data
    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    // Allocate memory for the pixel data
    RGB *pixelData = (RGB *)malloc(infoHeader.biWidth * infoHeader.biHeight * sizeof(RGB));
    if (pixelData == NULL)
    {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read the pixel data
    fread(pixelData, sizeof(RGB), infoHeader.biWidth * infoHeader.biHeight, file);

    // Close the file
    fclose(file);

    // Print RGB values (for demonstration)
    for (int y = 0; y < infoHeader.biHeight; y++)
    {
        for (int x = 0; x < infoHeader.biWidth; x++)
        {
            RGB pixel = pixelData[y * infoHeader.biWidth + x];
            printf("Pixel at (%d, %d): R=%d, G=%d, B=%d\n", x, y, pixel.red, pixel.green, pixel.blue);
        }
    }

    // Free allocated memory
    free(pixelData);

    return 0;
}
