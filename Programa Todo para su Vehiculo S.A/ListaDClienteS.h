#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include "Clientes.h"
class ListaClientes
{
private:
	Cliente* ptrPrimero;
	Cliente* ptrUltimo;
	Cliente* ptrAux;
	Cliente* nuevoCliente(); 
	short SecuanciaCl;
	
public:
	ListaClientes();
	~ListaClientes();
	void insertar(); 
	void eliminar(); 
	void modificar(); 
	void mostrar(); 
	Cliente* buscar(int);
	
};
#endif
