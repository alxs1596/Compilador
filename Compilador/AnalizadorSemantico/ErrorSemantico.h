#pragma once

#include <string>

using namespace std;

class ErrorSemantico
{
public:
	string error;
	int linea;
	ErrorSemantico(string e, int l) :error(e), linea(l) {}
	~ErrorSemantico();
};

