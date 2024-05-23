#include <stdio.h>
#include "datatype.h"
#include "FIFO.h"

void delay(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		continue;
	}
}

/* Level shifting to get 8-bit SIGNED values for the data */
void levelshift(void)
{
	int i, j;
	INT8 temp1[8][8], temp2[8][8]; // Temporary storage array
	int row, col, count = 0;

	// printf("Level shifting\n");

	while (1)
	{
		// printf("Count - %d\n", count);
		count++;

		for (j = 0; j < 64; j++)
		{
			row = j / 8;
			col = j % 8;

			// Read from the first FIFO
			READ_FIFO(&i, OUT_BASE_1to2A, CONTROL_BASE_1to2A);
			// delay(100000);

			i -= 128;
			// WRITE_FIFO(&i, IN_BASE_2to3, CONTROL_BASE_2to3);

			// Read from the second FIFO
			READ_FIFO(&i, OUT_BASE_1to2B, CONTROL_BASE_1to2B);
			// delay(100000);

			i -= 128;
			temp1[row][col] = i; // Store into temp array

			// Read from the third FIFO
			READ_FIFO(&i, OUT_BASE_1to2C, CONTROL_BASE_1to2C);

			i -= 128;
			temp2[row][col] = i; // Store into temp array

			// delay(1000);
		}

		// loop over the temp arrays
		// for (i = 0; i < 8; i++)
		// {
		// 	for (j = 0; j < 8; j++)
		// 	{
		// 		WRITE_FIFO(&temp1[i][j], IN_BASE_2to3, CONTROL_BASE_2to3);
		// 	}
		// }

		// for (i = 0; i < 8; i++)
		// {
		// 	for (j = 0; j < 8; j++)
		// 	{
		// 		WRITE_FIFO(&temp2[i][j], IN_BASE_2to3, CONTROL_BASE_2to3);
		// 	}
		// }
	}
}

int main(void)
{
	printf("Hello from cpu2\n");

	levelshift();

	return 0;
}
