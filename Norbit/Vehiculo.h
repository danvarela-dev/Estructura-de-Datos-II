#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>

using namespace std;

class Vehiculo
{
public:

	Vehiculo(string name);
	void TopSellers();
	void Autos();
	void RealizarVenta();
	int SaldoIngreso();
	void Menu();
private:
	string Empresa;
	int Ingresos = 0;
	string Empleados[10][2] = { {"Roberto","S1"},
								{"Cristian","S2"} ,
								{"Carlos","S3"},
								{"Rodrigo","S4"},
								{"Melvin","S5"}
								,{"Ronaldo","S6" },
								{"Andrea","S7" },
								{"María","S8"},
								{"Gabriela","S9"},
								{"Sandra","S10"}
								};

	int VentaEmpleado[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	string Bienes[7][2] = { {"Mazda CX","V1"} , { "Hyundai Elantra","V2" },
							{ "Ford Focus", "V3" }, { "Toyota Corola", "V4"} ,
							 {"Mitsubishi Lancer", "V5"} ,  {"Toyota Yaris" ,"V6"} ,
							 {"Ford Kia", "V7" }
							};

	int Precios[7] = { 75000, 60000, 90000, 110000, 84000, 95000, 78000 };
	
	};

#endif //VEHICULO_H


	