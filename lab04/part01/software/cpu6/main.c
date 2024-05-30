#include <stdio.h>
#include "FIFO.h"

typedef char INT8;
typedef unsigned char UINT8;

int main(void)
{
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];
	int temp;

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

		// filename[out++] = 't';
		// filename[out++] = 'e';
		// filename[out++] = 's';
		// filename[out++] = 't';

		filename[out - 3] = 'j';
		filename[out - 2] = 'p';
		filename[out - 1] = 'g';
		filename[out] = '\0';

		char path[50] = "/mnt/host/files/";
		strcat(path, filename);

		fptr = fopen(path, "wb");

		while (1)
		{
			// out = (UINT8)RECV2();
			READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);

			fputc(out, fptr);

			if (out == 0xFF)
			{
				// out = (UINT8)RECV2();
				READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);

				fputc(out, fptr);

				if (out == 0xD9)
					break;
			}
		}

		fclose(fptr);

		printf("Image Done!\n");
	}

	return 0;
}
