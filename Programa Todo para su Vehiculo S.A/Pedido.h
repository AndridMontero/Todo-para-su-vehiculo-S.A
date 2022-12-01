#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
using namespace std;

class Pedido
{
private:
	int id;
	string fecha;
	string descripcion;
	
public:
	Pedido* ptrAbajo;
	
	Pedido();
	Pedido(int, string, string);
	~Pedido();
	
	void setId(int);
	int getId();
	
	void setFecha(string);
	string getFecha();
	
	void setDescripcion(string);
	string getDescripcion();
	
};
#endif
