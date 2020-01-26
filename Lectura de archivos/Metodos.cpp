#include "Metodos.h"
#include <iostream>
#include <fstream>
#include <string.h>
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
     ifstream file(name , ios::in)


}



void Metodos::metodo_tres(char* name) {



}