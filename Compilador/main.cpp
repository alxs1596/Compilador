// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "Automata.h"

int main()
{

	AnalizadorLexico analizador;

	analizador.analizarProfe("Source.txt");
	
	analizador.imprimirTokens();
	analizador.imprimirErrores();

	system("pause");
    return 0;
}

/*
std::string codigo_fuente = "";


codigo_fuente += "Programa()\n";
codigo_fuente += "{\n";
codigo_fuente += "\tentero a,b,c,defg;\n";
codigo_fuente += "\tMientras(a+1>c)\n";
codigo_fuente += "\t{\n";
codigo_fuente += "\t\tentero d,z,o,\n";
codigo_fuente += "\t\tMientras(a<b)\n";
codigo_fuente += "\t\t{ //hola amigos\n";
codigo_fuente += "\t\t\tjojojo\n";
codigo_fuente += "\tabc}\n";
codigo_fuente += "\t}\n";
codigo_fuente += "}\n";

std::cout << codigo_fuente;

AnalizadorLexico analizadorLexico;

analizadorLexico.Analizar(codigo_fuente,1);

std::map<char, int> alfabeto;
int numeroEstados = 5;
std::vector<int> estadosFinales;
int estadoInicial = 0;
Matriz matriz;

alfabeto['a'] = Tipos::LETRA;
alfabeto['b'] = Tipos::LETRA;
alfabeto['c'] = Tipos::LETRA;
alfabeto['d'] = Tipos::LETRA;
alfabeto['e'] = Tipos::LETRA;
alfabeto['f'] = Tipos::LETRA;
alfabeto['g'] = Tipos::LETRA;
alfabeto['h'] = Tipos::LETRA;
alfabeto['i'] = Tipos::LETRA;
alfabeto['j'] = Tipos::LETRA;

//estadosFinales.push_back(0);
estadosFinales.push_back(3);
estadosFinales.push_back(4);

matriz[0][1] = new std::vector<int>();
matriz[0][1]->push_back(Tipos::LETRA);

Automata automata(alfabeto,numeroEstados,estadosFinales,estadoInicial,matriz);

automata.imprimir();

std::cout << automata.mover('a') << std::endl;
std::cout << automata.estado() << std::endl;
*/