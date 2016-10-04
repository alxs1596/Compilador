#pragma once

#define LAMBDA 0

#include <vector>
#include <stack>
#include <map>

#include "../CompiladorLib/Token.h"
#include "ElementoGramatical.h"
#include "Terminal.h"
#include "NoTerminal.h"
#include "Regla.h"

using namespace std;

class AnalizadorSintactico
{
private:
	vector<Terminal*> terminales;
	//NoTerminal** noTerminales;
	NoTerminal* noTerminalBase;
	Regla** reglasGramaticales;
	int cantidadReglas;
	stack<ElementoGramatical*> pila;
	map<int, map< string, int> > matriz;

	void llenarReglas();
	void llenarMatriz();
	int buscarEnReglas(int, string);
	bool buscarRegla(int, ElementoGramatical*);
public:
	__declspec(dllexport) AnalizadorSintactico();
	__declspec(dllexport) ~AnalizadorSintactico();

	__declspec(dllexport) bool Analizar(vector<Token*>);
};

