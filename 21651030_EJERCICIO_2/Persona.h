#include <iostream>
#include  <fstream>

using namespace std;


class Persona {
private:
    fstream filePersona;

public:
    char Nombres[100];
    char Apellidos[100];
    char Direccion[255];
    char Edad[3];
    char Genero;

    Persona();

    char in_buffer[460];

  
    
    
    void Pack();
    void unPack();


    void readAll();
    void writeAll();

};