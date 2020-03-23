#include "program.h"
#include <fstream>

#pragma warning (disable : 4996)

Registro::Registro() {
	buffer[0] = 0;
	Nombres[0] = 0;
	Apellidos[0] = 0;
	Direccion[0] = 0;
	Ciudad[0] = 0;
	Estado[0] = 0;
	ZipCode[0] = 0;
}

void Registro::Pack() {

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
	char temp[20];
	int i = 0, j = 0;
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



void ArchivoTexto::agregarRegistro() {
	ofstream file;

	file.open("Registros.txt", ofstream::out | ofstream::app);

	if (!file) {
		cout << "Error abriendo archivo: " << endl;
		return;
	}

	cout << "REGISTRO" << endl;
	cout << "Ingrese nombres: ";
	cin.getline(reg.Nombres, 16);
	cout << "Ingrese Apellidos: ";
	cin.getline(reg.Apellidos, 16);
	cout << "Ingrese Direccion: ";
	cin.getline(reg.Direccion, 16);
	cout << "Ingrese Ciudad: ";
	cin.getline(reg.Ciudad, 8);
	cout << "Ingrese Estado: ";
	cin.getline(reg.Estado, 3);
	cout << "Ingrese Zip Code: ";
	cin.getline(reg.ZipCode, 6);



	cout << endl;
	reg.Pack();

	int len = strlen(reg.buffer);
	for (size_t i = len ; i < 64; i++)
	{
		reg.buffer[i] = ' ';
	}

	file.write(reg.buffer, 64);

	file.close();

}

int ArchivoTexto::buscar(string nombre) {

	ifstream file;

	file.open("Registros.txt", ifstream::in);

	if (!file) {
		cout << "Error abriendo archivo: " << endl;
		return 0;
	}
	int curPointer = 0;

	while (!file.eof())
	{
		curPointer = file.tellg();
		file.read(reg.buffer, 64);

		reg.unPack();
		if (nombre == reg.Nombres) {
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
	return 0;
}

void ArchivoTexto::eliminar(string nombre) {
	int offsetToMark = buscar(nombre);
	char mark = '*';
	ofstream file;
	file.open("Registros.txt", ofstream::cur);
	file.seekp(offsetToMark, ios::cur);

	file << "*";

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
		i_file.read(buffer_aux, 64);

		if (buffer_aux[0] != '*' && curPointer < filesize) {
			o_file << buffer_aux;
		}

		curPointer += 64;
	}

	i_file.close();
	o_file.close();

}
