#pragma once

#include "../CompiladorLib/Cuadruplo.h"
#include <vector>

using namespace std;

using namespace compilador;

class AnalizadorSemantico
{
public:

	int offset = 1;

	AnalizadorSemantico();
	~AnalizadorSemantico();

	void analizar(vector<Cuadruplo*>* cuadruplos);
};

