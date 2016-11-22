#pragma once

#include "ElementoGramatical.h"
#include"Terminal.h"
#include"NoTerminal.h"

enum TiposDeCuadruplos {
	Asignacion,
	Operacion,
	Lectura,
	Escritura,
	Declaracion
};

class Cuadruplo
{
public:

	
	

	ElementoGramatical* Resultado;
	ElementoGramatical* Operando1;
	ElementoGramatical* Operador;
	ElementoGramatical* Operando2;

	TiposDeCuadruplos tipo;

	Cuadruplo* clonar();

	Cuadruplo();
	Cuadruplo(ElementoGramatical* Resultado,
		ElementoGramatical* Operando1,
		ElementoGramatical* Operador,
		ElementoGramatical* Operando2,
		TiposDeCuadruplos _tipo);
	~Cuadruplo();
};

