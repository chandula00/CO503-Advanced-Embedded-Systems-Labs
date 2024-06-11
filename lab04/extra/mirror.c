#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[] = "image7.jpg";
    char outputFileName[] = "output.jpg";

    // Open input file for reading
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Open output file for writing
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL)
    {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Get the size of the input file
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Allocate memory for the image data
    unsigned char *imageData = (unsigned char *)malloc(fileSize);
    if (imageData == NULL)
    {
        perror("Memory allocation failed");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Read the image data from the input file
    fread(imageData, 1, fileSize, inputFile);

    // Reverse the order of pixels in each row to mirror the image horizontally
    for (int i = 0; i < fileSize; i += 3)
    {
        unsigned char temp = imageData[i];
        imageData[i] = imageData[i + 2];
        imageData[i + 2] = temp;
    }

    // Write the modified image data to the output file
    fwrite(imageData, 1, fileSize, outputFile);

    // Close the files and free memory
    fclose(inputFile);
    fclose(outputFile);
    free(imageData);

    printf("Image mirrored successfully.\n");

    return 0;
}
