#include <iostream>
#include  <fstream>

using namespace std;

struct registro {
    char FirstName[16];
    char LastName[16];
    char Address[16];
    char City[16];
    char State[3];
    char ZipCode[10];
};


class Person {
private:
    registro reg;
    fstream FilePersons;
    
public:
    char FirstName_aux[16];
    char LastName_aux[16];
    char Address_aux[16];
    char City_aux[16];
    char State_aux[3];
    char ZipCode_aux[10];
    Person();

    
    void save_Registry();
    void write(const char*, const char*, const char*, const char*, const char*, const char*);

    void readFile(const char*);
    void Print();
};