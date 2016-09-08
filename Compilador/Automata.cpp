#include "stdafx.h"
#include "Automata.h"



Automata::Automata()
{
}

Automata::Automata(std::map<char, int> _alfabeto, int _numeroDeEstados, std::vector<int> _estadosFinales, int _estadoInicial, Matriz _matrizDeTransiciones)
{
	Alfabeto = _alfabeto;
	MatrizDeTransiciones = _matrizDeTransiciones;

	for (int i = 0; i < _numeroDeEstados; i++)
		Estados[i] = i;

	for (unsigned int i = 0; i < _estadosFinales.size(); i++)
	{
		EstadosFinales[_estadosFinales[i]] = &Estados[*EstadosFinales[i]];
	}

	EstadoInicial = &Estados[_estadoInicial];
}

Automata::~Automata()
{
}

bool Automata::mover(char c)
{
	return false;
}

bool Automata::esEstadoFinal()
{
	return false;
}

int Automata::estado()
{
	return 0;
}

void Automata::reset()
{
}

void Automata::imprimir()
{
	std::cout << "Alfabeto" << std::endl;
	for (std::map<char,int>::iterator it = Alfabeto.begin(); it != Alfabeto.end(); ++it)
		std::cout << it->first << ":" << it->second << std::endl;
	std::cout << "Estados" << std::endl;
	for (std::map<int, int>::iterator it = Estados.begin(); it != Estados.end(); ++it)
		std::cout << it->second << std::endl;
}

