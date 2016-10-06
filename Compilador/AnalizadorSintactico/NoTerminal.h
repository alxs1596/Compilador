#pragma once

#include <string>
#include <map>

#include "ElementoGramatical.h"

using namespace std;

enum NoTerminales
{
	LS = 0,
	S = 1,
	SD = 2,
	RD = 3,
	VA = 4,
	A = 5,
	TD = 6,
	EM = 7,
	Cantidad = 8
};

class NoTerminal :
	public ElementoGramatical
{
private:
	int id;
	//int descripcion;
public:
	NoTerminal(int id) :ElementoGramatical(NOTERMINAL), id(id) {}
	~NoTerminal();

	int getID() { return id; }
};



