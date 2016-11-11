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
	T = 16,
	LT = 17,
	OP1 = 18,
	F = 19,
	LF = 20,
	OP2 = 21,
	SUBBS = 22,
	ELSE = 23, 
	OL = 24,
	C = 25,
	OP3 = 26,
	OP4 = 27,
	LOL = 28,
	LC = 29,
	//EXP = 16,


	Cantidad = 30
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
	ElementoGramatical* clonar() {
		return new NoTerminal(this->id);
	}
	int getID() { return id; }
};



