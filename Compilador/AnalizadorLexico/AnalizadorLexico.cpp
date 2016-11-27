#include "stdafx.h"

#include "AnalizadorLexico.h"
#include <iostream>

using namespace std;

using namespace compilador;
using namespace compilador::lexico;

AnalizadorLexico::AnalizadorLexico()
{
	cargarDatos();
	error = true;
}


AnalizadorLexico::~AnalizadorLexico()
{
}

void AnalizadorLexico::cargarDatos()
{



	//Palabras Reservadas

	listaPalabrasReservadas.push_back("Programa");
	listaPalabrasReservadas.push_back("entero");
	listaPalabrasReservadas.push_back("Si");
	listaPalabrasReservadas.push_back("Osino");
	listaPalabrasReservadas.push_back("Mientras");
	listaPalabrasReservadas.push_back("LeerTeclado");
	listaPalabrasReservadas.push_back("EscribirPantalla");
	listaPalabrasReservadas.push_back("Hacer");

	sort(listaPalabrasReservadas.begin(), listaPalabrasReservadas.end());


}


std::vector<Token*> AnalizadorLexico::analizar(string codigoFuente)
{
	vector<Token*> listaTokens;
	int linea = 0;
	string buffer;
	automata.reset();
	int index = 0;
	while ( index<codigoFuente.size() )
	{
		char c = codigoFuente[index];
		if (automata.mover(c))
		{
			buffer.push_back(c);
			index++;
		}
		else
		{
			if (automata.esEstadoFinal())
			{
				TipoToken TipoToken = MapeaEstadoATipoToken(automata.estado());
				if (TipoToken == TipoToken::ComentarioMultilinea || TipoToken==TipoToken::CometarioLinea)
				{
					buffer = "";
					automata.reset();
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
						automata.reset();
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
				automata.reset();
			}
		}
	}
	if (listaErrorLexico.size() == 0) error = false;
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



void AnalizadorLexico::imprimirErrores()
{
	for (std::vector<ErrorLexico*>::iterator it = listaErrorLexico.begin(); it != listaErrorLexico.end(); ++it)
	{
		std::string cadena = (*it)->getError();
		std::cout << (*it)->getError() << " " << "Linea: " << (*it)->getLinea() << " " << "Caracter: " << (*it)->getCaracter() << std::endl;
	}
	
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

TipoToken compilador::lexico::AnalizadorLexico::MapeaEstadoATipoToken(int estado)
{
	switch (estado)
	{
	case 1: return TipoToken::Identificador;
	case 2: return TipoToken::ConstanteEntera;
	case 3: return TipoToken::Operador;
	case 5: return TipoToken::Operador;
	case 6: return TipoToken::Operador;
	case 7: return TipoToken::Operador;
	case 8: return TipoToken::Delimitador;
	case 10: return TipoToken::LiteralCadena;
	case 13: return TipoToken::Operador;
	case 18: return TipoToken::CometarioLinea;
	case 17: return TipoToken::ComentarioMultilinea;
	default:
		throw new exception("Tipo token no existe");
	}
}


bool AnalizadorLexico::BuscarEnPalabrasReservadas(std::string palabra)
{
	return binary_search(listaPalabrasReservadas.begin(), listaPalabrasReservadas.end(), palabra);
}
