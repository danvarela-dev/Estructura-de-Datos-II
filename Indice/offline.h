#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <string.h>
#include <list>



using namespace std;


class Registro {

public:
	Registro();
	void Pack();
	void unPack();

	char buffer[101];


	char Cedula[14];
	char Nombres[20];
	char Apellidos[20];
	char Direccion[20];
	char Ciudad[14];
	char Estado[7];
	char ZipCode[5];
};
class IndexFile;

class ArchivoTexto {
public:
	ArchivoTexto();

	void agregarRegistro();
	int buscar(string);
	void eliminar(string);
	void compactar();
	char buffer_aux[100];
	std::list<IndexFile> list;

private:
	Registro reg;

};

class IndexFile {
public:
	IndexFile() = default;
	ArchivoTexto arch;//para usar la list

	Registro reg;
	char indexBuff[50];

	char ID[14];
	int Offset;

	void indexPack();
	void indexUnPack();
	void createIndexFile();

	void loadList();

private:

};






#endif // !PROGRA8M_H
