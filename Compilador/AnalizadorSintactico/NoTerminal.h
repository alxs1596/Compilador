#pragma once

#include <string>
#include <map>

#include "ElementoGramatical.h"

using namespace std;

enum NoTerminales
{
	P = 0,
	BS = 1,
	LS = 2,
	S = 3,
	SD = 4,
	SA = 5,
	SC = 6,
	SM = 7, 
	SL = 8,
	SE = 9,
	SHM = 10,
	TD = 11,
	VA = 12,
	RD = 13,
	A = 14,
	EM = 15,
	EXP = 16,
	T = 17,
	LT = 18,
	OP1 = 19,
	F = 20,
	LF = 21,
	OP2 = 22,
	SUBBS = 23,
	ELSE = 24, 
	OL = 25,
	C = 26,
	OP3 = 27,
	OP4 = 28,


	Cantidad = 29
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



