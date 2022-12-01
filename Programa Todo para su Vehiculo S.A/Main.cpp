#include "ListaClientes.h"
ListaClientes listaCl;
Cliente* cliente;

int main()
{
	short opc = 0;
	short cat = 0;
	int id = 0;

	do {
		cout << "*****Menu*****" << endl;
		cout << " 1. Clientes" << endl;
		cout << " 2. Pedidos" << endl;
		cout << " 3. Salir " << endl;
		cout << "Inserte una opcion: ";
		cin >> cat;
		system("cls");
		
		switch (cat)
		{
		case 1:
			opc = 0;
			do
			{
				cout << "*****Menu Clientes*****" << endl;
				cout << " 1. Insertar" << endl;
				cout << " 2. Modificar" << endl;
				cout << " 3. Eliminar" << endl;
				cout << " 4. Mostrar" << endl;
				cout << " 5. Salir " << endl;
				cout << "Inserte una opcion: ";
				cin >> opc;
				system("cls");
				
				switch (opc)
				{
				case 1:
					listaCl.insertar();
					system("pause");
					system("cls");
					break;
				case 2:
					listaCl.modificar();
					system("pause");
					system("cls");
					break;
				case 3:
					listaCl.eliminar();
					system("pause");
					system("cls");
					break;
				case 4:
					listaCl.mostrar();
					system("pause");
					system("cls");
					break;
				}
			} while (opc != 5);
			break;
			
		case 2:
			opc = 0;
			do
			{
				cout << "*****Menu Pedidos*****" << endl;
				cout << " 1. Insertar" << endl;
				cout << " 2. Modificar" << endl;
				cout << " 3. Eliminar" << endl;
				cout << " 4. Mostrar" << endl;
				cout << " 5. Despachar" << endl;
				cout << " 6. Salir " << endl;
				cout << "Inserte una opcion: ";
				cin >> opc;
				system("cls");
				
				switch (opc)
				{
				case 1:
					cout << "Ingrese el ID del cliente: ";
					cin >> id;
					
					if (listaCl.buscar(id) != NULL)
					{
						cliente = listaCl.buscar(id);
						cliente->insertarPedido();
					}
					else
					{
						cout << "¡El cliente no existe! ";
					}
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "Ingrese el ID del cliente: ";
					cin >> id;
					
					if (listaCl.buscar(id) != NULL)
					{
						cliente = listaCl.buscar(id);
						cliente->modificar();
					}
					else
					{
						cout << "¡El cliente no existe! ";
					}
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "Ingrese el ID del cliente: ";
					cin >> id;
					
					if (listaCl.buscar(id) != NULL)
					{
						cliente = listaCl.buscar(id);
						cliente->eliminar();
					}
					else
					{
						cout << "¡El cliente no existe! ";
					}
					system("pause");
					system("cls");
					break;
				case 4:
					cout << "Ingrese el ID del cliente: ";
					cin >> id;
					
					if (listaCl.buscar(id) != NULL)
					{
						cliente = listaCl.buscar(id);
						cliente->mostrar();
					}
					else
					{
						cout << "¡El cliente no existe! ";
					}
					system("pause");
					system("cls");
					break;
				case 5:
					cout << "Ingrese el ID del cliente: ";
					cin >> id;
					
					if (listaCl.buscar(id) != NULL)
					{
						cliente = listaCl.buscar(id);
						cliente->despachar();
					}
					else
					{
						cout << "¡Este cliente no existe! ";
					}
					system("pause");
					system("cls");
					break;
				}
			} while (opc != 6);
			break;
		}
		
	} while (cat != 3);
	
	
	
	system("pause");
}
