#pragma once
#include <map>
using namespace std;
class Transicion
{
public:
	Transicion();
	~Transicion();
	

	void  insertarTransi(string llave,string valor);
private:
	map<string*, string*> _transi;
};

