#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"
// #include <time.h>

typedef char INT8;
typedef unsigned char UINT8;

int main(void)
{
	FILE *fptr, *fptr2;
	UINT8 out;
	INT8 filename[50];
	int temp;
	// clock_t start_time, end_time;
	int count = 1;

	printf("Starting CPU6 ....\n");

	while (1)
	{
		printf("\nFinal...\n");

		out = 0;
		READ_FIFO(&temp, OUT_BASE_1to6, CONTROL_BASE_1to6);
		filename[out] = temp;

		if (filename[out] == '\0')
			exit(0);

		while (filename[out] != '\0')
		{
			out++;
			READ_FIFO(&temp, OUT_BASE_1to6, CONTROL_BASE_1to6);
			filename[out] = temp;
		}

		printf("Name Received\n");

		filename[out - 3] = 'j';
		filename[out - 2] = 'p';
		filename[out - 1] = 'g';
		filename[out] = '\0';

		char path[50] = "/mnt/host/files/";
		strcat(path, filename);

		fptr = fopen(path, "wb");
		// fptr2 = fopen("/mnt/host/files/data.txt", "w");

		// start_time = clock(); // Measure start time

		while (1)
		{
			READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);

			fputc(out, fptr);
			// fprintf(fptr2, "%02X\n", out); // Write byte in hexadecimal format followed by a space

			if (out == 0xFF)
			{
				READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);

				fputc(out, fptr);
				// fprintf(fptr2, "%02X\n", out); // Write byte in hexadecimal format followed by a space

				if (out == 0xD9)
					break;
			}
		}

		// end_time = clock(); // Measure end time

		// fclose(fptr2);

		// double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate elapsed time in seconds

		// long long int file_size = ftell(fptr); // Get the file size

		// double throughput = (double)file_size / elapsed_time; // Calculate throughput (bytes per second)

		// printf("Time taken for encoding: %f seconds\n", elapsed_time);
		// printf("Throughput for writing the image data: %.2f bytes per second\n", throughput);

		fclose(fptr);
		printf("Image Done!\n");
	}

	return 0;
}
