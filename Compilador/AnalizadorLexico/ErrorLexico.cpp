#include "stdafx.h"
#include "ErrorLexico.h"


ErrorLexico::ErrorLexico()
{
}


ErrorLexico::~ErrorLexico()
{
}

ErrorLexico::ErrorLexico(std::string mensaje, int linea, int _caracter)
{
	mensaje.pop_back();
	error = mensaje;
	lineaError = linea;
	caracter = _caracter;
}

void ErrorLexico::setError(const std::string& er) 
{
	error = er;
}

const std::string& ErrorLexico::getError() const
{
	return error;
}

int ErrorLexico::getLinea() const
{
	return lineaError;
}

void ErrorLexico::setLinea(int linea)
{
	lineaError = linea;
}

int ErrorLexico::getCaracter() const
{
	return caracter;
}

void ErrorLexico::setCaracter(int c)
{
	caracter = c;
}
