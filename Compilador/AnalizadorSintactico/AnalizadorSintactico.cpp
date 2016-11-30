#include "stdafx.h"
#include "AnalizadorSintactico.h"

#include <iostream>
#include <algorithm>

using namespace std;

using namespace compilador::sintactico;

void AnalizadorSintactico::llenarReglas()
{

	
}

AnalizadorSintactico::AnalizadorSintactico()
{
	
	voltear = false;

	bloqueActual = NULL;
	bloquePadre = NULL;
	nbloque = 0;

	error = true;
}

AnalizadorSintactico::~AnalizadorSintactico()
{
}

void AnalizadorSintactico::vaciarPila() {
	while (!pila.empty())
		pila.pop();
}

void AnalizadorSintactico::voltearTemporal(int desde, int hasta) {
	reverse(listaCuadruplos.begin() + desde, listaCuadruplos.begin() + hasta + 1);
}

void AnalizadorSintactico::optimizar()
{
	vector<int> aEliminar;

	for (int i = 0; i < (int)listaCuadruplos.size() - 1; i++)
	{
		/*cout << "---------------------" << endl;
		imprimirCuadruplos();
		cout << "---------------------" << endl;*/
		Cuadruplo* actual = listaCuadruplos[i];
		if (actual->tipo == TiposDeCuadruplos::Asignacion)
		{

			for (size_t j = i + 1; j < listaCuadruplos.size(); j++)
			{
				if (actual->Resultado == listaCuadruplos[j]->Operando1)
				{
					listaCuadruplos[j]->Operando1 = actual->Operando1;
					aEliminar.push_back((int)i);
					break;
				}
				else if (actual->Resultado == listaCuadruplos[j]->Operando2)
				{
					listaCuadruplos[j]->Operando2 = actual->Operando1;
					aEliminar.push_back((int)i);
					break;
				}
			}
		}
		else if (actual->tipo == TiposDeCuadruplos::Operacion && listaCuadruplos[i + 1]->tipo == TiposDeCuadruplos::Asignacion)
		{
			if (actual->Resultado == listaCuadruplos[i + 1]->Operando1)
			{
				listaCuadruplos[i + 1]->Operando1 = actual->Operando1;
				listaCuadruplos[i + 1]->Operador = actual->Operador;
				listaCuadruplos[i + 1]->Operando2 = actual->Operando2;
				listaCuadruplos[i + 1]->tipo = TiposDeCuadruplos::Operacion;
				aEliminar.push_back((int)i);
			}
		}
	}
	
	for (int i = (int)aEliminar.size() - 1; i >= 0; i--)
		listaCuadruplos.erase(listaCuadruplos.begin() + aEliminar[i]);
		
}

void AnalizadorSintactico::llenarCuadruplos(int nregla, vector<ElementoGramatical*> produccion , vector<Terminal*>* entrada, int i, ElementoGramatical* tope)
{
	/*
	Terminal* terminal = (*entrada)[i];


	Terminal* T_Igual = new Terminal(new Token("=", TipoToken::Operador, 0));
	//Terminal* T_Si = new Terminal(new Token("Si", TipoToken::Operador, 0));
	//Terminal* T_Osino = new Terminal(new Token("Osino", TipoToken::Operador, 0));
	 
	switch (nregla) {

	case 2:

		voltearHasta = (int)listaCuadruplos.size() - 1;
		if (voltear) {
			voltearTemporal(voltearDesde, voltearHasta);
			voltear = false;
		}

		break;
	case 3:

		voltearHasta = (int)listaCuadruplos.size() - 1;
		if (voltear) {
			voltearTemporal(voltearDesde, voltearHasta);
			voltear = false;
		}

		break;
	case 15:
		cuadruplo->bloque = bloqueActual;

		cuadruplo->Resultado = terminal;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 16:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		cuadruplo->bloque = bloqueActual;

		cuadruplo->Resultado = listaCuadruplos[listaCuadruplos.size() - 1]->Resultado;
		cuadruplo->Operando1 = produccion[1];
		listaCuadruplos.push_back(cuadruplo);
		break;
	
	case 18:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		cuadruplo->bloque = bloqueActual;

		cuadruplo->Resultado = terminal;
		cuadruplo->Operando1 = produccion[2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 19:
		voltear = true;
		cuadruplo = new Cuadruplo(
			NULL,
			produccion[2],
			new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Mientras);
		cuadruplo->bloque = bloqueActual;

		listaCuadruplos.push_back(cuadruplo);
		break;
		
	case 20:
		voltearHasta = (int)listaCuadruplos.size() - 1;
		if (voltear) {
			voltearTemporal(voltearDesde, voltearHasta);
			voltear = false;
		}

		
		break;
	case 21:
		voltearHasta = (int)listaCuadruplos.size() - 1;
		if (voltear) {
			voltearTemporal(voltearDesde, voltearHasta);
			voltear = false;
		}

		break;
	case 22:
	// crear Bloques
		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();
		cuadruplo = new Cuadruplo(
			NULL,
			produccion[2],
			new Terminal(new Token("Si", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Si);
		cuadruplo->bloque = bloqueActual;

		listaCuadruplos.push_back(cuadruplo);
		//teminar Bloques
	break;
	case 23:
	// crear Bloques
		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();
		cuadruplo = new Cuadruplo(
			NULL,
			produccion[1],
			new Terminal(new Token("Osino", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Osino);
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);

	break;
	//teminar Bloques
	
		
	case 25:
		//voltearTemporal();
		cuadruplo->bloque = bloqueActual;

		cuadruplo->Resultado = (*entrada)[i + 2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 26:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();
		cuadruplo->bloque = bloqueActual;
		cuadruplo->Operando1 = produccion[2];
		listaCuadruplos.push_back(cuadruplo);
		break;

	case 28:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 29:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 30:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
			if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
				NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
				if (t == tope) {
					listaCuadruplos[i]->Operador = terminal;
					break;
				}
			}
		}
		cuadruplo->bloque = bloqueActual;
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		cuadruplo->Operando2 = produccion[2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 31:
		//imprimirCuadruplos();
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					ElementoGramatical* o = listaCuadruplos[i]->Operador;
					if (t == tope && o == NULL) {
						listaCuadruplos[i]->Operador = T_Igual;
						listaCuadruplos[i]->Operando2 = NULL;
						listaCuadruplos[i]->tipo = TiposDeCuadruplos::Asignacion;
						break;
					}
				}
		}
		//imprimirCuadruplos();
		break;
	case 32:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 33:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					if (t == tope) {
						listaCuadruplos[i]->Operador = terminal;
						break;
					}
				}
		}
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		cuadruplo->Operando2 = produccion[2];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 34:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					ElementoGramatical* o = listaCuadruplos[i]->Operador;
					if (t == tope && o == NULL) {
						listaCuadruplos[i]->Operador = T_Igual;
						listaCuadruplos[i]->Operando2 = NULL;
						listaCuadruplos[i]->tipo = TiposDeCuadruplos::Asignacion;
						break;
					}
				}
		}
		break;

	case 37:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 38:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
			if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
				NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
				if (t == tope) {
					listaCuadruplos[i]->Operador = terminal;
					break;
				}
			}
		}
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		cuadruplo->Operando2 = produccion[2];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 39:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					ElementoGramatical* o = listaCuadruplos[i]->Operador;
					if (t == tope && o == NULL) {
						listaCuadruplos[i]->Operador = T_Igual;
						listaCuadruplos[i]->Operando2 = NULL;
						listaCuadruplos[i]->tipo = TiposDeCuadruplos::Asignacion;
						break;
					}
				}
		}
		break;

	case 46:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 47:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = terminal;
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 48:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = terminal;
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 49:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					if (t == tope) {
						listaCuadruplos[i]->Operador = terminal;
						break;
					}
				}
		}
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		cuadruplo->Operando2 = produccion[2];
		cuadruplo->bloque = bloqueActual;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 50:
		for (int i = (int)listaCuadruplos.size() - 1; i >= 0; i--) {
			if (listaCuadruplos[i]->Operando2 != NULL)
				if (listaCuadruplos[i]->Operando2->getTipo() == NOTERMINAL) {
					NoTerminal* t = (NoTerminal*)listaCuadruplos[i]->Operando2;
					ElementoGramatical* o = listaCuadruplos[i]->Operador;
					if (t == tope && o == NULL) {
						listaCuadruplos[i]->Operador = T_Igual;
						listaCuadruplos[i]->Operando2 = NULL;
						listaCuadruplos[i]->tipo = TiposDeCuadruplos::Asignacion;
						break;
					}
				}
		}
		break;

	default:
		break;
	}
	*/
}

void AnalizadorSintactico::bloques(int linea, int regla)
{
	// Bloques 1: BS, 20: SUBBS
	if (regla == 1 || regla == 20)
	{
		if (bloquePadre == NULL)
		{
			bloquePadre = new TablaSimbolos(linea);
			bloqueActual = bloquePadre;
		}
		else
		{
			TablaSimbolos* nuevo = new TablaSimbolos(bloqueActual, ++nbloque, linea);
			if (regla != 20)
				bloqueActual = nuevo;
		}
	}
	// Bloques 3: LS => lambda
	else if (regla == 3)
	{
		bloqueActual = bloqueActual->padre;
	}
}

bool AnalizadorSintactico::Analizar(vector<Token*> entrada)
{

	vector<Terminal*> terminalesEntrada;
	for (unsigned int i = 0; i < entrada.size(); i++) {
		terminalesEntrada.push_back(new Terminal(entrada[i]));
	}
	vaciarPila();
	pila.push(reglasGramaticales._noterminales.noTerminalBase);
	unsigned int i = 0;


	int regla;
	while (i < entrada.size()) 
	{
		if (pila.empty())
		{
			cout << "1 - Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
			listaErrores.push_back(new ErrorSintactico());
			return false;
		}
		else
		{
			Token* a = ((Terminal*)(pila.top()))->getToken();
			if ((pila.top()->getTipo() == TERMINAL) && (((Terminal*)(pila.top()))->getToken()->esIgual(entrada[i]))) {
				pila.pop();
				//imprimirPila();
				i++;
			}
			else
			{
				if ((pila.top()->getTipo() == TERMINAL)) {
					//imprimirPila();
					cout << "2 - Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
					listaErrores.push_back(new ErrorSintactico());
					return false;	//error

				}
				else
				{
					string x = ((NoTerminal*)(pila.top()))->getID();
					string y = terminalesEntrada[i]->getID();
					regla = reglasGramaticales.matriz[x][y];
					if (regla == -1) {

						cout << "3 - Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
						listaErrores.push_back(new ErrorSintactico());
						return false; // error
					}
					else
					{

						vector<ElementoGramatical*> produccion = *reglasGramaticales.reglas[regla]->getProduccion();
						int nproducciones = (int)produccion.size();

						ElementoGramatical* tope = pila.top();

						bloques(entrada[i]->getLinea(), regla);

						llenarCuadruplos(regla, produccion,&terminalesEntrada, i, tope);
						pila.pop();

						for (size_t i = 0; i < reglasGramaticales.reglas[regla]->getProduccion()->size(); i++)
							if (produccion[nproducciones - i - 1] != LAMBDA)
								pila.push(produccion[nproducciones - i - 1]);
						//imprimirPila();
					}
				}
			}
		}
	}
	optimizar();

	if (listaErrores.size() == 0) error = false;

	return pila.size() == 0;
}

vector<Cuadruplo*> AnalizadorSintactico::Cuadruplos()
{
	return this->listaCuadruplos;
}

void AnalizadorSintactico::imprimirReglas()
{
	cout << "################### Reglas Gramaticales" << endl;
	for (int i = 0; i < reglasGramaticales.reglas.size(); i++) {
		cout << i << ":\t";
		Regla* regla = reglasGramaticales.reglas[i];
		NoTerminal *noTerminal = regla->getNoTerminal();
		cout << noTerminal->getID() << " -> ";
		vector<ElementoGramatical*>* produccion = regla->getProduccion();
		for (int j = 0; j < regla->getProduccion()->size(); j++) {
			ElementoGramatical *elemento = (*produccion)[j];
			if (elemento == LAMBDA) {
				cout << char(955) << " | ";
				continue;
			}
			if (elemento->getTipo() == TERMINAL) {
				Terminal* terminal = (Terminal*)elemento;
				cout << terminal->getID() << " | ";
			}
			else {
				NoTerminal* nterminal = (NoTerminal*)elemento;
				cout << nterminal->getID() << "| ";
			}
		}
		cout << endl;
	}
}

void AnalizadorSintactico::imprimirPila()
{
	cout << "Pila: -----------------" << endl;
	vector<ElementoGramatical*> temp;
	if (pila.empty()) {
		cout << "vacia" << endl;
		return;
	}
	while (!pila.empty()) {
		ElementoGramatical* e = pila.top();
		if (e->getTipo() == TERMINAL) {
			Terminal* t = (Terminal*)e;
			cout << t->getToken()->getLexema() << "(" << e << ")" << endl;
		}
		else {
			NoTerminal* t = (NoTerminal*)e;
			cout << t->getID() << "(" << e << ")" << endl;
		}
		temp.push_back(e);
		pila.pop();
	}
	
	for (vector<ElementoGramatical*>::iterator it = temp.end() - 1; it != temp.begin(); --it) {
		pila.push(*it);
	}

	pila.push(temp[0]);

	cout << "-----------------------" << endl;
}

void AnalizadorSintactico::imprimirCuadruplos()
{
	cout << endl << "Lista Cuadruplos" << endl;
	for (int i = 0; i < listaCuadruplos.size(); i++) {
		
		if (listaCuadruplos[i]->Resultado == NULL)
			cout << i << "\t: NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Resultado->getTipo() == TERMINAL)
				cout << i << "\t: " << (((Terminal*)(listaCuadruplos[i]->Resultado))->getToken()->getLexema());
			else
				cout << i << "\t: " << ((NoTerminal*)(listaCuadruplos[i]->Resultado))->getID();
			cout << "(" << listaCuadruplos[i]->Resultado << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operando1 == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operando1->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando1))->getToken()->getLexema());
			else
				cout << ((NoTerminal*)(listaCuadruplos[i]->Operando1))->getID();
			cout << "(" << listaCuadruplos[i]->Operando1 << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operador == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operador->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operador))->getToken()->getLexema());
			else
				cout << ((NoTerminal*)(listaCuadruplos[i]->Operador))->getID();
			cout << "(" << listaCuadruplos[i]->Operador << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operando2 == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operando2->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando2))->getToken()->getLexema());
			else
				cout << ((NoTerminal*)(listaCuadruplos[i]->Operando2))->getID();
			cout << "(" << listaCuadruplos[i]->Operando2 << ")" << "\t";
		}
		cout << listaCuadruplos[i]->tipo;
		cout << endl;
	}
}
