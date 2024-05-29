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
	printf("Level shifting\n");

	int i, j;
	INT8 temp1[8][8], temp2[8][8]; // Temporary storage array
	int row, col, value;

	while (1)
	{
		printf("Running...\n");

		// Read and level shift data
		printf("First 8x8 Grid:\n");
		for (j = 0; j < 64; j++)
		{
			row = j / 8;
			col = j % 8;

			// Read from the first FIFO
			READ_FIFO(&value, OUT_BASE_1to2A, CONTROL_BASE_1to2A);
			value -= 128;
			WRITE_FIFO(&value, IN_BASE_2to3, CONTROL_BASE_2to3);

			printf("%4d ", value);

			if (col == 7)
				printf("\n");

			// Read from the second FIFO
			READ_FIFO(&value, OUT_BASE_1to2B, CONTROL_BASE_1to2B);
			value -= 128;
			temp1[row][col] = value; // Store into temp array

			// Read from the third FIFO
			READ_FIFO(&value, OUT_BASE_1to2C, CONTROL_BASE_1to2C);
			value -= 128;
			temp2[row][col] = value; // Store into temp array
		}

		// Print the first 8x8 grid
		printf("Second 8x8 Grid:\n");
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%4d ", temp1[i][j]);
			}
			printf("\n");
		}

		// Print the second 8x8 grid
		printf("Third 8x8 Grid:\n");
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%4d ", temp2[i][j]);
			}
			printf("\n");
		}

		int temp;
		// Write the values from temp arrays to the FIFO
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				temp = temp1[i][j];
				WRITE_FIFO(&temp, IN_BASE_2to3, CONTROL_BASE_2to3);
			}
		}

		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				temp = temp2[i][j];
				WRITE_FIFO(&temp, IN_BASE_2to3, CONTROL_BASE_2to3);
			}
		}
	}
}

int main(void)
{
	printf("CPU2 Started!!!\n");

	delay(100000);
	FIFO_INIT(CONTROL_BASE_2to3);
	delay(100000);

	levelshift();

	return 0;
}
