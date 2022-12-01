#include "Clientes.h"
Cliente::Cliente()
{
	id = 0;
	nombre = " ";
	telefono = 0;
	direccion = " ";
	pedidos = false;
	ptrSgt = NULL;
	ptrAnt = NULL;
	ptrPrimero = NULL;
	ptrUltimo = NULL;
	ptrAux = NULL;
	SecuenciaP = 1;
}
Cliente::Cliente(int pId, string pNombre, int pTelefono, string pDireccion)
{
	id = pId;
	nombre = pNombre;
	telefono = pTelefono;
	direccion = pDireccion;
	ptrSgt = NULL;
	ptrAnt = NULL;
	pedidos = false;
	ptrSgt = NULL;
	ptrAnt = NULL;
	ptrPrimero = NULL;
	ptrUltimo = NULL;
	ptrAux = NULL;
	SecuenciaP = 1;
}
Cliente::~Cliente() 
{
	short cont = 0;
	while (ptrPrimero != NULL)
	{
		ptrAux = ptrPrimero;
		ptrPrimero = ptrPrimero->ptrAbajo;
		delete ptrAux;
		cont++;
	}
	cout << " Se logro eliminar los " << cont << " Pedidos" << endl;
	system("pause");
}
Pedido* Cliente::nuevoPedido()
{
	int id;
	string fecha;
	string descripcion;
	
	id = SecuenciaP;
	cout << "Ingrese la fecha: ";
	cin.ignore();
	getline(cin, fecha);
	cout << "Ingrese la descripcion: ";
	cin.ignore();
	getline(cin, descripcion);
	SecuenciaP++;
	
	return new Pedido(id, fecha, descripcion);
}
void Cliente::insertarPedido()
{
	ptrAux = nuevoPedido();
	ptrAux->ptrAbajo = NULL;
	
	if (ptrPrimero != NULL)
	{
		ptrUltimo->ptrAbajo = ptrAux;
		ptrUltimo = ptrAux;
	}
	else
		ptrPrimero = ptrUltimo = ptrAux;
	
	pedidos = true;
	ptrAux = NULL;
}
void Cliente::mostrar()
{
	ptrAux = ptrPrimero;
	while (ptrAux != NULL)
	{
		cout << "Detalles del Pedido: " << endl;
		cout << "ID: " << ptrAux->getId() << endl;
		cout << "Fecha: " << ptrAux->getFecha() << endl;
		cout << "Descripcion: " << ptrAux->getDescripcion() << endl;
		cout << "\n\n";
		ptrAux = ptrAux->ptrAbajo;
	}
	cout << endl;
	if (pedidos == false)
	{
		cout << "No hay pedidos pendientes" << endl;
	}
}
void Cliente::eliminar()
{
	bool existe = false;
	ptrAux = ptrPrimero;
	Pedido* anterior = ptrAux;
	
	if (ptrPrimero != NULL) 
	{
		cout << "Digite el ID del pedido al que desea eliminar: ";
		cin >> id;
		while (ptrAux != NULL) 
		{
			if (ptrAux->getId() == id) 
			{
				cout << "Detalles del Pedido que desea eliminar: " << endl;
				cout << "ID: " << ptrAux->getId() << endl;
				cout << "Fecha: " << ptrAux->getFecha() << endl;
				cout << "Descripcion: " << ptrAux->getDescripcion() << endl;
				cout << "\n\n";
				if (ptrAux == ptrPrimero) 
				{
					ptrPrimero = ptrPrimero->ptrAbajo;
				}
				else if (ptrAux == ptrUltimo && ptrUltimo != ptrPrimero)
				{
					ptrUltimo = anterior;
					ptrAux = ptrAux->ptrAbajo;
					ptrUltimo->ptrAbajo = NULL;
				}
				else 
				{
					anterior = ptrAux->ptrAbajo;
				}
				existe = true;
			}
			if (existe == true)  
			{
				ptrAux = NULL;
			}
			else
			{
				anterior = ptrAux;
				ptrAux = ptrAux->ptrAbajo;
			}
			
		}
		if (existe == false)
		{
			cout << "El pedido no existe en la lista de pedidos actuales" << endl;
		}
		else
		{
			delete ptrAux;
		}
	}
	else
	{
		cout << "No hay pedidos pendientes" << endl;
	}
	if (ptrPrimero == NULL)
	{
		pedidos = false;
	}
	ptrAux = NULL;
}
void Cliente::despachar()
{
	
	if (ptrPrimero != NULL)
	{
		ptrAux = ptrPrimero;
		ptrPrimero = ptrPrimero->ptrAbajo;
		
		cout << "Detalles del Pedido a despachar: " << endl;
		cout << "ID: " << ptrAux->getId() << endl;
		cout << "Fecha: " << ptrAux->getFecha() << endl;
		cout << "Descripcion: " << ptrAux->getDescripcion() << endl;
		cout << "\n\n";
		delete ptrAux;
		ptrAux = NULL;
	}
	else
		cout << "No hay pedidos pendientes" << endl;
	if (ptrPrimero == NULL)
	{
		pedidos = false;
	}
}
void Cliente::modificar()
{
	string nuevafecha, nuevaDescripcion;
	short opc;
	int id;
	ptrAux = ptrPrimero;
	
	if (ptrPrimero != NULL)
	{
		cout << "Digite el ID del pedido al que desea modificar: ";
		cin >> id;
		
		while (ptrAux != NULL) 
		{
			if (ptrAux->getId() == id)
			{
				cout << "1- Fecha: " << ptrAux->getFecha() << endl;
				cout << "2- Descripcion: " << ptrAux->getDescripcion() << endl;
				cout << "\n\n";
				
				cout << "Digite la opcion que sea modificar: ";
				cin >> opc;
				
				if (opc == 1)
				{
					cout << "Ingrese nuevo Dato de fecha: ";
					cin.ignore();
					getline(cin, nuevafecha);
					ptrAux->setFecha(nuevafecha);
				}
				if (opc == 2)
				{
					cout << "Ingrese nuevo Dato de Descripcion: ";
					cin.ignore();
					getline(cin, nuevaDescripcion);
					ptrAux->setDescripcion(nuevaDescripcion);
				}
			}
			ptrAux = ptrAux->ptrAbajo;
		}
	}
	else
	{
		cout << "No existen pedidos" << endl;
	}
	ptrAux = NULL;
}

void Cliente::setId(int nId)
{
	id = nId;
}

int Cliente::getId()
{
	return id;
}

void Cliente::setNombre(string pNombre)
{
	direccion = pNombre;
}

string Cliente::getNombre()
{
	return nombre;
}

void Cliente::setTelefono(int pTelefono)
{
	telefono = pTelefono;
}

int Cliente::getTelefono()
{
	return telefono;
}

void Cliente::setDireccion(string pDireccion)
{
	direccion = pDireccion;
}

string Cliente::getDireccion()
{
	return direccion;
}
