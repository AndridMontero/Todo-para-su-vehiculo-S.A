#include "Pedido.h"
Pedido::Pedido()
{
	id = 0;
	fecha = "";
	descripcion = "";
	ptrAbajo = NULL;
}

Pedido::Pedido(int pId, string pFecha, string pDescripcion)
{
	id = pId;
	fecha = pFecha;
	descripcion = pDescripcion;
	ptrAbajo = NULL;
}

Pedido::~Pedido() {}

void Pedido::setId(int nId)
{
	id = nId;
}

int Pedido::getId()
{
	return id;
}

void Pedido::setFecha(string pFecha)
{
	fecha = pFecha;
}

string Pedido::getFecha()
{
	return fecha;
}

void Pedido::setDescripcion(string pDescripcion)
{
	descripcion = pDescripcion;
}

string Pedido::getDescripcion()
{
	return descripcion;
}
