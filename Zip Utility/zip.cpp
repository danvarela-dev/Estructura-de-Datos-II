#include "zip.h"

using namespace std;
#pragma warning(disable : 4996)
Headers::Headers() {
	Init();
}

void Headers::Init() {
	signature[4] = '\0';
	version = 0;
	bitFlag = 0;
	compression = 0;
	lastMod_Time = 0;
	lastMod_Date = 0;
	CRC32 = 0;
	compressed_size = 0;
	uncompressed_size = 0;
	fileName_Length = 0;
	extraField_Length = 0;
	
} 



void Headers::unPack() {
	char* c = localFile;
	memcpy(&signature, c, 4);
	memcpy(&version, c += 4, 4);
	memcpy(&bitFlag, c+=4, 2);
	memcpy(&compression, c += 2, 2);
	memcpy(&lastMod_Time, c += 2, 2);
	memcpy(&lastMod_Date, c += 2, 2);
	memcpy(&CRC32, c += 2, 4);
	memcpy(&compressed_size, c += 4, 4);
	memcpy(&uncompressed_size, c += 4, 4);
	memcpy(&fileName_Length, c += 4, 2);
	memcpy(&extraField_Length, c += 4, 2);
}

void Headers::setBuffer(const char* buffer) {
	memcpy(localFile, buffer, 30);
	unPack();

}

Zip::Zip() {}


void Zip::print() {
	

	cout << "Signature: " << zipHeader.signature << endl;
	generalBuffer += zipHeader.signature;
	generalBuffer += '\n';
	cout << "Version: " << zipHeader.version << endl;

	cout << "Bit Flag: " << zipHeader.bitFlag << endl;
	cout << "Compression: " << zipHeader.compression << endl;
	cout << "Last Modification Time: " << zipHeader.lastMod_Time << endl; 
	cout << "Last Modification Date: " << zipHeader.lastMod_Date << endl;
	cout << "CRC-32: " << zipHeader.CRC32 << endl;
	cout << "Compressed Size: " << zipHeader.compressed_size << endl;
	cout << "Uncompressed Size: " << zipHeader.uncompressed_size << endl;
	cout << "File Name Length: " << zipHeader.fileName_Length << endl;
	cout << "Extra Field Length: " << zipHeader.extraField_Length << endl;

}


void Zip::readLocalHeader() {
	zip_file.seekg(0, ios_base::beg);

	zip_file.read(buffer_localFile, sizeof(buffer_localFile));

	zipHeader.setBuffer(buffer_localFile);
	
	print();

}



void Zip::openZip(string filename) {
	zip_file.open(filename, ifstream::in, ifstream::binary);

	if (!zip_file) {
		cerr << "Error opening file..." << endl;
		return;
		}

	readLocalHeader();
	zip_file.close();

}



