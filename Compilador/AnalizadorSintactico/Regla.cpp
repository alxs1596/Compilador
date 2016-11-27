#include "stdafx.h"
#include "Regla.h"

using namespace compilador::sintactico;

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
	ElementoGramatical** nuevo = new ElementoGramatical*[elementosProduccion];
	for (int i = 0; i < elementosProduccion; i++) {
		if (produccion[i] == NULL) nuevo[i] = NULL;
		else nuevo[i] = produccion[i]->clonar();
	}
	return nuevo;
}

int Regla::getNumeroProducciones()
{
	return elementosProduccion;
}

NoTerminal * Regla::getNoTerminal()
{
	return noTerminal;
}

void Regla::setPlantilla(ElementoGramatical * Resultado, ElementoGramatical * Operando1, ElementoGramatical * Operador, ElementoGramatical * Operando2, TiposDeCuadruplos tipo)
{
	Cuadruplo* c = new Cuadruplo(Resultado, Operando1, Operador, Operando2, tipo);
	this->plantilla = c;
}

Cuadruplo * Regla::getCuadruplo()
{
	if (plantilla == NULL) return NULL;
	return plantilla->clonar();
}
