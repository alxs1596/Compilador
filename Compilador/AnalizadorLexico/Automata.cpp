#include "stdafx.h"
#include "Automata.h"



Automata::Automata()
{
	conjuntoEstadosFinales[1] = TipoToken::Identificador;
	conjuntoEstadosFinales[2] = TipoToken::ConstanteEntera;
	conjuntoEstadosFinales[3] = TipoToken::Operador;
	conjuntoEstadosFinales[9] = TipoToken::Delimitador;
	conjuntoEstadosFinales[5] = TipoToken::Operador;
	conjuntoEstadosFinales[6] = TipoToken::Operador;
	conjuntoEstadosFinales[7] = TipoToken::Operador;
	conjuntoEstadosFinales[8] = TipoToken::Operador;
	conjuntoEstadosFinales[11] = TipoToken::LiteralCadena;
}

Automata::Automata(std::map<char, int> _alfabeto, int _numeroDeEstados, std::vector<int> _estadosFinales, int _estadoInicial, Matriz _matrizDeTransiciones)
{
	
	Alfabeto = _alfabeto;
	MatrizDeTransiciones = _matrizDeTransiciones;

	for (int i = 0; i < _numeroDeEstados; i++)
		Estados[i] = i;

	for (unsigned int i = 0; i < _estadosFinales.size(); i++)
	{
		//int* p = &Estados[_estadosFinales[i]];
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

	for (int i = 0; i < Estados.size(); i++)
		if (MatrizDeTransiciones[*EstadoActual][i] != 0)
		if (std::binary_search(MatrizDeTransiciones[*EstadoActual][i]->begin(), MatrizDeTransiciones[*EstadoActual][i]->end(), Alfabeto[c])) 
		{
				EstadoActual = &Estados[i];
				return true;
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
	EstadoActual = EstadoInicial;
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

TipoToken Automata::obtenerTipo()
{
	return conjuntoEstadosFinales[estado()];
}

void Automata::dibujarAutomata()
{
	std::map<int, std::string> T;
	T[7] = "LETRA";
	T[8] = "NUMERO";
	T[9] = "OPERADOR";
	T[10] = "DELIMITADOR";
	T[11] = "\\\"";
	T[12] = "!";
	T[13] = "=";
	T[14] = ">";
	T[15] = "<";

	std::ofstream archivo;
	archivo.open("automata.gv");
	archivo << "digraph{" << std::endl;

	archivo << *EstadoInicial << "[color=red]" << std::endl;

	for (std::map<int, int*>::iterator it = ++EstadosFinales.begin(); it != EstadosFinales.end(); ++it) {
		archivo << it->first << "[color=blue]" << std::endl;
	}

	for (unsigned int i = 0; i < Estados.size(); i++) {
		for (unsigned int j = 0; j < Estados.size(); j++) {
			if (MatrizDeTransiciones[i][j] != nullptr) {
				archivo << i << " -> " << j << " [label=\"";
				for (unsigned int k = 0; k < MatrizDeTransiciones[i][j]->size(); k++) {
					archivo << T[((*MatrizDeTransiciones[i][j])[k])] << ",";
				}
				archivo << "\"]" << std::endl;
			}
		}
	}

	archivo << "}" << std::endl;
	archivo.close();

	system("dot -Tpng automata.gv -o automata.png");
	system("automata.png");

}

