#pragma once

#include <string>

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
		ComentarioMultilinea = 8
	};

	class Token
	{
	public:
		Token();
		~Token();

		Token(std::string lexema, int tipo_token, int linea);
		const std::string& getLexema() const;
		void setLexema(const std::string& lexema);
		int getTipo() const;
		void setTipo(int tipo);
		bool esIgual(Token*);
		int getLinea();
	private:
		std::string PalabraLexema;
		int Tipo;
		int linea;
	};

}