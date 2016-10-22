#pragma once

#include <string>


enum TipoToken
{
	Identificador,
	PalabraReservada,
	Delimitador,
	LiteralCadena,
	ConstanteEntera,
	Operador
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

