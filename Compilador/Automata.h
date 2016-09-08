#pragma once

#include <map>
#include <vector>

// Matriz
typedef std::map<int, std::map<int, std::vector<int> > > Matriz;


class Automata
{

public:
	
	Automata();
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

