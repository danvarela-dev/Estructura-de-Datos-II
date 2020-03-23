#ifndef ZIP_H
#define ZIP_H
#include "inttypes.h"
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

class Headers {
private:
    char localFile[30];

    void unPack();
    void Init();


public:
    char signature[5];
    uint16_t version;
    uint16_t bitFlag;
    uint16_t compression;
    uint16_t lastMod_Time;
    uint16_t lastMod_Date;
    int CRC32;
    int compressed_size;
    int uncompressed_size;
    uint16_t fileName_Length;
    uint16_t extraField_Length;


    void setBuffer(const char *);


};


class Zip {

private:
    char* fileName;
    char buffer_localFile[30];
    string generalBuffer;

    ifstream zip_file;

    Headers zipHeader;


    void readLocalHeader();

public:
    Zip();
    void openZip(string);
    void print();
    

};

#endif // ZIP_H
