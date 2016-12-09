#pragma once

#include "../CompiladorLib/Cuadruplo.h"
#include <vector>
#include "../AnalizadorSintactico/Terminal.h"
#include "ErrorSemantico.h"


using namespace std;

using namespace compilador;
using namespace compilador::sintactico;

namespace compilador {
	namespace semantico {
		class AnalizadorSemantico
		{
		public:

			bool error;

			vector <ErrorSemantico*> errores;

			int offset = 1;

			AnalizadorSemantico();
			~AnalizadorSemantico();

			void analizar(vector<Cuadruplo*>* cuadruplos);
		};

	}
}