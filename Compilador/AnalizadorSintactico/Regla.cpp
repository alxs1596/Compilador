#include "stdafx.h"
#include "Regla.h"


Regla::Regla(NoTerminal * noTerminal, ElementoGramatical ** produccion, int numeroProducciones)
{
	this->noTerminal = noTerminal;
	this->produccion = produccion;
	this->elementosProduccion = numeroProducciones;
}

Regla::~Regla()
{
}

ElementoGramatical ** Regla::getProduccion()
{
	return produccion;
}

int Regla::getNumeroProducciones()
{
	return elementosProduccion;
}

NoTerminal * Regla::getNoTerminal()
{
	return noTerminal;
}
