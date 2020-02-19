#include <iostream>
#include  <fstream>

using namespace std;

#pragma pack(push , 1 )
struct registro {
    char LastName[16];
    char FirstName[16];
    char Address[16];
    char City[16];
    char State[5];
    char ZipCode[10];
};
#pragma pack(pop)


class Persona {
private:
    registro reg;
    ofstream oFilePersons;
    ifstream iFilePersons;

public:
    char LastName_aux[16];
    char FirstName_aux[16];
    char Address_aux[16];
    char City_aux[16];
    char State_aux[5];
    char ZipCode_aux[10];
    Persona();



    void transferBuffer(registro);
    void save_Registry();
    void write(const char*, const char*, const char*, const char*, const char*, const char*);

    void readFile(const char*);
};