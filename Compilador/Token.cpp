#include "stdafx.h"
#include "Token.h"


Token::Token()
{
}


Token::~Token()
{
}

Token::Token(std::string lexema, int tipo_token)
{
	PalabraLexema = lexema;
	Tipo = tipo_token;
}

const std::string& Token::getLexema() const 
{
	return PalabraLexema;
}

void Token::setLexema(const std::string& lexema)
{
	PalabraLexema = lexema;
}

int Token::getTipo() const
{
	return Tipo;
}

void Token::setTipo(int tipo)
{
	Tipo = tipo;
}