#pragma once
class ErrorLexico
{
public:
	ErrorLexico();
	~ErrorLexico();

	ErrorLexico(std::string mensaje, int linea);
};

