#pragma once
class Automata
{
public:
	Automata();
	~Automata();

	bool mover(char c);
	bool esEstadoFinal();
	int estado();
	void reset();
};

