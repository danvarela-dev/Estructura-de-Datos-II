#ifndef  PERSON_H
#define PERSON_H
#include <fstream>
using namespace std;

struct registro {
    char LastName[99];
    char FirstName[99];
    char Address[99];
    char City[99];
    char State[99];
    char ZipCode[99];
};

class Person {
private:
    fstream file;
    registro reg;

public:
    char LastName[99];
    char FirstName[99];
    char Address[99];
    char City[99];
    char State[99];
    char ZipCode[99];



    Person();
    void Print();

    void unPack(const char*);
    char * Pack();
    void Print();
    void PrintAll();
    void Write();

};

#endif // ! PERSON_H


