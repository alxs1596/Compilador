#include "stdafx.h"
#include "Alfabeto.h"

//using namespace util;
using namespace compilador::lexico;

Alfabeto::Alfabeto()
{

	letras = new vector<char>();
	numeros = new vector<char>();
	operadores = new vector<char>();
	delimitadores = new vector<char>();
	todo = new vector<char>();
	blancos = new vector<char>();

	letras->push_back('a');
	letras->push_back('b');
	letras->push_back('c');
	letras->push_back('d');
	letras->push_back('e');
	letras->push_back('f');
	letras->push_back('g');
	letras->push_back('h');
	letras->push_back('i');
	letras->push_back('j');
	letras->push_back('k');
	letras->push_back('l');
	letras->push_back('m');
	letras->push_back('n');
	letras->push_back('o');
	letras->push_back('p');
	letras->push_back('q');
	letras->push_back('r');
	letras->push_back('s');
	letras->push_back('t');
	letras->push_back('u');
	letras->push_back('v');
	letras->push_back('w');
	letras->push_back('x');
	letras->push_back('y');
	letras->push_back('z');
	letras->push_back('A');
	letras->push_back('B');
	letras->push_back('C');
	letras->push_back('D');
	letras->push_back('E');
	letras->push_back('F');
	letras->push_back('G');
	letras->push_back('H');
	letras->push_back('I');
	letras->push_back('J');
	letras->push_back('K');
	letras->push_back('L');
	letras->push_back('M');
	letras->push_back('N');
	letras->push_back('O');
	letras->push_back('P');
	letras->push_back('Q');
	letras->push_back('R');
	letras->push_back('S');
	letras->push_back('T');
	letras->push_back('U');
	letras->push_back('V');
	letras->push_back('W');
	letras->push_back('X');
	letras->push_back('Y');
	letras->push_back('Z');

	numeros->push_back('0');
	numeros->push_back('1');
	numeros->push_back('2');
	numeros->push_back('3');
	numeros->push_back('4');
	numeros->push_back('5');
	numeros->push_back('6');
	numeros->push_back('7');
	numeros->push_back('8');
	numeros->push_back('9');

	operadores->push_back('-');
	operadores->push_back('+');
	operadores->push_back('*');
	operadores->push_back('%');
	operadores->push_back('/');
	operadores->push_back('=');
	operadores->push_back('<');
	operadores->push_back('>');
	operadores->push_back('!');
	operadores->push_back('|');
	operadores->push_back('&');

	/*alfabeto[' '] = Tipos::BLANCO;
	alfabeto['\n'] = Tipos::SALTO_LINEA;
	alfabeto['\t'] = Tipos::BLANCO;*/

	delimitadores->push_back('(');
	delimitadores->push_back(')');
	delimitadores->push_back('{');
	delimitadores->push_back('}');
	delimitadores->push_back(',');
	delimitadores->push_back(';');


	blancos->push_back(' ');
	blancos->push_back('\t');
	blancos->push_back('\n');

	//alfabeto['"'] = Tipos::COMILLA;

	//alfabeto['*'] = Tipos::ASTERISCO;

	agregarVectorAVector(todo, letras);
	agregarVectorAVector(todo, delimitadores);
	agregarVectorAVector(todo, operadores);
	agregarVectorAVector(todo, numeros);
	agregarVectorAVector(todo, blancos);
	todo->push_back('"');

	//todo->insert(todo->end(), letras->begin(), letras->end());
	//todo->insert(todo->end(), delimitadores->begin(), delimitadores->end());
	//todo->insert(todo->end(), operadores->begin(), operadores->end());
	//todo->insert(todo->end(), numeros->begin(), numeros->end());

	//sort(todo->begin(), todo->end());

	ordenar(letras);
	ordenar(delimitadores);
	ordenar(operadores);
	ordenar(numeros);
	ordenar(blancos);
	ordenar(todo);

}


Alfabeto::~Alfabeto()
{
}

void Alfabeto::agregarVectorAVector(vector<char>* a, vector<char>* b)
{
	a->insert(a->end(), b->begin(), b->end());
}

vector<char>* compilador::lexico::Alfabeto::VectorMenos(vector<char>* a, vector<char> b)
{
	vector<char>* nuevo = new vector<char>();
	agregarVectorAVector(nuevo, a);
	for (size_t i = 0; i < b.size(); i++) {
		nuevo->erase(std::find(nuevo->begin(), nuevo->end(), b[i]));
	}
	return nuevo;
}

vector<char>* compilador::lexico::Alfabeto::VectorMenos(vector<char>* a, char b)
{
	vector<char>* nuevo = new vector<char>();
	agregarVectorAVector(nuevo, a);
	nuevo->erase(std::find(nuevo->begin(), nuevo->end(), b));
	return nuevo;
}

void compilador::lexico::Alfabeto::ordenar(vector<char>* v)
{
	sort(v->begin(), v->end());
}

vector<char>* compilador::lexico::Alfabeto::Letras()
{
	return letras;
}

vector<char>* compilador::lexico::Alfabeto::Delimitadores()
{
	return delimitadores;
}

vector<char>* compilador::lexico::Alfabeto::Operadores()
{
	return operadores;
}

vector<char>* compilador::lexico::Alfabeto::Numeros()
{
	return numeros;
}

vector<char>* compilador::lexico::Alfabeto::Todo()
{
	return todo;
}

vector<char>* compilador::lexico::Alfabeto::Blancos()
{
	return blancos;
}

