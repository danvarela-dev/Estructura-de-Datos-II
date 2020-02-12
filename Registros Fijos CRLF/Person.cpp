#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


void Person::readFile(const char* filename) {

    iFilePersons.open(filename, ios::in);

    if (!iFilePersons) {
        cout << "Error opening file..." << endl;
        return;
    }
    string s;

        cout << "First Name: " << setw(8) << "Last Name:" << setw(8)
            << "Address:" << setw(8)
            << "City:" << setw(8)
            << "State: " << setw(8)
            << "Zip Code:" "\n";
    
   
        while (getline(iFilePersons, s, ';')) {
            
            cout << s << setw(12);
        }
    

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


    for (size_t i = 0; i < quantity; i++)
    {
        cout << endl << "First Name: ";
        cin >> FirstName_aux;
        strcat_s(FirstName_aux, sizeof(FirstName_aux),";");
        cout << endl << "Last Name:";
        cin >> LastName_aux;
        strcat_s(LastName_aux, sizeof(LastName_aux), ";");
        cout << endl << "Address: ";
        cin >> Address_aux;
        strcat_s(Address_aux, sizeof(Address_aux), ";");
        cout << endl << "City: ";
        cin >> City_aux;
        strcat_s(City_aux, sizeof(City_aux), ";");
        cout << endl << "State: ";
        cin >> State_aux;
        strcat_s(State_aux, sizeof(State_aux), ";");
        cout << endl << "Zip Code: ";
        cin >> ZipCode_aux;
        strcat_s(ZipCode_aux, sizeof(ZipCode_aux), "\r\n");
        cout << endl << endl;
        write(FirstName_aux, LastName_aux, Address_aux, City_aux, State_aux, ZipCode_aux);

    }

    /*write("Daniel", "Varela", "Jardines", "SPS", "NYC", "12112");
    write("Jose", "Alejo", "Jardines", "SPS", "NYC", "12112");
    write("Jack", "Gutz", "Jardines", "nyc", "NYC", "12112");*/

    oFilePersons.close();
}

void Person::write(const char* firstName, const char* lastName, const char* address, const char* city, const char* state, const char* zipcode) {

    oFilePersons << firstName << lastName << address << city <<  state <<  zipcode;

}


Person::Person() {
    LastName_aux[0] = 0;
    FirstName_aux[0] = 0;
    Address_aux[0] = 0;
    City_aux[0] = 0;
    State_aux[0] = 0;
    ZipCode_aux[0] = 0;
}
