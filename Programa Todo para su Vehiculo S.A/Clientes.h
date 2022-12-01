#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include "Pedido.h"
using namespace std;

class Cliente
{
private:
	int id;
	string nombre;
	int telefono;
	string direccion;
	
	Pedido* ptrPrimero;
	Pedido* ptrUltimo;
	Pedido* ptrAux;
	
	Pedido* nuevoPedido();
	short SecuenciaP;
	
public:
	Cliente* ptrSgt;
	Cliente* ptrAnt;
	bool pedidos;

	Cliente();
	Cliente(int, string, int, string);
	~Cliente();
	
	void insertarPedido(); 
	void eliminar(); 
	void modificar(); 
	void mostrar(); 
	void despachar();
	
	void setId(int);
	int getId();
	
	void setNombre(string);
	string getNombre();
	
	void setTelefono(int);
	int getTelefono();
	
	void setDireccion(string);
	string getDireccion();
};
#endif
