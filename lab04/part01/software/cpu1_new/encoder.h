#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "readYUV.h"

#ifndef ENCODER_H
#define ENCODER_H

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

	jpeg->offset = (UINT16)((image_width * ((mcu_height >> 1) - 1) - (mcu_width - jpeg->cols_in_right_mcus)) * bytes_per_pixel);
}

UINT8 encode_image(char *input_file_name, UINT32 quality_factor, UINT32 image_width, UINT32 image_height)
{
	UINT16 i, j;

	JPEG_ENCODER_STRUCTURE JpegStruct;
	JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure = &JpegStruct;

	FILE *fpt;

	/* Initialization of JPEG control structure */
	initialization(jpeg_encoder_structure, image_width, image_height);

	/* Quantization Table Initialization */
	// initialize_quantization_tables (quality_factor);
	// SEND4((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));
	// SEND4(quality_factor);

	/* Writing Marker Data */
	// SEND5(image_width);
	// SEND5(image_height);
	// SEND5((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));

	fpt = fopen(input_file_name, "rb");
	if (fpt == NULL)
	{
		fprintf(stderr, "Error opening input file: %s\n", input_file_name);
		return 1;
	}

	UINT8 *input = (UINT8 *)malloc(((jpeg_encoder_structure->mcu_height * image_width * 3) + 1) * sizeof(UINT8));
	if (input == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		fclose(fpt);
		return 1;
	}

	for (i = 1; i <= jpeg_encoder_structure->vertical_mcus; i++)
	{
		printf("Input image data (hex) - %d\n", i);

		if (i < jpeg_encoder_structure->vertical_mcus)
			jpeg_encoder_structure->rows = jpeg_encoder_structure->mcu_height;
		else
			jpeg_encoder_structure->rows = jpeg_encoder_structure->rows_in_bottom_mcus;

		fread(input, 1, (jpeg_encoder_structure->rows * image_width * 3), fpt);

		UINT8 *temp_ptr = input; // Use a temporary pointer for the loop

		for (j = 1; j <= jpeg_encoder_structure->horizontal_mcus; j++)
		{
			if (j < jpeg_encoder_structure->horizontal_mcus)
			{
				jpeg_encoder_structure->cols = jpeg_encoder_structure->mcu_width;
				jpeg_encoder_structure->incr = jpeg_encoder_structure->length_minus_mcu_width;
			}
			else
			{
				jpeg_encoder_structure->cols = jpeg_encoder_structure->cols_in_right_mcus;
				jpeg_encoder_structure->incr = jpeg_encoder_structure->length_minus_width;
			}

			read_444_format(jpeg_encoder_structure, temp_ptr);

			temp_ptr += jpeg_encoder_structure->mcu_width_size;
		}
	}

	free(input);

	if (fclose(fpt) != 0)
	{
		fprintf(stderr, "Error closing file\n");
	}

	return 0;
}

#endif
