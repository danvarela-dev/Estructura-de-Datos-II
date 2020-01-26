#include "Metodos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> 

using namespace std;

#pragma warning (disable : 4996)

Metodos::Metodos() {}

void Metodos::metodo_uno(char* name) {
    int num;
    strcat(name, ".txt");
    ifstream file(name , ios::in);

    while (!file.eof()) {

        file >> num;
        cout << num << " ";

    }
    file.close();
}

void Metodos::metodo_dos(char* name) {
    strcat(name, ".txt");

    fstream File;
    string filename;


    File.open(name, ios::in);
    File.unsetf(ios::skipws);

    while (1) {
        File >> filename;
        if (File.fail())break;
        cout << filename;
    }
    File.close();


}



void Metodos::metodo_tres(char* name) {
    string line;

    strcat(name, ".txt");

    ifstream myfile(name);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }


}