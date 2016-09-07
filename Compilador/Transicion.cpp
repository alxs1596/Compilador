#include "stdafx.h"
#include "Transicion.h"


Transicion::Transicion()
{
}


Transicion::~Transicion()
{
}

void Transicion::insertarTransi(string llave, string valor)
{
	Transicion::_transi.insert[llave] = valor;
}
