#ifndef BMP_H
#define BMP_H
#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Headers{

	char signature[2];
	uint32_t fileSize;
		uint16_t Reserved_1;
		uint16_t Reserved_2;
	uint32_t dataOffset;

};

struct headerInfo {
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

#pragma pack(pop)

struct colorPallete {
	uint8_t B;
	uint8_t G;
	uint8_t R;
	uint8_t Padding;
};


class Mybitmap {
private:
	char* file_name;
	ifstream file_bmp;
	Headers reg_header;
	headerInfo reg_headerInfo;
	colorPallete reg_colorPallete;

	void readHeader();
	void read_headerInfo();
	void read_colorPallete();

public:
	void openBMP(const char *);
	void printHeader();

};




#endif // !BMP_H
