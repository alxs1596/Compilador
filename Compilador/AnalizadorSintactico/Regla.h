#pragma once

#include "NoTerminal.h"
#include "ElementoGramatical.h"

class Regla
{
private:
	NoTerminal* noTerminal;
	ElementoGramatical** produccion;
	int elementosProduccion;
public:
	Regla(NoTerminal*, ElementoGramatical**, int);
	~Regla();

	ElementoGramatical** getProduccion();
	int getNumeroProducciones();
	NoTerminal* getNoTerminal();
};
