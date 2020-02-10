#include "person.h";
#include <iostream>
#include <fstream>


using namespace std;

void Person::Print() {
    cout << "Last Name '" << LastName_aux << "'\n"
        << "First Name '" << FirstName_aux << "'\n"
        << "Address '" << Address_aux << "'\n"
        << "City '" << City_aux << "'\n"
        << "State '" << State_aux << "'\n"
        << "Zip Code '" << ZipCode_aux << "'\n"
        << flush;
}

void Person::readFile(const char* filename) {

    file.open(filename, fstream::in | ifstream::binary);
    file.seekg(0, ios_base::beg);

    file.read((char*)&reg, sizeof(reg));
    transferBuffer(reg);
    file.close();

}


void Person::transferBuffer(registro buffer) {
    memcpy(LastName_aux, buffer.LastName, 16);
    memcpy(FirstName_aux, buffer.FirstName, 16);
    memcpy(Address_aux, buffer.Address, 16);
    memcpy(City_aux, buffer.City, 16);
    memcpy(State_aux, buffer.State, 3);
    memcpy(ZipCode_aux, buffer.ZipCode, 10);

}

Person::Person() {
    LastName_aux[0] = 0;
    FirstName_aux[0] = 0;
    Address_aux[0] = 0;
    City_aux[0] = 0;
    State_aux[0] = 0;
    ZipCode_aux[0] = 0;
}
