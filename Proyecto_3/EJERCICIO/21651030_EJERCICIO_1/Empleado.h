#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;



class Empleado
{

private:

	fstream file_hData;

public:
	Empleado();

	uint16_t regSize;
	

	char in_buffer[226];


	char Nombres[100];
	char Apellidos[100];
	char Cedula[14];
	double Sueldo;
	int Edad;

	void Pack();
	void unPack();
	void readAll();
	void writeAll();
	void print();

};





#endif // !EMPLEADO_H
