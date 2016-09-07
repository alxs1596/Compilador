// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "Automata.h"

int main()
{

	std::string codigo_fuente = "";
		
		
	codigo_fuente += "Programa()\n";
	codigo_fuente += "{\n";
	codigo_fuente += "\tentero a,b,c,defg;\n";
	codigo_fuente += "\tMientras(a+1>c)\n";
	codigo_fuente += "\t{\n";
	codigo_fuente += "\t\tentero d,z,o,\n";
	codigo_fuente += "\t\tMientras(a<b)\n";
	codigo_fuente += "\t\t{ //hola amigos\n";
	codigo_fuente += "\t\t\t/*jojojo\n";
	codigo_fuente += "\tabc*/}\n";
	codigo_fuente += "\t}\n";
	codigo_fuente += "}\n";
		
	std::cout << codigo_fuente;

	AnalizadorLexico analizadorLexico;

	analizadorLexico.Analizar(codigo_fuente,1);

	std::map<char, int> alfabeto;
	int numeroEstados;
	std::vector<int> estadosFinales;
	int estadoInicial;
	Matriz matriz;

	Automata automata(alfabeto,numeroEstados,estadosFinales,estadoInicial,matriz);

	

	system("pause");
    return 0;
}

