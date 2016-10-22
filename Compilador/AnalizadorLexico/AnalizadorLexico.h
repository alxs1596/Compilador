#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <streambuf>
#include <map>

#include "Automata.h"
#include "../CompiladorLib/Tipos.h"
#include "../CompiladorLib/Token.h"
#include "ErrorLexico.h"

using namespace std;

class AnalizadorLexico
{
public:
	AnalizadorLexico();
	~AnalizadorLexico();
	std::vector<Token*> ejecutar(std::string);
	void imprimirTokens();
	void imprimirErrores();
	void dibujarAutomata();
//private:
	Automata *automata;
	std::string buffer;
	std::map<std::string, bool> listaPalabrasReservadas;
	std::vector<Token*> listaTokens;
	std::vector<ErrorLexico*> listaErrorLexico;
	std::map<int, TipoToken> EstadoAToken;
	std::map<int, std::string > TOKENS;

	bool comentario;

	void cargarDatos();
	void Analizar(std::string, int);

	void ReiniciarTodo();

	int EliminarBlancos(std::string,int);
	TipoToken MapeaEstadoATipoToken(int estado);
	bool BuscarEnPalabrasReservadas(std::string palabra);

	/////////////////////////////////////////////

	string leerArchivo(string rutaArchivo);
	bool esBlanco(char c);
};
