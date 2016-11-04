#pragma once

#include "ElementoGramatical.h"
#include"Terminal.h"
#include"NoTerminal.h"

class Cuadruplo
{
public:

	
	

	ElementoGramatical* Resultado;
	ElementoGramatical* Operando1;
	ElementoGramatical* Operador;
	ElementoGramatical* Operando2;

	Cuadruplo* clonar();

	Cuadruplo();
	Cuadruplo(ElementoGramatical* Resultado,
		ElementoGramatical* Operando1,
		ElementoGramatical* Operador,
		ElementoGramatical* Operando2);
	~Cuadruplo();
};

