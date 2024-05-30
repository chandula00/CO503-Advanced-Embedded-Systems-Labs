#include <stdio.h>
#include "datatype.h"'
#include "FIFO.h"

#define BLOCK_SIZE 64

UINT8 Lqt[BLOCK_SIZE];
UINT8 Cqt[BLOCK_SIZE];
UINT16 ILqt[BLOCK_SIZE];
UINT16 ICqt[BLOCK_SIZE];
INT16 Temp[BLOCK_SIZE];

UINT8 zigzag_table[] =
	{
		0, 1, 5, 6, 14, 15, 27, 28,
		2, 4, 7, 13, 16, 26, 29, 42,
		3, 8, 12, 17, 25, 30, 41, 43,
		9, 11, 18, 24, 31, 40, 44, 53,
		10, 19, 23, 32, 39, 45, 52, 54,
		20, 22, 33, 38, 46, 51, 55, 60,
		21, 34, 37, 47, 50, 56, 59, 61,
		35, 36, 48, 49, 57, 58, 62, 63};

void delay(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		continue;
	}
}

/*	This function implements 16 Step division for Q.15 format data */
UINT16 DSP_Division(UINT32 numer, UINT32 denom)
{
	UINT16 i;

	denom <<= 15;

	for (i = 16; i > 0; i--)
	{
		if (numer > denom)
		{
			numer -= denom;
			numer <<= 1;
			numer++;
		}
		else
			numer <<= 1;
	}

	return (UINT16)numer;
}

/* Multiply Quantization table with quality factor to get LQT and CQT */
void initialize_quantization_tables(void)
{
	UINT16 i, index;
	UINT32 value;
	int temp;

	UINT8 luminance_quant_table[] =
		{
			16, 11, 10, 16, 24, 40, 51, 61,
			12, 12, 14, 19, 26, 58, 60, 55,
			14, 13, 16, 24, 40, 57, 69, 56,
			14, 17, 22, 29, 51, 87, 80, 62,
			18, 22, 37, 56, 68, 109, 103, 77,
			24, 35, 55, 64, 81, 104, 113, 92,
			49, 64, 78, 87, 103, 121, 120, 101,
			72, 92, 95, 98, 112, 100, 103, 99};

	UINT8 chrominance_quant_table[] =
		{
			17, 18, 24, 47, 99, 99, 99, 99,
			18, 21, 26, 66, 99, 99, 99, 99,
			24, 26, 56, 99, 99, 99, 99, 99,
			47, 66, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99,
			99, 99, 99, 99, 99, 99, 99, 99};

	READ_FIFO(&temp, OUT_BASE_1to4, CONTROL_BASE_1to4);
	UINT32 quality_factor = temp;

	printf("Quality Done\n");

	for (i = 0; i < 64; i++)
	{
		index = zigzag_table[i];

		/* luminance quantization table * quality factor */
		value = luminance_quant_table[i] * quality_factor;
		value = (value + 0x200) >> 10;

		if (value == 0)
			value = 1;
		else if (value > 255)
			value = 255;

		Lqt[index] = (UINT8)value;
		ILqt[i] = DSP_Division(0x8000, value);

		/* chrominance quantization table * quality factor */
		value = chrominance_quant_table[i] * quality_factor;
		value = (value + 0x200) >> 10;

		if (value == 0)
			value = 1;
		else if (value > 255)
			value = 255;

		Cqt[index] = (UINT8)value;
		ICqt[i] = DSP_Division(0x8000, value);
	}

	for (i = 0; i < 64; i++)
	{
		temp = ILqt[i];
		WRITE_FIFO(&temp, IN_BASE_4to5, CONTROL_BASE_4to5);
	}

	for (i = 0; i < 64; i++)
	{
		temp = ICqt[i];
		WRITE_FIFO(&temp, IN_BASE_4to5, CONTROL_BASE_4to5);
	}
}

/* multiply DCT Coefficients with Quantization table and store in ZigZag location */
void quantization(UINT16 *const quant_table_ptr)
{
	INT16 i;
	INT32 value;
	int temp;

	for (i = 0; i <= 63; i++)
	{

		READ_FIFO(&temp, OUT_BASE_3to4, CONTROL_BASE_3to4);
		value = (INT16)temp * quant_table_ptr[i];

		value = (value + 0x4000) >> 15;

		Temp[zigzag_table[i]] = (INT16)value;
	}

	for (i = 0; i <= 63; i++)
	{
		temp = Temp[i];
		WRITE_FIFO(&temp, IN_BASE_4to5, CONTROL_BASE_4to5);
	}
}

int main(void)
{
	printf("Starting CPU4\n");

	delay(1000000);
	FIFO_INIT(CONTROL_BASE_4to5);
	delay(1000000);

	while (1)
	{
		printf("Quantization Started\n");

		UINT32 count;
		READ_FIFO(&count, OUT_BASE_1to4, CONTROL_BASE_1to4);

		printf("Count Done\n");

		initialize_quantization_tables();

		for (; count > 0; count--)
		{
			quantization(ILqt);
			quantization(ICqt);
			quantization(ICqt);

			printf("Quantization Done\n");
		}

		printf("\n Done ! \n");
		// break;
	}
}
