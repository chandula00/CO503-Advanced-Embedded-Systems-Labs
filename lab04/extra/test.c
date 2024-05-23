#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void read_bmp(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        perror("Error opening file");
        exit(1);
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, f);

    if (fileHeader.bfType != 0x4D42)
    {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(f);
        exit(1);
    }

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, f);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int bitCount = infoHeader.biBitCount;
    int bytesPerPixel = bitCount / 8;

    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Bit Count: %d\n\n", bitCount);

    if (bitCount != 24)
    {
        fprintf(stderr, "Only 24-bit BMP files are supported\n");
        fclose(f);
        exit(1);
    }

    fseek(f, fileHeader.bfOffBits, SEEK_SET);

    uint8_t *pixelData = (uint8_t *)malloc(width * height * bytesPerPixel);
    fread(pixelData, sizeof(uint8_t), width * height * bytesPerPixel, f);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (x + (height - 1 - y) * width) * bytesPerPixel;
            uint8_t B = pixelData[index];
            uint8_t G = pixelData[index + 1];
            uint8_t R = pixelData[index + 2];

            printf("(%3d,%3d,%3d)", R, G, B);
        }
        printf("\n");
    }

    free(pixelData);
    fclose(f);
}

int main()
{
    const char *filename = "resized_image.bmp";
    read_bmp(filename);
    return 0;
}
