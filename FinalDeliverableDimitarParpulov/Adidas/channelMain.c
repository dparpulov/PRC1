#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adidas.h"


int main(int argc, char* argv[]) {
	FILE* inputFilePtr = fopen(argv[1], "rb");
	FILE* channeledFilePtr = fopen(argv[2], "wb");

	if (inputFilePtr == NULL)
	{
		printf("Enter names for 2 files\n");

	}
	else if (inputFilePtr == NULL)
	{
		printf("Enter name for input file");
	}
	else if (channeledFilePtr == NULL)
	{
		printf("Enter name for channeled file");
	}

	uint16_t buffer = 0;
	int byteRead = fread(&buffer, 2, 1, inputFilePtr);
		
	int counter = 0;

	while (byteRead != 0)
	{
		uint16_t encodedByte = 0;

		encodedByte = channel(buffer);


		fwrite(&encodedByte, 2, 1, channeledFilePtr);

		byteRead = fread(&buffer, 2, 1, inputFilePtr);

		counter++;
	}

	fclose(inputFilePtr);
	fclose(channeledFilePtr);


	return 0;
}