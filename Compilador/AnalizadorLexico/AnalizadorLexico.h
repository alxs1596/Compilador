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
			std::vector<Token*> ejecutar(std::string);
			void imprimirTokens();
			void imprimirErrores();

			std::vector<Token*> analizar(string codigoFuente);

			bool getError() { return error; }

		private:

			bool error;

			Automata automata;
			std::string buffer;
			std::vector<std::string> listaPalabrasReservadas;
			std::vector<Token*> listaTokens;
			std::vector<ErrorLexico*> listaErrorLexico;
			std::map<int, TipoToken> EstadoAToken;
			std::map<int, std::string > TOKENS;

			bool comentario;

			void cargarDatos();
			void EliminarBlancos(std::string, int& index, int& linea);
			TipoToken MapeaEstadoATipoToken(int estado);
			bool BuscarEnPalabrasReservadas(std::string palabra);

			/////////////////////////////////////////////

			string leerArchivo(string rutaArchivo);
			//private:

		};
	}
}