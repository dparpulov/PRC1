#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adidas.h"

int main(int argc, char* argv[]) {
	FILE* inputFilePtr = fopen(argv[1], "rb");
	FILE* decodedFilePtr = fopen(argv[2], "wb");

	if (inputFilePtr == NULL)
	{
		printf("Enter names for 2 files\n");

	}
	else if (inputFilePtr == NULL)
	{
		printf("Enter name for input file");
	}
	else if (decodedFilePtr == NULL)
	{
		printf("Enter name for channeled file");
	}

	uint16_t buffer = 0;
	int byteRead = fread(&buffer, 2, 1, inputFilePtr);

	while (byteRead != 0)
	{
		uint8_t decodedByte = decode(buffer);

		fwrite(&decodedByte, 1, 1, decodedFilePtr);

		byteRead = fread(&buffer, 2, 1, inputFilePtr);
	}


	fclose(inputFilePtr);
	fclose(decodedFilePtr);

	return 0;
}