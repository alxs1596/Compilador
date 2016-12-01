#include "stdafx.h"
#include "TablaSimbolos.h"

using namespace compilador;

TablaSimbolos::TablaSimbolos(TablaSimbolos* padre)
{
	variables = new vector<EntradaTablaSimbolos*>();
	this->padre = padre;
}


TablaSimbolos::~TablaSimbolos()
{
}

EntradaTablaSimbolos* TablaSimbolos::fueDeclarada(string lexema)
{
	EntradaTablaSimbolos* res = nullptr;
	for (size_t i = 0; i < variables->size(); i++) {
		if ((*variables)[i]->lexema == lexema) {
			res = (*variables)[i];
			break;
		}
	}
	if (res != nullptr) return res;
	if (padre == nullptr) return nullptr;
	return padre->fueDeclarada(lexema);
}
