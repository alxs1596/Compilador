#include "stdafx.h"

#include "AnalizadorLexico.h"
#include <iostream>

using namespace std;

AnalizadorLexico::AnalizadorLexico()
{
	cargarDatos();
	error = false;
}


AnalizadorLexico::~AnalizadorLexico()
{
}

void AnalizadorLexico::cargarDatos()
{


	//######################
	//TOKENS

	TOKENS[TipoToken::Identificador] = "TOKEN_IDENTIFICADOR";
	TOKENS[TipoToken::PalabraReservada] = "TOKEN_PALABRA_RESERVADA";
	TOKENS[TipoToken::LiteralCadena] = "TOKEN_LITERAL_DE_CADENA";
	TOKENS[TipoToken::ConstanteEntera] = "TOKEN_VARIABLE_ENTERA";
	TOKENS[TipoToken::Delimitador] = "TOKEN_DELIMITADOR";
	TOKENS[TipoToken::Operador] = "TOKEN_OPERADOR";
	TOKENS[TipoToken::CometarioLinea] = "TOKEN_COMENTARIO_LINEA";
	TOKENS[TipoToken::ComentarioMultilinea] = "TOKEN_COMENTARIO_MULTILINEA";

	//######################

	std::map<char, int> alfabeto;
	int numeroEstados = 19;
	std::vector<int> estadosFinales;
	int estadoInicial = 0;
	Matriz matriz;

	//Palabras Reservadas

	listaPalabrasReservadas["Programa"] = true;
	listaPalabrasReservadas["entero"] = true;
	listaPalabrasReservadas["Si"] = true;
	listaPalabrasReservadas["Osino"] = true;
	listaPalabrasReservadas["Mientras"] = true;
	listaPalabrasReservadas["LeerTeclado"] = true;
	listaPalabrasReservadas["EscribirPantalla"] = true;
	listaPalabrasReservadas["Hacer"] = true;

	//Estados A TipoToken
	
	EstadoAToken[1] = TipoToken::Identificador;// Tipos::TOKEN_IDENTIFICADOR;
	EstadoAToken[2] = TipoToken::ConstanteEntera;// Tipos::TOKEN_VARIABLE_ENTERA;
	EstadoAToken[3] = TipoToken::Operador;// Tipos::TOKEN_OPERADOR;
	EstadoAToken[5] = TipoToken::Operador;// Tipos::TOKEN_OPERADOR;
	EstadoAToken[6] = TipoToken::Operador;//Tipos::TOKEN_OPERADOR;
	EstadoAToken[7] = TipoToken::Operador;//Tipos::TOKEN_OPERADOR;
	EstadoAToken[8] = TipoToken::Delimitador;//Tipos::TOKEN_DELIMITADOR;
	EstadoAToken[10] = TipoToken::LiteralCadena;// Tipos::TOKEN_LITERAL_DE_CADENA;
	EstadoAToken[13] = TipoToken::Operador;//Tipos::TOKEN_COMENTARIO_OPERADOR;
	EstadoAToken[18] = TipoToken::CometarioLinea;//TIPOS::TOKEN_COMENTARIO_LINEA;
	EstadoAToken[17] = TipoToken::ComentarioMultilinea;//TIPOS::TOKEN_COMENTARIO_MILTILINEA;
	

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
	//alfabeto['*'] = Tipos::OPERADOR;
	alfabeto['%'] = Tipos::OPERADOR;
	alfabeto['/'] = Tipos::DIVISION;
	alfabeto['='] = Tipos::IGUAL;
	alfabeto['<'] = Tipos::MENOR;
	alfabeto['>'] = Tipos::MAYOR;
	alfabeto['!'] = Tipos::ADMIRACION;
	alfabeto['|'] = Tipos::OR;
	alfabeto['&'] = Tipos::AND;
	
	alfabeto[' '] = Tipos::BLANCO;
	alfabeto['\n'] = Tipos::SALTO_LINEA;
	alfabeto['\t'] = Tipos::BLANCO;

	alfabeto['('] = Tipos::DELIMITADOR;
	alfabeto[')'] = Tipos::DELIMITADOR;
	alfabeto['{'] = Tipos::DELIMITADOR;
	alfabeto['}'] = Tipos::DELIMITADOR;
	alfabeto[','] = Tipos::DELIMITADOR;
	alfabeto[';'] = Tipos::DELIMITADOR;

	alfabeto['"'] = Tipos::COMILLA;

	alfabeto['*'] = Tipos::ASTERISCO;


	//estadosFinales
	
	estadosFinales.push_back(1);
	estadosFinales.push_back(2);
	estadosFinales.push_back(3);
	estadosFinales.push_back(5);
	estadosFinales.push_back(6);
	estadosFinales.push_back(7);
	estadosFinales.push_back(8);
	estadosFinales.push_back(10);
	estadosFinales.push_back(13);
	estadosFinales.push_back(17);
	estadosFinales.push_back(18);


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
	matriz[0][3]->push_back(Tipos::ASTERISCO);

	matriz[0][4] = new std::vector<int>();
	matriz[0][4]->push_back(Tipos::ADMIRACION);

	matriz[4][3] = new std::vector<int>();
	matriz[4][3]->push_back(Tipos::IGUAL);

	matriz[0][5] = new std::vector<int>();
	matriz[0][5]->push_back(Tipos::MENOR);

	matriz[5][3] = new std::vector<int>();
	matriz[5][3]->push_back(Tipos::IGUAL);

	matriz[0][6] = new std::vector<int>();
	matriz[0][6]->push_back(Tipos::MAYOR);

	matriz[6][3] = new std::vector<int>();
	matriz[6][3]->push_back(Tipos::IGUAL);

	matriz[0][7] = new std::vector<int>();
	matriz[0][7]->push_back(Tipos::IGUAL);

	matriz[7][3] = new std::vector<int>();
	matriz[7][3]->push_back(Tipos::IGUAL);

	matriz[0][8] = new std::vector<int>();
	matriz[0][8]->push_back(Tipos::DELIMITADOR);

	matriz[0][9] = new std::vector<int>();
	matriz[0][9]->push_back(Tipos::COMILLA);

	matriz[9][9] = new std::vector<int>();
	matriz[9][9]->push_back(Tipos::LETRA);
	matriz[9][9]->push_back(Tipos::NUMERO);
	matriz[9][9]->push_back(Tipos::ADMIRACION);
	matriz[9][9]->push_back(Tipos::DELIMITADOR);
	matriz[9][9]->push_back(Tipos::AND);
	matriz[9][9]->push_back(Tipos::IGUAL);
	matriz[9][9]->push_back(Tipos::MAYOR);
	matriz[9][9]->push_back(Tipos::MENOR);
	matriz[9][9]->push_back(Tipos::OPERADOR);
	matriz[9][9]->push_back(Tipos::OR);
	matriz[9][9]->push_back(Tipos::ASTERISCO);
	matriz[9][9]->push_back(Tipos::DIVISION);
	matriz[9][9]->push_back(Tipos::BLANCO);
	matriz[9][9]->push_back(Tipos::SALTO_LINEA);
	
	
	matriz[9][10] = new std::vector<int>();
	matriz[9][10]->push_back(Tipos::COMILLA);

	matriz[0][11] = new std::vector<int>();
	matriz[0][11]->push_back(Tipos::OR);

	matriz[11][3] = new std::vector<int>();
	matriz[11][3]->push_back(Tipos::OR);

	matriz[0][12] = new std::vector<int>();
	matriz[0][12]->push_back(Tipos::AND);
	
	matriz[12][3] = new std::vector<int>();
	matriz[12][3]->push_back(Tipos::AND);

	matriz[0][13] = new std::vector<int>();
	matriz[0][13]->push_back(Tipos::DIVISION);

	matriz[13][14] = new std::vector<int>();
	matriz[13][14]->push_back(Tipos::DIVISION);

	matriz[14][14] = new std::vector<int>();
	matriz[14][14]->push_back(Tipos::LETRA);
	matriz[14][14]->push_back(Tipos::NUMERO);
	matriz[14][14]->push_back(Tipos::ADMIRACION);
	matriz[14][14]->push_back(Tipos::AND);
	matriz[14][14]->push_back(Tipos::ASTERISCO);
	matriz[14][14]->push_back(Tipos::DELIMITADOR);
	matriz[14][14]->push_back(Tipos::DIVISION);
	matriz[14][14]->push_back(Tipos::BLANCO);
	matriz[14][14]->push_back(Tipos::IGUAL);
	matriz[14][14]->push_back(Tipos::MAYOR);
	matriz[14][14]->push_back(Tipos::MENOR);
	matriz[14][14]->push_back(Tipos::OPERADOR);
	matriz[14][14]->push_back(Tipos::OR);

	matriz[14][18] = new std::vector<int>();
	matriz[14][18]->push_back(Tipos::SALTO_LINEA);



	matriz[13][15] = new std::vector<int>();
	matriz[13][15]->push_back(Tipos::ASTERISCO);

	matriz[15][15] = new std::vector<int>();
	matriz[15][15]->push_back(Tipos::LETRA);
	matriz[15][15]->push_back(Tipos::NUMERO);
	matriz[15][15]->push_back(Tipos::ADMIRACION);
	matriz[15][15]->push_back(Tipos::AND);
	matriz[15][15]->push_back(Tipos::DELIMITADOR);
	matriz[15][15]->push_back(Tipos::DIVISION);
	matriz[15][15]->push_back(Tipos::BLANCO);
	matriz[15][15]->push_back(Tipos::SALTO_LINEA);
	matriz[15][15]->push_back(Tipos::IGUAL);
	matriz[15][15]->push_back(Tipos::MAYOR);
	matriz[15][15]->push_back(Tipos::MENOR);
	matriz[15][15]->push_back(Tipos::OPERADOR);
	matriz[15][15]->push_back(Tipos::OR);
	
	matriz[15][16] = new std::vector<int>();
	matriz[15][16]->push_back(Tipos::ASTERISCO);

	matriz[16][15] = new std::vector<int>();
	matriz[16][15]->push_back(Tipos::LETRA);
	matriz[16][15]->push_back(Tipos::NUMERO);
	matriz[16][15]->push_back(Tipos::ADMIRACION);
	matriz[16][15]->push_back(Tipos::AND);
	matriz[16][15]->push_back(Tipos::DELIMITADOR);
	matriz[16][15]->push_back(Tipos::BLANCO);
	matriz[16][15]->push_back(Tipos::SALTO_LINEA);
	matriz[16][15]->push_back(Tipos::IGUAL);
	matriz[16][15]->push_back(Tipos::MAYOR);
	matriz[16][15]->push_back(Tipos::MENOR);
	matriz[16][15]->push_back(Tipos::OPERADOR);
	matriz[16][15]->push_back(Tipos::OR);

	matriz[16][17] = new std::vector<int>();
	matriz[16][17]->push_back(Tipos::DIVISION);

	automata = new Automata(alfabeto, numeroEstados, estadosFinales, estadoInicial, matriz);

	//automata->imprimir();

}

std::vector<Token*> AnalizadorLexico::ejecutar(std::string archivo)
{
	listaTokens.clear();

	string codigoFuente = leerArchivo(archivo);

	analizar(codigoFuente);

	return listaTokens;
}

std::vector<Token*> AnalizadorLexico::analizar(string codigoFuente)
{
	int linea = 0;
	string buffer;
	automata->reset();
	int index = 0;
	while ( index<codigoFuente.size() )
	{
		char c = codigoFuente[index];
		if (automata->mover(c))
		{
			buffer.push_back(c);
			index++;
		}
		else
		{
			if (automata->esEstadoFinal())
			{
				int TipoToken = MapeaEstadoATipoToken(automata->estado());
				if (TipoToken == TipoToken::ComentarioMultilinea || TipoToken==TipoToken::CometarioLinea)
				{
					buffer = "";
					automata->reset();
				}
				else
				{
					if (buffer != "")
					{
						if (TipoToken == TipoToken::Identificador)
						{
							if (BuscarEnPalabrasReservadas(buffer))
								TipoToken = TipoToken::PalabraReservada;
						}
						listaTokens.push_back(new Token(buffer, TipoToken, linea));
						buffer = "";
						automata->reset();
					}
				}
			}
			else
			{
				if (buffer.size() > 0)
				{
					listaErrorLexico.push_back(new ErrorLexico(buffer, linea, index));
					index++;
				}
				else
					EliminarBlancos(codigoFuente, index, linea);

				buffer = "";
				automata->reset();
			}
		}
	}
	return listaTokens;
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
		throw new exception("No se pudo abrir el archivo");
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

void AnalizadorLexico::EliminarBlancos(std::string cadena, int& index, int& linea)
{
	while (index < cadena.size() && (cadena[index] == ' ' || cadena[index] == '\t' || cadena[index] == '\n'))
	{
		if (cadena[index] == '\n')
			linea++;
		index++;
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
