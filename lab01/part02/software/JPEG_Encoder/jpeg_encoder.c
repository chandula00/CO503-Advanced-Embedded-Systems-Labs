/*************************************************************************************
 * CO503 Advanced Embedded Systems
 *
 * Date			: 16-08-2016
 * Author 		: Isuru Nawinne
 * Edited by	:
 *
 * Description	: Compress and convert a BMP image file into JPEG format
 *
 *************************************************************************************/

#include "application/jpeg_encoding.h"
#include "application/bmp_extract.h"
#include <stdio.h>
#include <stdint.h>
#include <io.h>
#include <unistd.h>

#define NO_OF_FILES 7
#include <time.h>

void convert_picture(const char *jtag_input);
#define LED_BASE 0x11001010 // INSERT BASE ADDRESS OF "led_out" PIO DEVICE FROM QSYS
#define OFFSET 0x00000000

static uint8_t count;
static uint8_t countShow;
static uint8_t countItr = 0;

int main()
{
	char jtag_input[20];

	// Print that welcome message. Programmers looove welcome messages! ;)
	printf("CO503 JPEG Encoder \n\n");

	while (countItr < NO_OF_FILES)
	{
		printf("Input file: ");
		IOWR_8DIRECT(LED_BASE, OFFSET, 0xF0);
		usleep(200000);
		scanf("%s", jtag_input); // Ask for the input BMP file

		// Check if the filename ends in '.bmp'
		if (strcmp(&jtag_input[strlen(jtag_input) - 4], ".bmp") == 0)
		{

			convert_picture(jtag_input); // See function at the bottom
		}
		printf("\n\n");
		countItr++;
	}
	count = 15;
	while (count > 1)
	{
		usleep(100000); // Wait for about 0.1 seconds

		IOWR_8DIRECT(LED_BASE, OFFSET, count); // Write the value of "count" to the "led_out" PIO device
		count /= 2;
	}
	while (1)
	{
		IOWR_8DIRECT(LED_BASE, OFFSET, count);
		usleep(200000); // Wait for about 0.2 seconds
		IOWR_8DIRECT(LED_BASE, OFFSET, 0);
		usleep(200000); // Wait for about 0.2 seconds
	}

	return 0;
}

/*
 * Convert a BMP picture of name <jtag_input> into JPEG.
 */
void convert_picture(const char *jtag_input)
{
	char file_name[80] = "/mnt/host/files/";
	char destination[80] = "/mnt/host/files/";
	Bmp_data pic_data;

	strcat(file_name, jtag_input);
	strcat(destination, jtag_input);

	count = 1;
	countShow = 0;
	while (count < 9)
	{
		usleep(100000); // Wait for about 0.1 seconds
		countShow += count;
		IOWR_8DIRECT(LED_BASE, OFFSET, countShow); // Write the value of "count" to the "led_out" PIO device
		count *= 2;
	}

	// Replace the '.bmp' with '.jpg'
	strcpy(&destination[strlen(destination) - 3], "jpg");

	if (bmp_extract(file_name, &pic_data) == 0)
	{
		clock_t start, end;
		double cpu_time;
		start = clock();

		// Convert to JPEG. This is where the magic happens!
		jpeg_encode(destination, pic_data.bitmap, pic_data.header->BMPHeight, pic_data.header->BMPWidth, 90);

		end = clock();

		cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

		printf("Time - %f", cpu_time);
	}
	else
	{
		// An error has happened
	}
}
