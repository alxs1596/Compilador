// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "AnalizadorLexico\AnalizadorLexico.h"
#include "AnalizadorSintactico\AnalizadorSintactico.h"

#include <sstream>

using namespace compilador;
using namespace lexico;

void imprimirTokens(vector<Token*> listaTokens)
{
	

	for (std::vector<Token*>::iterator it = listaTokens.begin(); it != listaTokens.end(); ++it)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

int main()
{

	AnalizadorLexico lexico;

	string codigoFuente = lexico.leerArchivo("Source.txt");

	auto tokens = lexico.analizar(codigoFuente);

	imprimirTokens(tokens);

	AnalizadorSintactico sintactico;
	
	auto cuadruplos = sintactico.Analizar(tokens);

	cout << (sintactico.getError() == true ? "True" : "False") << std::endl;

	sintactico.imprimirCuadruplos();
	

	system("pause");
	return 0;

}