#include "Zip.h"
#include <fstream>
#include <zip.h>

ZIP::ZIP() {
    Initialize();
}

void ZIP::Initialize() {
    signature[0] = 0;
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
    filename[0] = 0;
    extraField[0] = 0;

    eocd_signature[0] = 0;
    numberOf_thisDisk = 0;
    diskwhereCD = 0;
    numberofCD_onDisk = 0;
    total_numerofCD_onDisk = 0;
    sizeOf_CD = 0;
    offSetCD = 0;
    eocd_commentLength = 0;
    eocd_comment[0] = 0;

    CD_signature[0] = 0;
    CD_versionMade = 0;
    CD_versionNeeded = 0;
    CD_bitFlag = 0;
    CD_compression = 0;
    CD_lastMod_Time = 0;
    CD_lastMod_Date = 0;
    CD_CRC32 = 0;
    CD_compressed_size = 0;
    CD_uncompressed_size = 0;
    CD_fileName_Length = 0;
    CD_extraField_Length = 0;
    CD_fileComment_Length = 0;
    CD_diskStart = 0;
    CD_interalFileAttributes = 0;
    CD_externalFileAttributes = 0;
    CD_offsetLocalFileHeader = 0;
    CD_filename[0] = 0;
    CD_extraField[0] = 0;
    CD_fileComment[0] = 0;

}

void ZIP::unPack() {

    char* c = buff_localHeader;

    memcpy(&signature, c, 4);
    memcpy(&version, c += 4, 2);
    memcpy(&bitFlag, c += 2, 2);
    memcpy(&compression, c += 2, 2);
    memcpy(&lastMod_Date, c += 2, 2);
    memcpy(&lastMod_Time, c += 2, 2);
    memcpy(&CRC32, c += 2, 4);
    memcpy(&compressed_size, c += 4, 4);
    memcpy(&uncompressed_size, c += 4, 4);
    /*memcpy(&fileName_Length, c += 4, 2);
    memcpy(&extraField_Length, c += 2, 2);
    memcpy(&filename ,c += 2, fileName_Length);
    memcpy(&extraField, c += fileName_Length, extraField_Length);*/

    char* d = buff_eocd;
    memcpy(&eocd_signature, d, 4);
    memcpy(&numberOf_thisDisk, d += 4, 2);
    memcpy(&diskwhereCD, d += 2, 2);
    memcpy(&numberofCD_onDisk, d += 2, 2);
    memcpy(&total_numerofCD_onDisk, d += 2, 2);
    memcpy(&sizeOf_CD, d += 2, 4);
    memcpy(&offSetCD, d += 4, 4);
    memcpy(&eocd_commentLength, d += 4, 2);
    memcpy(&eocd_comment, d += 2, eocd_commentLength);

    char* e = buff_CD;
    memcpy(&CD_signature, e, 4);
    memcpy(&CD_versionMade, e += 4, 2);
    memcpy(&CD_versionNeeded, e += 2, 2);
    memcpy(&CD_bitFlag, e += 2, 2);
    memcpy(&CD_compression, e += 2, 2);
    memcpy(&CD_lastMod_Date, e += 2, 2);
    memcpy(&CD_lastMod_Time, e += 2, 2);
    memcpy(&CD_CRC32, e += 2, 4);
    memcpy(&CD_compressed_size, e += 4, 4);
    memcpy(&CD_uncompressed_size, e += 4, 4);
    memcpy(&CD_fileName_Length, e += 4, 2);
    memcpy(&CD_extraField_Length, e += 2, 2);
    memcpy(&CD_fileComment_Length, e += 2, 2);
    memcpy(&CD_diskStart, e += 2, 2);
    memcpy(&CD_interalFileAttributes, e += 2, 2);
    memcpy(&CD_externalFileAttributes, e += 2, 4);
    memcpy(&CD_offsetLocalFileHeader, e += 4, 4);
    //memcpy(&CD_filename, e += 4, CD_fileName_Length);
    //memcpy(&CD_extraField, e += CD_fileName_Length, CD_extraField_Length);
    //memcpy(&CD_fileComment, e += CD_extraField_Length, CD_fileComment_Length);

}

void ZIP::setBuffer(const char* buffer) {
    memcpy(buff_localHeader, buffer, strlen(buffer));
    unPack();

}

void ZIP::readEOCD() {
    zipFile.seekg(0, ios_base::end);
    int fileSize = zipFile.tellg();
    int offset = fileSize - 22;

    zipFile.seekg(offset, ios_base::beg);
    zipFile.read(buff_eocd, 22);

    unPack();
}

void ZIP::readCD() {
    zipFile.seekg(offSetCD + 28, ios_base::beg);

    char fileName_LengthStr[2];
    char extraField_LengthStr[2];


    zipFile.read(fileName_LengthStr, 2);
    zipFile.read(extraField_LengthStr, 2);


    memcpy(&CD_fileName_Length, fileName_LengthStr, 2);
    memcpy(&CD_extraField_Length, extraField_LengthStr, 2);

    zipFile.seekg(offSetCD + 46, ios_base::beg);

    zipFile.read(CD_filename, CD_fileName_Length);
    zipFile.read(CD_extraField, CD_extraField_Length);


    zipFile.seekg(offSetCD, ios_base::beg);

    zipFile.read(buff_CD, 46);
    unPack();

    pos = CD_offsetLocalFileHeader;

}


void ZIP::readLocalHeader() {

    zipFile.seekg(pos + 26, ios_base::beg);

    char fileName_LengthStr[2];
    char extraField_LengthStr[2];


    zipFile.read(fileName_LengthStr, 2);
    zipFile.read(extraField_LengthStr, 2);


    memcpy(&fileName_Length, fileName_LengthStr, 2);
    memcpy(&extraField_Length, extraField_LengthStr, 2);

    zipFile.read(filename, fileName_Length);
    zipFile.read(extraField, extraField_Length);

    /*filename[fileName_Length] = '\0';
    extraField[extraField_Length] = '\0';*/

    zipFile.seekg(pos, ios_base::beg);

    zipFile.read(buff_localHeader, 26);
    pos = zipFile.tellg();

    unPack();

//    compressedBuffer = new char[compressed_size + 1];
//    zipFile.read(compressedBuffer, compressed_size);
//    compressedBuffer[strlen(compressedBuffer)] = '\0';

}

void ZIP::print() {

    cout << "**EOCD**" << endl;
    cout << "EOCD Signature: " << eocd_signature[0] << eocd_signature[1] << (int)eocd_signature[2] << (int)eocd_signature[3] << endl;
    cout << "Number of this disk: " << numberOf_thisDisk << endl;
    cout << "Disk where central directory starts: " << diskwhereCD << endl;
    cout << "Number of central directory records on this disk: " << numberofCD_onDisk << endl;
    cout << "Total number of central directory records: " << total_numerofCD_onDisk << endl;
    cout << "Size of central directory (bytes): " << sizeOf_CD << endl;
    cout << "Offset of start of central directory, relative to start of archive: " << offSetCD << endl;
    cout << " Comment length (n) " << eocd_commentLength << endl << endl;


    cout << "** CENTRAL DIRECTORY HEADER ** " << endl << endl;
    cout << "Signature" << CD_signature[0] << CD_signature[1] << (int)CD_signature[2] << (int)CD_signature[3] << endl;
    cout << "Version made by : " << CD_versionMade << endl;
    cout << "Version needed to extract (minimum): " << CD_versionNeeded << endl;
    cout << "General purpose bit flag: " << CD_bitFlag << endl;
    cout << "Compression method: " << CD_compression << endl;
    cout << "File last modification time: " << CD_lastMod_Time << endl;
    cout << "File last modification date: " << CD_lastMod_Date << endl;
    cout << "CRC-32: " << CD_CRC32 << endl;
    cout << "Compressed size: " << CD_compressed_size << endl;
    cout << "Unompressed size: " << CD_uncompressed_size << endl;
    cout << "File name length (n): " << CD_fileName_Length << endl;
    cout << "Extra field length (m): " << CD_extraField_Length << endl;
    cout << "File comment length : " << CD_fileComment_Length << endl;
    cout << "Disk number where file starts: " << CD_diskStart << endl;
    cout << "Internal file attributes: " << CD_interalFileAttributes << endl;
    cout << "External file attributes: " << CD_externalFileAttributes << endl;
    cout << "Relative offset of local file header: " << CD_offsetLocalFileHeader << endl;
    cout << "Filename: " << CD_filename << endl;
    cout << "Extrafield Comment: " << CD_fileComment << endl << endl;


    //CD_filename
    //CD_extraField
    //CD_fileComment

    cout << "** local file header **" << endl;
    cout << "signature: " << signature[0] << signature[1] << (int)signature[2] << (int)signature[3] << endl;
    cout << "version: " << version << endl;
    cout << "bit flag: " << bitFlag << endl;
    cout << "compression: " << compression << endl;
    cout << "last modification time: " << lastMod_Time << endl;
    cout << "last modification date: " << lastMod_Date << endl;
    cout << "crc-32: " << CRC32 << endl;
    cout << "compressed size: " << compressed_size << endl;
    cout << "uncompressed size: " << uncompressed_size << endl;
    cout << "file name length: " << fileName_Length << endl;
    cout << "extra field length: " << extraField_Length << endl;
    cout << "filename: " << filename << endl;
      cout << "extra field: " << extraField << endl;
//    cout << "Compressed Data: [ " << compressedBuffer <<" ]" << endl;

}

void ZIP::openZip(string filename) {
       zipFile.open(filename, ifstream::in| ifstream::binary);

    readEOCD();
    readCD();


        readLocalHeader();
        print();

    zipFile.close();
}



int ZIP::getEOCD_offset() {



    return 0;
}
