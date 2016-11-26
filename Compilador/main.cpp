// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "AnalizadorLexico\AnalizadorLexico.h"
#include "AnalizadorSintactico\AnalizadorSintactico.h"

#include <sstream>

using namespace compilador;
using namespace lexico;

int main()
{

	AnalizadorLexico analizador;

	

	std::vector<Token*> vectorToken = analizador.ejecutar("Source.txt");
	//analizador.ejecutar("Source.txt");
	//analizador.dibujarAutomata();
	analizador.imprimirTokens();

	AnalizadorSintactico analizadorSintactico;

	//analizadorSintactico.imprimirReglas();
	
	bool res = analizadorSintactico.Analizar(vectorToken);

	cout << (res == true ? "True" : "False") << std::endl;

	analizadorSintactico.imprimirCuadruplos();
	

	system("pause");
	return 0;

}