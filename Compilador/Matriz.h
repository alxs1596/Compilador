#pragma once

#include <map>

#include "Transicion.h"

class Matriz
{
public:
	Matriz();
	~Matriz();

private:

	std::map<int, std::map<int, Transicion*> > matriz;
	


};

