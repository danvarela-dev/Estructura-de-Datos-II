#ifndef  PERSONA_H
#define PERSONA_H
#include <fstream>
using namespace std;
struct registro {
    char LastName[99] = { 0 };
    char FirstName[99] = { 0 };
    char Address[99] = { 0 };
    char City[99] = { 0 };
    char State[99] = { 0 };
    char ZipCode[99] = { 0 };
};
class Persona {
private:
    fstream file;
    registro reg;

public:
    Persona();

    char LastName[99];
    char FirstName[99];
    char Address[99];
    char City[99];
    char State[99];
    char ZipCode[99];


    void Print();
    void leerArch();
    void unPack(const char*);
    void Pack();
    void PrintAll();
    void writeFile();

};




#endif // ! PERSONA_H


