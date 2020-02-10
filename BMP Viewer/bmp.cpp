#include "bmp.h"

void Mybitmap::readHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char*)&reg_header, sizeof(reg_header));
}

void Mybitmap::read_headerInfo() {
	file_bmp.seekg(sizeof(reg_header), ios_base::beg);
	file_bmp.read((char*)&reg_headerInfo, sizeof(reg_headerInfo));
}
void Mybitmap::read_colorPallete() {
	file_bmp.seekg(sizeof(reg_header) + sizeof(reg_headerInfo), ios_base::beg);
	file_bmp.read((char*)&reg_colorPallete, sizeof(reg_colorPallete));
	}

void Mybitmap::openBMP(const char* filename) {
	file_name = (char*)filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	readHeader();
	read_headerInfo();
	read_colorPallete();
}

void Mybitmap::printHeader() {
	char type[3];

	type[0] = reg_header.signature[0];
	type[1] = reg_header.signature[1];

	type[2] = '\0';
	//memcpy(type, &reg_header.signature, 2);

	cout << "Header\n********************************************" << endl;
	cout << "Signature: " << type << endl;
	cout << "File Size: " << reg_header.fileSize << endl;

	cout << "Reserved 1: " << reg_header.Reserved_1 << endl;
	cout << "Reserved 2: " << reg_header.Reserved_2 << endl;

	cout << "Data Offset: " << reg_header.dataOffset << endl;

	cout << "********************************************\nInfoHeader\n" << endl;
	cout << "Size: " << reg_headerInfo.size << endl;
	cout << "Width: " << reg_headerInfo.width << endl;
	cout << "Height: " << reg_headerInfo.height << endl;
	cout << "Planes: " << reg_headerInfo.planes << endl;
	cout << "Bit Count: " << reg_headerInfo.bitCount << endl;
	cout << "Compression: " << reg_headerInfo.compression << endl;
	cout << "Image Size: " << reg_headerInfo.imageSize << endl;
	cout << "X Pixels Per M: " << reg_headerInfo.xPixelsPerM << endl;
	cout << "Y Pixels Per M: " << reg_headerInfo.yPixelsPerM << endl;
	cout << "Colors Used: " << reg_headerInfo.colorsUsed << endl;
	cout << "Colors Important: " << reg_headerInfo.colorsImportant << endl;
	cout << "********************* Color Pallete ***********************" << endl;
	cout << "B: " << reg_colorPallete.B << endl;
	cout << "G: " << reg_colorPallete.G << endl;
	cout << "R: " << reg_colorPallete.R << endl;
	cout << "Padding" << reg_colorPallete.Padding << endl;




}

