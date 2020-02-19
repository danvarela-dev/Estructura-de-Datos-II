#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>

#define MAX_BUFFER 6*99


using namespace std;

struct registro {

	char LastName[99] = { 0 };
	char FirstName[99] = { 0 };
	int Age = 0;
	char Gender = 0;
	char Address[99] = { 0 };
	char City[99] = { 0 };
	char State[99] = { 0 };
	char ZipCode[99] = { 0 };

};





class Persona {
private:

	fstream file_hData;
	void Pack();
	void UnPack();
	void GetSizeStr(int, char*);
	registro regHumano;
public:




	uint16_t SIZE;
	char in_buffer[MAX_BUFFER];

	char LastName[99];
	char FirstName[99];
	int Age;
	char Gender;
	char Address[99];
	char City[99];
	char State[99];
	char ZipCode[99];

	Persona();
	void Print();
	void SetBuffer(const char*);
	void writeFile();
	void readFile();


};
