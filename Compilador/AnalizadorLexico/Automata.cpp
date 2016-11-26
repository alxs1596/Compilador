#include "stdafx.h"
#include "Automata.h"

using namespace compilador;
using namespace compilador::lexico;

void Automata::llenarMatriz()
{

	for (int i = 0; i < numeroDeEstados; i++) {
		for (int j = 0; j < numeroDeEstados; j++) {
			matriz[i][j] = new vector<char>();
		}
	}

	Alfabeto::agregarVectorAVector(matriz[0][1], alfabeto.Letras());

	Alfabeto::agregarVectorAVector(matriz[1][1], alfabeto.Letras());
	Alfabeto::agregarVectorAVector(matriz[1][1], alfabeto.Numeros());
	Alfabeto::ordenar(matriz[1][1]);

	Alfabeto::agregarVectorAVector(matriz[0][2], alfabeto.Numeros());

	Alfabeto::agregarVectorAVector(matriz[2][2], alfabeto.Numeros());

	matriz[0][3]->push_back('+');
	matriz[0][3]->push_back('-');
	matriz[0][3]->push_back('*');
	matriz[0][3]->push_back('%');
	Alfabeto::ordenar(matriz[0][3]);

	matriz[0][4]->push_back('!');

	matriz[4][3]->push_back('=');

	matriz[0][5]->push_back('<');

	matriz[5][3]->push_back('=');

	matriz[0][6]->push_back('>');

	matriz[6][3]->push_back('=');

	matriz[0][7]->push_back('=');

	matriz[7][3]->push_back('=');

	Alfabeto::agregarVectorAVector(matriz[0][8], alfabeto.Delimitadores());

	matriz[0][9]->push_back('"');

	delete matriz[9][9];
	matriz[9][9] = NULL;
	matriz[9][9] = Alfabeto::VectorMenos(alfabeto.Todo(), '"');

	matriz[9][10]->push_back('"');

	matriz[0][11]->push_back('|');

	matriz[11][3]->push_back('|');

	matriz[0][12]->push_back('&');

	matriz[12][3]->push_back('&');

	matriz[0][13]->push_back('/');

	matriz[13][14]->push_back('/');

	delete matriz[14][14];
	matriz[14][14] = NULL;
	matriz[14][14] = Alfabeto::VectorMenos(alfabeto.Todo(), '\n');

	matriz[14][18]->push_back('\n');

	matriz[13][15]->push_back('*');

	delete matriz[15][15];
	matriz[15][15] = NULL;
	matriz[15][15] = Alfabeto::VectorMenos(alfabeto.Todo(), '*');

	matriz[15][16]->push_back('*');

	delete matriz[16][15];
	matriz[16][15] = NULL;
	matriz[16][15] = Alfabeto::VectorMenos(alfabeto.Todo(), '/');

	matriz[16][17]->push_back('/');
}

Automata::Automata()
{
	numeroDeEstados = 19;
	llenarMatriz();
}

Automata::~Automata()
{
}

bool Automata::mover(char c)
{
	bool res = false;
	for (int i = 0; i < numeroDeEstados; i++)
	{
		if (matriz[EstadoActual][i]->size() != 0)
		{
			auto v = matriz[EstadoActual][i];
			bool encontrado = binary_search(v->begin(), v->end(), c);
			if (encontrado)
			{
				EstadoActual = i;
				res = true;
				break;
			}
		}
	}
	return res;
}

bool Automata::esEstadoFinal()
{
	switch (EstadoActual)
	{
	case 1:
	case 2:
	case 3:
	case 5:
	case 6:
	case 7:
	case 8:
	case 10:
	case 13:
	case 17:
	case 18:
		return true;
	default:
		return false;
	}
}

int Automata::estado()
{
	return EstadoActual;
}

void Automata::reset()
{
	EstadoActual = 0;
}


