#pragma once

#define LAMBDA 0

#include "Regla.h"
#include "NoTerminales.h"
#include "Terminales.h"

#include <vector>

using namespace std;

namespace compilador {
	namespace sintactico {

		class ReglasGramaticales {
		public:
			vector<Regla*> reglas;

			map<string, map< string, int> > matriz;

			ReglasGramaticales();

			Terminales _terminales;
			NoTerminales _noterminales;

		private:

			

			void llenarMatriz();
			int buscarEnReglas(string noTerminal, string terminal);
		};

	}
}



