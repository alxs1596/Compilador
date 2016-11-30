#include "stdafx.h"
#include "Regla.h"

using namespace compilador::sintactico;

compilador::sintactico::Regla::Regla(NoTerminal * noTerminal, vector<ElementoGramatical*>* produccion)
{
	this->noTerminal = noTerminal;
	this->produccion = produccion;
}


Regla::~Regla()
{
}

vector<ElementoGramatical *>* Regla::getProduccion()
{
	vector<ElementoGramatical*>* nuevo = new vector<ElementoGramatical*>(produccion->size());
	for (size_t i = 0; i < produccion->size(); i++) {
		if ((*produccion)[i] == NULL) (*nuevo)[i] = NULL;
		else (*nuevo)[i] = (*produccion)[i]->clonar();
	}
	return nuevo;
}

NoTerminal * Regla::getNoTerminal()
{
	return noTerminal;
}


