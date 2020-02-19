#include "Persona.h"

Persona::Persona() 
{
	Nombres[0] = 0;
	Apellidos[0] = 0;
	Direccion[0] = 0;
	Edad[0] = 0;
	Genero = 0;

}

void Persona::Pack() 
{

	strcpy(in_buffer, "Nombres = ");
	strcat(in_buffer, Nombres);
	strcat(in_buffer, ",");
	strcpy(in_buffer, "Apellidos = ");
	strcat(in_buffer, Apellidos);
	strcat(in_buffer, ",");
	strcpy(in_buffer, "Direccion = ");
	strcat(in_buffer, Direccion);
	strcat(in_buffer, ",");
	strcpy(in_buffer, "Edad = ");
	strcat(in_buffer, Edad);
	strcat(in_buffer, ",");
	strcpy(in_buffer, "Genero = ");
	strcat(in_buffer,(char *)Genero);
	strcat(in_buffer, "\r\n");


	filePersona.write((char*)in_buffer, sizeof(in_buffer));
	filePersona.close();

}
void Persona::unPack() 
{
	

}
void Persona::readAll() 
{
	filePersona.open("Personas.bin", fstream::in, fstream::binary);
	if (!filePersona)
	{
		cerr << "Error al abrir el archivo...";
		return;
	}
	string s;

	while (!filePersona.eof())
	{
		file_hData.read((char*)&sizeReg, 2);
		file_hData.read((char*)&in_buffer, sizeReg);
		UnPack();
		Print();

	}


}

void Persona::writeAll() {
	filePersona.open("Personas.bin", ios::out | ios::app | ios::binary);

	if (!filePersona)
	{
		cerr << "Error writing file...";
		return;
	}



	cout << "Nombre : " << flush; cin.getline(Nombres, 99);
	cout << "Apellido : " << flush; cin.getline(Apellidos, 99);
	cout << "Direccion : " << flush; cin.getline(Direccion, 255);
	cout << "Edad : " << flush; cin.getline(Edad, 3);
	cout << "Genero : { M | F }" << flush; cin >> Genero;

	Pack();

}