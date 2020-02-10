#ifndef BMP_H
#define BMP_H
#include <iostream>
#include <fstream>

using namespace std;

class Headers {
private:
	char bufferHeader[14];
	char buffer_headerInfo[40];
	char buffer_colorPallete[256];

	void unPack();
	void Init();

public:
	char signature[3];
	//header
	uint32_t fileSize;
	uint16_t Reserved_1;
	uint16_t Reserved_2;
	uint32_t dataOffset;
	//infoHeader
	uint32_t headerSize;
	uint32_t imageWidth;
	uint32_t imageHeight;
	uint16_t planes;
	uint16_t bitsperPixel;
	uint32_t compression;
	uint32_t imageSize;
	uint32_t xPixels;
	uint32_t yPixels;
	uint32_t totalColors;
	uint32_t importantColors;
	//color table

	uint8_t BLUE;
	uint8_t GREEN;
	uint8_t RED;
	uint8_t RESERVED_4PADDING;


	Headers();
	void setHeaderBuffer(const char *);
	void setHeader_infoBuffer(const char*);
	void setColorPallete_Buffer(const char * );
	
};

class MyBitmap {

private:
	char* file_name;
	char bufferHeader_aux[14];
	char buffer_headerInfo_aux[40];
	char 

	ifstream file_bmp;

	Headers bmpHeader;

	void readHeader();
	

public:
	
	void openBMP(const char*);
	void print_metaData();

};


#endif // !BMP_H
