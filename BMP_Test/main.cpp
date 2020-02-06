#include <iostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <inttypes.h>
#include <cstring>

using namespace std;

int main() {
	//Header

	char str_signature[3];
	char str_fileSize[4];
	char str_reserved[4];
	char str_dataOffset[4];
	

	//landing variables
	int fileSize;
	int reserved_data;
	int dataOffset;
	int xPixelsPerM;
	int yPixelsPerM;
	int colorsImportant;

	char bmp_header[14];
	ifstream file_bmp;

	file_bmp.open("m.bmp", ifstream::in | ifstream::binary);
	file_bmp.read(bmp_header, sizeof(bmp_header));

	str_signature[2] = '\0';
	str_signature[0] = bmp_header[0];
	str_signature[1] = bmp_header[1];
	printf("Header { \n");

	printf("Tipo: %s", str_signature);

	str_fileSize[0] = bmp_header[2];
	str_fileSize[1] = bmp_header[3];
	str_fileSize[2] = bmp_header[4];
	str_fileSize[3] = bmp_header[5];

	memcpy(&fileSize, str_fileSize, 4);
	printf("\nSize: %d", fileSize);

	str_reserved[0] = bmp_header[6];
	str_reserved[1] = bmp_header[7];
	str_reserved[2] = bmp_header[8];
	str_reserved[3] = bmp_header[9];

	memcpy(&reserved_data, str_reserved, 4);
	printf("\nReserved: %i", reserved_data);

	str_dataOffset[0] = bmp_header[10];
	str_dataOffset[1] = bmp_header[11];
	str_dataOffset[2] = bmp_header[12];
	str_dataOffset[3] = bmp_header[13];

	memcpy(&dataOffset, str_dataOffset, 4);
	printf("\nDataOffset: %i", dataOffset);
	printf("\n}");

	//InfoHeader
	char bmp_infoHeader[40];
	file_bmp.read(bmp_infoHeader, sizeof(bmp_infoHeader));

	char str_size[4];
	char str_width[4];
	char str_height[4];
	char str_planes[2];
	char str_bitCount[2];
	char str_compression[4];
	char str_imageSize[4];
	char str_xPixelsPerM[4];
	char str_yPixelsPerM[4];
	char str_colorsUsed[4];
	char str_colorsImportant[4];

	int size;
	int width;
	int height;
	uint16_t planes;
	uint16_t bitCount;
	int compression;
	int imageSize;
	int colorsUsed;

	str_size[0] = bmp_infoHeader[0];
	str_size[1] = bmp_infoHeader[1];
	str_size[2] = bmp_infoHeader[2];
	str_size[3] = bmp_infoHeader[3];

	memcpy(&size, str_size , 4);

	printf("\nInfoHeader { \n");
	printf("Size: %i",size);

	str_width[0] = bmp_infoHeader[4];
	str_width[1] = bmp_infoHeader[5];
	str_width[2] = bmp_infoHeader[6];
	str_width[3] = bmp_infoHeader[7];

	memcpy(&width, str_width, 4);
	printf("\nWidth: %i", width);

	str_height[0] = bmp_infoHeader[8];
	str_height[1] = bmp_infoHeader[9];
	str_height[2] = bmp_infoHeader[10];
	str_height[3] = bmp_infoHeader[11];
	
	memcpy(&height, str_height, 4);
	printf("\nHeight: %i", height);

	str_planes[0] = bmp_infoHeader[12];
	str_planes[1] = bmp_infoHeader[13];

	memcpy(&planes, str_planes , 2);
	cout << "\nPlanes: " << planes;

	str_bitCount[0] = bmp_infoHeader[14];
	str_bitCount[1] = bmp_infoHeader[15];

	memcpy(&bitCount, str_bitCount, 2);
	cout << "\nBit Count: " << bitCount;

	str_compression[0] = bmp_infoHeader[16];
	str_compression[1] = bmp_infoHeader[17];
	str_compression[2] = bmp_infoHeader[18];
	str_compression[3] = bmp_infoHeader[19];

	memcpy(&compression, str_compression, 4);
	printf("\nCompression: %i", compression);

	str_imageSize[0] = bmp_infoHeader[20];
	str_imageSize[1] = bmp_infoHeader[21];
	str_imageSize[2] = bmp_infoHeader[22];
	str_imageSize[3] = bmp_infoHeader[23];

	memcpy(&imageSize, str_imageSize, 4);
	printf("\nImage Size: %i", imageSize);

	str_xPixelsPerM[0] = bmp_infoHeader[24];
	str_xPixelsPerM[1] = bmp_infoHeader[25];
	str_xPixelsPerM[2] = bmp_infoHeader[26];
	str_xPixelsPerM[3] = bmp_infoHeader[27];

	memcpy(&xPixelsPerM, str_xPixelsPerM ,4);
	printf("\nX Pixels Per M: %i" ,xPixelsPerM);

	str_yPixelsPerM[0] = bmp_infoHeader[28];
	str_yPixelsPerM[1] = bmp_infoHeader[29];
	str_yPixelsPerM[2] = bmp_infoHeader[30];
	str_yPixelsPerM[3] = bmp_infoHeader[31];

	memcpy(&yPixelsPerM, str_yPixelsPerM, 4);
	printf("\nY Pixels Per M: %i", yPixelsPerM);

	str_colorsUsed[0] = bmp_infoHeader[32];
	str_colorsUsed[1] = bmp_infoHeader[33];
	str_colorsUsed[2] = bmp_infoHeader[34];
	str_colorsUsed[3] = bmp_infoHeader[35];

	memcpy(&colorsUsed, str_colorsUsed , 4);
	printf("\nColors Used: %i", colorsUsed);

	str_colorsImportant[0] = bmp_infoHeader[36];
	str_colorsImportant[1] = bmp_infoHeader[37];
	str_colorsImportant[2] = bmp_infoHeader[38];
	str_colorsImportant[3] = bmp_infoHeader[39];
	
	memcpy(&colorsImportant, str_colorsImportant, 4);
	printf("\nColors Important: %i", colorsImportant);



	printf("\n}");


	file_bmp.close();
}

