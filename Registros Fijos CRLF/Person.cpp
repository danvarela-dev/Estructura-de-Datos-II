
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Person.h"

using namespace std;

#pragma warning(disable : 4996)

void Person::Print() {

    if (LastName_aux != "0") {
        cout << "First Name: " << setw(15) << "Last Name:" << setw(15)
            << "Address:" << setw(15)
            << "City:" << setw(15)
            << "State: " << setw(15)
            << "Zip Code:" "\n";
    }

    cout << reg.FirstName
        << setw(5) << reg.LastName
        << setw(10) << reg.Address
        << setw(10) << reg.City
        << setw(10) << reg.State
        << setw(10) << reg.ZipCode << "\n";

}

void Person::readFile(const char* filename) {

    FilePersons.open(filename, ifstream::in | ifstream::binary);

    if (!FilePersons) {
        cout << "Error opening file..." << endl;
        return;
    }


    while (FilePersons >> reg.FirstName >> reg.LastName >> reg.Address >> reg.City >> reg.State >> reg.ZipCode) {
        Print();
    }

}



void Person::save_Registry()
{
    FilePersons.open("Persons.dat", ios::app);

    if (!FilePersons)
    {
        cout << "Error opening file..." << endl;
        return; 
    }

    int quantity;

    cout << "Enter amount of Persons: ";
    cin >> quantity;


    string firstName;


    /*for (size_t i = 0; i < quantity; i++)
    {
        cout << endl << "First Name: ";
        cin >> reg.FirstName;
        strcat(reg.FirstName, ";");
        cout << endl << "Last Name:";
        cin >> reg.LastName;
        strcat(reg.LastName, ";");
        cout << endl << "Address: ";
        cin >> reg.Address;
        strcat(reg.Address, ";");
        cout << endl << "City: ";
        cin >> reg.City;
        strcat(reg.City, ";");
        cout << endl << "State: ";
        cin >> reg.State;
        strcat(reg.State, ";");
        cout << endl << "Zip Code: ";
        cin >> reg.ZipCode;
        strcat(reg.ZipCode, "\r\n");
        cout << endl << endl;
        FilePersons.write(reinterpret_cast<const char*>(&reg),sizeof(registro));
    }*/

    write("Daniel", "Varela", "Jardines", "SPS", "NYC", "12112");
    write("Jose", "Alejo", "Jardines", "SPS", "NYC", "12112");
    write("Jack", "Gutz", "Jardines", "nyc", "NYC", "12112");

    FilePersons.close();
}



void Person::write(const char* firstName, const char* lastName, const char* address, const char* city, const char* state, const char* zipcode) {

    strcpy(reg.FirstName, firstName);
    strcat(reg.FirstName, ";");

    strcpy(reg.LastName, lastName);
    strcat(reg.LastName, ";");

    strcpy(reg.Address, address);
    strcat(reg.Address, ";");

    strcpy(reg.City, city);
    strcat(reg.City, ";");

    strcpy(reg.State, state);
    strcat(reg.State, ";");

    strcpy(reg.ZipCode, zipcode);
    strcat(reg.ZipCode, "\r\n");

    FilePersons.write(reinterpret_cast<const char*>(&reg), sizeof(registro));

}

Person::Person() {
    LastName_aux[0] = 0;
    FirstName_aux[0] = 0;
    Address_aux[0] = 0;
    City_aux[0] = 0;
    State_aux[0] = 0;
    ZipCode_aux[0] = 0;
}
