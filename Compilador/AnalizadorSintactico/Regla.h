#pragma once

#include "NoTerminal.h"
#include "ElementoGramatical.h"
#include "../CompiladorLib/Cuadruplo.h"

using namespace compilador;

namespace compilador {
	namespace sintactico {

		class Regla
		{
		private:
			NoTerminal* noTerminal;
			vector<ElementoGramatical*>* produccion;
			ElementoGramatical** genera;

		public:
			Regla(NoTerminal*, vector<ElementoGramatical*>*);
			~Regla();

			vector<ElementoGramatical*>* getProduccion();
			NoTerminal* getNoTerminal();

		};

	}
}