#pragma once

#include <map>
#include <vector>

#include "Matriz.h"


class Automata
{
public:
	Automata(std::map<char, int>, int, std::vector<int>, int, Matriz);
	~Automata();

	bool mover(char c);
	bool esEstadoFinal();
	int estado();
	void reset();
	void imprimir();
private:
	// Matriz de Transiciones
	Matriz MatrizDeTransiciones;
	// Conjunto de Estados
	std::map<int, int> Estados;
	// Conjunto de estados Finales
	std::map<int, int*> EstadosFinales;
	// Estado Inicial
	int* EstadoInicial;
	// Alfabeto
	std::map<char, int> Alfabeto;
};

