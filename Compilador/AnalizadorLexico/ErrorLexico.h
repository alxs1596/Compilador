#pragma once
#include "stdafx.h"

#include <string>

class ErrorLexico
{
public:

	ErrorLexico();
	~ErrorLexico();
	ErrorLexico(std::string mensaje, int linea, int);
	const std::string& getError() const;
	void setError(const std::string& error);
	int getLinea() const;
	void setLinea(int linea);
	int getCaracter() const;
	void setCaracter(int c);

private:
	std::string error;
	int lineaError;
	int caracter;

	
};

