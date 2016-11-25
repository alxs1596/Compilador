#include "stdafx.h"
#include "TablaSimbolos.h"
#include <functional>

TablaSimbolos::TablaSimbolos(TablaSimbolos* padre)
{
	variables = new vector<EntradaTablaSimbolos>();
	padre = padre;
}


TablaSimbolos::~TablaSimbolos()
{
}

bool TablaSimbolos::fueDeclarada(string lexema)
{
	//buscar lexema en variables
	//si encuentra return true
	return padre->fueDeclarada(lexema);
}
