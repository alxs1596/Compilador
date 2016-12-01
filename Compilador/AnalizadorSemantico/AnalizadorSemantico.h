#pragma once

#include "../CompiladorLib/Cuadruplo.h"
#include <vector>
#include "../AnalizadorSintactico/Terminal.h"


using namespace std;

using namespace compilador;
using namespace compilador::sintactico;

class AnalizadorSemantico
{
public:

	int offset = 1;

	AnalizadorSemantico();
	~AnalizadorSemantico();

	void analizar(vector<Cuadruplo*>* cuadruplos);
};

