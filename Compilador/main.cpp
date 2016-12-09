// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "AnalizadorLexico\AnalizadorLexico.h"
#include "AnalizadorSintactico\AnalizadorSintactico.h"
#include "AnalizadorSemantico\AnalizadorSemantico.h"
#include "CompiladorLib\Compilador.h"

#include <sstream>

using namespace compilador::lexico;
using namespace compilador::sintactico;


void imprimirTokens(vector<Token*> listaTokens)
{
	for (std::vector<Token*>::iterator it = listaTokens.begin(); it != listaTokens.end(); ++it)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}



int main(int argc,      // Number of strings in array argv  
	char *argv[],   // Array of command-line argument strings  
	char *envp[])  // Array of environment variable strings  
{

	if (argc < 2) {
		cout << "Ruta no ingresada" << endl;
		return 0;
	}

	string ruta = argv[1];

	Compilador compilador;
	compilador.compilar(ruta);

	

	
	//system("pause");
	return 0;

}