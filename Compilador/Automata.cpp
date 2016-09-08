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
		EstadosFinales[_estadosFinales[i]] = &Estados[_estadosFinales[i]];
	}

	EstadoInicial = &Estados[_estadoInicial];

	EstadoActual = EstadoInicial;
}

Automata::~Automata()
{
}

bool Automata::mover(char c)
{
	bool sePuedeMover = false;

	for (int i = 0; i < Estados.size(); i++) {
		if (std::binary_search(MatrizDeTransiciones[*EstadoActual][i]->begin(), MatrizDeTransiciones[*EstadoActual][i]->end(), Alfabeto[c])) {
			EstadoActual = &Estados[i];
			return true;
		}
	}

	return false;
}

bool Automata::esEstadoFinal()
{
	return EstadosFinales[*EstadoActual] == EstadoActual;
}

int Automata::estado()
{
	return *EstadoActual;
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
		std::cout << it->first << ":" << &(it->second) << std::endl;
	std::cout << "Estados finales" << std::endl;
	for (std::map<int, int*>::iterator it = EstadosFinales.begin(); it != EstadosFinales.end(); ++it)
		std::cout << it->first << ":" << it->second << std::endl;
	std::cout << "Estado Inicial" << std::endl;
	std::cout << *EstadoInicial << ":" << EstadoInicial << std::endl;
	std::cout << "Matriz de Transiciones" << std::endl;
	for (int i = 0; i < Estados.size(); i++) {
		for (int j = 0; j < Estados.size(); j++) {
			if (MatrizDeTransiciones[i][j] == 0) {
				std::cout << "N" << " ";
			}
			else
			{
				for (int k = 0; k < MatrizDeTransiciones[i][j]->size(); k++)
					std::cout << MatrizDeTransiciones[i][j]->operator[](k) << " ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	
}

