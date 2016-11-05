#pragma once

#define LAMBDA 0

#include <vector>
#include <stack>
#include <map>
#include <iostream>

#include "../CompiladorLib/Token.h"
#include "ElementoGramatical.h"
#include "Terminal.h"
#include "NoTerminal.h"
#include "Regla.h"
#include "Cuadruplo.h"

using namespace std;

class AnalizadorSintactico
{
private:
	map<int, string> NombresNoTerminales;
	vector<Terminal*> terminales;
	NoTerminal* noTerminalBase;
	Regla** reglasGramaticales;
	int cantidadReglas;
	stack<ElementoGramatical*> pila;
	map<int, map< string, int> > matriz;
	vector<Cuadruplo*> listaCuadruplos;
	vector<Cuadruplo*> listaCuadruplosTemporal;

	bool voltear;

	void llenarReglas();
	void llenarMatriz();
	int buscarEnReglas(int, string);
	bool buscarRegla(int, ElementoGramatical*);
	void llenarNombresNoTerminales();
	void vaciarPila();
	void llenarCuadruplos(int nregla, Terminal* terminal);
public:
	AnalizadorSintactico();
	~AnalizadorSintactico();

	bool Analizar(vector<Token*>);

	void imprimirReglas();

	void imprimirCuadruplos();
};

