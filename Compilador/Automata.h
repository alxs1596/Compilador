#pragma once

#include <map>
class Automata
{
public:
	Automata();
	~Automata();



	bool mover(char c);
	bool esEstadoFinal();
	int estado();
	void reset();

private:
	typedef std::map<int, std::map<int, std::vector<int> > > Matriz;
};

