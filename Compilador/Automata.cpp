#include "stdafx.h"
#include "Automata.h"



Automata::Automata(std::map<char, int> _alfabeto, int _numeroDeEstados, std::vector<int> _estadosFinales, int _estadoInicial, Matriz _matrizDeTransiciones)
{
	Alfabeto = _alfabeto;
	MatrizDeTransiciones = _matrizDeTransiciones;

	for (int i = 0; i < _numeroDeEstados; i++)
		Estados.insert(i, i);
	
	for (std::vector<int>::iterator it = _estadosFinales.begin; it != _estadosFinales.end(); ++it)
	{
		EstadosFinales.insert(*it, Estados[*it]);
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
	for (std::map<char,int>::iterator it = Alfabeto.begin(); it != Alfabeto.end(); ++it)
	{
		std::cout << it->first;
	}
}

