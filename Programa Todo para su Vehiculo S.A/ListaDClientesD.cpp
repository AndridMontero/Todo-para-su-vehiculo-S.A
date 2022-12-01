#include "ListaDClientes.h"
ListaClientes::ListaClientes()
{
	ptrPrimero = ptrUltimo = ptrAux = NULL;
	SecuanciaCl = 1;
}
ListaClientes::~ListaClientes()
{
	short cont = 0;
	while (ptrPrimero != NULL)
	{
		ptrAux = ptrPrimero;
		ptrPrimero = ptrPrimero->ptrSgt;
		delete ptrAux;
		cont++;
	}
	cout << "Se lograron eliminar: " << cont << " clientes" << endl;
	system("pause");
}
Cliente* ListaClientes::nuevoCliente()
{
	int id;
	string nombre;
	int telefono;
	string direccion;
	
	id = SecuanciaCl;
	cout << "Ingrese el Nombre: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese el Numero de telefono: ";
	cin >> telefono;
	cout << "Ingrese la Direccion: ";
	cin.ignore();
	getline(cin, direccion);
	SecuanciaCl++;
	
	return new Cliente(id, nombre, telefono, direccion);
}

void ListaClientes::insertar()
{
	bool existe = false;
	ptrAux = ptrPrimero;
	Cliente* nuevo = nuevoCliente();
	
	if (ptrPrimero != NULL) 
	{
		while (ptrAux != NULL)
		{
			if (ptrAux->getNombre() == nuevo->getNombre() && ptrAux->getTelefono() == nuevo->getTelefono() && ptrAux->getDireccion() == nuevo->getDireccion())
			{
				cout << "Este cliente no se encuntra en lista" << endl;
				existe = true;
			}
			ptrAux = ptrAux->ptrSgt;
		}
		if (existe == false) 
		{
			ptrAux = nuevo;
			ptrAux->ptrSgt = NULL;
			ptrAux->ptrAnt = ptrUltimo;
			
			ptrUltimo->ptrSgt = ptrAux;
			ptrUltimo = ptrAux;
		}
	}
	else
	{
		ptrPrimero = ptrUltimo = nuevo;
	}
	
	ptrAux = NULL;
}

void ListaClientes::mostrar()
{
	bool existe = false;
	ptrAux = ptrPrimero;
	
	if (ptrPrimero != NULL)
	{
		int id;
		cout << "Ingrese el ID de cliente: ";
		cin >> id;
		
		while (ptrAux != NULL) 
		{
			if (ptrAux->getId() == id)
			{
				cout << "ID Cliente: " << ptrAux->getId() << endl;
				cout << "Nombre: " << ptrAux->getNombre() << endl;
				cout << "Telefono: " << ptrAux->getTelefono() << endl;
				cout << "Direccion: " << ptrAux->getDireccion() << endl;
				cout << "\n\n";
				ptrAux->mostrar();
				existe = true;
				ptrAux = ptrUltimo;
			}
			ptrAux = ptrAux->ptrSgt;
		}
		if (existe == false)
		{
			cout << "Este cliente no se encuentra en la lista" << endl;
		}
	}
	else
	{
		cout << "Todavia no hay clientes" << endl;
	}
}

void ListaClientes::eliminar()
{
	if (ptrPrimero != NULL)
	{
		ptrAux = ptrPrimero;
		int id;
		bool existe = false;
		
		cout << " Ingrese el ID de cliente: ";
		cin >> id;
		
		while (ptrAux != NULL)
		{
			if (ptrAux->getId() == id)
			{
				if (ptrAux->pedidos == false)
				{
					cout << "El cliente que eliminara es: \n";
					cout << "ID Cliente: " << ptrAux->getId() << endl;
					cout << "Nombre: " << ptrAux->getNombre() << endl;
					cout << "Telefono: " << ptrAux->getTelefono() << endl;
					cout << "Direccion: " << ptrAux->getDireccion() << endl;
					cout << "\n\n";
					
					if (ptrAux == ptrPrimero)
					{
						ptrPrimero = ptrPrimero->ptrSgt;
						
						if (ptrPrimero != NULL)
						{
							ptrPrimero->ptrAnt = NULL;
						}
						else
						{
							ptrUltimo = ptrPrimero = NULL;
						}
					}
					else if (ptrAux == ptrUltimo)
					{
						if (ptrPrimero == ptrUltimo)
						{
							ptrPrimero = ptrUltimo = NULL;
						}
						else
						{
							ptrUltimo = ptrUltimo->ptrAnt;
							ptrUltimo->ptrSgt = NULL;
						}
					}
					else
					{
						ptrAux->ptrAnt->ptrSgt = ptrAux->ptrSgt;
					}
					
					existe = true;
				}
				else
				{
					existe = true;
					cout << "El cliente tiene pedidos pendientes, actualice los pedidos para poderlo eliminar" << endl;
				}
			}
			if (existe == true)
			{
				ptrAux = NULL;
			}
			else
			{
				ptrAux = ptrAux->ptrSgt;
			}
		}
		if (existe == false)
		{
			cout << "Este cliente no se encuentra en la lista" << endl;
		}
		else
		{
			delete ptrAux;
		}
	}
	else
	{
		cout << "Todavia no hay clientes" << endl;
	}
	ptrAux = NULL;
}
void ListaClientes::modificar()
{
	string NombreViejo, NombreNuevo, DireccionNueva;
	int TelefonoNuevo, id;
	short opc;
	bool existe = false;
	ptrAux = ptrPrimero;
	
	if (ptrPrimero != NULL)
	{
		cout << "Digite el ID de cliente que desea modificar: ";
		cin >> id;
		
		while (ptrAux != NULL)
		{
			if (ptrAux->getId() == id)
			{
				cout << "1- Nombre: " << ptrAux->getNombre() << endl;
				cout << "2- Telefono: " << ptrAux->getTelefono() << endl;
				cout << "3- Direccion: " << ptrAux->getDireccion() << endl;
				cout << "\n\n";
				
				cout << "\nDigite la opcion que desea modificar: ";
				cin >> opc;
				
				if (opc == 1)
				{
					cout << "\nIngrese el nuevo nombre: ";
					cin.ignore();
					getline(cin, NombreNuevo);
					ptrAux->setNombre(NombreNuevo);
				}
				if (opc == 2)
				{
					cout << "\nIngrese el nuevo n. telefono: ";
					cin >> TelefonoNuevo;
					ptrAux->setTelefono(TelefonoNuevo);
				}
				if (opc == 3)
				{
					cout << "\nIngrese la nueva direccion: ";
					cin.ignore();
					getline(cin, DireccionNueva);
					ptrAux->setDireccion(DireccionNueva);
					break;
				}
				existe = true;
			}
			ptrAux = ptrAux->ptrSgt;
		}
		
		if (existe == false)
		{
			cout << "\nEl dato se modifico de manera correcta!" << endl;
		}
		
	}
	else
	{
		cout << "\nTodavia no hay clientes" << endl;
	}
	ptrAux = NULL;
}

Cliente* ListaClientes::buscar(int pId)
{
	Cliente* cliente = NULL;
	ptrAux = ptrPrimero;
	
	while (ptrAux != NULL)
	{
		if (ptrAux->getId() == pId)
		{
			cliente = ptrAux;
			ptrAux = ptrUltimo;
		}
		ptrAux = ptrAux->ptrSgt;
	}
	return cliente;
}
