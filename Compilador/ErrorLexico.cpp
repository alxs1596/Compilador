#include "ErrorLexico.h"


ErrorLexico::ErrorLexico()
{
}


ErrorLexico::~ErrorLexico()
{
}

ErrorLexico::ErrorLexico(std::string mensaje, int linea)
{
	error = mensaje;
	lineaError = linea;
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