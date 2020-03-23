#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <string.h>



using namespace std;


class Registro {

public:
	Registro();
	void Pack();
	void unPack();

	char buffer[64];


	char Nombres[16];
	char Apellidos[16];
	char Direccion[16];
	char Ciudad[8];
	char Estado[3];
	char ZipCode[5];
};


class ArchivoTexto{
public:
	ArchivoTexto() = default;

	void agregarRegistro();
	int buscar(string);
	void eliminar(string);
	void compactar();
	char buffer_aux[64];

private: 
	Registro reg;

};

#endif // !PROGRA8M_H
