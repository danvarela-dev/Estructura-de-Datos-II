#include "offline.h"
#include <fstream>

#pragma warning (disable : 4996)

Registro::Registro() {

	buffer[0] = 0;

	Cedula[0] = 0;
	Nombres[0] = 0;
	Apellidos[0] = 0;
	Direccion[0] = 0;
	Ciudad[0] = 0;
	Estado[0] = 0;
	ZipCode[0] = 0;
}

void Registro::Pack() {

	if (buffer[0] != 0)
		buffer[0] = 0;

	strcat(buffer, Cedula);
	strcat(buffer, "|");
	strcat(buffer, Nombres);
	strcat(buffer, "|");
	strcat(buffer, Apellidos);
	strcat(buffer, "|");
	strcat(buffer, Direccion);
	strcat(buffer, "|");
	strcat(buffer, Ciudad);
	strcat(buffer, "|");
	strcat(buffer, Estado);
	strcat(buffer, "|");
	strcat(buffer, ZipCode);
	strcat(buffer, "|");

}

void Registro::unPack() {

	char* c = buffer;
	char temp[30];
	int i = 0, j = 0;

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Cedula, temp);


	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Nombres, temp);

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Apellidos, temp);

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Direccion, temp);
	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Ciudad, temp);

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(Estado, temp);

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	i++;
	strcpy(ZipCode, temp);

}

ArchivoTexto::ArchivoTexto() {}

void ArchivoTexto::agregarRegistro() {
	ofstream file;

	file.open("Registros.txt", ofstream::out | ofstream::app);

	if (!file) {
		cout << "Error abriendo archivo: " << endl;
		return;
	}

	cout << "REGISTRO" << endl;
	cout << "Ingrese Cedula:";
	cin.getline(reg.Cedula, 14);
	cout << "Ingrese nombres: ";
	cin.getline(reg.Nombres, 20);
	cout << "Ingrese Apellidos: ";
	cin.getline(reg.Apellidos, 20);
	cout << "Ingrese Direccion: ";
	cin.getline(reg.Direccion, 20);
	cout << "Ingrese Ciudad: ";
	cin.getline(reg.Ciudad, 15);
	cout << "Ingrese Estado: ";
	cin.getline(reg.Estado, 7);
	cout << "Ingrese Zip Code: ";
	cin.getline(reg.ZipCode, 6);
	cout << endl;
	reg.Pack();

	int len = strlen(reg.buffer);

	for (size_t i = len; i < 101; i++)
	{
		reg.buffer[i] = ' ';
	}


	file.write(reg.buffer, 100);

	file.close();

}

int ArchivoTexto::buscar(string nombre) {

	ifstream file;

	file.open("Registros.txt", ifstream::in);

	if (!file) {
		cout << "Error abriendo archivo: " << endl;
		return -1;
	}
	int curPointer = 0;

	while (!file.eof())
	{
		curPointer = file.tellg();
		file.read(reg.buffer, 100);

		reg.unPack();
		if (nombre == reg.Nombres) {
			cout << "Cedula: " << reg.Cedula << endl;
			cout << "Nombres: " << reg.Nombres << endl;
			cout << "Apellidos: " << reg.Apellidos << endl;
			cout << "Direccion: " << reg.Direccion << endl;
			cout << "Ciudad: " << reg.Ciudad << endl;
			cout << "Estado: " << reg.Estado << endl;
			cout << "Zip Code: " << reg.ZipCode << endl;


			return curPointer;
		}
	}
	file.close();
	return -1;
}

void ArchivoTexto::eliminar(string nombre) {

	int offsetToMark = buscar(nombre);
	char mark = '*';
	ofstream file;
	file.open("Registros.txt", ofstream::cur);
	file.seekp(offsetToMark, ios::cur);

	file << "*";

	if (offsetToMark == -1) 
		cout << "Registro no encontrado..." << endl;
	else
		cout << "Registro Eliminado..." << endl;
	

	file.close();
	 
}

void ArchivoTexto::compactar() {
	ifstream i_file;
	ofstream o_file;
	int curPointer = 0;


	i_file.open("Registros.txt", ifstream::in);
	o_file.open("Registros-Compacted.txt", ofstream::out | ios::trunc);


	i_file.seekg(0, ios::end);
	int filesize = i_file.tellg();
	i_file.seekg(0, ios::beg);


	while (!i_file.eof())
	{

		i_file.seekg(curPointer, ios::beg);
		i_file.read(buffer_aux, 100);
		buffer_aux[99] = '\0';
		strcpy(reg.buffer, buffer_aux);
		reg.unPack();

		if (reg.Nombres[0] != '*' && curPointer < filesize) {
			o_file << buffer_aux;
		}

		curPointer += 100;
	}

	i_file.close();
	o_file.close();

}

void IndexFile::createIndexFile()
{
	ifstream iFile;
	ofstream oFile;

	iFile.open("Registros.txt", ifstream::in);
	oFile.open("Index.dat", ifstream::out);

	char buff[50];

	int offset = 0;

	while (!iFile.eof())
	{
		offset = iFile.tellg();
		iFile.read(reg.buffer, 100);
		reg.unPack();

		strcpy(ID, reg.Cedula);
		Offset = offset;
		indexPack();
		
		if (indexBuff[0] != '*') {
			oFile.write(indexBuff, 50);
		}
	}

	iFile.close();
	oFile.close();
	createIndexFile();//crea el archivo basado en registros.txt y se omiten los registros borrados
}


void IndexFile::indexPack()
{
	char offsetStr[10];
	offsetStr[0] = 0;
	strcat(indexBuff, ID);
	strcat(indexBuff, "|");
	sprintf(offsetStr, "%d", Offset);
	offsetStr[strlen(offsetStr)] = '\0';
	strcat(indexBuff, offsetStr);
	strcat(indexBuff, "|");

	for (size_t i = strlen(indexBuff); i < 50; i++)
		indexBuff[i] = ' ';

	indexBuff[strlen(indexBuff)] = '\0';

}

void IndexFile::indexUnPack() {
	char* c = indexBuff;
	char temp[15];
	char offsetStr[15];

	int i = 0, j = 0;

	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	strcpy(ID, temp);


	while (c[i] != '|')
	{
		temp[j++] = c[i++];
	}
	temp[j] = '\0';
	j = 0;
	strcpy(offsetStr, temp);
	int offset_ = atoi(offsetStr);

	Offset = offset_;

}

void IndexFile::loadList() {
	
	ifstream file;
	IndexFile index;
	file.open("Index.dat", ios::in);

	while (!file.eof())
	{
		file.read(indexBuff, 50);
		indexUnPack();
		strcpy(index.ID, ID);
		index.Offset = Offset;
		
		arch.list.push_back(index);

	}

	for (auto it = arch.list.begin(); it != arch.list.end(); it++)
	{
		cout << it->ID << "|" << (int)it->Offset << endl;
	}


}