#include "stdafx.h"
#include "AnalizadorSintactico.h"

#include <iostream>

using namespace std;

void AnalizadorSintactico::llenarReglas()
{

	this->cantidadReglas = 11;

	reglasGramaticales = new Regla*[cantidadReglas];

	ElementoGramatical** produccion;
	int cantidadProducciones = 0;


	// Regla 0 : < LS > → < S > < LS >

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::S);
	produccion[1] = new NoTerminal(NoTerminales::LS);
	reglasGramaticales[0] = new Regla(new NoTerminal(NoTerminales::LS), produccion, cantidadProducciones);

	// Regla 1 : < LS > → λ

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[1] = new Regla(new NoTerminal(NoTerminales::LS), produccion, cantidadProducciones);

	// Regla 2 : < S > → < SD > 

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SD);
	reglasGramaticales[2] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);

	// Regla 3 : < SD > → < TD > < VA > < RD > ; 

	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::TD);
	produccion[1] = new NoTerminal(NoTerminales::VA);
	produccion[2] = new NoTerminal(NoTerminales::RD);
	produccion[3] = new Terminal(new Token(";",TipoToken::Delimitador));
	reglasGramaticales[3] = new Regla(new NoTerminal(NoTerminales::SD), produccion , cantidadProducciones);

	terminales.push_back((Terminal*)produccion[3]);

	// Regla 4 : < RD > → , < VA > < RD >

	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token(",", TipoToken::Delimitador));
	produccion[1] = new NoTerminal(NoTerminales::VA);
	produccion[2] = new NoTerminal(NoTerminales::RD);
	reglasGramaticales[4] = new Regla(new NoTerminal(NoTerminales::RD), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	// Regla 5 : < RD > → λ

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[5] = new Regla(new NoTerminal(NoTerminales::RD), produccion, cantidadProducciones);

	// Regla 6 : < VA > → id < A > 

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador));
	produccion[1] = new NoTerminal(NoTerminales::A);
	reglasGramaticales[6] = new Regla(new NoTerminal(NoTerminales::VA), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	// Regla 7 : < A > → = < EM > 

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("=", TipoToken::Operador));
	produccion[1] = new NoTerminal(NoTerminales::EM);
	reglasGramaticales[7] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	// Regla 8 : < A > → λ

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[8] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);

	// Regla 9 : < TD > → int

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("entero", TipoToken::PalabraReservada));
	reglasGramaticales[9] = new Regla(new NoTerminal(NoTerminales::TD), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	// Regla 10 : < EM > → Expresion Matemática

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Numero", TipoToken::ConstanteEntera));
	reglasGramaticales[10] = new Regla(new NoTerminal(NoTerminales::EM), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
}

void AnalizadorSintactico::llenarMatriz()
{
	
	for (unsigned int j = 0; j < terminales.size(); j++) {
		cout << "\t" << terminales[j]->getID() << "\t";
	}
	cout << endl << endl;
	
	for (int i = 0; i < NoTerminales::Cantidad; i++) {
		switch (i)
		{
		case 0:
			cout << "LS";
			break;
		case 1:
			cout << "S";
			break;
		case 2:
			cout << "SD";
			break;
		case 3:
			cout << "RD";
			break;
		case 4:
			cout << "VA";
			break;
		case 5:
			cout << "A";
			break;
		case 6:
			cout << "TD";
			break;
		case 7:
			cout << "EM";
			break;
		default:
			break;
		}
		//cout << i;
		for (unsigned int j = 0; j < terminales.size(); j++) {
			Terminal* temp = terminales[j];
			string id = temp->getID();
			int r = buscarEnReglas(i, (id));
			matriz[i][temp->getID()] = r;
			cout << "\t" << matriz[i][temp->getID()] << "\t";
		}
		cout << endl;
	}

	

}

int AnalizadorSintactico::buscarEnReglas(int noTerminal, string terminal)
{
	int res = -1;
	for (int i = 0; i < cantidadReglas; i++) 
	{
		Regla* regla = reglasGramaticales[i];

		if (regla->getNoTerminal()->getID() == noTerminal) {
			
			if (regla->getProduccion()[0] == LAMBDA) 
			{
				return i;
			}
			else {
				if (regla->getProduccion()[0]->getTipo() == TERMINAL) {
					
						if (((Terminal*)(regla->getProduccion()[0]))->getID() == terminal)
							return i;
					
				}
				else
				{
					res = buscarEnReglas(((NoTerminal*)(regla->getProduccion()[0]))->getID(), terminal);
					if (res > -1) return i;
				}
			}
		}
	}
	return res;
}

bool AnalizadorSintactico::buscarRegla(int noT, ElementoGramatical* primerElemento)
{
	for (int i = 0; i < cantidadReglas; i++) {
		if (reglasGramaticales[i]->getProduccion()[0] == LAMBDA || primerElemento == LAMBDA)
		{
			if (reglasGramaticales[i]->getNoTerminal()->getID() == noT && reglasGramaticales[i]->getProduccion()[0] == primerElemento)
				return true;
		}
		else 
		{
			if (reglasGramaticales[i]->getNoTerminal()->getID() == noT && reglasGramaticales[i]->getProduccion()[0]->getTipo() == primerElemento->getTipo()) {
				if (reglasGramaticales[i]->getProduccion()[0]->getTipo() == TERMINAL) {
					Terminal* t = (Terminal*)reglasGramaticales[i]->getProduccion()[0];
					Terminal* p = (Terminal*)primerElemento;
					if (t->getID() == p->getID()) return true;
				}
				else {
					NoTerminal* t = (NoTerminal*)reglasGramaticales[i]->getProduccion()[0];
					NoTerminal* p = (NoTerminal*)primerElemento;
					if (t->getID() == p->getID()) return true;
				}
			}
		}
	}
	return false;
}

void AnalizadorSintactico::llenarNombresNoTerminales()
{
	NombresNoTerminales[NoTerminales::A] = "A";
	NombresNoTerminales[NoTerminales::EM] = "EM";
	NombresNoTerminales[NoTerminales::LS] = "LS";
	NombresNoTerminales[NoTerminales::RD] = "RD";
	NombresNoTerminales[NoTerminales::S] = "S";
	NombresNoTerminales[NoTerminales::SD] = "SD";
	NombresNoTerminales[NoTerminales::TD] = "TD";
	NombresNoTerminales[NoTerminales::VA] = "VA";
}

AnalizadorSintactico::AnalizadorSintactico()
{
	llenarNombresNoTerminales();
	llenarReglas();
	llenarMatriz();
	noTerminalBase = new NoTerminal(NoTerminales::LS);
}

AnalizadorSintactico::~AnalizadorSintactico()
{
}

bool AnalizadorSintactico::Analizar(vector<Token*> entrada)
{

	vector<Terminal*> terminalesEntrada;
	for (unsigned int i = 0; i < entrada.size(); i++) {
		terminalesEntrada.push_back(new Terminal(entrada[i]));
	}

	pila.push(noTerminalBase);
	//for (unsigned int i = 0; i < entrada.size(); i++) {
	unsigned int i = 0;
	int regla;
	while (i < entrada.size()) {
		if (pila.empty()) return false;
		if ((pila.top()->getTipo() == TERMINAL) && (((Terminal*)(pila.top()))->getToken()->esIgual(entrada[i]))) {
			pila.pop();
			i++;
		}
		else
		{
			if ((pila.top()->getTipo() == TERMINAL)) {
				while (!pila.empty())
					pila.pop();
				return false;	//error
			}
			else
			{
				int x = ((NoTerminal*)(pila.top()))->getID();
				string y = terminalesEntrada[i]->getID();
				regla = matriz[x][y];
				if (regla == -1) {
					while (!pila.empty())
						pila.pop();
					return false; // error
				}
				else
				{
					pila.pop();
					
					for (int i = 0; i < reglasGramaticales[regla]->getNumeroProducciones(); i++)
						if (reglasGramaticales[regla]->getProduccion()[reglasGramaticales[regla]->getNumeroProducciones() - i - 1] != LAMBDA)
							pila.push(reglasGramaticales[regla]->getProduccion()[reglasGramaticales[regla]->getNumeroProducciones() - i - 1]);
				}
			}
		}
	}
	
	if (pila.size() == 0) {
		return true;
	}
	else
	{
		
		/*Terminal* t1 = (Terminal*)(pila.top());*/
		/*if (!pila.empty())
		{
			NoTerminal* t = (NoTerminal*)(pila.top());

		}*/
		if (buscarRegla(((NoTerminal*)(pila.top()))->getID(),LAMBDA))
			return true;
		while (!pila.empty()) 
			pila.pop();
		
		return false;
	}
}

void AnalizadorSintactico::imprimirReglas()
{
	cout << "################### Reglas Gramaticales" << endl;
	for (int i = 0; i < cantidadReglas; i++) {
		Regla* regla = reglasGramaticales[i];
		NoTerminal *noTerminal = regla->getNoTerminal();
		cout << NombresNoTerminales[noTerminal->getID()] << " -> ";
		ElementoGramatical** produccion = regla->getProduccion();
		for (int j = 0; j < regla->getNumeroProducciones(); j++) {
			ElementoGramatical *elemento = produccion[j];
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
				cout << NombresNoTerminales[nterminal->getID()] << "| ";
			}
		}
		cout << endl;
	}
}
