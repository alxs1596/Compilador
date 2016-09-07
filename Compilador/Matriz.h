#pragma once

#include <map>

#include "Matriz.h"

class Matriz
{
public:
	Matriz();
	~Matriz();

private:

	std::map<int, std::map<int, Transicion> > matriz;


};

