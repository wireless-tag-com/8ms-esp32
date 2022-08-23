#include "stdint.h"

// CRC-16 / MODBUS -> 8005H
const uint16_t crctalbeabs[] = { 
	0x0000, 0xCC01, 0xD801, 0x1400, 0xF001, 0x3C00, 0x2800, 0xE401, 
	0xA001, 0x6C00, 0x7800, 0xB401, 0x5000, 0x9C01, 0x8801, 0x4400 
};
 
uint16_t crc16tablefast(uint8_t *data, uint32_t len)
{
	uint16_t crc = 0xffff; 
	uint8_t *ptr = data;
	uint32_t i;
	uint8_t ch;
 
	for (i = 0; i < len; i++) {
		ch = *ptr++;
		crc = crctalbeabs[(ch ^ crc) & 15] ^ (crc >> 4);
		crc = crctalbeabs[((ch >> 4) ^ crc) & 15] ^ (crc >> 4);
	} 
	
	return crc;
}

uint16_t crc16tablefast_muti(uint8_t *data, uint32_t len, uint8_t *data1, uint32_t len1) 
{
	uint16_t crc = 0xffff; 
	uint8_t *ptr = data;
	uint8_t *pt1 = data1;
	uint32_t i;
	uint8_t ch;

	for (i = 0; i < len; i++) {
		ch = *ptr++;
		crc = crctalbeabs[(ch ^ crc) & 15] ^ (crc >> 4);
		crc = crctalbeabs[((ch >> 4) ^ crc) & 15] ^ (crc >> 4);
	} 

	for(i = 0; i<len1; i++) {
		ch = *pt1++;
		crc = crctalbeabs[(ch ^ crc) & 15] ^ (crc >> 4);
		crc = crctalbeabs[((ch >> 4) ^ crc) & 15] ^ (crc >> 4);
	}

	return crc;
}

uint16_t crc16tablesingle(uint8_t *data, uint32_t len, uint16_t crc) {
	uint8_t *ptr = data;
	uint32_t i;
	uint8_t ch;
 
	for (i = 0; i < len; i++) {
		ch = *ptr++;
		crc = crctalbeabs[(ch ^ crc) & 15] ^ (crc >> 4);
		crc = crctalbeabs[((ch >> 4) ^ crc) & 15] ^ (crc >> 4);
	} 
	
	return crc;
}