#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class ZIP
{
public:
	ZIP();

	void openZip(string);
	void print();
	void setBuffer(const char*);

	//End of central directory record
	char eocd_signature[4];
	uint16_t numberOf_thisDisk;
	uint16_t diskwhereCD;
	uint16_t numberofCD_onDisk;
	uint16_t total_numerofCD_onDisk;
	uint32_t sizeOf_CD;
	uint32_t offSetCD;
	uint32_t eocd_commentLength;
	char eocd_comment[99];
	// Central directory

	char CD_signature[4];
	uint16_t CD_versionMade;
	uint16_t CD_versionNeeded;
	uint16_t CD_bitFlag;
	uint16_t CD_compression;
	uint16_t CD_lastMod_Time;
	uint16_t CD_lastMod_Date;
	uint32_t CD_CRC32;
	uint32_t CD_compressed_size;
	uint32_t CD_uncompressed_size;
	uint16_t CD_fileName_Length;
	uint16_t CD_extraField_Length;
	uint16_t CD_fileComment_Length;
	uint16_t CD_diskStart;
	uint16_t CD_interalFileAttributes;
	uint32_t CD_externalFileAttributes;
	uint32_t CD_offsetLocalFileHeader;
	char CD_filename[99];
	char CD_extraField[99];
	char CD_fileComment[99];


	//local file header
	char signature[4];
	uint16_t version;
	uint16_t bitFlag;
	uint16_t compression;
	uint16_t lastMod_Time;
	uint16_t lastMod_Date;
	uint32_t CRC32;
	uint32_t compressed_size;
	uint32_t uncompressed_size;
	uint16_t fileName_Length;
	uint16_t extraField_Length;
	char filename[99];
	char extraField[99];



private:
	char buff_localHeader[26];
	char buff_eocd[22];
	char buff_CD[46];

	ifstream zipFile;


	void readLocalHeader();
	void readCD();
	void readEOCD();
	int getEOCD_offset();

	void Initialize();
	void unPack();
};

