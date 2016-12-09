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

	mientras = NULL;
	si = NULL;
	osino = NULL;
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

void AnalizadorSintactico::buscarCuadruploAsignarOperadorFaltante(ElementoGramatical* tope, Terminal* terminalEntrada)
{
	for (int it = (int)listaCuadruplos.size() - 1; it >= 0; it--)
	{
		if (listaCuadruplos[it]->Operando2 != NULL)
			if (listaCuadruplos[it]->Operando2->getTipo() == NOTERMINAL)
			{
				NoTerminal* t = (NoTerminal*)listaCuadruplos[it]->Operando2;
				if (t == tope)
				{
					listaCuadruplos[it]->Operador = terminalEntrada;
					break;
				}
			}
	}
}

void AnalizadorSintactico::buscarCuadruploCambiarOperacionPorAsignacion(ElementoGramatical* tope)
{
	for (int it = (int)listaCuadruplos.size() - 1; it >= 0; it--)
	{
		if (listaCuadruplos[it]->Operando2 != NULL)
			if (listaCuadruplos[it]->Operando2->getTipo() == NOTERMINAL)
			{
				NoTerminal* t = (NoTerminal*)listaCuadruplos[it]->Operando2;
				ElementoGramatical* o = listaCuadruplos[it]->Operador;
				if (t == tope && o == NULL)
				{
					listaCuadruplos[it]->Operador = reglasGramaticales._terminales.Igual;
					listaCuadruplos[it]->Operando2 = NULL;
					listaCuadruplos[it]->tipo = TiposDeCuadruplos::Asignacion;
					break;
				}
			}
	}
}


void AnalizadorSintactico::llenarCuadruplos(int nregla, vector<ElementoGramatical*> produccion , vector<Terminal*>* entrada, int i, ElementoGramatical* tope)
{
	
	Terminal* terminalEntrada = (*entrada)[i];

	 
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

		listaCuadruplos.push_back(new Cuadruplo(NULL,NULL,NULL,NULL,TiposDeCuadruplos::Destruccion, bloqueActual));

		if (mientras != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					mientras,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinMientras,
					bloqueActual));
			mientras = NULL;
		}

		if (si != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					si,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinSi,
					bloqueActual));
			osino = si;
			si = NULL;
		}
		else 
		if (osino != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					osino,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinOsino,
					bloqueActual));
			osino = NULL;
		}

		break;
	case 15:

		listaCuadruplos.push_back(
			new Cuadruplo(
				terminalEntrada, 
				reglasGramaticales._terminales.Entero,
				reglasGramaticales._terminales.Declaracion,
				NULL,
				TiposDeCuadruplos::Declaracion,
				bloqueActual));
		break;
	case 16:
		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		listaCuadruplos.push_back(
			new Cuadruplo(
				listaCuadruplos[listaCuadruplos.size() - 1]->Resultado, 
				produccion[1],
				reglasGramaticales._terminales.Igual, 
				NULL, 
				TiposDeCuadruplos::Asignacion, 
				bloqueActual));
		break;
	
	case 18:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		listaCuadruplos.push_back(
			new Cuadruplo(
				terminalEntrada, 
				produccion[2], //EM
				reglasGramaticales._terminales.Igual, 
				NULL, 
				TiposDeCuadruplos::Asignacion, 
				bloqueActual));
		break;
	case 19:
		mientras = new Terminal(new Token("ETIQUETA_MIENTRAS", TipoToken::Cuadruplos, 0));

		listaCuadruplos.push_back(
			new Cuadruplo(
				NULL,
				mientras,
				NULL,
				NULL,
				TiposDeCuadruplos::EtiquetaInicioMientras,
				bloqueActual));

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		listaCuadruplos.push_back(
			new Cuadruplo(
				NULL, 
				produccion[2], //EM
				reglasGramaticales._terminales.Mientras, 
				listaCuadruplos[listaCuadruplos.size() - 1]->Operando1, 
				TiposDeCuadruplos::Mientras, 
				bloqueActual));
		break;
		
	case 20:
	case 21:
		voltearHasta = (int)listaCuadruplos.size() - 1;
		if (voltear) {
			voltearTemporal(voltearDesde, voltearHasta);
			voltear = false;
		}

		break;
	case 22:

		si = new Terminal(new Token("ETIQUETA_SI", TipoToken::Cuadruplos, 0));

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();
		listaCuadruplos.push_back(
			new Cuadruplo(
				NULL, 
				produccion[2], //EM
				reglasGramaticales._terminales.Si, 
				si, 
				TiposDeCuadruplos::Si, 
				bloqueActual));
		break;
	case 23:
		//voltear = true;
		//voltearDesde = (int)listaCuadruplos.size();
		listaCuadruplos.push_back(
			new Cuadruplo(
				NULL, 
				osino, 
				reglasGramaticales._terminales.Osino, 
				NULL, 
				TiposDeCuadruplos::Osino, 
				bloqueActual));
		break;	
	case 25:
		listaCuadruplos.push_back(
			new Cuadruplo(
				(*entrada)[i + 2], 
				NULL, 
				reglasGramaticales._terminales.LeerTeclado, 
				NULL, 
				TiposDeCuadruplos::Lectura, 
				bloqueActual));
		break;
	case 26:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		listaCuadruplos.push_back(
			new Cuadruplo(
				reglasGramaticales._terminales.EscribirPantalla, 
				produccion[2], //EM
				NULL, 
				NULL, 
				TiposDeCuadruplos::Escritura, 
				bloqueActual));
		break;

	case 28:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[0], //OL
				NULL, 
				produccion[1], //LOL
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 29:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[0], //C
				NULL, 
				produccion[1], //LC
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 30:
		buscarCuadruploAsignarOperadorFaltante(tope, terminalEntrada);
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[1], //OL
				NULL, 
				produccion[2], //LOL
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 31:
		buscarCuadruploCambiarOperacionPorAsignacion(tope);
		break;
	case 32:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[0], //T
				NULL, 
				produccion[1], //LT
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 33:
		buscarCuadruploAsignarOperadorFaltante(tope, terminalEntrada);
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope,
				produccion[1],//C,
				NULL,
				produccion[2],// LC,
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 34:
		buscarCuadruploCambiarOperacionPorAsignacion(tope);
		break;

	case 37:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[0],//F,
				NULL, 
				produccion[1],//LF,
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 38:
		buscarCuadruploAsignarOperadorFaltante(tope, terminalEntrada);
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[1],//T,
				NULL, 
				produccion[2],//LT,
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 39:
		buscarCuadruploCambiarOperacionPorAsignacion(tope);
		break;

	case 46:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[1],//EM,
				reglasGramaticales._terminales.Igual, 
				NULL, 
				TiposDeCuadruplos::Asignacion, 
				bloqueActual));
		break;
	case 47:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				terminalEntrada, 
				reglasGramaticales._terminales.Igual, 
				NULL, 
				TiposDeCuadruplos::Asignacion, 
				bloqueActual));
		break;
	case 48:
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				terminalEntrada, 
				reglasGramaticales._terminales.Igual, 
				NULL, 
				TiposDeCuadruplos::Asignacion, 
				bloqueActual));
		break;
	case 49:
		buscarCuadruploAsignarOperadorFaltante(tope, terminalEntrada);
		listaCuadruplos.push_back(
			new Cuadruplo(
				tope, 
				produccion[1],//F,
				NULL, 
				produccion[2],//LF,
				TiposDeCuadruplos::Operacion, 
				bloqueActual));
		break;
	case 50:
		buscarCuadruploCambiarOperacionPorAsignacion(tope);
		break;
	case 56:
		listaCuadruplos.push_back(new Cuadruplo(NULL, NULL, NULL, NULL, TiposDeCuadruplos::Destruccion, bloqueActual));
		if (mientras != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					mientras,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinMientras,
					bloqueActual));
			mientras = NULL;
		}
		if (si != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					si,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinSi,
					bloqueActual));
			osino = si;
			si = NULL;
		}
		else
		if (osino != NULL) {
			listaCuadruplos.push_back(
				new Cuadruplo(
					NULL,
					osino,
					NULL,
					NULL,
					TiposDeCuadruplos::EtiquetaFinOsino,
					bloqueActual));
			osino = NULL;
		}
		break;
	default:
		break;
	}
	/*cout << endl << "------------ Regla: " << nregla;
	imprimirCuadruplos();
	cout << "------------" << endl;*/
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
			//if (regla != 20)
				bloqueActual = nuevo;
		}
	}
	// Bloques 3: LS => lambda 56: SUBBSVacio => LAMBDA
	else if (regla == 3 || regla == 56)
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

						

						llenarCuadruplos(regla, produccion,&terminalesEntrada, i, tope);

						bloques(entrada[i]->getLinea(), regla);

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
		cout << listaCuadruplos[i]->toString() << endl;
	}
}
