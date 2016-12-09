#include "stdafx.h"
#include "Cuadruplo.h"

using namespace compilador;
using namespace sintactico;

Cuadruplo * Cuadruplo::clonar()
{
	Cuadruplo* c = new Cuadruplo();
	
	if (Resultado != 0) {
		if (Resultado->getTipo() == TERMINAL) {
			Terminal* res = (Terminal*)Resultado;
			c->Resultado = res->clonar();
		}
		else {
			NoTerminal* res = (NoTerminal*)Resultado;
			c->Resultado = res->clonar();
		}
	}

	if (Operando1 != 0) {
		if (Operando1->getTipo() == TERMINAL) {
			Terminal* op1 = (Terminal*)Operando1;
			c->Operando1 = op1->clonar();
		}
		else {
			NoTerminal* op1 = (NoTerminal*)Operando1;
			c->Operando1 = op1->clonar();
		}
	}

	if (Operador != 0) {
		Terminal* op = (Terminal*)Operador;
		c->Operador = op->clonar();
	}

	if (Operando2 != 0) {
		if (Operando2->getTipo() == TERMINAL) {
			Terminal* op2 = (Terminal*)Operando2;
			c->Operando2 = op2->clonar();
		}
		else {
			NoTerminal* op2 = (NoTerminal*)Operando2;
			c->Operando2 = op2->clonar();
		}
	}
	c->tipo = this->tipo;

	return c;
}

Cuadruplo::Cuadruplo()
{
	this->Operador = 0;
	this->Operando1 = 0;
	this->Operando2 = 0;
	this->Resultado = 0;
}

Cuadruplo::Cuadruplo(ElementoGramatical * Resultado, ElementoGramatical * Operando1, ElementoGramatical * Operador, ElementoGramatical * Operando2, TiposDeCuadruplos _tipo, TablaSimbolos* _bloque)
{
	this->Operador = Operador;
	this->Operando1 = Operando1;
	this->Operando2 = Operando2;
	this->Resultado = Resultado;
	this->tipo = _tipo;
	this->bloque = _bloque;
}


Cuadruplo::~Cuadruplo()
{
}

string compilador::Cuadruplo::toString()
{
	stringstream ss;

	if (Resultado == NULL)
		ss << "NULL";
	else
	{
		if (Resultado->getTipo() == TERMINAL)
			ss << (((Terminal*)(Resultado))->getToken()->getLexema());
		else
			ss << ((NoTerminal*)(Resultado))->getID();
		//ss << "(" << Resultado << ")";
	}
	if (Operando1 == NULL)
		ss << "\tNULL";
	else
	{
		if (Operando1->getTipo() == TERMINAL)
			ss << "\t" <<(((Terminal*)(Operando1))->getToken()->getLexema());
		else
			ss << "\t" << ((NoTerminal*)(Operando1))->getID();
		//ss << "(" << Operando1 << ")";
	}
	if (Operador == NULL)
		ss << "\tNULL";
	else
	{
		if (Operador->getTipo() == TERMINAL)
			ss << "\t" << (((Terminal*)(Operador))->getToken()->getLexema());
		else
			ss << "\t" << ((NoTerminal*)(Operador))->getID();
		//ss << "(" << Operador << ")";
	}
	if (Operando2 == NULL)
		ss << "\tNULL";
	else
	{
		if (Operando2->getTipo() == TERMINAL)
			ss << "\t" << (((Terminal*)(Operando2))->getToken()->getLexema());
		else
			ss << "\t" << ((NoTerminal*)(Operando2))->getID();
		//ss << "(" << Operando2 << ")";
	}
	ss << "\tBloque: " << bloque->nbloque;
	ss << "\tTipo: " << tipo;

	return ss.str();
}
