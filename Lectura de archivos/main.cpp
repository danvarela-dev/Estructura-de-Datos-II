#include "Metodos.h"
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    int opt = 0;

    do {
        Metodos m;
        cout << "Ingrese el nombre del archivo: ";
        char name[30];
        cin >> name;
        cout << "\nIngrese el metodo a probar:\n1. Metodo Uno\n2. Metodo Dos\n3. Metodo Tres";
        cin >> opt;
        clock_t t;
        t = clock();

        switch (opt)
        {
        case 1:
            m.metodo_uno(name);
            break;
        case 2:
            m.metodo_dos(name);
            break;
        case 3:
            m.metodo_tres(name);
            break;

        }

        t = clock() - t;
        cout << "\n\nTiempo de ejecucion: ";
        cout << t;

        cout << "Inserte -1 para salir...";
    } while (opt != -1);

}