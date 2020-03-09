#include "Humano.h"

using namespace std;

#pragma warning(disable : 4996 )

void Persona::Print() {
	cout << FirstName << "  "
		<< LastName << " "
		<< Address << "  "
		<< City << "  "
		<< State << "  "
		<< ZipCode <<"  " 
		<< Age << "  "
		<< Gender << "\n"
		<< flush;
}

Persona::Persona() {
	in_buffer[0] = 0;
	LastName[0] = 0;
	FirstName[0] = 0;
	Age = 0;
	Gender = 0;
	Address[0] = 0;
	City[0] = 0;
	State[0] = 0;
	ZipCode[0] = 0;
	SIZE = 0;
}


void Persona::SetBuffer(const char* buffer) {
	memcpy(in_buffer, buffer, MAX_BUFFER);
	UnPack();
}


void Persona::UnPack() {
	
	int size = 0;

	char* c = in_buffer;

	memcpy((char*)&size, c, 1);
	//size = atoi(cSize);
	memcpy(FirstName, c += 1, size);
	FirstName[size] = 0;

	memcpy((char*)&size, c += size, 1);
	//size = atoi(cSize);
	memcpy(LastName, c += 1, size);
	LastName[size] = 0;

	memcpy((char*)&size, c += size, 1);
	//size = atoi(cSize);
	memcpy(Address, c += 1, size);
	Address[size] = 0;

	memcpy((char*)&size, c += size, 1);
	//size = atoi(cSize);
	memcpy(City, c += 1, size);
	City[size] = 0;

	memcpy((char*)&size, c += size, 1);
	//size = atoi(cSize);
	memcpy(State, c += 1, size);
	State[size] = 0;

	memcpy((char*)&size, c += size, 1);
	//size = atoi(cSize);
	memcpy(ZipCode, c += 1, size);
	ZipCode[size] = 0;

	memcpy(&Age, c += size, 4);

	memcpy(&Gender, c += 4 ,  1);
	

}

void Persona::GetSizeStr(int size, char* str_size) 

	str_size[0] = 0;
	if (size <= 9) sprintf(str_size, "%d", size);
	else sprintf(str_size, "%d", size);

}

void Persona::Pack() {

	char str_size[3];
	int l_size = 0;
	str_size[2] = '\0';

	l_size = strlen(FirstName);
	/*GetSizeStr(l_size, str_size);*/
	strcpy(in_buffer, (char*)&l_size);
	strcat(in_buffer, FirstName);

	l_size = strlen(LastName);
	//GetSizeStr(l_size, str_size);
	strcat(in_buffer, (char*)&l_size);
	strcat(in_buffer, LastName);

	l_size = strlen(Address);
	//GetSizeStr(l_size, str_size);
	strcat(in_buffer, (char*)&l_size);
	strcat(in_buffer, Address);

	l_size = strlen(City);
	//GetSizeStr(l_size, str_size);
	strcat(in_buffer, (char*)&l_size);
	strcat(in_buffer, City);

	l_size = strlen(State);
	//GetSizeStr(l_size, str_size);
	strcat(in_buffer, (char*)&l_size);
	strcat(in_buffer, State);

	l_size = strlen(ZipCode);
	GetSizeStr(l_size, str_size);
	strcat(in_buffer, (char*)&l_size);
	strcat(in_buffer, ZipCode);
	SIZE = strlen(in_buffer);
	char* age = 0;
	
	strcat(in_buffer, (char*)&Age);


	strcat(in_buffer, (char*)&Gender);



	char strSizeBuffer[3];
	strSizeBuffer[2] = '\0';



	SIZE = strlen(in_buffer);

	file_hData.write((char*)&strSizeBuffer, 2);
	file_hData.write((char*)&in_buffer, SIZE);

	file_hData.close();
}

void Persona::writeFile() {

	file_hData.open("Humanos.bin", ios::out | ios::app | ios::binary);

	if (!file_hData)
	{
		cerr << "Error writing file...";
		return;
	}



	cout << "Nombre : " << flush; cin.getline(FirstName, 99);
	cout << "Apellido : " << flush; cin.getline(LastName, 99);
	cout << "Direccion : " << flush; cin.getline(Address, 99);
	cout << "Ciudad : " << flush; cin.getline(City, 99);
	cout << "Departamento : " << flush; cin.getline(State, 99);
	cout << "Codigo-Postal : " << flush; cin.getline(ZipCode, 99);
	cout << "Edad : " << flush; cin >> Age;
	cout << "Genero: { M | F }: " << flush; cin >> Gender;

	Pack();
}



void Persona::readFile()
{
	file_hData.open("Humanos.bin", fstream::in, fstream::binary);
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
		UnPack();
		Print();

	}






}
