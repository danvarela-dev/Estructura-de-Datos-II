#include "BMP.h"

using namespace std;

void MyBitmap::readHeaders() {
	file_bmp.seekg(0, ios_base::beg);

	file_bmp.read(bufferHeader_aux, sizeof(bufferHeader_aux));
	file_bmp.read(buffer_headerInfo_aux, sizeof(buffer_headerInfo_aux));
	

	bmpHeader.setHeaderBuffer(bufferHeader_aux);
	bmpHeader.setHeader_infoBuffer(buffer_headerInfo_aux);
	
	print_metaData();
}	

void MyBitmap::readPixels() {
	int height = bmpHeader.imageHeight;
	int width = bmpHeader.imageWidth;

	int pixelDimensions = width * height;
	int padding = (4 - (width * 3) % 4) % 4 ;

		 

	for (int i = 0; i < width; i++)
	{
		for (int i = 0; i < height; i++)
		{
			file_bmp.read((char*)&BLUE_aux,1);
			file_bmp.read((char*)&GREEN_aux, 1);
			file_bmp.read((char*)&RED_aux, 1);
			file_bmp.read((char*)&RESERVED4PADDING_aux, 1);

			cout << "B:" << (int)BLUE_aux << "\t\t\tG: " << (int)GREEN_aux << "\t\t\tR: " <<(int)RED_aux << endl;

		}
		file_bmp.seekg(bmpHeader.imageWidth % 4, std::ios::cur);
	}


	//file_bmp.read((char*)&bgr, sizeof(bgr));
	

}

MyBitmap::MyBitmap()
{
}

void MyBitmap::openBMP(const char* filename)
{
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	readHeaders();
	readPixels();
	file_bmp.close();
	
}

void MyBitmap::print_metaData() {

	cout << "**************************** H E A D E R *******************************" << endl;
	cout << "Signature: " << bmpHeader.signature << endl; 
	cout << "File Size: " << bmpHeader.fileSize << endl;
	cout << "Reserved 1: " << bmpHeader.Reserved_1 << endl;
	cout << "Reserved 2: " << bmpHeader.Reserved_2 << endl;
	cout << "Data Offset: " << bmpHeader.dataOffset << endl;
	cout << "**************************** I N F O  H E A D E R *******************************" << endl;
	cout << "Size: " << bmpHeader.headerSize << endl;
	cout << "Width: " << bmpHeader.imageWidth << endl;
	cout << "Height: " << bmpHeader.imageHeight << endl;
	cout << "Planes: " << bmpHeader.planes << endl;
	cout << "Bit Count: " << bmpHeader.bitsperPixel << endl;
	cout << "Compression: " << bmpHeader.compression << endl;
	cout << "Image Size: " << bmpHeader.imageSize << endl;
	cout << "X Pixels Per M: " << bmpHeader.xPixels << endl;
	cout << "Y Pixels Per M: " << bmpHeader.yPixels << endl;
	cout << "Colors Used: " << bmpHeader.totalColors << endl;
	cout << "Colors Important: " << bmpHeader.importantColors << endl;
	cout << "********************* C O L O R  P A L L E T E ***********************" << endl;

	/*for (size_t i = 0; i < 500; i++)
	{
			cout << "B:" << bmpHeader.BLUE << "G: " << bmpHeader.GREEN << "R: " << bmpHeader.RED << endl;

	}*/

//diferencia entre economia de libre de mercado y economia planeada	

}

Headers::Headers()
{
	Init();
}

void Headers::setHeaderBuffer(const char* buffer)
{
	memcpy(bufferHeader, buffer, 14);
	unPack();
}
void Headers::setHeader_infoBuffer(const char* buffer) {
		memcpy(buffer_headerInfo, buffer, 40);
		unPack();
}

void Headers::setColorPallete_Buffer(char B, char G, char R, char padding) {
	char BGR_AUX[5];
	BGR_AUX[0] = B;
	BGR_AUX[1] = G;
	BGR_AUX[2] = R;
	BGR_AUX[4] = padding;

	//memcpy(BGR,BGR_AUX, 4);
	unPack();
}

void Headers::Init()
{
	//header variables
	signature[2] = '\0';
	fileSize = 0;
	Reserved_1 = 0;
	Reserved_2 = 0;
	dataOffset = 0;
	//header info variables
	headerSize = 0 ;
	imageWidth = 0 ;
	imageHeight = 0 ;
	planes = 0 ;
	bitsperPixel = 0 ;
	compression = 0 ;
	imageSize = 0 ;
	xPixels = 0 ;
	yPixels = 0 ;
	totalColors = 0 ;
	importantColors = 0 ;
	//colors 
	

}



void Headers::unPack() {
	char *c = bufferHeader;
	memcpy(&signature, c, 2);
	memcpy(&fileSize, c+=2, 4);
	memcpy(&Reserved_1, c+=4, 2);
	memcpy(&Reserved_2, c+=2, 2);
	memcpy(&dataOffset, c+=2, 4);
	//header Info
	char* d = buffer_headerInfo;
	memcpy(&headerSize, d, 4	);
	memcpy(&imageWidth, d += 4 , 4);
	memcpy(&imageHeight, d += 4, 4);
	memcpy(&planes, d += 4, 2);
	memcpy(&bitsperPixel, d += 2, 2);
	memcpy(&compression, d += 2, 4);
	memcpy(&imageSize, d += 4, 4);
	memcpy(&xPixels, d += 4, 4);
	memcpy(&yPixels, d += 4, 4);
	memcpy(&totalColors, d += 4, 4);
	memcpy(&importantColors, d += 4, 4);

	/*uint8_t *e = BGR;
	memcpy(&BLUE, e, 1);
	memcpy(&GREEN, e+=1, 1);
	memcpy(&RED, e+=1, 1);
	memcpy(&RESERVED, e+=1, 1);*/

	}

