#pragma once

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "../CompiladorLib/Tipos.h"
#include "../CompiladorLib/Token.h"
#include "Alfabeto.h"

namespace compilador {
	namespace lexico {

		typedef std::map<int, std::map<int, std::vector<char>* > > Matriz;


		class Automata
		{
		private:
			Alfabeto alfabeto;
			Matriz matriz;
			void llenarMatriz();
			int numeroDeEstados;
			int EstadoActual;
		public:
			Automata();
			~Automata();
			bool mover(char c);
			bool esEstadoFinal();
			int estado();
			void reset();
		};

	}
}