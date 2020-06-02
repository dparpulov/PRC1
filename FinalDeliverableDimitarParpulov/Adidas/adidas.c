#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adidas.h"

uint8_t getHighNibble(uint8_t buffer) {
	uint8_t highNibble = (buffer & 0xf0) >> 1;   // buffer AND 11110000  => keeps the first 4 bits
	return highNibble;
}

uint8_t getLowNibble(uint8_t buffer) {
	uint8_t lowNibble = (buffer & 0x0f ) << 3;	// buffer AND 00001111 => keeps the second 4 bits
	return lowNibble;
}

uint8_t getReverseHighNibble(uint8_t channeledByte) {
	uint8_t highNibble = (channeledByte << 1 ) & 0xf0;   // channeledByte is shifted with 1 bit to the left & 11110000  => gets the original high nibble
	return highNibble;
}

uint8_t getReverseLowNibble(uint8_t channeledByte) {
	uint8_t lowNibble = (channeledByte >> 3) & 0x0f;	// channeledByte is shifted with 3 bits to the right & 00001111 => gets the original low nibble
	return lowNibble;
}

//uses XOR to put all bits into the LSB
//strips all except LSB (& 1) and flips it (~byte) { (~byte) & 1  }=> returns 1 if even
// byte & 1 => returns 0 when even and 1 when odd
int checkParity(uint8_t byte) {
	byte ^= byte >> 4;
	byte ^= byte >> 2;
	byte ^= byte >> 1;

	//return (~byte) & 1;
	return byte & 1;

}

uint8_t addParityBits(uint8_t nibble) {
	uint8_t p0 = checkParity(nibble & 0x38);  //d0 d1 d2   //byte & 0x 00111000 //38 
	uint8_t p1 = checkParity(nibble & 0x58);  //d0 d1 d3   //byte & 0x 01011000 //58
	uint8_t p2 = checkParity(nibble & 0x70);  //d1 d2 d3   //byte & 0x 01110000 //70

	uint8_t byteWithParity = nibble | (p2 << 2) | (p1 << 1) | p0;

	return byteWithParity;
}

uint16_t encode(uint8_t buffer)
{
	uint8_t highNibble = getHighNibble(buffer);   ///No need to create functions for such small statements
	uint8_t lowNibble = getLowNibble(buffer);

	uint8_t firstByte = addParityBits(highNibble);
	uint8_t secondByte = addParityBits(lowNibble);

	uint16_t encodedByte = (uint16_t) (firstByte << 8) | secondByte;

	return encodedByte;
}

uint16_t channel(uint16_t encodedByte) {
	srand(time(NULL));

	uint16_t noiseBit = 1 << (rand() % 16);

	return encodedByte ^ noiseBit;
}

uint8_t fixNoiseBits(uint8_t nibbleByte) {
	int checkParityZeroCircle = checkParity(nibbleByte & 0x39); //d0 d1 d2   //byte & 00111001
	int checkParityOneCircle = checkParity(nibbleByte & 0x5a);  //d0 d1 d3   //byte & 01011010
	int checkParityTwoCircle = checkParity(nibbleByte & 0x74);  //d1 d2 d3   //byte & 01110100
	
	if (checkParityZeroCircle && checkParityOneCircle && checkParityTwoCircle)
		return nibbleByte ^ 0x10;   //nibbleByte XOR 00010000
	else if (checkParityZeroCircle && checkParityOneCircle)
		return nibbleByte ^ 0x08;	//nibbleByte XOR 00001000
	else if (checkParityZeroCircle && checkParityTwoCircle)
		return nibbleByte ^ 0x20;	//nibbleByte XOR 00100000
	else if (checkParityOneCircle && checkParityTwoCircle)
		return nibbleByte ^ 0x40;	//nibbleByte XOR 01000000

	return nibbleByte;
}

// When converting uint16_t to uint8_t the second 8 bits are put into the smaller variable
uint8_t decode(uint16_t channeledByte) {
	uint8_t byteFromHighNibble = fixNoiseBits(channeledByte >> 8); 
	uint8_t byteFromLowNibble = fixNoiseBits(channeledByte);

	uint8_t highNibble = getReverseHighNibble(byteFromHighNibble);
	uint8_t lowNibble = getReverseLowNibble(byteFromLowNibble);

	return highNibble | lowNibble;
}