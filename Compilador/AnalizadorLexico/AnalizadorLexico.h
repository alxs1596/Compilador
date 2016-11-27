#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <streambuf>
#include <map>

#include "Automata.h"
#include "../CompiladorLib/Tipos.h"
#include "../CompiladorLib/Token.h"
#include "ErrorLexico.h"

using namespace std;
namespace compilador {
	namespace lexico {
		class AnalizadorLexico
		{
		public:
			AnalizadorLexico();
			~AnalizadorLexico();
			void imprimirErrores();

			vector<Token*> analizar(string codigoFuente);

			bool getError() { return error; }

			string leerArchivo(string rutaArchivo);

		private:

			bool error;

			Automata automata;
			vector<std::string> listaPalabrasReservadas;
			vector<ErrorLexico*> listaErrorLexico;

			void cargarDatos();
			void EliminarBlancos(string, int& index, int& linea);
			TipoToken MapeaEstadoATipoToken(int estado);
			bool BuscarEnPalabrasReservadas(string palabra);

			

		};
	}
}