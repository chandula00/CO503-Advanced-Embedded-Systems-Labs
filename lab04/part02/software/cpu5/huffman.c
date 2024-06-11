#include <stdio.h>
#include "datatype.h"
#include "huffdata.h"
#include "markdata.h"
#include "FIFO.h"
// #include <time.h>

int temp;

void delay(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		continue;
	}
}

#define PUTBITS                                                               \
	{                                                                         \
		bits_in_next_word = (INT16)(bitindex + numbits - 32);                 \
		if (bits_in_next_word < 0)                                            \
		{                                                                     \
			lcode = (lcode << numbits) | data;                                \
			bitindex += numbits;                                              \
		}                                                                     \
		else                                                                  \
		{                                                                     \
			lcode = (lcode << (32 - bitindex)) | (data >> bits_in_next_word); \
			out = (UINT8)(lcode >> 24);                                       \
			/* SEND1(out); */                                                 \
			WRITE_FIFO(out, IN_BASE_5to6, CONTROL_BASE_5to6);                 \
			if (out == 0xff)                                                  \
			{ /* SEND1(0); */                                                 \
				WRITE_FIFO(0, IN_BASE_5to6, CONTROL_BASE_5to6);               \
			}                                                                 \
			out = (UINT8)(lcode >> 16);                                       \
			/* SEND1(out); */                                                 \
			WRITE_FIFO(out, IN_BASE_5to6, CONTROL_BASE_5to6);                 \
			if (out == 0xff)                                                  \
			{ /* SEND1(0); */                                                 \
				WRITE_FIFO(0, IN_BASE_5to6, CONTROL_BASE_5to6);               \
			}                                                                 \
			out = (UINT8)(lcode >> 8);                                        \
			/* SEND1(out); */                                                 \
			WRITE_FIFO(out, IN_BASE_5to6, CONTROL_BASE_5to6);                 \
			if (out == 0xff)                                                  \
			{ /* SEND1(0); */                                                 \
				WRITE_FIFO(0, IN_BASE_5to6, CONTROL_BASE_5to6);               \
			}                                                                 \
			out = (UINT8)lcode;                                               \
			/* SEND1(out); */                                                 \
			WRITE_FIFO(out, IN_BASE_5to6, CONTROL_BASE_5to6);                 \
			if (out == 0xff)                                                  \
			{ /* SEND1(0); */                                                 \
				WRITE_FIFO(0, IN_BASE_5to6, CONTROL_BASE_5to6);               \
			}                                                                 \
			lcode = data;                                                     \
			bitindex = bits_in_next_word;                                     \
		}                                                                     \
	}

// Header for JPEG Encoder

void write_markers(UINT32 image_width, UINT32 image_height)
{
	UINT16 i, header_length;
	UINT8 number_of_components;

	// // Start of image marker
	// SEND1(0xFF);
	// SEND1(0xD8);
	WRITE_FIFO(0xFF, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0xD8, IN_BASE_5to6, CONTROL_BASE_5to6);

	// // Quantization table marker
	// SEND1(0xFF);
	// SEND1(0xDB);
	WRITE_FIFO(0xFF, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0xDB, IN_BASE_5to6, CONTROL_BASE_5to6);

	// // Quantization table length
	// SEND1(0x00);
	// SEND1(0x84);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x84, IN_BASE_5to6, CONTROL_BASE_5to6);

	// // Pq, Tq
	// SEND1(0x00);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);

	// // Lqt table
	for (i = 0; i < 64; i++)
	{
		// SEND1((UINT8)RECV2()); // Lqt [i];
		WRITE_FIFO(READ_FIFO(OUT_BASE_4to5, CONTROL_BASE_4to5), IN_BASE_5to6, CONTROL_BASE_5to6);
	}

	// // Pq, Tq
	// SEND1(0x01);
	WRITE_FIFO(0x01, IN_BASE_5to6, CONTROL_BASE_5to6);

	// // Cqt table
	for (i = 0; i < 64; i++)
	{
		// SEND1((UINT8)RECV2()); // Cqt [i];
		WRITE_FIFO(READ_FIFO(OUT_BASE_4to5, CONTROL_BASE_4to5), IN_BASE_5to6, CONTROL_BASE_5to6);
	}

	// // huffman table(DHT)
	for (i = 0; i < 210; i++)
	{
		// SEND1((UINT8)(markerdata[i] >> 8));
		// SEND1((UINT8)markerdata[i]);

		WRITE_FIFO((UINT8)(markerdata[i] >> 8), IN_BASE_5to6, CONTROL_BASE_5to6);
		WRITE_FIFO((UINT8)markerdata[i], IN_BASE_5to6, CONTROL_BASE_5to6);
	}

	number_of_components = 3;

	// Frame header(SOF)

	// Start of frame marker
	// SEND1(0xFF);
	// SEND1(0xC0);
	WRITE_FIFO(0xFF, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0xC0, IN_BASE_5to6, CONTROL_BASE_5to6);

	header_length = (UINT16)(8 + 3 * number_of_components);

	// Frame header length
	// SEND1((UINT8)(header_length >> 8));
	// SEND1((UINT8)header_length);
	WRITE_FIFO((UINT8)(header_length >> 8), IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO((UINT8)header_length, IN_BASE_5to6, CONTROL_BASE_5to6);

	// Precision (P)
	// SEND1(0x08);
	WRITE_FIFO(0x08, IN_BASE_5to6, CONTROL_BASE_5to6);

	// image height
	// SEND1((UINT8)(image_height >> 8));
	// SEND1((UINT8)image_height);
	WRITE_FIFO((UINT8)(image_height >> 8), IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO((UINT8)image_height, IN_BASE_5to6, CONTROL_BASE_5to6);

	// image width
	// SEND1((UINT8)(image_width >> 8));
	// SEND1((UINT8)image_width);
	WRITE_FIFO((UINT8)(image_width >> 8), IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO((UINT8)image_width, IN_BASE_5to6, CONTROL_BASE_5to6);

	// Nf
	// SEND1(number_of_components);
	WRITE_FIFO(number_of_components, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x01);
	WRITE_FIFO(0x01, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x11);
	WRITE_FIFO(0x11, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x00);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x02);
	// SEND1(0x11);
	// SEND1(0x01);
	WRITE_FIFO(0x02, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x11, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x01, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x03);
	// SEND1(0x11);
	// SEND1(0x01);
	WRITE_FIFO(0x03, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x11, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x01, IN_BASE_5to6, CONTROL_BASE_5to6);

	// Start of scan marker
	// SEND1(0xFF);
	// SEND1(0xDA);
	WRITE_FIFO(0xFF, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0xDA, IN_BASE_5to6, CONTROL_BASE_5to6);

	header_length = (UINT16)(6 + (number_of_components << 1));

	// Scan header length

	// SEND1((UINT8)(header_length >> 8));
	// SEND1((UINT8)header_length);
	WRITE_FIFO((UINT8)(header_length >> 8), IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO((UINT8)header_length, IN_BASE_5to6, CONTROL_BASE_5to6);

	// Ns
	// SEND1(number_of_components);
	WRITE_FIFO(number_of_components, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x01);
	// SEND1(0x00);
	WRITE_FIFO(0x01, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x02);
	// SEND1(0x11);
	WRITE_FIFO(0x02, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x11, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x03);
	// SEND1(0x11);
	WRITE_FIFO(0x03, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x11, IN_BASE_5to6, CONTROL_BASE_5to6);

	// SEND1(0x00);
	// SEND1(0x3F);
	// SEND1(0x00);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x3F, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0x00, IN_BASE_5to6, CONTROL_BASE_5to6);
}

UINT32 lcode = 0;
UINT16 bitindex = 0;
INT16 ldc1 = 0, ldc2 = 0, ldc3 = 0;

void huffman(UINT16 component)
{
	UINT16 i;
	UINT16 *DcCodeTable, *DcSizeTable, *AcCodeTable, *AcSizeTable;

	// static INT16 ldc1 = 0, ldc2 = 0, ldc3 = 0;

	INT16 *Temp_Ptr, Coeff, LastDc;
	UINT16 AbsCoeff, HuffCode, HuffSize, RunLength = 0, DataSize = 0, index;

	INT16 bits_in_next_word;
	UINT16 numbits;
	UINT32 data;

	UINT8 out;

	// Coeff = (INT16)RECV2();
	Coeff = (INT16)READ_FIFO(OUT_BASE_4to5, CONTROL_BASE_4to5);

	// printf("Incoming Data:\n");
	// printf("%4d ", Coeff);

	if (component == 1)
	{
		DcCodeTable = luminance_dc_code_table;
		DcSizeTable = luminance_dc_size_table;
		AcCodeTable = luminance_ac_code_table;
		AcSizeTable = luminance_ac_size_table;

		LastDc = ldc1;
		ldc1 = Coeff;
	}
	else
	{
		DcCodeTable = chrominance_dc_code_table;
		DcSizeTable = chrominance_dc_size_table;
		AcCodeTable = chrominance_ac_code_table;
		AcSizeTable = chrominance_ac_size_table;

		if (component == 2)
		{
			LastDc = ldc2;
			ldc2 = Coeff;
		}
		else
		{
			LastDc = ldc3;
			ldc3 = Coeff;
		}
	}

	Coeff -= LastDc;

	AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;

	while (AbsCoeff != 0)
	{
		AbsCoeff >>= 1;
		DataSize++;
	}

	HuffCode = DcCodeTable[DataSize];
	HuffSize = DcSizeTable[DataSize];

	Coeff &= (1 << DataSize) - 1;
	data = (HuffCode << DataSize) | Coeff;
	numbits = HuffSize + DataSize;

	PUTBITS

	for (i = 63; i > 0; i--)
	{

		if (((Coeff = (INT16)READ_FIFO(OUT_BASE_4to5, CONTROL_BASE_4to5)) != 0))
		{
			// printf("%4d ", Coeff);

			// int col = i % 8;

			// if (col == 0)
			// 	printf("\n");

			while (RunLength > 15)
			{
				RunLength -= 16;
				data = AcCodeTable[161];
				numbits = AcSizeTable[161];
				PUTBITS
			}

			AbsCoeff = (Coeff < 0) ? -Coeff-- : Coeff;

			if (AbsCoeff >> 8 == 0)
				DataSize = bitsize[AbsCoeff];
			else
				DataSize = bitsize[AbsCoeff >> 8] + 8;

			index = RunLength * 10 + DataSize;
			HuffCode = AcCodeTable[index];
			HuffSize = AcSizeTable[index];

			Coeff &= (1 << DataSize) - 1;
			data = (HuffCode << DataSize) | Coeff;
			numbits = HuffSize + DataSize;

			PUTBITS
			RunLength = 0;
		}
		else
		{
			RunLength++;

			// printf("%4d ", Coeff);

			// int col = i % 8;

			// if (col == 0)
			// 	printf("\n");
		}
	}

	// printf("\n");

	if (RunLength != 0)
	{
		data = AcCodeTable[0];
		numbits = AcSizeTable[0];
		PUTBITS
	}
}

/* For bit Stuffing and EOI marker */
void close_bitstream(void)
{
	UINT16 i, count;
	UINT8 *ptr;

	UINT8 out;

	if (bitindex > 0)
	{
		lcode <<= (32 - bitindex);
		count = (bitindex + 7) >> 3;

		ptr = (UINT8 *)&lcode + 3;

		for (i = count; i > 0; i--)
		{
			out = *ptr--;

			// SEND1(out);
			WRITE_FIFO(out, IN_BASE_5to6, CONTROL_BASE_5to6);

			if (out == 0xff)
			{
				// SEND1(0);
				WRITE_FIFO(0, IN_BASE_5to6, CONTROL_BASE_5to6);
			}
		}
	}

	// End of image marker
	// SEND1(0xFF);
	// SEND1(0xD9);
	WRITE_FIFO(0xFF, IN_BASE_5to6, CONTROL_BASE_5to6);
	WRITE_FIFO(0xD9, IN_BASE_5to6, CONTROL_BASE_5to6);
}

int main(void)
{
	printf("Starting CPU5\n");

	// clock_t start_time, end_time;
	// FILE *log_file;

	// log_file = fopen("/mnt/host/files/log.txt", "w");
	// if (log_file == NULL)
	// {
	// 	fprintf(stderr, "Error opening log file\n");
	// 	return 1;
	// }

	delay(1000000);
	FIFO_INIT(CONTROL_BASE_5to6);
	delay(1000000);

	while (1)
	{
		printf("Huffman Started ! \n");

		lcode = 0;
		bitindex = 0;
		ldc1 = 0;
		ldc2 = 0;
		ldc3 = 0;

		UINT32 width = (UINT32)READ_FIFO(OUT_BASE_1to5, CONTROL_BASE_1to5);
		UINT32 height = (UINT32)READ_FIFO(OUT_BASE_1to5, CONTROL_BASE_1to5);
		UINT32 count = (UINT32)READ_FIFO(OUT_BASE_1to5, CONTROL_BASE_1to5);

		printf("Meta Data Done\n");

		write_markers(width, height);

		for (; count > 0; count--)
		{
			// start_time = clock();
			huffman(1);
			// end_time = clock();

			// log timestamp
			// fprintf(log_file, "Time taken for Huffman encoding: %f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

			huffman(2);
			huffman(3);

			printf("Block Done\n");
		}

		close_bitstream();

		// SEND2(1);

		printf("Image Done\n");
	}

	printf("\n Finished !\n");
	return 0;
}
