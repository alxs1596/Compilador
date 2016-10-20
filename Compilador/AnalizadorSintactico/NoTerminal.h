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
	EXP = 8,
	T = 9,
	LT = 10,
	OP1 = 11,
	F = 12,
	LF = 13,
	OP2 = 14,
	Cantidad = 15
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



