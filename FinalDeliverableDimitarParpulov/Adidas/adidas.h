#ifndef ADIDAS_H
#define ADIDAS_H

#include <stdint.h>

	uint8_t getHighNibble(uint8_t buffer);
	
	uint8_t getLowNibble(uint8_t buffer);

	int checkParity(uint8_t byte);
	
	uint8_t addParityBits(uint8_t byte);

	uint16_t encode(uint8_t buffer);

	uint16_t channel(uint16_t encodedByte);

	uint8_t decode(uint16_t channeledByte);

	uint8_t fixNoiseBits(uint8_t nibbleByte);
#endif