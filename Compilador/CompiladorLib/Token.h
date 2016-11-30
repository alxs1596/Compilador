#pragma once

#include <string>
#include <map>
#include <sstream>

using namespace std;

namespace compilador {
	enum TipoToken
	{
		Identificador = 1,
		PalabraReservada = 2,
		Delimitador = 3,
		LiteralCadena = 4,
		ConstanteEntera = 5,
		Operador = 6,
		CometarioLinea = 7,
		ComentarioMultilinea = 8,

		Cuadruplos = 9
	};

	class Token
	{
	public:
		Token();
		~Token();

		Token(string lexema, TipoToken tipo_token, int linea);
		const string& getLexema() const;
		void setLexema(const string& lexema);
		TipoToken getTipo() const;
		void setTipo(TipoToken tipo);
		bool esIgual(Token*);
		int getLinea();

		string toString();

	private:
		std::string PalabraLexema;
		TipoToken Tipo;
		int linea;
	};

}