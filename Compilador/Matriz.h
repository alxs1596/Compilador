#pragma once

#include <map>
#include "Transicion.h"
#include <vector>
#include "Matriz.h"
#include "Tipos.h"
using namespace std;


class Matriz
{
public:
	Matriz();
	~Matriz();
	void preguntar(int , int );
	void insertar(int llave, int Kvalor, int Vvalor);
private:
	
	map<int, map<int,vector<int>>> *matrix;
	
};

