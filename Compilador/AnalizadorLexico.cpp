#include "stdafx.h"
#include "AnalizadorLexico.h"


AnalizadorLexico::AnalizadorLexico()
{
}


AnalizadorLexico::~AnalizadorLexico()
{
}
/*

Analizar(S)
index = 0
2: c = S[index]
if(automata.mover(c))
	buffer.add(c)
	index++;
else
	index = EliminarBlancos(index)
	if(automata.esEstadoFinal())
		TipoToken = MapeaEstadoATipoToken(automata.estado())
		if (TipoToken == Tipos.IDENTIFICADOR)
			if(listaPalabrasReservadas.buscar(buffer))
				TipoToken = Tipos.PALABRA_RESERVADA
		listaTokens.add(new Token(buffer,TipoToken))
		automata.reset()
	else
		listaErrorLexico.add(new Error(bufer,linea))
		automata.reset()
ir a 2
*/
void AnalizadorLexico::Analizar(std::string S, int linea)
{
	int index = 0;
	char c = S[index];
	if (automata.mover(c)) {
		buffer.push_back(c);
		index++;
	}
	else
	{
		index = EliminarBlancos(S,index);
		if (automata.esEstadoFinal())
		{
			int TipoToken = MapeaEstadoATipoToken(automata.estado());
			if (TipoToken == Tipos::TOKEN_IDENTIFICADOR)
			{
				if (BuscarEnPalabrasReservadas(buffer))
					TipoToken = Tipos::TOKEN_PALABRA_RESERVADA;
			}
			listaTokens.push_back(new Token(buffer, TipoToken));
			automata.reset();
		}
		else
		{
			listaErrorLexico.push_back(new ErrorLexico(buffer, linea));
			automata.reset();
		}
	}
}

int AnalizadorLexico::EliminarBlancos(std::string cadena, int index)
{
	return 0;
}

int AnalizadorLexico::MapeaEstadoATipoToken(int estado)
{
	return 0;
}

bool AnalizadorLexico::BuscarEnPalabrasReservadas(std::string palabra)
{
	return binary_search(listaPalabrasReservadas.begin(), listaPalabrasReservadas.end(), palabra);
}
