#include "stdafx.h"
#include "AnalizadorSintactico.h"

#include <iostream>

using namespace std;

void AnalizadorSintactico::llenarReglas()
{

	this->cantidadReglas = 24;

	reglasGramaticales = new Regla*[cantidadReglas];

	ElementoGramatical** produccion;
	int cantidadProducciones = 0;

	//Regla 0: <P> → Programa ( ) <BS>
	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Programa", TipoToken::PalabraReservada));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador));
	produccion[2] = new Terminal(new Token(")", TipoToken::Delimitador));
	produccion[3] = new NoTerminal(NoTerminales::BS);
	reglasGramaticales[0] = new Regla(new NoTerminal(NoTerminales::P), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[2]);


	//Regla 1: <BS> → { <LS> }
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("{", TipoToken::Delimitador));
	produccion[1] = new NoTerminal(NoTerminales::LS);
	produccion[2] = new Terminal(new Token("}", TipoToken::Delimitador));
	reglasGramaticales[1] = new Regla(new NoTerminal(NoTerminales::BS), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);


	//Regla 2: <LS> → <S> <LS>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::S);
	produccion[1] = new NoTerminal(NoTerminales::LS);
	reglasGramaticales[2] = new Regla(new NoTerminal(NoTerminales::LS), produccion, cantidadProducciones);


	//Regla 3: <LS> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[3] = new Regla(new NoTerminal(NoTerminales::LS), produccion, cantidadProducciones);


	//Regla 4: <S> → <SD>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SD);
	reglasGramaticales[4] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 5: <S> → <SA>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SA);
	reglasGramaticales[5] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 6: <S> → <SC>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SC);
	reglasGramaticales[6] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 7: <S> → <SM>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SM);
	reglasGramaticales[7] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 8: <S> → <SL>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SL);
	reglasGramaticales[8] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 9: <S> → <SE>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SE);
	reglasGramaticales[9] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);


	//Regla 10: <S> → <SHM>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SHM);
	reglasGramaticales[10] = new Regla(new NoTerminal(NoTerminales::S), produccion, cantidadProducciones);

	
	//Regla 11: <SD> → <TD> <VA> <RD> ;
	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::TD);
	produccion[1] = new NoTerminal(NoTerminales::VA);
	produccion[2] = new NoTerminal(NoTerminales::RD);
	reglasGramaticales[11] = new Regla(new NoTerminal(NoTerminales::SD), produccion, cantidadProducciones);
	//Regla 12: <TD> → entero

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new  Terminal(new Token("entero", TipoToken::PalabraReservada));
	reglasGramaticales[12] = new Regla(new NoTerminal(NoTerminales::TD), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 13: <RD> → , <VA> <RD>

	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token(",", TipoToken::Delimitador));
	produccion[1] = new NoTerminal(NoTerminales::VA);
	produccion[2] = new NoTerminal(NoTerminales::RD);
	reglasGramaticales[13] = new Regla(new NoTerminal(NoTerminales::RD), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 14: <RD> → LAMBDA

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[14] = new Regla(new NoTerminal(NoTerminales::RD), produccion, cantidadProducciones);

	//Regla 15: <VA> → id <A>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador));
	produccion[1] = new NoTerminal(NoTerminales::A);
	reglasGramaticales[15] = new Regla(new NoTerminal(NoTerminales::VA), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 16: <A> → = <EM>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("=", TipoToken::Operador));
	produccion[1] = new NoTerminal(NoTerminales::EM);
	reglasGramaticales[16] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 17: <A> → LAMBDA

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[17] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);


	//Regla 18: <S> → <SM>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::SM);
	reglasGramaticales[18] = new Regla(new NoTerminal(NoTerminales::SD), produccion, cantidadProducciones);


	//Regla 19: <SA> → id = <EM>

	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador));
	produccion[1] = new Terminal(new Token("=", TipoToken::Operador));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	reglasGramaticales[19] = new Regla(new NoTerminal(NoTerminales::SA), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 20: <SM> → Mientras ( <EM> ) <SUBBS>

	cantidadProducciones = 5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Mientras", TipoToken::PalabraReservada));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador));
	produccion[4] = new NoTerminal(NoTerminales::SUBBS);
	reglasGramaticales[20] = new Regla(new NoTerminal(NoTerminales::SA), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);

	// Regla 21 : <SUBBS> → <S>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::S);
	reglasGramaticales[1] = new Regla(new NoTerminal(NoTerminales::SUBBS), produccion, cantidadProducciones);

	// Regla 22 : <SUBBS> → <BS>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::BS);
	reglasGramaticales[1] = new Regla(new NoTerminal(NoTerminales::SUBBS), produccion, cantidadProducciones);

	// Regla 23 : <SD> → Si ( <EM> ) <SUBBS> <ELSE>

	cantidadProducciones = 6;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Si", TipoToken::PalabraReservada));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador));
	produccion[4] = new NoTerminal(NoTerminales::SUBBS);
	produccion[5] = new NoTerminal(NoTerminales::ELSE);
	reglasGramaticales[6] = new Regla(new NoTerminal(NoTerminales::SD), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);

	// Regla 24 : <ELSE> → Osino <SUBBS>

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Osino", TipoToken::PalabraReservada));
	produccion[1] = new NoTerminal(NoTerminales::SUBBS);
	reglasGramaticales[2] = new Regla(new NoTerminal(NoTerminales::ELSE), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	










	//Regla 25: <ELSE> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[25] = new Regla(new NoTerminal(NoTerminales::ELSE), produccion, cantidadProducciones);

	//Regla 26: <SHM> → Hacer <SUBBS> Mientras ( <EM> ) ;
	cantidadProducciones = 6;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Hacer", TipoToken::PalabraReservada));
	produccion[1] = new NoTerminal(NoTerminales::SUBBS);
	produccion[2] = new Terminal(new Token("Mientras", TipoToken::PalabraReservada));
	produccion[3] = new Terminal(new Token("(", TipoToken::Delimitador));
	produccion[4] = new NoTerminal(NoTerminales::EM);
	produccion[5] = new Terminal(new Token(")", TipoToken::Delimitador));
	reglasGramaticales[26] = new Regla(new NoTerminal(NoTerminales::SHM), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[2]);
	terminales.push_back((Terminal*)produccion[3]);
	terminales.push_back((Terminal*)produccion[5]);

	//Regla 27: <EM> → <EXP>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::EXP);
	reglasGramaticales[27] = new Regla(new NoTerminal(NoTerminales::EM), produccion, cantidadProducciones);

	//Regla 28: <EXP> → <T> <LT>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::T);
	produccion[1] = new NoTerminal(NoTerminales::LT);
	reglasGramaticales[28] = new Regla(new NoTerminal(NoTerminales::EXP), produccion, cantidadProducciones);

	//Regla 29: <LT> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[29] = new Regla(new NoTerminal(NoTerminales::LT), produccion, cantidadProducciones);

	//Regla 30: <LT> → <OP1> <T> <LT>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP1);
	produccion[1] = new NoTerminal(NoTerminales::T);
	produccion[2] = new NoTerminal(NoTerminales::LT);
	reglasGramaticales[30] = new Regla(new NoTerminal(NoTerminales::LT), produccion, cantidadProducciones);



	//Regla 31: <OP1> → +
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("+", TipoToken::Operador));
	reglasGramaticales[31] = new Regla(new NoTerminal(NoTerminales::OP1), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 32: <OP1> → -
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("-", TipoToken::Operador));
	reglasGramaticales[32] = new Regla(new NoTerminal(NoTerminales::OP1), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 33: <T> → <F> <LF>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::F);
	produccion[1] = new NoTerminal(NoTerminales::LF);
	reglasGramaticales[33] = new Regla(new NoTerminal(NoTerminales::T), produccion, cantidadProducciones);


	//Regla 34: <LF> → <OP2> <F> <LF>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP2);
	produccion[1] = new NoTerminal(NoTerminales::F);
	produccion[2] = new NoTerminal(NoTerminales::LF);
	reglasGramaticales[34] = new Regla(new NoTerminal(NoTerminales::LF), produccion, cantidadProducciones);


	//Regla 35: <LF> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[35] = new Regla(new NoTerminal(NoTerminales::LF), produccion, cantidadProducciones);


	//Regla 36: <F> → ( <EXP> )
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("(", TipoToken::Delimitador));
	produccion[1] = new NoTerminal(NoTerminales::EXP);
	produccion[2] = new Terminal(new Token(")", TipoToken::Delimitador));
	reglasGramaticales[36] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[2]);


	//Regla 37: <F> → Numero
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Numero", TipoToken::ConstanteEntera));
	reglasGramaticales[37] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 38: <F> → id
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador));
	reglasGramaticales[38] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 39: <OP2> → *
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("*", TipoToken::Operador));
	reglasGramaticales[39] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 40: <OP2> → /
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("/", TipoToken::Operador));
	reglasGramaticales[40] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 41: <OP2> → %
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("%", TipoToken::Operador));
	reglasGramaticales[41] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);

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
