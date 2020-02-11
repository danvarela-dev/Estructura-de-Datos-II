#include "person.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

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

    iFilePersons.open(filename, ios::in);

    if (!oFilePersons) {
        cout << "Error opening file..." << endl;
        return;
    }


    while (iFilePersons >> reg.FirstName >> reg.LastName >> reg.Address >> reg.City >> reg.State >> reg.ZipCode) {
      Print();
    }

}


void Person::transferBuffer(registro buffer) {
    
}

void Person::save_Registry()
{
    oFilePersons.open("Persons.dat", ios::app);

    if (!oFilePersons)
    {
        cout << "Error opening file..." << endl;
        return; 
    }

    int quantity;

    cout << "Enter amount of Persons: ";
    cin >> quantity;

    

    /*for (size_t i = 0; i < quantity; i++)
    {
        cout << endl << "First Name: ";
        cin >> FirstName_aux;
        cout << endl << "Last Name:";
        cin >> LastName_aux;
        cout << endl << "Address: ";
        cin >> Address_aux;
        cout << endl << "City: ";
        cin >> City_aux;
        cout << endl << "State: ";
        cin >> State_aux;
        cout << endl << "Zip Code: ";
        cin >> ZipCode_aux;
        cout << endl << endl;
        write(FirstName_aux, LastName_aux, Address_aux, City_aux, State_aux, ZipCode_aux);
    }*/

    write("Daniel", "Varela", "Jardines", "SPS", "NYC", "12112");
    write("Jose", "Alejo", "Jardines", "SPS", "NYC", "12112");
    write("Jack", "Gutz", "Jardines", "nyc", "NYC", "12112");

    oFilePersons.close();
}

void Person::write(const char* firstName, const char* lastName, const char* address, const char* city, const char* state, const char* zipcode) {

    oFilePersons << firstName << "\t\t"<< lastName << "\t\t"  << address << "\t\t" << city
        <<"\t\t" << state << "\t\t" << zipcode << "\n";

}


Person::Person() {
    LastName_aux[0] = 0;
    FirstName_aux[0] = 0;
    Address_aux[0] = 0;
    City_aux[0] = 0;
    State_aux[0] = 0;
    ZipCode_aux[0] = 0;
}
