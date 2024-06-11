#include <stdio.h>
#include <stdlib.h> // Added for malloc
#include "datatype.h"
#include "FIFO.h"
#include <time.h>

FILE *log_file;

void delay(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		continue;
	}
}

INT16 *data;

/* DCT for One block(8x8) */
void DCT(void)
{
	UINT16 i;
	INT32 x0, x1, x2, x3, x4, x5, x6, x7, x8;
	clock_t start_time, end_time;
	int temp;

	/* All values are shifted left by 10 and rounded off to nearest integer */

	static const UINT16 c1 = 1420; /* cos PI/16 * root(2) */
	static const UINT16 c2 = 1338; /* cos PI/8 * root(2) */
	static const UINT16 c3 = 1204; /* cos 3PI/16 * root(2) */
	static const UINT16 c5 = 805;  /* cos 5PI/16 * root(2) */
	static const UINT16 c6 = 554;  /* cos 3PI/8 * root(2) */
	static const UINT16 c7 = 283;  /* cos 7PI/16 * root(2) */

	static const UINT16 s1 = 3;
	static const UINT16 s2 = 10;
	static const UINT16 s3 = 13;

	/* read back from queue */
	for (i = 0; i < 64; i++)
	{
		READ_FIFO(&temp, OUT_BASE_2to3, CONTROL_BASE_2to3);
		data[i] = temp; // Casting data
	}

	// printf("Incoming Data:\n");
	// for (i = 0; i < 64; i++)
	// {
	// 	printf("%4d ", data[i]);
	// 	if ((i + 1) % 8 == 0)
	// 		printf("\n");
	// }

	start_time = clock();

	for (i = 8; i > 0; i--)
	{
		x8 = data[0] + data[7];
		x0 = data[0] - data[7];

		x7 = data[1] + data[6];
		x1 = data[1] - data[6];

		x6 = data[2] + data[5];
		x2 = data[2] - data[5];

		x5 = data[3] + data[4];
		x3 = data[3] - data[4];

		x4 = x8 + x5;
		x8 -= x5;

		x5 = x7 + x6;
		x7 -= x6;

		data[0] = (INT16)(x4 + x5);
		data[4] = (INT16)(x4 - x5);

		data[2] = (INT16)((x8 * c2 + x7 * c6) >> s2);
		data[6] = (INT16)((x8 * c6 - x7 * c2) >> s2);

		data[7] = (INT16)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s2);
		data[5] = (INT16)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s2);
		data[3] = (INT16)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s2);
		data[1] = (INT16)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s2);

		data += 8;
	}

	data -= 64;

	for (i = 8; i > 0; i--)
	{
		x8 = data[0] + data[56];
		x0 = data[0] - data[56];

		x7 = data[8] + data[48];
		x1 = data[8] - data[48];

		x6 = data[16] + data[40];
		x2 = data[16] - data[40];

		x5 = data[24] + data[32];
		x3 = data[24] - data[32];

		x4 = x8 + x5;
		x8 -= x5;

		x5 = x7 + x6;
		x7 -= x6;

		data[0] = (INT16)((x4 + x5) >> s1);
		data[32] = (INT16)((x4 - x5) >> s1);

		data[16] = (INT16)((x8 * c2 + x7 * c6) >> s3);
		data[48] = (INT16)((x8 * c6 - x7 * c2) >> s3);

		data[56] = (INT16)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s3);
		data[40] = (INT16)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s3);
		data[24] = (INT16)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s3);
		data[8] = (INT16)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s3);

		data++;
	}

	data -= 8;

	// printf("Transformed Data:\n");
	// for (i = 0; i < 64; i++)
	// {
	// 	printf("%4d ", data[i]);
	// 	if ((i + 1) % 8 == 0)
	// 		printf("\n");
	// }

	end_time = clock();
	fprintf(log_file, "Time taken for DCT encoding: %f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

	/* write out to queue */
	for (i = 0; i < 64; i++)
	{
		temp = data[i];
		WRITE_FIFO(&temp, IN_BASE_3to4, CONTROL_BASE_3to4); // Casting data
	}
}

int main(void)
{
	printf("Starting CPU3\n");

	log_file = fopen("/mnt/host/files/log.txt", "w");
	if (log_file == NULL)
	{
		fprintf(stderr, "Error opening log file\n");
		return 1;
	}

	/* Initialize FIFO */
	delay(100000);
	FIFO_INIT(CONTROL_BASE_3to4);
	delay(100000);

	data = (INT16 *)malloc(sizeof(INT16) * 64);

	while (1)
	{
		printf("DCT Started\n");

		DCT();
		DCT();
		DCT();

		printf("DCT Done\n");
	}

	free(data);

	return 0;
}
