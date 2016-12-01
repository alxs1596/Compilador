#include "stdafx.h"
#include "EntradaTablaSimbolos.h"

using namespace compilador;

EntradaTablaSimbolos::EntradaTablaSimbolos(string lexema, int lineaDeclaracion , int offset)
{
	this->lexema = lexema;
	this->lineaDeclaracion = lineaDeclaracion;	
	this->offset = offset;
}


EntradaTablaSimbolos::~EntradaTablaSimbolos()
{
}
