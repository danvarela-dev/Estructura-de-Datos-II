#include "Empleado.h"

Empleado::Empleado()
{
	Nombres[0] = 0;
	Apellidos[0] = 0;
	Cedula[0] = 0;
	Edad = 0;
	Sueldo = 0;

}

void Empleado::print() {

	cout << Nombres << "  "
		<< Apellidos << " "
		<< Cedula << "  "
		/*<< Sueldo << "  "*/
		<< Edad << endl
		<< flush;
}


void Empleado::unPack()
{
	int size = 0;
	char* c = in_buffer;
	
	memcpy((char*)&size, c, 1);
	memcpy(Nombres, c += 1, size);
	Nombres[size] = 0;

	memcpy((char*)&size, c += size, 1);
	memcpy(Apellidos, c += 1, size);
	Apellidos[size] = 0;

	memcpy(Cedula, c += 1, 13);

	//memcpy(&Sueldo, c += 13, 8);
	memcpy(&Edad, c += 13, 4);

}

void Empleado::readAll()
{
	file_hData.open("Empleados.bin", fstream::in, fstream::binary);
	if (!file_hData)
	{
		cerr << "Error opening file...\n";
		return;
	}

	uint16_t sizeReg = 0;
	

	while (!file_hData.eof())
	{
		file_hData.read((char*)&sizeReg, 2);
		file_hData.read((char*)&in_buffer, sizeReg);
		unPack();
		print();

	}

}

void Empleado::writeAll()
{
	file_hData.open("Empleados.bin", ios::out | ios::app | ios::binary);

	if (!file_hData)
	{
		cerr << "Error writing file...";
		return;
	}

	cout << "Nombres : " << flush; cin.getline(Nombres, 99);
	cout << "Apellidos : " << flush; cin.getline(Apellidos, 99);
	cout << "Cedula : " << flush; cin.getline(Cedula, 14);
	//cout << "Sueldo : " << flush; cin >> Sueldo;
	cout << "Edad : " << flush; cin >> Edad;

	Pack();

	
}

void Empleado::Pack()
{
	int fieldSize = 0;
	

	fieldSize = strlen(Nombres);
	strcpy(in_buffer, (char*)&fieldSize);
	strcat(in_buffer, Nombres);
	
	fieldSize = strlen(Apellidos);
	strcat(in_buffer, (char*)&fieldSize);
	strcat(in_buffer, Apellidos);

	
	strcat(in_buffer, (char*)&Sueldo);
	strcat(in_buffer, (char*)&Edad);

	regSize = strlen(in_buffer);

	file_hData.write((char*)&regSize, 2);
	file_hData.write((char*)&in_buffer, regSize);

	file_hData.close();

}
