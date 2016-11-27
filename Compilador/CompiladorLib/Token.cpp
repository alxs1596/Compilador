#include "stdafx.h"
#include "Token.h"

using namespace compilador;

Token::Token()
{
}


Token::~Token()
{
}

Token::Token(std::string lexema, TipoToken tipo_token, int linea)
{
	PalabraLexema = lexema;
	Tipo = tipo_token;
	this->linea = linea;
}

const std::string& Token::getLexema() const 
{
	return PalabraLexema;
}

void Token::setLexema(const std::string& lexema)
{
	PalabraLexema = lexema;
}

TipoToken Token::getTipo() const
{
	return Tipo;
}

void Token::setTipo(TipoToken tipo)
{
	Tipo = tipo;
}

bool Token::esIgual(Token * otroToken)
{
	if (this->Tipo == TipoToken::Identificador)
		return this->Tipo == otroToken->getTipo();
	else if (this->Tipo == TipoToken::ConstanteEntera)
	{
		return this->Tipo == otroToken->getTipo();
	}
	else {
		return ((this->Tipo == otroToken->getTipo()) && (this->PalabraLexema == otroToken->getLexema()));
	}
}

int Token::getLinea()
{
	return linea;
}

string Token::toString() {
	map<TipoToken, std::string > TOKENS;
	TOKENS[TipoToken::Identificador] = "TOKEN_IDENTIFICADOR";
	TOKENS[TipoToken::PalabraReservada] = "TOKEN_PALABRA_RESERVADA";
	TOKENS[TipoToken::LiteralCadena] = "TOKEN_LITERAL_DE_CADENA";
	TOKENS[TipoToken::ConstanteEntera] = "TOKEN_VARIABLE_ENTERA";
	TOKENS[TipoToken::Delimitador] = "TOKEN_DELIMITADOR";
	TOKENS[TipoToken::Operador] = "TOKEN_OPERADOR";
	TOKENS[TipoToken::CometarioLinea] = "TOKEN_COMENTARIO_LINEA";
	TOKENS[TipoToken::ComentarioMultilinea] = "TOKEN_COMENTARIO_MULTILINEA";

	stringstream ss;

	ss << this->PalabraLexema << "\t\t" << TOKENS[Tipo];
	
	return ss.str();
}