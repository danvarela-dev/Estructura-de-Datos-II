#ifndef BMP_H
#define BMP_H
#include <iostream>
#include <fstream>

using namespace std;

class header {
public:
	char signature[2];
	uint32_t fileSize;
	uint16_t Reserved_1;
	uint16_t Reserved_2;
	uint32_t dataOffset;
};

class infoHeader {
public:
	uint32_t size;
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bitCount;
	uint32_t compression;
	uint32_t imageSize;
	uint32_t xPixelsPerM;
	uint32_t yPixelsPerM;
	uint32_t colorsUsed;
	uint32_t colorsImportant;
};

class MyBitmap {

private:
	char* file_name;
	ifstream file_bmp;
	header reg_header;
	infoHeader reg_infoHeader;

	void readHeader();
	void read_infoHeader();

public:
	MyBitmap();

	
	void openBMP(const char*);
	void print_metaData();



	


};


#endif // !BMP_H
