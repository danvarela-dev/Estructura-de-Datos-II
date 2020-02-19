#include "Vehiculo.h"

Vehiculo::Vehiculo(string name) {
	Empresa = name;
}
void Vehiculo::TopSellers()
{
	int temporal;
	string temporalNombre;
	string temporalID;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			if (VentaEmpleado[j] < VentaEmpleado[j + 1]) { // Ordena el array de mayor a menor, cambiar el "<" a ">" para ordenar de menor a mayor
				temporal = VentaEmpleado[j];
				temporalNombre = Empleados[j][0];
				temporalID = Empleados[j][1];

				VentaEmpleado[j] = VentaEmpleado[j + 1];
				VentaEmpleado[j + 1] = temporal;

				Empleados[j][0] = Empleados[j + 1][0];
				Empleados[j][1] = Empleados[j + 1][1];

				Empleados[j + 1][0] = temporalNombre;
				Empleados[j + 1][1] = temporalID;
				
			}
		}
	}

	cout << "** E M P L E A D O S **\n";
	cout << "Empleado      ID      Ventas" << endl;
	
	for (int i = 0; i < 10; i++)
	{
		cout << Empleados[i][0] <<"      "<<Empleados[i][1] <<"      "<< VentaEmpleado[i] << endl;

	}

	
}

void Vehiculo::Autos()
{
	cout << "** A U T O S **\n";

	cout << "*Auto\t\t*Codigo\t\tPrecio" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << Bienes[i][0] << "\t\t" << Bienes[i][1] <<"\t\t"<<Precios[i] << endl;
	}


}

void Vehiculo::RealizarVenta()
{
	cout << "** R E A L I Z A R  V E N T A **\n";
	string ID2 , id;
	string autoID2 ,autoid ;
	bool encontro = false;


		cout << "Ingres el ID del vendedor: ";
		cin >> ID2;
		cout << endl << "Ingrese el ID del auto a vender: ";
		cin >> autoID2;


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (ID2 == Empleados[i][1] && autoID2 == Bienes[j][1])
				{
					encontro = true;
					Ingresos = Ingresos + Precios[j];
					VentaEmpleado[i]++;
					cout << "Venta realizada exitosamente.." << endl;
				}
			}
			
		}
		if (!encontro) {
			cout << "Datos inexistentes, intente de nuevo...";
		}

}

int Vehiculo::SaldoIngreso()
{
	cout << "Ingresos:";
	return Ingresos;
}

void Vehiculo::Menu()
{
	int opcion;
	
	do {
		cout << "\n*** Menu " << Empresa << "***\n";
		cout << "1) Mostrar Empleados\n2) Mostar Autos\n3) Realizar venta\n4) Ingresos por venta\n5) Salir\nIngrese su opcion:";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			TopSellers();
			break;
		case 2:
			Autos();
			break;
		case 3:
			RealizarVenta();
			break;
		case 4:
			cout << SaldoIngreso();
			break;
		
		}

	} while (opcion != 5);

}
