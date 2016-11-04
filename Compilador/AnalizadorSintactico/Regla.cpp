#include "stdafx.h"
#include "Regla.h"


Regla::Regla(NoTerminal * noTerminal, ElementoGramatical ** produccion, int numeroProducciones)
{
	this->noTerminal = noTerminal;
	this->produccion = produccion;
	this->elementosProduccion = numeroProducciones;
	this->plantilla = NULL;
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

void Regla::setPlantilla(ElementoGramatical * Resultado, ElementoGramatical * Operando1, ElementoGramatical * Operador, ElementoGramatical * Operando2)
{
	Cuadruplo* c = new Cuadruplo(Resultado, Operando1, Operador, Operando2);
	this->plantilla = c;
}

Cuadruplo * Regla::getCuadruplo()
{
	if (plantilla == NULL) return NULL;
	return plantilla->clonar();
}
