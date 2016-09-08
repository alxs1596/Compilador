#pragma once
#include "stdafx.h"

class ErrorLexico
{
public:

	ErrorLexico();
	~ErrorLexico();
	ErrorLexico(std::string mensaje, int linea);
	const std::string& getError() const;
	void setError(const std::string& error);
	int getLinea() const;
	void setLinea(int linea);

private:
	std::string error;
	int lineaError;

	
};

