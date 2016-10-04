#pragma once

#include <string>

#include "ElementoGramatical.h"
#include "../CompiladorLib/Token.h"

using namespace std;

class Terminal :
	public ElementoGramatical
{
private:
	string id;
	Token* token;
public:
	Terminal(Token* token) :ElementoGramatical(TERMINAL) 
	{ 
		this->token = token; 
		id = token->getLexema();
		if (token->getTipo() == TipoToken::Identificador)
			id = "id";
		if (token->getTipo() == TipoToken::ConstanteEntera)
			id = "Numero";
				
	}
	~Terminal();

	Token* getToken() { return token; }
	string getID() { return id; }
};

