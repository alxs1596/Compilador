#pragma once

#include "NoTerminal.h"
#include "ElementoGramatical.h"
#include "Cuadruplo.h"

class Regla
{
private:
	NoTerminal* noTerminal;
	ElementoGramatical** produccion;
	ElementoGramatical** genera;
	int elementosProduccion;

	Cuadruplo* plantilla;
public:
	Regla(NoTerminal*, ElementoGramatical**, int);
	~Regla();

	ElementoGramatical** getProduccion();
	int getNumeroProducciones();
	NoTerminal* getNoTerminal();

	void setPlantilla(ElementoGramatical * Resultado, ElementoGramatical * Operando1, ElementoGramatical * Operador, ElementoGramatical * Operando2);
	Cuadruplo* getCuadruplo();

};

