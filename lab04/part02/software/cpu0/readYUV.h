#include <stdio.h>
#include "datatype.h"
#include "FIFO.h"

#ifndef READYUV_H
#define READYUV_H

void delay(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		continue;
	}
}

typedef struct JPEG_ENCODER_STRUCTURE
{
	UINT16 mcu_width;
	UINT16 mcu_height;
	UINT16 horizontal_mcus;
	UINT16 vertical_mcus;
	UINT16 cols_in_right_mcus;
	UINT16 rows_in_bottom_mcus;

	UINT16 rows;
	UINT16 cols;

	UINT16 length_minus_mcu_width;
	UINT16 length_minus_width;
	UINT16 incr;
	UINT16 mcu_width_size;

} JPEG_ENCODER_STRUCTURE;

void read_444_format(JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure, UINT8 *input_ptr)
{
	INT32 i, j;

	UINT8 R, G, B;
	INT32 Y, Cb, Cr;

	UINT16 rows = jpeg_encoder_structure->rows;
	UINT16 cols = jpeg_encoder_structure->cols;
	UINT16 incr = jpeg_encoder_structure->incr;

	for (i = rows; i > 0; i--)
	{
		// Print a new line for each row
		// printf("\nRow %d: ", rows - i + 1);
		for (j = cols; j > 0; j--)
		{
			B = *input_ptr++;
			G = *input_ptr++;
			R = *input_ptr++;

			// Print the RGB values
			// printf("(%3d, %3d, %3d) ", R, G, B);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			// printf("(%3d, %3d, %3d) ", Y, Cb, Cr);

			// Send into fifo
			WRITE_FIFO(&Y, IN_BASE_1to2A, CONTROL_BASE_1to2A);
			WRITE_FIFO(&Cb, IN_BASE_1to2B, CONTROL_BASE_1to2B);
			WRITE_FIFO(&Cr, IN_BASE_1to2C, CONTROL_BASE_1to2C);
		}

		if ((j = (8 - cols)) > 0)
		{
			B = *(input_ptr - 3);
			G = *(input_ptr - 2);
			R = *(input_ptr - 1);

			// Print the RGB values
			// printf("(%3d, %3d, %3d) ", R, G, B);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			for (; j > 0; j--)
			{
				// Print the RGB values
				// printf("(%3d, %3d, %3d) ", R, G, B);

				// printf("(%3d, %3d, %3d) ", Y, Cb, Cr);

				WRITE_FIFO(&Y, IN_BASE_1to2A, CONTROL_BASE_1to2A);
				WRITE_FIFO(&Cb, IN_BASE_1to2B, CONTROL_BASE_1to2B);
				WRITE_FIFO(&Cr, IN_BASE_1to2C, CONTROL_BASE_1to2C);
			}
		}

		input_ptr += incr;
	}

	input_ptr -= incr;

	for (i = 8 - rows; i > 0; i--)
	{
		// Print a new line for each row
		// printf("\nRow %d: ", rows + (8 - rows) - i + 1);
		for (j = cols * 3; j > 0;)
		{
			B = *(input_ptr - (j--));
			G = *(input_ptr - (j--));
			R = *(input_ptr - (j--));

			// Print the RGB values
			// printf("(%3d, %3d, %3d) ", R, G, B);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			// printf("(%3d, %3d, %3d) ", Y, Cb, Cr);

			WRITE_FIFO(&Y, IN_BASE_1to2A, CONTROL_BASE_1to2A);
			WRITE_FIFO(&Cb, IN_BASE_1to2B, CONTROL_BASE_1to2B);
			WRITE_FIFO(&Cr, IN_BASE_1to2C, CONTROL_BASE_1to2C);
		}

		if ((j = (8 - cols)) > 0)
		{
			B = *(input_ptr - 3);
			G = *(input_ptr - 2);
			R = *(input_ptr - 1);

			// Print the RGB values
			// printf("(%3d, %3d, %3d) ", R, G, B);
			// printf("(%3d, %3d, %3d) ", Y, Cb, Cr);

			Y = ((77 * R + 150 * G + 29 * B) >> 8);
			Cb = ((-43 * R - 85 * G + 128 * B) >> 8) + 128;
			Cr = ((128 * R - 107 * G - 21 * B) >> 8) + 128;

			if (Y < 0)
				Y = 0;
			else if (Y > 255)
				Y = 255;

			if (Cb < 0)
				Cb = 0;
			else if (Cb > 255)
				Cb = 255;

			if (Cr < 0)
				Cr = 0;
			else if (Cr > 255)
				Cr = 255;

			for (; j > 0; j--)
			{
				// Print the RGB values
				// printf("(%3d, %3d, %3d) ", R, G, B);
				// printf("(%3d, %3d, %3d) ", Y, Cb, Cr);

				WRITE_FIFO(&Y, IN_BASE_1to2A, CONTROL_BASE_1to2A);
				WRITE_FIFO(&Cb, IN_BASE_1to2B, CONTROL_BASE_1to2B);
				WRITE_FIFO(&Cr, IN_BASE_1to2C, CONTROL_BASE_1to2C);
			}
		}
	}

	// printf("\n");
}

#endif
