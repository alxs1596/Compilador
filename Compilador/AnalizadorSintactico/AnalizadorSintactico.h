#pragma once

#include <stack>
#include <iostream>

#include "../CompiladorLib/Token.h"
#include "../CompiladorLib/Cuadruplo.h"
#include "ErrorSintactico.h"
#include "ReglasGramaticales.h"


using namespace std;

namespace compilador {
	namespace sintactico {

		class AnalizadorSintactico
		{
		private:

			bool error;

			ReglasGramaticales reglasGramaticales;

			vector<ErrorSintactico*> listaErrores;

			stack<ElementoGramatical*> pila;
			vector<Cuadruplo*> listaCuadruplos;
			vector<Cuadruplo*> listaCuadruplosTemporal;

			bool voltear;
			int voltearDesde;
			int voltearHasta;

			Terminal* mientras;
			Terminal* si;
			Terminal* osino;

			TablaSimbolos* bloquePadre;
			TablaSimbolos* bloqueActual;
			int nbloque;

			void llenarReglas();
			void vaciarPila();
			void llenarCuadruplos(int nregla, vector<ElementoGramatical*> produccion, vector<Terminal*>* entrada, int i, ElementoGramatical* tope);
			void bloques(int linea, int regla);
			void voltearTemporal(int desde, int hasta);
			void optimizar();

			void buscarCuadruploAsignarOperadorFaltante(ElementoGramatical* tope, Terminal* terminalEntrada);
			void buscarCuadruploCambiarOperacionPorAsignacion(ElementoGramatical* tope);
		public:
			AnalizadorSintactico();
			~AnalizadorSintactico();

			bool Analizar(vector<Token*>);

			vector <Cuadruplo*> Cuadruplos();

			void imprimirReglas();

			void imprimirPila();

			void imprimirCuadruplos();

			bool getError() { return error; }
		};
	}
}