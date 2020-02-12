#include "Person.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

void Person::Print() {
    file.open("Persons.dat", ios::in);

    if (!file) {
        cout << "Error opening file..." << endl;
        return;
    }
    string s;

    cout << "First Name: " << setw(8) << "Last Name:" << setw(8)
        << "Address:" << setw(8)
        << "City:" << setw(8)
        << "State: " << setw(8)
        << "Zip Code:" "\n";


    while (getline(file, s, '|')) {

        cout << s << setw(12);
    }
}

void Person::PrintAll()
{
	file.open("Persons.dat", ifstream::in | ifstream::binary);
    

    while (file.eof())
    {
        file.read((char*)&reg, sizeof(registro));
        cout << reg.LastName << reg.FirstName << reg.Address << reg.City << reg.State << reg.ZipCode;
    }
    file.close();
}

void Person::Write()
{
    file.open("Persons.dat", ios::app);

    if (!file)
    {
        cout << "Error opening file..." << endl;
        return;
    }

    int quantity;

    cout << "Enter amount of Persons: ";
    cin >> quantity;


    for (size_t i = 0; i < quantity; i++)
    {
        cout << endl << "First Name: ";
        cin >> FirstName;
        cout << endl << "Last Name:";
        cin >> LastName;
        cout << endl << "Address: ";
        cin >> Address;
        cout << endl << "City: ";
        cin >> City;
        cout << endl << "State: ";
        cin >> reg.State;
        cout << endl << "Zip Code: ";
        cin >> reg.ZipCode;
        cout << endl << endl;

        Pack();

        file << sizeof(reg.FirstName )<< reg.FirstName << sizeof(LastName) << address << city << state << zipcode;

    }

    /*write("Daniel", "Varela", "Jardines", "SPS", "NYC", "12112");
    write("Jose", "Alejo", "Jardines", "SPS", "NYC", "12112");
    write("Jack", "Gutz", "Jardines", "nyc", "NYC", "12112");*/

    oFilePersons.close();


   
}

void Person::unPack(const char* buffer)
{
    


}

char * Person::Pack()
{
    char* buffer;
    char value[2];
    itoa(sizeof(LastName), value , 10);
    strcat(buffer, value);
    strcat(buffer, LastName);
    value[0] = 0;

    itoa(sizeof(FirstName), value, 10);
    strcat(buffer, value);
    strcat(buffer, FirstName);

    value[0] = 0;

        itoa(sizeof(Address), value, 10);
    strcat(buffer, value);
    strcat(buffer, Address);
    value[0] = 0;

    itoa(sizeof(LastName), value, 10);
    strcat(buffer, value);
    strcat(buffer, LastName);

    value[0] = 0;
    itoa(sizeof(LastName), value, 10);
    strcat(buffer, value);
    strcat(buffer, LastName);
    
    value[0] = 0;
    itoa(sizeof(LastName), value, 10);
    strcat(buffer, value);
    strcat(buffer, LastName);
    value[0] = 0;


}

Person::Person() {
    LastName[0] = 0;
    FirstName[0] = 0;
    Address[0] = 0;
    City[0] = 0;
    State[0] = 0;
    ZipCode[0] = 0;
}
