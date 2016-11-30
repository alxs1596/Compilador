#pragma once

#include <vector>

#include "Terminal.h"

using namespace std;

namespace compilador {
	namespace sintactico {

		class Terminales
		{
		public:
			Terminal* Programa = new Terminal(new Token("Programa", TipoToken::PalabraReservada, 0));
			Terminal* ParentesisAbierto = new Terminal(new Token("(", TipoToken::Delimitador, 0));
			Terminal* ParentesisCerrado = new Terminal(new Token(")", TipoToken::Delimitador, 0));
			Terminal* CorchetesAbierto = new Terminal(new Token("{", TipoToken::Delimitador, 0));
			Terminal* CorchetesCerrado = new Terminal(new Token("}", TipoToken::Delimitador, 0));
			Terminal* PuntoYComa= new Terminal(new Token(";", TipoToken::Delimitador, 0));
			Terminal* Entero= new Terminal(new Token("entero", TipoToken::PalabraReservada, 0));
			Terminal* Coma= new Terminal(new Token(",", TipoToken::Delimitador, 0));
			Terminal* Id= new Terminal(new Token("id", TipoToken::Identificador, 0));
			Terminal* Igual= new Terminal(new Token("=", TipoToken::Operador, 0));
			Terminal* Mientras= new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0));
			Terminal* Si= new Terminal(new Token("Si", TipoToken::PalabraReservada, 0));
			Terminal* Osino= new Terminal(new Token("Osino", TipoToken::PalabraReservada, 0));
			Terminal* LeerTeclado= new Terminal(new Token("LeerTeclado", TipoToken::PalabraReservada, 0));
			Terminal* EscribirPantalla= new Terminal(new Token("EscribirPantalla", TipoToken::PalabraReservada, 0));
			Terminal* Hacer= new Terminal(new Token("Hacer", TipoToken::PalabraReservada, 0));
			Terminal* Mas= new Terminal(new Token("+", TipoToken::Operador, 0));
			Terminal* Menos= new Terminal(new Token("-", TipoToken::Operador, 0));
			Terminal* Numero= new Terminal(new Token("Numero", TipoToken::ConstanteEntera, 0));
			Terminal* Por= new Terminal(new Token("*", TipoToken::Operador, 0));
			Terminal* Entre= new Terminal(new Token("/", TipoToken::Operador, 0));
			Terminal* Modulo= new Terminal(new Token("%", TipoToken::Operador, 0));
			Terminal* MenorIgual= new Terminal(new Token("<=", TipoToken::Operador, 0));
			Terminal* MayorIgual= new Terminal(new Token(">=", TipoToken::Operador, 0));
			Terminal* IgualIgual= new Terminal(new Token("==", TipoToken::Operador, 0));
			Terminal* Diferente= new Terminal(new Token("!=", TipoToken::Operador, 0));
			Terminal* Menor= new Terminal(new Token("<", TipoToken::Operador, 0));
			Terminal* Mayor= new Terminal(new Token(">", TipoToken::Operador, 0));
			Terminal* Or= new Terminal(new Token("||", TipoToken::Operador, 0));
			Terminal* And= new Terminal(new Token("&&", TipoToken::Operador, 0));

			// Cuadruplos
			Terminal* Declaracion= new Terminal(new Token("Declaracion", TipoToken::Cuadruplos, 0));
			//------------

			vector<Terminal*>* Todos();
		};


		

	}
}
