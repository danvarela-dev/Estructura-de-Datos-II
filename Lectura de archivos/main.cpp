#include "Metodos.h"
#include <fstream>
#include <time.h>

using namespace std;

int main() {
    int opt = 0;

    do {
        Metodos m;
        cout << "\nIngrese el nombre del archivo: ";
        
        char name[30];
        cin >> name;
        cout << "\nIngrese el metodo a probar:\n1. Metodo Uno\n2. Metodo Dos\n3. Metodo Tres\nIngrese Opcion: ";
        cin >> opt;
        clock_t tStart = clock();

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

        printf("\n\nTime taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
      

        cout << "\nInserte -1 para salir...";
    } while (opt != -1);

}