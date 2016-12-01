#include "stdafx.h"
#include "AnalizadorSemantico.h"


AnalizadorSemantico::AnalizadorSemantico()
{
}


AnalizadorSemantico::~AnalizadorSemantico()
{
}

void AnalizadorSemantico::analizar(vector<Cuadruplo*>* cuadruplos)
{

	for (size_t i = 0; i < cuadruplos->size() ; i++)
	{
		Cuadruplo* cuadruplo = (*cuadruplos)[i];
		if (cuadruplo->tipo == TiposDeCuadruplos::Declaracion)
		{
			auto token = ((Terminal*)cuadruplo->Resultado)->getToken();
			if (cuadruplo->Resultado->getTipo() == TERMINAL)
			{ 
				auto entrada = cuadruplo->bloque->fueDeclarada(token->getLexema());
				if (entrada != nullptr)
				{
					throw new exception("Variable ya declarada");
				}
				else
				{
					EntradaTablaSimbolos *entrada = new EntradaTablaSimbolos(token->getLexema(), token->getLinea(), offset++);
					cuadruplo->bloque->variables->push_back(entrada);

				}
			}
		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Asignacion)
		{
			if (cuadruplo->Resultado->getTipo() == TERMINAL)
			{
				auto token = ((Terminal*)cuadruplo->Resultado)->getToken();
				auto entrada = cuadruplo->bloque->fueDeclarada(token->getLexema());
				if (entrada != nullptr)
				{
					auto bloque = cuadruplo->bloque;
					if (entrada->lineaPrimeraAsignacion == -1)
								entrada->lineaPrimeraAsignacion = token->getLinea();
					
				}
				else
				{
					throw new exception("Variable no declarada");
				}
			}

		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Operacion)
		{
			if (cuadruplo->Resultado->getTipo() == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Resultado;
				if ((t->getToken())->getTipo() == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada((t->getToken())->getLexema());
					if (entrada == nullptr) {

						throw new exception("Variable no declarada");
					}

				}
			}
			if (cuadruplo->Operando1->getTipo() == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Operando1;
				if (t->getToken()->getTipo() == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada((t->getToken())->getLexema());
					if (entrada == nullptr)
						throw new exception("Variable no declarada");
				}
			}
			if (cuadruplo->Operando2->getTipo() == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Operando2;
				if (t->getToken()->getTipo() == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada(t->getToken()->getLexema());
					if (entrada == nullptr)
						throw new exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Lectura)
		{
			if (cuadruplo->Resultado->getTipo() == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Resultado;
				if (t->getToken()->getTipo() == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada(t->getToken()->getLexema());
					if (entrada == nullptr)
						throw new exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Escritura)
		{
			if (cuadruplo->Operando1->getTipo()== TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Operando1;
				if (t->getToken()->getTipo() == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada(t->getToken()->getLexema());
						if (entrada == nullptr) {
							throw new exception("Variable no declarada");
						}
				}
			}
		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Mientras)
		{
			if (cuadruplo->Operando1->getTipo() == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Operando1;
				if (t->getToken()->getTipo == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada(t->getToken()->getLexema());
					if (entrada == nullptr)
						throw new exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo->tipo == TiposDeCuadruplos::Si)
		{
			if (cuadruplo->Operando1->getTipo == TERMINAL)
			{
				Terminal *t = (Terminal*)cuadruplo->Operando1;
				if (t->getToken()->getTipo == TipoToken::Identificador)
				{
					auto entrada = cuadruplo->bloque->fueDeclarada(t->getToken()->getLexema);
					if (entrada == nullptr)
						throw new exception("Variable no declarada");
				}
			}
		}
	}
}