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

class ArchivoTexto {
public:
	ArchivoTexto();

	//agrega registro a archivo
	void agregarRegistro();
	int buscar(string);
	void eliminar(string);
	void compactar();//compacta el archivo de registros y tambien el de indices
	char buffer_aux[100];
	
private:
	Registro reg;

};

class IndexFile {
public:
	IndexFile() {}

	Registro reg;
	char indexBuff[50];

	char ID[14];
	int Offset;

	//empaqueta variables de clase
	void indexPack();
	//desempaqueta variables de buffer leido de archivo
	void indexUnPack();
	//crea un archivo usando como llave primaria cedula
	// y el offset, este se crea secuecialmente, no necesita ser ordenado
	void createIndexFile();

	//carga archivo de indices a lista
	list<IndexFile> getList();
	//escribe a archivo lista recibida de parametro
	void setList(list<IndexFile>);

};






#endif // !PROGRAM_H
