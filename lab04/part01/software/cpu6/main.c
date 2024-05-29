#include <stdio.h>
#include "FIFO.h"

typedef char INT8;
typedef unsigned char UINT8;

int main(void)
{
	FILE *fptr;
	UINT8 out;
	INT8 filename[50];

	printf("Start\n");

	while (1)
	{

		out = 0;
		// READ_FIFO(&filename[out], OUT_BASE_5to6, CONTROL_BASE_1to6);

		// if (filename[out] == '\0')
		// 	exit(0);

		// while (filename[out] != '\0')
		// {
		// 	out++;
		// 	READ_FIFO(&filename[out], OUT_BASE_5to6, CONTROL_BASE_1to6);
		// }

		filename[out++] = 't';
		filename[out++] = 'e';
		filename[out++] = 's';
		filename[out++] = 't';

		filename[out++] = '.';
		filename[out++] = 'j';
		filename[out++] = 'p';
		filename[out++] = 'g';
		filename[out] = '\0';

		char path[50] = "/mnt/host/files/";
		strcat(path, filename);

		fptr = fopen(path, "wb");

		int n = 0;
		while (n < 100)
		{
			// out = (UINT8)RECV2();
			// READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);
			out = 'a';

			fputc(out, fptr);

			// if (out == 0xFF)
			// {
			// 	// out = (UINT8)RECV2();
			// 	READ_FIFO(&out, OUT_BASE_5to6, CONTROL_BASE_5to6);

			// 	fputc(out, fptr);

			// 	if (out == 0xD9)
			// 		break;
			// }

			n++;
		}

		fclose(fptr);

		printf("Image Done!\n");

		break;
	}

	return 0;
}
