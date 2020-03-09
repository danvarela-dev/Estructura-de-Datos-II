#include "program.h"
#include <string>
#include <string.h>
#include <bitset>
#include <sstream>

using namespace std;
#pragma warning(disable : 4996)


MyBitmap::MyBitmap() {

}

uint8_t MyBitmap::bitToggle(int num, int pos) {

	if (pos <= 0)
		return num;

	return (num ^ (1 << (pos - 1)));
}

bool MyBitmap::isBitOn(int n, int k) {

	int new_num = n >> (k - 1);

	return (new_num & 1);
}

void MyBitmap::setBufferinBinary(string buffer) {

	string binaryString = "";
	for (char& _char : buffer) {
		binaryString += bitset<8>(_char).to_string();
	}

	bufferBin = binaryString.c_str();
}

string MyBitmap::bintoString(string buffer) {
	string binStr = " ";
	//necesito convertir el buffer binario a bitset
	stringstream sstream(buffer);
	while (sstream.good())
	{
		bitset<8> bits;
		sstream >> bits;
		binStr += char(bits.to_ulong());
	}

	return binStr;
}


void MyBitmap::msgEncryptor(string filename, string msg) {

	string array = "\\Users\\Danie\\Documents\\build-BMP_Viewer_2-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\";


	file_bmp.open(filename, ios::in | ios::out | ios::binary);


	if (!file_bmp) {

		cerr << "Error while opening files...\n";
		return;
	}


	readHeaders();

	string signature = bmpHeader.signature;

	if (signature != "BM") {
		cout << "Formato Invalido!";
		return;
	}
	else if (msg.size() > (bmpHeader.imageWidth * bmpHeader.imageHeight) / 3) {
		cout << "El mensaje es muy grande para el archivo...\n";
		return;
	}
	else if (bmpHeader.bitsperPixel != 24) {
		cout << "Solo soporta archivos de 24 bits...\n";
		return;
	}
	/*else if (bmpHeader.Reserved_1 != 0) {
		cout << "La imagen ya contiene un mensaje...\n";
		return;
	}*/
	else {
		cout << "Imagen valida | Encriptacion en proceso...\n";
	}


	setBufferinBinary(msg);
	hideMsg_inPixels();
	file_bmp.close();

	cout << "Imagen encriptada exitosamente!" << endl;

}

void MyBitmap::msgDecryptor(string filename)
{
	string array = "\\Users\\Danie\\Documents\\build-BMP_Viewer_2-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\";


	file_bmp.open(filename, ios::in | ios::out | ios::binary);


	if (!file_bmp) {

		cerr << "Error while opening files...\n";
		return;
	}


	readHeaders();
	if (bmpHeader.Reserved_1 == 0) {
		cout << "No existe mensaje oculto..." << endl;
		return;
	}
	else {
		cout << "Existe mensaje oculto" << endl;
	}

	string signature = bmpHeader.signature;
	if (signature != "BM") {
		cout << "Formato Invalido!";
		return;
	}
	else if (bmpHeader.bitsperPixel != 24) {
		cout << "Solo soporta archivos de 24 bits...\n";
		return;
	}
	else {
		cout << "Imagen valida | Decodificacion en proceso...\n";

	}



	getHiddenMsg();
	file_bmp.close();


}

void MyBitmap::msgEncryptorFile(string filename, string fileSrc)
{

	ifstream file;
	file.open(fileSrc, ios::in);
	string buffer;
	string line;
	

	while (getline(file, line))
	{
		
		buffer += line;
		buffer += "\n";
	}

	file.close();



	msgEncryptor(filename, buffer);
	cout << endl << "Saved succesfully into " << filename << "...";

}

void MyBitmap::msgDecryptor2File(string filename, string filedest)
{
	msgDecryptor(filename);

	ofstream file;
	file.open(filedest, ios::trunc);
	
	file << bufferASCII;

	file.close();

}

int MyBitmap::getMaxSpace(string filename)
{
	string array = "\\Users\\Danie\\Documents\\build-BMP_Viewer_2-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\";


	file_bmp.open(filename, ios::in | ios::binary);
	if (!file_bmp) {

		cerr << "Error while opening file...\n";
		return 0;
	}

	readHeaders();

	return (bmpHeader.imageWidth * bmpHeader.imageHeight) / 3;

}

void MyBitmap::validation(string filename)
{
	string array = "\\Users\\Danie\\Documents\\build-BMP_Viewer_2-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\";


	file_bmp.open(filename, ios::in | ios::binary);
	if (!file_bmp) {

		cerr << "Error while opening file...\n";
		return;
	}

	readHeaders();
	if (bmpHeader.Reserved_1 != 0)
	{
		cout << "100: Imagen no valida para ocultar el mensaje\n101: Imagen ya contiene un mensaje de " << bmpHeader.Reserved_1 / 8 << " caracteres..." << endl;
	}
	else {
		cout << "Valida: Imagen valida para guardar mensaje!" << endl;

	}

}

void MyBitmap::getHiddenMsg() {

	string bufferString;
	int height = bmpHeader.imageHeight;
	int width = bmpHeader.imageWidth;
	int bitsxPixel = bmpHeader.bitsperPixel;

	int Index = 0;

	int bufferSize = bmpHeader.Reserved_1;
	vector<uint8_t> pixelData;


	//  int pixelDimensions = width * height;
	int padding = ((4 - (width * 3) % 4) % 4);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			file_bmp.read((char*)&BLUE_aux, 1);
			file_bmp.read((char*)&GREEN_aux, 1);
			file_bmp.read((char*)&RED_aux, 1);

			pixelData.push_back(BLUE_aux);
			pixelData.push_back(GREEN_aux);
			pixelData.push_back(RED_aux);



			if (padding != 0) { //si el width no es multiplo de 4
				file_bmp.read((char*)&RESERVED4PADDING_aux, 1);
				pixelData.push_back(RESERVED4PADDING_aux);

			}
		}
	}
	string buff;
	for (size_t i = 0; i < bufferSize; i++)
	{
		if (isBitOn(pixelData[i], 1))
		{
			buff += "1";
		}
		else
		{
			buff += "0";
		}
	}


	bufferASCII = bintoString(buff);
	cout << bufferASCII;

}


void MyBitmap::readHeaders() {
	file_bmp.seekg(0, ios_base::beg);

	file_bmp.read(bufferHeader_aux, sizeof(bufferHeader_aux));
	file_bmp.read(buffer_headerInfo_aux, sizeof(buffer_headerInfo_aux));

	bmpHeader.setHeaderBuffer(bufferHeader_aux);
	bmpHeader.setHeader_infoBuffer(buffer_headerInfo_aux);

}

void MyBitmap::readPixels() {

	int height = bmpHeader.imageHeight;
	int width = bmpHeader.imageWidth;
	int bitsxPixel = bmpHeader.bitsperPixel;

	int Index = 0;

	//  int pixelDimensions = width * height;
	int padding = ((4 - (width * 3) % 4) % 4);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			file_bmp.read((char*)&BLUE_aux, 1);
			file_bmp.read((char*)&GREEN_aux, 1);
			file_bmp.read((char*)&RED_aux, 1);

			if (padding != 0) //si el width no es multiplo de 4
				file_bmp.read((char*)&RESERVED4PADDING_aux, 1);

			//cout << "B:" << (int)BLUE_aux << "\tG: " << (int)GREEN_aux << "\tR: " << (int)RED_aux << /*"\tReserved: " << (int)RESERVED4PADDING_aux <<*/ endl;
		}
	}

}

void MyBitmap::hideMsg_inPixels() {

	int height = bmpHeader.imageHeight;
	int width = bmpHeader.imageWidth;
	int bitsxPixel = bmpHeader.bitsperPixel;

	uint8_t encryptedBlue, encryptedGreen, encryptedRed = 0;
	vector<uint8_t> pixelData;

	int Index = 0;

	int padding = ((4 - (width * 3) % 4) % 4);
	//meter todos los valores modificados a un arreglo y despues escribirlos a partir del offset de los pixeles
	int offset = file_bmp.tellg();

	file_bmp.seekg(6, ios::beg);
	uint16_t bufferSize = strlen(bufferBin.c_str());

	file_bmp.write((char*)&bufferSize, 2);

	file_bmp.seekg(54, ios::beg);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			file_bmp.read((char*)&BLUE_aux, 1);
			pixelData.push_back(BLUE_aux);

			file_bmp.read((char*)&GREEN_aux, 1);
			pixelData.push_back(GREEN_aux);

			file_bmp.read((char*)&RED_aux, 1);
			pixelData.push_back(RED_aux);

			if (padding != 0) { //si el width no es multiplo de 4
				file_bmp.read((char*)&RESERVED4PADDING_aux, 1);

			}
		}
	}
	int sizeBuffer = strlen(bufferBin.c_str());

	for (size_t i = 0; i < sizeBuffer; i++)
	{
		if (bufferBin[i] == '0' && isBitOn(pixelData[i], 1) || bufferBin[i] == '1' && !isBitOn(pixelData[i], 1))
		{
			pixelData[i] = bitToggle(pixelData[i], 1);
		}
	}

	file_bmp.seekg(offset, ios::beg);

	int padSkip = 0;

	for (size_t i = 0; i < strlen(bufferBin.c_str()); i++)
	{

		file_bmp.write((char*)&pixelData[i], 1);
	}

}




void MyBitmap::openBMP(const char* filename)
{


	string array = "\\Users\\Danie\\Documents\\build-BMP_Viewer_2-Desktop_Qt_5_14_1_MinGW_32_bit-Debug\\";


	file_bmp.open(filename, ios::in | ios::binary);
	if (!file_bmp) {

		cerr << "Error while opening file...\n";
		return;
	}

	readHeaders();
	print_metaData();
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



void Headers::Init()
{
	//header variables
	signature[2] = '\0';
	fileSize = 0;
	Reserved_1 = 0;
	Reserved_2 = 0;
	dataOffset = 0;
	//header info variables
	headerSize = 0;
	imageWidth = 0;
	imageHeight = 0;
	planes = 0;
	bitsperPixel = 0;
	compression = 0;
	imageSize = 0;
	xPixels = 0;
	yPixels = 0;
	totalColors = 0;
	importantColors = 0;
}

void Headers::unPack() {
	char* c = bufferHeader;
	memcpy(&signature, c, 2);
	memcpy(&fileSize, c += 2, 4);
	memcpy(&Reserved_1, c += 4, 2);
	memcpy(&Reserved_2, c += 2, 2);
	memcpy(&dataOffset, c += 2, 4);
	//header Info
	char* d = buffer_headerInfo;
	memcpy(&headerSize, d, 4);
	memcpy(&imageWidth, d += 4, 4);
	memcpy(&imageHeight, d += 4, 4);
	memcpy(&planes, d += 4, 2);
	memcpy(&bitsperPixel, d += 2, 2);
	memcpy(&compression, d += 2, 4);
	memcpy(&imageSize, d += 4, 4);
	memcpy(&xPixels, d += 4, 4);
	memcpy(&yPixels, d += 4, 4);
	memcpy(&totalColors, d += 4, 4);
	memcpy(&importantColors, d += 4, 4);
}

