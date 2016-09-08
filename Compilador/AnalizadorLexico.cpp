#include "stdafx.h"
#include "AnalizadorLexico.h"


AnalizadorLexico::AnalizadorLexico()
{
}


AnalizadorLexico::~AnalizadorLexico()
{
}

void AnalizadorLexico::ejecutar(std::string archivo )
{
	
		std::string linea;
		std::ifstream nombre;
		nombre.open(archivo);
		int nLinea = 1;
		std::cout << "#############################\n\tCodigo Fuente:\n\n";
		while (!nombre.eof())
		{
			getline(nombre, linea);
			Analizar(linea, nLinea++);
			std::cout << linea << std::endl;
		}
		std::cout << "#############################\n\tTokens:\n\n";
		imprimirTokens();
		std::cout << "#############################\n\tErrores:\n\n";
		imprimirErrores();
}


void AnalizadorLexico::cargarDatos()
{

	//Comentario

	comentario = false;

	//######################
	//TOKENS

	TOKENS[1] = "TOKEN_IDENTIFICADOR";
	
	TOKENS[2] = "TOKEN_PALABRA_RESERVADA";
	TOKENS[3] = "TOKEN_LITERAL_DE_CADENA";
	TOKENS[4] = "TOKEN_VARIABLE_ENTERA";
	TOKENS[5] = "TOKEN_DELIMITADOR";
	TOKENS[6] = "TOKEN_OPERADOR";

	//######################

	std::map<char, int> alfabeto;
	int numeroEstados = 7;
	std::vector<int> estadosFinales;
	int estadoInicial = 0;
	Matriz matriz;

	//Palabras Reservadas

	listaPalabrasReservadas["Programa"] = true;
	listaPalabrasReservadas["entero"] = true;
	listaPalabrasReservadas["Si"] = true;
	listaPalabrasReservadas["Sino"] = true;
	listaPalabrasReservadas["Mientras"] = true;
	listaPalabrasReservadas["leerTeclado"] = true;
	listaPalabrasReservadas["leerPantalla"] = true;

	//Estados A TipoToken

	EstadoAToken[1] = Tipos::TOKEN_IDENTIFICADOR;
	EstadoAToken[2] = Tipos::TOKEN_VARIABLE_ENTERA;
	EstadoAToken[3] = Tipos::TOKEN_OPERADOR;
	EstadoAToken[4] = Tipos::TOKEN_DELIMITADOR;
	EstadoAToken[6] = Tipos::TOKEN_LITERAL_DE_CADENA;

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
	alfabeto['='] = Tipos::OPERADOR;
	alfabeto['<'] = Tipos::OPERADOR;
	alfabeto['>'] = Tipos::OPERADOR;
	alfabeto['=='] = Tipos::OPERADOR;
	alfabeto['>='] = Tipos::OPERADOR;
	alfabeto['<='] = Tipos::OPERADOR;

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
	estadosFinales.push_back(4);
	estadosFinales.push_back(6);

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
	matriz[0][4]->push_back(Tipos::DELIMITADOR);

	matriz[0][5] = new std::vector<int>();
	matriz[0][5]->push_back(Tipos::COMILLA);

	matriz[5][5] = new std::vector<int>();
	matriz[5][5]->push_back(Tipos::LETRA);
	matriz[5][5]->push_back(Tipos::NUMERO);

	matriz[5][6] = new std::vector<int>();
	matriz[5][6]->push_back(Tipos::COMILLA);

	automata = new Automata(alfabeto, numeroEstados, estadosFinales, estadoInicial, matriz);

	//automata->imprimir();

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
	S.push_back('@');
	int index = 0;
	EliminarComentario(S,index);
	index = EliminarBlancos(S, index);
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
					if (TipoToken == Tipos::TOKEN_IDENTIFICADOR)
					{
						if (BuscarEnPalabrasReservadas(buffer))
							TipoToken = Tipos::TOKEN_PALABRA_RESERVADA;
					}
					listaTokens.push_back(new Token(buffer, TipoToken));
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
		std::cout << (*it)->getError() << "\t" <<(*it)->getLinea() << "\t" << std::endl;
		for (int i = 0; i < (*it)->getCaracter(); i++)
			std::cout << " ";
		char a = 238;
		std::cout << a << std::endl;
	}
	
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

void AnalizadorLexico::EliminarComentario(std::string cadena , int index)
{
	/*if (index < cadena.size() - 2) 
		if (cadena[index] == '/' && cadena[index + 1] == '*') comentario = true;
	if (cadena[index] == '@')
	{

	}
	if (index > 1)
		if (cadena[index - 2] == '*' && cadena[index - 1] == '/') comentario = false;
	//    abc*/


}

int AnalizadorLexico::MapeaEstadoATipoToken(int estado)
{
	return EstadoAToken[estado];
}

bool AnalizadorLexico::BuscarEnPalabrasReservadas(std::string palabra)
{
	return listaPalabrasReservadas[palabra];
}
