#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adidas.h"


int main(int argc, char* argv[]) {
	FILE* inputFilePtr = fopen(argv[1], "rb");
	FILE* encodedFilePtr = fopen(argv[2], "wb");
	//char c;
	//char ch[150];
	//if argc == 0 no files
	if (argc == 0)
	{
		printf("Enter names for 2 files\n");
		
	}
	else if(inputFilePtr == NULL)
	{
		printf("Enter name for input file");
	}
	else if(encodedFilePtr == NULL)
	{
		printf("Enter name for encoded file");
	}

	uint8_t buffer = 0; 
	int byteRead = fread(&buffer, 1, 1, inputFilePtr);
	//char charBin[8];
	//char highNibble[4];
	//char lowNibble[4];

	while (byteRead != 0)
	{
		uint16_t encodedByte = encode(buffer);

		fwrite(&encodedByte, 2, 1, encodedFilePtr);

		byteRead = fread(&buffer, 1, 1, inputFilePtr);
	}
	/*
	//while ((c = getc(inputFilePtr)) != EOF)
	//{
	//	//printf("Bytes read: %d\n", (bytesRead & 0xf0) >> 1);

	//	printf("\nByte: ");
	//	for (int i = 7; i >= 0; i--) {
	//		charBin[i] = (c >> i) & 1 ? 1 : 0;
	//		printf("%d", charBin[i]);
	//	}

	//	printf("\nHighNibble: ");
	//	for (int j = 7; j >= 4; j--) {
	//		highNibble[j] = (c >> j) & 1 ? 1 : 0;
	//		printf("%d", highNibble[j]);
	//	}

	//	printf("\nLowNibble: ");
	//	for (int k = 3; k >= 0; k--) {
	//		lowNibble[k] = (c >> k) & 1 ? 1 : 0;
	//		printf("%d", lowNibble[k]);
	//	}

	//	printf("\nChar: %c\n", c);
	//}

	fscanf(inputFilePtr, "%[^\n]", ch);
	printf("%s", ch);
	while ((c = fgetc(inputFilePtr)) != EOF) {

		
	}
	while ((ch = getc(inputFilePtr)) != EOF) {
		ch = fgetc(inputFilePtr);
		printf("%c", ch);
		putchar(ch);
	}
	*/
	
	fclose(inputFilePtr);
	fclose(encodedFilePtr);

	return 0;
}