#pragma once

#include "ElementoGramatical.h"
#include"Terminal.h"
#include"NoTerminal.h"
#include "TablaSimbolos.h"

enum TiposDeCuadruplos {
	Asignacion,
	Operacion,
	Lectura,
	Escritura,
	Declaracion,
	Mientras,
	Si,
	Osino
};

class Cuadruplo
{
public:

	ElementoGramatical* Resultado;
	ElementoGramatical* Operando1;
	ElementoGramatical* Operador;
	ElementoGramatical* Operando2;

	TiposDeCuadruplos tipo;

	TablaSimbolos* bloque;

	Cuadruplo* clonar();

	Cuadruplo();
	Cuadruplo(ElementoGramatical* Resultado,
		ElementoGramatical* Operando1,
		ElementoGramatical* Operador,
		ElementoGramatical* Operando2,
		TiposDeCuadruplos _tipo);
	~Cuadruplo();
};

