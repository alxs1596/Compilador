#include "stdafx.h"
#include "Cuadruplo.h"


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

	return c;
}

Cuadruplo::Cuadruplo()
{
	this->Operador = 0;
	this->Operando1 = 0;
	this->Operando2 = 0;
	this->Resultado = 0;
}

Cuadruplo::Cuadruplo(ElementoGramatical * Resultado, ElementoGramatical * Operando1, ElementoGramatical * Operador, ElementoGramatical * Operando2, TiposDeCuadruplos _tipo)
{
	this->Operador = Operador;
	this->Operando1 = Operando1;
	this->Operando2 = Operando2;
	this->Resultado = Resultado;
	this->tipo = _tipo;
}


Cuadruplo::~Cuadruplo()
{
}
