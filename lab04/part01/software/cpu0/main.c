#include <io.h>
#include "datatype.h"
#include "encoder.h"
#include "FIFO.h"

int main(int argc, char *argv[])
{

	INT8 input_file_name[150];
	FILE *fp;
	UINT32 quality_factor, image_width, image_height;

	delay(100000);
	FIFO_INIT(CONTROL_BASE_1to2A);
	delay(100000);
	FIFO_INIT(CONTROL_BASE_1to2B);
	delay(100000);
	FIFO_INIT(CONTROL_BASE_1to2C);
	delay(100000);

	printf("Starting the program\n");

	fp = fopen("/mnt/host/files/param.txt", "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error opening parameter file\n");
		return 1;
	}

	while (fscanf(fp, "%s", input_file_name) != EOF)
	{

		printf("\nReading from file: %s\n", input_file_name);

		fscanf(fp, "%d", &quality_factor);
		fscanf(fp, "%d", &image_width);
		fscanf(fp, "%d", &image_height);

		encode_image(input_file_name, quality_factor, image_width, image_height);

		printf("End of the Image!\n");
	}

	fclose(fp);

	printf("\nDone!\n");

	return 0;
}