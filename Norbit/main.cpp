#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {


	int opcion;
	int Saldo[9] = { 8500,7600,4500,3200,2850,3670,7500,8010,5200 };
	string nombre[9] = { "Olmin Josue Calderon Cruz","Jose Enrique Santamaria Chacon","Josue Manuel Murillo Benitez",
	"Abraham Adolfo Rodriguez Paz","Rolando Jesus Maradiaga Pineda","Mario Roberto Aguilar Euceda",
	"Andres Emilio Guevara Kattan","Paul Enrique Cardona Gutierrez",
	"Wilfredo David Lontero Paz" };

	cout << "1) Filtrar por el primer nombre \n";
	cout << "2) Filtrar por el segundo nombre\n";
	cout << "3) Filtrar por el perimer apellido\n";
	cout << "4) Filtrar por el segundo apellido\n";
	cout << "Ingrese una opcion: ";
	cin >> opcion;
	cout << "\n\n";

	char letra;
	int cantEspacios =0 ;
	bool printed = true;


	switch (opcion) {
	case 1:
		cout << "****** FILTRO POR PRIMER NOMBRE ******\n";
		cout << "Ingrese letra: \n";
		cin >> letra;
		for (int i = 0; i < 9; i++)
		{
			for (size_t j = 0; j < nombre[i].size(); j++)
			{
				if (nombre[i].at(j) == ' ') {
					for (size_t k = 0; k < j; k++)
					{
						if (nombre[i].at(k) == letra)
							if (printed) {
								cout << "Nombre: " << nombre[i] << " Saldo: " << Saldo[i] << endl;
								printed = false;
							
						}
					}
				}

			}
		}
		break;

	case 2:
		cout << "****** FILTRO POR SEGUNDO NOMBRE ******\n";
		cout << "Ingrese letra: \n";
		cin >> letra;

		for (size_t i = 0; i < 9; i++)
		{
			cantEspacios = 0;

			for (size_t j = 0; j < nombre[i].size(); j++)
			{
				if (nombre[i].at(j) == ' ') {
					cantEspacios++;
					if (cantEspacios == 1	) {

						if (nombre[i].at(j + 1) == letra)
							cout << "Nombre: " << nombre[i] << " Saldo: " << Saldo[i] << endl;

					}
				}
			}

		}

		break;

	case 3:

		cout << "****** FILTRO POR PRIMER APELLIDO ******\n";
		cout << "Ingrese letra: \n";
		cin >> letra;

		for (size_t i = 0; i < 9; i++)
		{
			cantEspacios = 0;

			for (size_t j = 0; j < nombre[i].size(); j++)
			{
				if (nombre[i].at(j) == ' ' ) {
					cantEspacios++;
					if (cantEspacios == 2) {

						if (nombre[i].at(j + 1) == letra)
							cout << "Nombre: " << nombre[i] << " Saldo: " << Saldo[i] << endl;

					}
				}
			}

		}

		break;

	case 4:

		cout << "****** FILTRO POR SEGUNDO APELLIDO ******\n";
		cout << "Ingrese letra: \n";
		cin >> letra;

	
		for (size_t i = 0; i < 9; i++)
		{
			cantEspacios = 0;
			for (size_t j = 0; j < nombre[i].size(); j++)
			{
				if (nombre[i].at(j) == ' ') {
					cantEspacios++;
					if (cantEspacios == 3) {

						if (nombre[i].at(j + 1) == letra)
							cout << "Nombre: " << nombre[i] << " Saldo: " << Saldo[i] << endl;

					}
				}
			}

		}


		break;

	default: // El defaulta, similar al else ejecuta una instruccion en caso que no se haya encontrado niguna coincidencia


	


		cout << "No se han encontrado coincidencias!";
		break;

	}
	return 0;
}
