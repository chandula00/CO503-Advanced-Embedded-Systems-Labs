#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "readYUV.h"

#ifndef ENCODER_H
#define ENCODER_H

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

void print_grid(UINT8 *data, UINT32 width, UINT32 height)
{
	UINT32 row, col;
	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			UINT32 index = row * width * 3 + col * 3;
			printf("(%3d, %3d, %3d) ", data[index + 2], data[index + 1], data[index]);
		}
		printf("\n");
	}
	printf("\n");
}

void initialization(JPEG_ENCODER_STRUCTURE *jpeg, UINT32 image_width, UINT32 image_height)
{
	UINT16 mcu_width, mcu_height, bytes_per_pixel;

	jpeg->mcu_width = mcu_width = 8;
	jpeg->mcu_height = mcu_height = 8;

	jpeg->horizontal_mcus = (UINT16)((image_width + mcu_width - 1) >> 3);
	jpeg->vertical_mcus = (UINT16)((image_height + mcu_height - 1) >> 3);

	bytes_per_pixel = 3;

	jpeg->rows_in_bottom_mcus = (UINT16)(image_height - (jpeg->vertical_mcus - 1) * mcu_height);
	jpeg->cols_in_right_mcus = (UINT16)(image_width - (jpeg->horizontal_mcus - 1) * mcu_width);

	jpeg->length_minus_mcu_width = (UINT16)((image_width - mcu_width) * bytes_per_pixel);
	jpeg->length_minus_width = (UINT16)((image_width - jpeg->cols_in_right_mcus) * bytes_per_pixel);

	jpeg->mcu_width_size = (UINT16)(mcu_width * bytes_per_pixel);
}

UINT8 encode_image(char *input_file_name, UINT32 quality_factor)
{
	UINT16 i, j;
	UINT32 image_width, image_height;

	JPEG_ENCODER_STRUCTURE JpegStruct;
	JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure = &JpegStruct;

	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	FILE *fpt;

	fpt = fopen(input_file_name, "rb");
	if (fpt == NULL)
	{
		fprintf(stderr, "Error opening input file: %s\n", input_file_name);
		return 1;
	}

	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpt);
	if (fileHeader.bfType != 0x4D42)
	{
		fprintf(stderr, "Not a valid BMP file\n");
		fclose(fpt);
		return 1;
	}

	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpt);

	if (infoHeader.biBitCount != 24)
	{
		fprintf(stderr, "Only 24-bit BMP files are supported\n");
		fclose(fpt);
		return 1;
	}

	image_width = infoHeader.biWidth;
	image_height = abs(infoHeader.biHeight);
	int row_padded = (image_width * 3 + 3) & (~3);

	UINT8 *data = (UINT8 *)malloc(row_padded * image_height);
	if (!data)
	{
		fprintf(stderr, "Memory allocation failed\n");
		fclose(fpt);
		return 1;
	}

	fseek(fpt, fileHeader.bfOffBits, SEEK_SET);
	fread(data, 1, row_padded * image_height, fpt);
	fclose(fpt);

	/* Initialization of JPEG control structure */
	initialization(jpeg_encoder_structure, image_width, image_height);

	/* Quantization Table Initialization */
	// initialize_quantization_tables(quality_factor);
	// SEND4((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));
	// SEND4(quality_factor);

	/* Writing Marker Data */
	// SEND5(image_width);
	// SEND5(image_height);
	// SEND5((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));

	// Print the entire image data as a grid
	// printf("Entire image data as a grid:\n");
	// print_grid(data, image_width, image_height);

	UINT8 *data_ptr = data;
	for (i = 0; i < jpeg_encoder_structure->vertical_mcus; i++)
	{
		printf("\nBlock Number - %d\n", i + 1);

		jpeg_encoder_structure->rows = (i < jpeg_encoder_structure->vertical_mcus - 1) ? jpeg_encoder_structure->mcu_height : jpeg_encoder_structure->rows_in_bottom_mcus;

		for (j = 0; j < jpeg_encoder_structure->horizontal_mcus; j++)
		{
			jpeg_encoder_structure->cols = (j < jpeg_encoder_structure->horizontal_mcus - 1) ? jpeg_encoder_structure->mcu_width : jpeg_encoder_structure->cols_in_right_mcus;
			jpeg_encoder_structure->incr = (j < jpeg_encoder_structure->horizontal_mcus - 1) ? jpeg_encoder_structure->length_minus_mcu_width : jpeg_encoder_structure->length_minus_width;

			read_444_format(jpeg_encoder_structure, data_ptr);

			data_ptr += jpeg_encoder_structure->mcu_width_size;
		}

		data_ptr = data + jpeg_encoder_structure->mcu_height * image_width * 3 * (i + 1);
	}

	free(data);

	return 0;
}

#endif
