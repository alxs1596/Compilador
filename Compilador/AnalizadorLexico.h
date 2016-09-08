#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "Automata.h"
#include "Tipos.h"
#include "Token.h"
#include "ErrorLexico.h"
#include "File.h"
#include <fstream>
class AnalizadorLexico
{
public:
	AnalizadorLexico();
	~AnalizadorLexico();
	void ejecutar(std::string);
	void cargarDatos();
	void Analizar(std::string, int);

	void imprimirTokens();
private:
	Automata *automata;
	std::string buffer;
	std::map<std::string, bool> listaPalabrasReservadas;
	std::vector<Token*> listaTokens;
	std::vector<ErrorLexico*> listaErrorLexico;
	std::map<int, int> EstadoAToken;

	int EliminarBlancos(std::string cadena, int index);
	int MapeaEstadoATipoToken(int estado);
	bool BuscarEnPalabrasReservadas(std::string palabra);
};

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