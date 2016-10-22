#include "stdafx.h"

#include "AnalizadorLexico.h"
#include <iostream>

using namespace std;

AnalizadorLexico::AnalizadorLexico()
{
	cargarDatos();
}


AnalizadorLexico::~AnalizadorLexico()
{
}

std::vector<Token*> AnalizadorLexico::ejecutar(std::string archivo )
{	
		string linea;
		ifstream codigoFuente;
		codigoFuente.open(archivo);

		if (codigoFuente.fail())
		{
			//Manejar con excepciones
			cout << "No se abre archivo" << endl;
		}
		else
		{
			int numeroLinea = 1;
			while (!codigoFuente.eof())
			{
				getline(codigoFuente, linea);
				Analizar(linea, numeroLinea++);
			}
		}
		return listaTokens;
}



void AnalizadorLexico::cargarDatos()
{

	//Comentario

	comentario = false;

	//######################
	//TOKENS

	TOKENS[TipoToken::Identificador] = "TOKEN_IDENTIFICADOR";
	TOKENS[TipoToken::PalabraReservada] = "TOKEN_PALABRA_RESERVADA";
	TOKENS[TipoToken::LiteralCadena] = "TOKEN_LITERAL_DE_CADENA";
	TOKENS[TipoToken::ConstanteEntera] = "TOKEN_VARIABLE_ENTERA";
	TOKENS[TipoToken::Delimitador] = "TOKEN_DELIMITADOR";
	TOKENS[TipoToken::Operador] = "TOKEN_OPERADOR";

	//######################

	std::map<char, int> alfabeto;
	int numeroEstados = 12;
	std::vector<int> estadosFinales;
	int estadoInicial = 0;
	Matriz matriz;

	//Palabras Reservadas

	listaPalabrasReservadas["Programa"] = true;
	listaPalabrasReservadas["entero"] = true;
	listaPalabrasReservadas["Si"] = true;
	listaPalabrasReservadas["Osino"] = true;
	listaPalabrasReservadas["Mientras"] = true;
	listaPalabrasReservadas["leerTeclado"] = true;
	listaPalabrasReservadas["leerPantalla"] = true;
	listaPalabrasReservadas["Hacer"] = true;

	//Estados A TipoToken

	EstadoAToken[1] = TipoToken::Identificador;// Tipos::TOKEN_IDENTIFICADOR;
	EstadoAToken[2] = TipoToken::ConstanteEntera;// Tipos::TOKEN_VARIABLE_ENTERA;
	EstadoAToken[3] = TipoToken::Operador;// Tipos::TOKEN_OPERADOR;
	EstadoAToken[9] = TipoToken::Delimitador;// Tipos::TOKEN_DELIMITADOR;
	EstadoAToken[5] = TipoToken::Operador;// Tipos::TOKEN_OPERADOR;
	EstadoAToken[6] = TipoToken::Operador;//Tipos::TOKEN_OPERADOR;
	EstadoAToken[7] = TipoToken::Operador;//Tipos::TOKEN_OPERADOR;
	EstadoAToken[8] = TipoToken::Operador;//Tipos::TOKEN_OPERADOR;
	EstadoAToken[11] = TipoToken::LiteralCadena;//Tipos::TOKEN_LITERAL_DE_CADENA;
	

	//Alfabeto
	alfabeto['a'] = Tipos::LETRA;
	alfabeto['b'] = Tipos::LETRA;
	alfabeto['c'] = Tipos::LETRA;
	alfabeto['d'] = Tipos::LETRA;
	alfabeto['e'] = Tipos::LETRA;
	alfabeto['f'] = Tipos::LETRA;
	alfabeto['g'] = Tipos::LETRA;
	alfabeto['h'] = Tipos::LETRA;
	alfabeto['i'] = Tipos::LETRA;
	alfabeto['j'] = Tipos::LETRA;
	alfabeto['k'] = Tipos::LETRA;
	alfabeto['l'] = Tipos::LETRA;
	alfabeto['m'] = Tipos::LETRA;
	alfabeto['n'] = Tipos::LETRA;
	//alfabeto['ñ'] = Tipos::LETRA;
	alfabeto['o'] = Tipos::LETRA;
	alfabeto['p'] = Tipos::LETRA;
	alfabeto['q'] = Tipos::LETRA;
	alfabeto['r'] = Tipos::LETRA;
	alfabeto['s'] = Tipos::LETRA;
	alfabeto['t'] = Tipos::LETRA;
	alfabeto['u'] = Tipos::LETRA;
	alfabeto['v'] = Tipos::LETRA;
	alfabeto['w'] = Tipos::LETRA;
	alfabeto['x'] = Tipos::LETRA;
	alfabeto['y'] = Tipos::LETRA;
	alfabeto['z'] = Tipos::LETRA;
	alfabeto['A'] = Tipos::LETRA;
	alfabeto['B'] = Tipos::LETRA;
	alfabeto['C'] = Tipos::LETRA;
	alfabeto['D'] = Tipos::LETRA;
	alfabeto['E'] = Tipos::LETRA;
	alfabeto['F'] = Tipos::LETRA;
	alfabeto['G'] = Tipos::LETRA;
	alfabeto['H'] = Tipos::LETRA;
	alfabeto['I'] = Tipos::LETRA;
	alfabeto['J'] = Tipos::LETRA;
	alfabeto['K'] = Tipos::LETRA;
	alfabeto['L'] = Tipos::LETRA;
	alfabeto['M'] = Tipos::LETRA;
	alfabeto['N'] = Tipos::LETRA;
	//alfabeto['Ñ'] = Tipos::LETRA;
	alfabeto['O'] = Tipos::LETRA;
	alfabeto['P'] = Tipos::LETRA;
	alfabeto['Q'] = Tipos::LETRA;
	alfabeto['R'] = Tipos::LETRA;
	alfabeto['S'] = Tipos::LETRA;
	alfabeto['T'] = Tipos::LETRA;
	alfabeto['U'] = Tipos::LETRA;
	alfabeto['V'] = Tipos::LETRA;
	alfabeto['W'] = Tipos::LETRA;
	alfabeto['X'] = Tipos::LETRA;
	alfabeto['Y'] = Tipos::LETRA;
	alfabeto['Z'] = Tipos::LETRA;

	alfabeto['0'] = Tipos::NUMERO;
	alfabeto['1'] = Tipos::NUMERO;
	alfabeto['2'] = Tipos::NUMERO;
	alfabeto['3'] = Tipos::NUMERO;
	alfabeto['4'] = Tipos::NUMERO;
	alfabeto['5'] = Tipos::NUMERO;
	alfabeto['6'] = Tipos::NUMERO;
	alfabeto['7'] = Tipos::NUMERO;
	alfabeto['8'] = Tipos::NUMERO;
	alfabeto['9'] = Tipos::NUMERO;

	alfabeto['-'] = Tipos::OPERADOR;
	alfabeto['+'] = Tipos::OPERADOR;
	alfabeto['*'] = Tipos::OPERADOR;
	alfabeto['/'] = Tipos::OPERADOR;
	alfabeto['%'] = Tipos::OPERADOR;
	alfabeto['='] = Tipos::IGUAL;
	alfabeto['<'] = Tipos::MENOR;
	alfabeto['>'] = Tipos::MAYOR;
	alfabeto['!'] = Tipos::ADMIRACION;
	//alfabeto['=='] = Tipos::OPERADOR;
	//alfabeto['>='] = Tipos::OPERADOR;
	//alfabeto['<='] = Tipos::OPERADOR;

	alfabeto['('] = Tipos::DELIMITADOR;
	alfabeto[')'] = Tipos::DELIMITADOR;
	alfabeto['{'] = Tipos::DELIMITADOR;
	alfabeto['}'] = Tipos::DELIMITADOR;
	alfabeto[','] = Tipos::DELIMITADOR;
	alfabeto[';'] = Tipos::DELIMITADOR;

	alfabeto['"'] = Tipos::COMILLA;

	//estadosFinales
	estadosFinales.push_back(1);
	estadosFinales.push_back(2);
	estadosFinales.push_back(3);
	estadosFinales.push_back(5);
	estadosFinales.push_back(6);
	estadosFinales.push_back(7);
	estadosFinales.push_back(8);
	estadosFinales.push_back(9);
	estadosFinales.push_back(11);

	//Matriz de transiciones
	matriz[0][1] = new std::vector<int>();
	matriz[0][1]->push_back(Tipos::LETRA);

	matriz[1][1] = new std::vector<int>();
	matriz[1][1]->push_back(Tipos::LETRA);
	matriz[1][1]->push_back(Tipos::NUMERO);

	matriz[0][2] = new std::vector<int>();
	matriz[0][2]->push_back(Tipos::NUMERO);
	
	matriz[2][2] = new std::vector<int>();
	matriz[2][2]->push_back(Tipos::NUMERO);

	matriz[0][3] = new std::vector<int>();
	matriz[0][3]->push_back(Tipos::OPERADOR);

	matriz[0][4] = new std::vector<int>();
	matriz[0][4]->push_back(Tipos::ADMIRACION);

	matriz[4][5] = new std::vector<int>();
	matriz[4][5]->push_back(Tipos::IGUAL);

	matriz[0][6] = new std::vector<int>();
	matriz[0][6]->push_back(Tipos::IGUAL);

	matriz[6][5] = new std::vector<int>();
	matriz[6][5]->push_back(Tipos::IGUAL);

	matriz[0][7] = new std::vector<int>();
	matriz[0][7]->push_back(Tipos::MENOR);

	matriz[7][5] = new std::vector<int>();
	matriz[7][5]->push_back(Tipos::IGUAL);

	matriz[0][8] = new std::vector<int>();
	matriz[0][8]->push_back(Tipos::MAYOR);

	matriz[8][5] = new std::vector<int>();
	matriz[8][5]->push_back(Tipos::IGUAL);

	matriz[0][9] = new std::vector<int>();
	matriz[0][9]->push_back(Tipos::DELIMITADOR);

	matriz[0][10] = new std::vector<int>();
	matriz[0][10]->push_back(Tipos::COMILLA);

	matriz[10][10] = new std::vector<int>();
	matriz[10][10]->push_back(Tipos::LETRA);
	matriz[10][10]->push_back(Tipos::NUMERO);

	matriz[10][11] = new std::vector<int>();
	matriz[10][11]->push_back(Tipos::COMILLA);

	automata = new Automata(alfabeto, numeroEstados, estadosFinales, estadoInicial, matriz);

	//automata->imprimir();

}
void AnalizadorLexico::Analizar(std::string S, int linea)
{
	S.push_back('@');
	int index = 0;
	index =EliminarBlancos(S, index);
	while(index < S.size()) {
		if (S[index] == '/' && S[index + 1] == '/') return;
		if (S[index] == '/' && S[index + 1] == '*') comentario = true;
		if (S[index] == '*' && S[index + 1] == '/') { comentario = false; index = index + 2; }
		if (!comentario) {
			char c = S[index];
			if (automata->mover(c)) {
				buffer.push_back(c);
				index++;
			}
			else
			{
				index = EliminarBlancos(S, index);
				if (automata->esEstadoFinal())
				{
					int TipoToken = MapeaEstadoATipoToken(automata->estado());
					if (TipoToken == TipoToken::Identificador)
					{
						if (BuscarEnPalabrasReservadas(buffer))
							TipoToken = TipoToken::PalabraReservada;
					}
					listaTokens.push_back(new Token(buffer, TipoToken, linea));
					buffer = "";
					automata->reset();
				}
				else
				{
					if (index != S.size() - 1)
						listaErrorLexico.push_back(new ErrorLexico(S, linea, index));
					buffer = "";
					index++;
					automata->reset();
				}
			}
		}
		else
		{
			index++;
		}
		
	}
	//imprimirTokens();
}

void AnalizadorLexico::ReiniciarTodo()
{
	automata->reset();
	buffer = "";
}

string AnalizadorLexico::leerArchivo(string rutaArchivo)
{
	string codigoFuente = "";

	string linea;
	ifstream archivoCodigoFuente;
	archivoCodigoFuente.open(rutaArchivo);

	if (archivoCodigoFuente.fail())
	{
		//Manejar con excepciones
		cout << "No se abre archivo" << endl;
	}
	else
	{
		int numeroLinea = 1;
		while (!archivoCodigoFuente.eof())
		{
			getline(archivoCodigoFuente, linea);
			codigoFuente += linea + '\n';
		}
	}

	return codigoFuente;
}
bool AnalizadorLexico::esBlanco(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}
void AnalizadorLexico::imprimirTokens()
{
	for (std::vector<Token*>::iterator it = listaTokens.begin(); it != listaTokens.end(); ++it)
	{
		std::cout << (*it)->getLexema() << "\t\t" << TOKENS[(*it)->getTipo()] << std::endl;
	}
}

void AnalizadorLexico::imprimirErrores()
{
	for (std::vector<ErrorLexico*>::iterator it = listaErrorLexico.begin(); it != listaErrorLexico.end(); ++it)
	{
		std::string cadena = (*it)->getError();
		std::cout << (*it)->getError() << " " << "Linea: " << (*it)->getLinea() << " " << "Caracter: " << (*it)->getCaracter() << std::endl;
	}
	
}

void AnalizadorLexico::dibujarAutomata()
{
	automata->dibujarAutomata();
}

int AnalizadorLexico::EliminarBlancos(std::string cadena, int index)
{
	if (index == cadena.length() || cadena[index] == ' ' || cadena[index] == '\t')
	{

		return EliminarBlancos(cadena, index + 1);

	}
	else {

		return index;
	}
}

TipoToken AnalizadorLexico::MapeaEstadoATipoToken(int estado)
{
	return EstadoAToken[estado];
}

bool AnalizadorLexico::BuscarEnPalabrasReservadas(std::string palabra)
{
	return listaPalabrasReservadas[palabra];
}
