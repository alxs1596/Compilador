#include "stdafx.h"
#include "Terminales.h"

using namespace compilador::sintactico;

vector<Terminal*>* Terminales::Todos()
{
	auto r = new vector<Terminal*>();
	r->push_back(Programa);
	r->push_back(ParentesisAbierto);
	r->push_back(ParentesisCerrado);
	r->push_back(CorchetesAbierto);
	r->push_back(CorchetesCerrado);
	r->push_back(PuntoYComa);
	r->push_back(Entero);
	r->push_back(Coma);
	r->push_back(Id);
	r->push_back(Igual);
	r->push_back(Mientras);
	r->push_back(Si);
	r->push_back(Osino);
	r->push_back(LeerTeclado);
	r->push_back(EscribirPantalla);
	r->push_back(Hacer);
	r->push_back(Mas);
	r->push_back(Menos);
	r->push_back(Numero);
	r->push_back(Por);
	r->push_back(Entre);
	r->push_back(Modulo);
	r->push_back(MenorIgual);
	r->push_back(MayorIgual);
	r->push_back(IgualIgual);
	r->push_back(Diferente);
	r->push_back(Menor);
	r->push_back(Mayor);
	r->push_back(Or);
	r->push_back(And);

	return r;

}