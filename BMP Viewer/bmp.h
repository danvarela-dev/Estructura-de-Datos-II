#ifndef BMP_H
#define BMP_H
#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct header{

	char signature[2];
	uint32_t fileSize;
		uint16_t Reserved_1;
		uint16_t Reserved_2;
	uint32_t dataOffset;

};
#pragma pack(push, 1)


#pragma pack(pop)

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
//struct headerinfo {
//	uint32_t size;
//	uint32_t width;
//	uint32_t height;
//	uint16_t planes;
//	uint16_t bitCount;
//	uint32_t compression;
//	uint32_t imageSize;
//	uint32_t x_pixels;
//	uint32_t y_pixels;
//	uint32_t colorsUsed;
//	uint32_t importantColors;
//};

class Mybitmap {
private:
	char* file_name;
	ifstream file_bmp;
	header reg_header;
	headerInfo reg_headerInfo;

	void readHeader();
	void read_headerInfo();

public:
	void openBMP(const char *);
	void printHeader();

};




#endif // !BMP_H
