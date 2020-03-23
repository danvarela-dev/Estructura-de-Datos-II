#include <limits>
#include <fstream>
#include <inttypes.h>
#include <time.h>
#include "Empleado.h"
#pragma warning( disable : 4996)

using namespace std;
void generateIndexFile() {

	char buffer[MAX_BUFFER];
	char s[2];
	uint16_t r_size;
	Empleado p;
	ifstream f;
	ofstream g;
	uint16_t reg_offset;
	uint16_t fieldSize;


	f.open("empleado.txt");
	g.open("Index.bin", ios::binary | ios::trunc);
	while (1)
	{
		reg_offset = f.tellg();
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);
		if (f.eof()) break;
		p.SetBuffer(buffer, r_size);



		g.write((char*)&reg_offset, sizeof(reg_offset));
		fieldSize = strlen(p.Nombres);

		g.write((char*)&fieldSize, sizeof(fieldSize));
		g.write(p.Nombres, strlen(p.Nombres));

		fieldSize = strlen(p.Apellidos);
		g.write((char*)&fieldSize, sizeof(fieldSize));
		g.write(p.Apellidos, strlen(p.Apellidos));

	}
	f.close();
	g.close();

}
void ReadAll() {
	char buffer[MAX_BUFFER];
	char s[2];
	uint16_t r_size;
	Empleado p;
	ifstream f;
	cout << "Nombres  Apellidos  Cedula Sueldo Edad" << endl;

	f.open("empleado.txt");
	while (1)
	{
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);
		if (f.eof()) break;

		p.SetBuffer(buffer, r_size);
		p.Print();
	}
	f.close();
}
Empleado getEmpleadoByName(string name) {
	char buffer[MAX_BUFFER];
	char s[2];
	uint16_t r_size;
	Empleado p;
	ifstream f;


	f.open("empleado.txt");
	while (1)
	{
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);
		if (f.eof()) break;

		p.SetBuffer(buffer, r_size);

		if (name == p.Nombres) {
			return p;
		}
	}
	f.close();

	return p;
}

int WriteAll() {
	char c[100];
	c[0] = 0;
	Empleado p;

	ofstream f;
	f.open("empleado.txt", ios::binary | ios::app);
	while (1)
	{
		p.Write();
		f.seekp(0, ios::end);
		f.write(p.BUFFER_REG, p.SIZE);

		cout << "Desea Continuar? (S/N): " << flush; cin.getline(c, 100);
		if (strcmp(c, "N") == 0) break;
	}
	f.close();
	generateIndexFile();
	return 1;
}


void generate_erasedIndex() {
	char buffer[MAX_BUFFER];
	char s[2];
	uint16_t r_size;
	Empleado p;
	ifstream f;
	ofstream g;
	uint16_t reg_offset;
	uint16_t fieldSize;


	f.open("empleado.txt");
	g.open("erasedIndex.txt", ios::binary | ios::trunc);
	while (1)
	{
		reg_offset = f.tellg();
		f.read(s, 2);
		memcpy(&r_size, s, 2);
		f.read(buffer, r_size);
		if (f.eof()) break;
		p.SetBuffer(buffer, r_size);


		g.write((char*)&reg_offset, sizeof(reg_offset));
		fieldSize = strlen(p.Nombres);

		g.write((char*)&fieldSize, sizeof(fieldSize));
		g.write(p.Nombres, strlen(p.Nombres));

		fieldSize = strlen(p.Apellidos);
		g.write((char*)&fieldSize, sizeof(fieldSize));
		g.write(p.Apellidos, strlen(p.Apellidos));

	}
	f.close();
	g.close();

}


int getOffset(string name) {
		char buffer[MAX_BUFFER];
		char offset[2];
		char fieldSize[2];
		uint16_t offset_int;
		uint16_t fieldSize_int;
		Empleado p;
		ifstream f;
		bool found = 0;

		f.open("Index.bin");
		while (1)
		{
			f.read(offset, sizeof(offset));
			memcpy(&offset_int, offset, sizeof(fieldSize));

			f.read(fieldSize, sizeof(fieldSize));
			memcpy(&fieldSize_int, fieldSize, sizeof(fieldSize));
			buffer[0] = 0;
			
			f.read(buffer, fieldSize_int);

			buffer[fieldSize_int] = '\0'; 
			if (buffer == name) {
				found = 1;
			}

			f.read(fieldSize, sizeof(fieldSize));
			memcpy(&fieldSize_int, fieldSize, sizeof(fieldSize));
			f.read(buffer, fieldSize_int);

			if (found) return offset_int;

			if (f.eof()) break;

		}
		f.close();

		return 0;
}

void eraseReg(string name) {

	int offset = getOffset(name);

	ofstream oF;
	char a;
	a = '\0';
	
	oF.open("empleado.txt");
	oF.seekp(offset, ios::beg);
	oF.write((char*)&a, 2);
	
	oF.close();
}


void searchUsingOffset(string name) {
	
	Empleado p;
	ifstream f;
	char buffer[99];
	char s[2];
	uint16_t r_size;

	f.open("empleado.txt");


	f.seekg(getOffset(name));

	f.read(s, 2);
	memcpy(&r_size, s, 2);
	f.read(buffer, r_size);

	p.SetBuffer(buffer, r_size);
	p.Print();
}

int main(int argc, char** argv) {

	eraseReg("Mario Rolando");

}


