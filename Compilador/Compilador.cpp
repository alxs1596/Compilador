// Compilador.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include "Automata.h"

int main()
{

	std::map<char, int> alfabeto;
	int numeroEstados = 5;
	std::vector<int> estadosFinales;
	int estadoInicial = 0;
	Matriz matriz;


	//Alfabeto
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
	alfabeto['k'] = Tipos::LETRA;
	alfabeto['l'] = Tipos::LETRA;
	alfabeto['m'] = Tipos::LETRA;
	alfabeto['n'] = Tipos::LETRA;
	//alfabeto['ñ'] = Tipos::LETRA;
	alfabeto['o'] = Tipos::LETRA;
	alfabeto['p'] = Tipos::LETRA;
	alfabeto['q'] = Tipos::LETRA;
	alfabeto['r'] = Tipos::LETRA;
	alfabeto['s'] = Tipos::LETRA;
	alfabeto['t'] = Tipos::LETRA;
	alfabeto['u'] = Tipos::LETRA;
	alfabeto['v'] = Tipos::LETRA;
	alfabeto['w'] = Tipos::LETRA;
	alfabeto['x'] = Tipos::LETRA;
	alfabeto['y'] = Tipos::LETRA;
	alfabeto['z'] = Tipos::LETRA;
	alfabeto['A'] = Tipos::LETRA;
	alfabeto['B'] = Tipos::LETRA;
	alfabeto['C'] = Tipos::LETRA;
	alfabeto['D'] = Tipos::LETRA;
	alfabeto['E'] = Tipos::LETRA;
	alfabeto['F'] = Tipos::LETRA;
	alfabeto['G'] = Tipos::LETRA;
	alfabeto['H'] = Tipos::LETRA;
	alfabeto['I'] = Tipos::LETRA;
	alfabeto['J'] = Tipos::LETRA;
	alfabeto['K'] = Tipos::LETRA;
	alfabeto['L'] = Tipos::LETRA;
	alfabeto['M'] = Tipos::LETRA;
	alfabeto['N'] = Tipos::LETRA;
	//alfabeto['Ñ'] = Tipos::LETRA;
	alfabeto['O'] = Tipos::LETRA;
	alfabeto['P'] = Tipos::LETRA;
	alfabeto['Q'] = Tipos::LETRA;
	alfabeto['R'] = Tipos::LETRA;
	alfabeto['S'] = Tipos::LETRA;
	alfabeto['T'] = Tipos::LETRA;
	alfabeto['U'] = Tipos::LETRA;
	alfabeto['V'] = Tipos::LETRA;
	alfabeto['W'] = Tipos::LETRA;
	alfabeto['X'] = Tipos::LETRA;
	alfabeto['Y'] = Tipos::LETRA;
	alfabeto['Z'] = Tipos::LETRA;

	alfabeto['0'] = Tipos::NUMERO;
	alfabeto['1'] = Tipos::NUMERO;
	alfabeto['2'] = Tipos::NUMERO;
	alfabeto['3'] = Tipos::NUMERO;
	alfabeto['4'] = Tipos::NUMERO;
	alfabeto['5'] = Tipos::NUMERO;
	alfabeto['6'] = Tipos::NUMERO;
	alfabeto['7'] = Tipos::NUMERO;
	alfabeto['8'] = Tipos::NUMERO;
	alfabeto['9'] = Tipos::NUMERO;

	alfabeto['-'] = Tipos::OPERADOR;
	alfabeto['+'] = Tipos::OPERADOR;
	alfabeto['*'] = Tipos::OPERADOR;
	alfabeto['/'] = Tipos::OPERADOR;
	alfabeto['%'] = Tipos::OPERADOR;
	alfabeto['='] = Tipos::OPERADOR;
	alfabeto['<'] = Tipos::OPERADOR;
	alfabeto['>'] = Tipos::OPERADOR;
	alfabeto['=='] = Tipos::OPERADOR;
	alfabeto['>='] = Tipos::OPERADOR;
	alfabeto['<='] = Tipos::OPERADOR;

	alfabeto['('] = Tipos::DELIMITADOR;
	alfabeto[')'] = Tipos::DELIMITADOR;
	alfabeto['{'] = Tipos::DELIMITADOR;
	alfabeto['}'] = Tipos::DELIMITADOR;
	alfabeto[','] = Tipos::DELIMITADOR;
	alfabeto[';'] = Tipos::DELIMITADOR;

	alfabeto['"'] = Tipos::COMILLA;
	


	//estadosFinales
	estadosFinales.push_back(3);
	estadosFinales.push_back(4);

	//Matriz de transiciones
	matriz[0][1] = new std::vector<int>();
	matriz[0][1]->push_back(Tipos::LETRA);

	Automata automata(alfabeto, numeroEstados, estadosFinales, estadoInicial, matriz);

	automata.imprimir();

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