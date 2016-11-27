#include "stdafx.h"
#include "TablaSimbolos.h"

using namespace compilador;

TablaSimbolos::TablaSimbolos(TablaSimbolos* padre)
{
	variables = new vector<EntradaTablaSimbolos>();
	this->padre = padre;
}


TablaSimbolos::~TablaSimbolos()
{
}

bool TablaSimbolos::fueDeclarada(string lexema)
{
	//buscar lexema en variables
	//si encuentra return true
	//return padre->fueDeclarada(lexema);
	return false;
}
