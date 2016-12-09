#include "stdafx.h"
#include "ReglasGramaticales.h"

using namespace compilador::sintactico;

ReglasGramaticales::ReglasGramaticales() {

	vector<ElementoGramatical*>* produccion;

	//Regla 0: <P> → Programa ( ) <BS>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Programa);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_noterminales.BS);
	reglas.push_back(new Regla(_noterminales.P, produccion));

	//Regla 1: <BS> → { <LS> }
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.CorchetesAbierto);
	produccion->push_back(_noterminales.LS);
	produccion->push_back(_terminales.CorchetesCerrado);
	reglas.push_back(new Regla(_noterminales.BS, produccion));

	//Regla 2: <LS> → <S> <LS>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.S);
	produccion->push_back(_noterminales.LS);
	reglas.push_back(new Regla(_noterminales.LS, produccion));


	//Regla 3: <LS> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.LS, produccion));


	//Regla 4: <S> → <SD>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SD);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 5: <S> → <SA>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SA);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 6: <S> → <SC>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SC);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 7: <S> → <SM>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SM);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 8: <S> → <SL>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SL);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 9: <S> → <SE>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SE);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 10: <S> → <SHM>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.SHM);
	reglas.push_back(new Regla(_noterminales.S, produccion));


	//Regla 11: <SD> → <TD> <VA> <RD> ;
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.TD);
	produccion->push_back(_noterminales.VA);
	produccion->push_back(_noterminales.RD);
	produccion->push_back(_terminales.PuntoYComa);
	reglas.push_back(new Regla(_noterminales.SD, produccion));

	//Regla 12: <TD> → entero
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Entero);
	reglas.push_back(new Regla(_noterminales.TD, produccion));

	//Regla 13: <RD> → , <VA> <RD>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Coma);
	produccion->push_back(_noterminales.VA);
	produccion->push_back(_noterminales.RD);
	reglas.push_back(new Regla(_noterminales.RD, produccion));

	//Regla 14: <RD> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.RD, produccion));

	//Regla 15: <VA> → id <A>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Id);
	produccion->push_back(_noterminales.A);
	reglas.push_back(new Regla(_noterminales.VA, produccion));

	//Regla 16: <A> → = <EM>				
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Igual);
	produccion->push_back(_noterminales.EM);
	reglas.push_back(new Regla(_noterminales.A, produccion));

	//Regla 17: <A> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.A, produccion));


	//Regla 18: <SA> → id = <EM> ;
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Id);
	produccion->push_back(_terminales.Igual);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.PuntoYComa);
	reglas.push_back(new Regla(_noterminales.SA, produccion));

	//Regla 19: <SM> → Mientras ( <EM> ) <SUBBS>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Mientras);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_noterminales.SUBBS);
	reglas.push_back(new Regla(_noterminales.SM, produccion));

	// Regla 20 : <SUBBS> → <S> <SUBBSVacio>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.S);
	produccion->push_back(_noterminales.SUBBSVacio);
	reglas.push_back(new Regla(_noterminales.SUBBS, produccion));

	// Regla 21 : <SUBBS> → <BS>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.BS);
	reglas.push_back(new Regla(_noterminales.SUBBS, produccion));

	// Regla 22 : <SC> → Si ( <EM> ) <SUBBS> <ELSE>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Si);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_noterminales.SUBBS);
	produccion->push_back(_noterminales.ELSE);
	reglas.push_back(new Regla(_noterminales.SC, produccion));

	// Regla 23 : <ELSE> → Osino <SUBBS>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Osino);
	produccion->push_back(_noterminales.SUBBS);
	reglas.push_back(new Regla(_noterminales.ELSE, produccion));

	//Regla 24: <ELSE> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.ELSE, produccion));


	//Regla: 25 SL -> LeerTeclado (id) ;
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.LeerTeclado);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_terminales.Id);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_terminales.PuntoYComa);
	reglas.push_back(new Regla(_noterminales.SL, produccion));

	//Regla: 26 SE -> EscribirPantalla( <EM> );
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.EscribirPantalla);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_terminales.PuntoYComa);
	reglas.push_back(new Regla(_noterminales.SE, produccion));

	//Regla 27: <SHM> → Hacer <SUBBS> Mientras ( <EM> ) ;
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Hacer);
	produccion->push_back(_noterminales.SUBBS);
	produccion->push_back(_terminales.Mientras);
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.ParentesisCerrado);
	produccion->push_back(_terminales.PuntoYComa);
	reglas.push_back(new Regla(_noterminales.SHM, produccion));



	//Regla 28: <EM> → <OL> <LOL>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.OL);
	produccion->push_back(_noterminales.LOL);
	reglas.push_back(new Regla(_noterminales.EM, produccion));

	//REGLA 29: OL -> <C> <LC>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.C);
	produccion->push_back(_noterminales.LC);
	reglas.push_back(new Regla(_noterminales.OL, produccion));

	//Regla 30: <LOL> → <OP1> <OL> <LOL>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.OP1);
	produccion->push_back(_noterminales.OL);
	produccion->push_back(_noterminales.LOL);
	reglas.push_back(new Regla(_noterminales.LOL, produccion));

	//Regla 31: LOL -> Lambda
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.LOL, produccion));

	// REGLA 32 : C -> <T> <LT>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.T);
	produccion->push_back(_noterminales.LT);
	reglas.push_back(new Regla(_noterminales.C, produccion));

	//Regla 33: <LC> → <OP2> <C> <LC>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.OP2);
	produccion->push_back(_noterminales.C);
	produccion->push_back(_noterminales.LC);
	reglas.push_back(new Regla(_noterminales.LC, produccion));

	//Regla 34: LC -> Lambda
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.LC, produccion));

	//Regla 35: OP1 -> ||
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Or);
	reglas.push_back(new Regla(_noterminales.OP1, produccion));

	//Regla 36: OP1 -> &&
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.And);
	reglas.push_back(new Regla(_noterminales.OP1, produccion));

	//Regla 37: <T> → <F> <LF>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.F);
	produccion->push_back(_noterminales.LF);
	reglas.push_back(new Regla(_noterminales.T, produccion));

	//Regla 38: <LT> → <OP3> <T> <LT>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.OP3);
	produccion->push_back(_noterminales.T);
	produccion->push_back(_noterminales.LT);
	reglas.push_back(new Regla(_noterminales.LT, produccion));

	//Regla 39: <LT> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.LT, produccion));

	//Regla 40 op2-> <=
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.MenorIgual);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 41 op2-> >=
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.MayorIgual);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 42 op2-> ==
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.IgualIgual);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 43 op2-> !=
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Diferente);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 44 op2-> <
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Menor);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 45 op2-> >
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Mayor);
	reglas.push_back(new Regla(_noterminales.OP2, produccion));

	//Regla 46: <F> → ( <EM> )
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.ParentesisAbierto);
	produccion->push_back(_noterminales.EM);
	produccion->push_back(_terminales.ParentesisCerrado);
	reglas.push_back(new Regla(_noterminales.F, produccion));

	//Regla 47: <F> → Numero
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Numero);
	reglas.push_back(new Regla(_noterminales.F, produccion));

	//Regla 48: <F> → id
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Id);
	reglas.push_back(new Regla(_noterminales.F, produccion));

	//Regla 49: <LF> → <OP4> <F> <LF>
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_noterminales.OP4);
	produccion->push_back(_noterminales.F);
	produccion->push_back(_noterminales.LF);
	reglas.push_back(new Regla(_noterminales.LF, produccion));

	//Regla 50: <LF> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.LF, produccion));

	//Regla 51: <OP3> → +
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Mas);
	reglas.push_back(new Regla(_noterminales.OP3, produccion));

	//Regla 52: <OP3> → -
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Menos);
	reglas.push_back(new Regla(_noterminales.OP3, produccion));

	//Regla 53: <OP4> → *
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Por);
	reglas.push_back(new Regla(_noterminales.OP4, produccion));


	//Regla 54: <OP4> → /
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Entre);
	reglas.push_back(new Regla(_noterminales.OP4, produccion));


	//Regla 55: <OP4> → %
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(_terminales.Modulo);
	reglas.push_back(new Regla(_noterminales.OP4, produccion));

	//Regla 56: <SUBBSVacio> → LAMBDA
	produccion = new vector<ElementoGramatical*>();
	produccion->push_back(LAMBDA);
	reglas.push_back(new Regla(_noterminales.SUBBSVacio, produccion));

	llenarMatriz();
}


void ReglasGramaticales::llenarMatriz()
{
	auto terminales = _terminales.Todos();
	auto noterminales = _noterminales.Todos();
	for (int i = 0; i < _noterminales.Count; i++) {
		for (size_t j = 0; j < terminales->size(); j++) {
			Terminal* temp = (*terminales)[j];
			string t_id = temp->getID();
			string nt_id = (*noterminales)[i]->getID();

			int r = buscarEnReglas(nt_id, (t_id));
			matriz[nt_id][t_id] = r;
		}
	}
}

int ReglasGramaticales::buscarEnReglas(string noTerminal, string terminal)
{
	int res = -1;
	for (size_t i = 0; i < reglas.size(); i++)
	{
		Regla* regla = reglas[i];

		if (regla->getNoTerminal()->getID() == noTerminal) {
			vector<ElementoGramatical*> produccion = *regla->getProduccion();
			if (produccion[0] == LAMBDA)
			{
				return (int)i;
			}
			else {
				if (produccion[0]->getTipo() == TERMINAL) {

					if (((Terminal*)(produccion[0]))->getID() == terminal)
						return (int)i;

				}
				else
				{
					res = buscarEnReglas(((NoTerminal*)(produccion[0]))->getID(), terminal);
					if (res > -1) return (int)i;
				}
			}
		}
	}
	return res;
}