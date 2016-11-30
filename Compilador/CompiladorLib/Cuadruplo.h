#pragma once

#include "../AnalizadorSintactico/ElementoGramatical.h"
#include"../AnalizadorSintactico/Terminal.h"
#include"../AnalizadorSintactico/NoTerminal.h"
#include "TablaSimbolos.h"


namespace compilador {

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

		compilador::sintactico::ElementoGramatical* Resultado;
		compilador::sintactico::ElementoGramatical* Operando1;
		compilador::sintactico::ElementoGramatical* Operador;
		compilador::sintactico::ElementoGramatical* Operando2;

		TiposDeCuadruplos tipo;

		TablaSimbolos* bloque;

		Cuadruplo* clonar();

		Cuadruplo();
		Cuadruplo(compilador::sintactico::ElementoGramatical* Resultado,
			compilador::sintactico::ElementoGramatical* Operando1,
			compilador::sintactico::ElementoGramatical* Operador,
			compilador::sintactico::ElementoGramatical* Operando2,
			TiposDeCuadruplos _tipo,
			TablaSimbolos* _bloque);
		~Cuadruplo();
	};

}