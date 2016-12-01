#pragma once

#include "../AnalizadorSintactico/AnalizadorSintactico.h"

using namespace compilador::sintactico;

class Compilador
{
public:
	Compilador();
	~Compilador();
	string generarCodigo(vector<Cuadruplo*> cuadruplos);
};

