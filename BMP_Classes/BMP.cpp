#include "BMP.h"

MyBitmap::MyBitmap() {}

void MyBitmap::readHeader() {
	file_bmp.seekg(0, ios_base::beg);
	file_bmp.read((char*)&reg_header, sizeof(reg_header.signature));
}

void MyBitmap::read_infoHeader() {
	file_bmp.seekg(sizeof(reg_header), ios_base::beg);
	file_bmp.read((char*)&reg_infoHeader, sizeof(reg_infoHeader));
}

void MyBitmap::openBMP(const char* filename) 
{
	file_name = (char*)filename;
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	readHeader();
	read_infoHeader();

}

void MyBitmap::print_metaData() {

	char signature[3];
	signature[0] = reg_header.signature[0];
	signature[1] = reg_header.signature[1];
	signature[2] = '\0';


	cout << "**************************** H E A D E R *******************************" << endl;
	cout << "Signature: " << signature << endl; 
	cout << "File Size: " << reg_header.fileSize << endl;
	cout << "Reserved 1: " << reg_header.Reserved_1 << endl;
	cout << "Reserved 2: " << reg_header.Reserved_2 << endl;
	cout << "Data Offset: " << reg_header.dataOffset << endl;
	cout << "**************************** H E A D E R *******************************" << endl;



//diferencia entre economia de libre de mercado y economia planeada	

}