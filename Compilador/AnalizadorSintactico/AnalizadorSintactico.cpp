#include "stdafx.h"
#include "AnalizadorSintactico.h"

#include <iostream>
#include <algorithm>

using namespace std;

void AnalizadorSintactico::llenarReglas()
{

	this->cantidadReglas = 56;

	reglasGramaticales = new Regla*[cantidadReglas];

	ElementoGramatical** produccion;
	int cantidadProducciones = 0;

	//Terminales

	Terminal* T_Programa = new Terminal(new Token("Programa", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Programa);
	Terminal* T_ParentesisAbierto = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	terminales.push_back(T_ParentesisAbierto);
	Terminal* T_ParentesisCerrado = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	terminales.push_back(T_ParentesisCerrado);
	Terminal* T_CorchetesAbierto = new Terminal(new Token("{", TipoToken::Delimitador, 0));
	terminales.push_back(T_CorchetesAbierto);
	Terminal* T_CorchetesCerrado = new Terminal(new Token("}", TipoToken::Delimitador, 0));
	terminales.push_back(T_CorchetesCerrado);
	Terminal* T_PuntoYComa = new  Terminal(new Token(";", TipoToken::Delimitador, 0));
	terminales.push_back(T_PuntoYComa);
	Terminal* T_Entero = new  Terminal(new Token("entero", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Entero);
	Terminal* T_Coma = new Terminal(new Token(",", TipoToken::Delimitador, 0));
	terminales.push_back(T_Coma);
	Terminal* T_Id = new Terminal(new Token("id", TipoToken::Identificador, 0));
	terminales.push_back(T_Id);
	Terminal* T_Igual = new Terminal(new Token("=", TipoToken::Operador, 0));
	terminales.push_back(T_Igual);
	Terminal* T_Mientras = new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Mientras);
	Terminal* T_Si = new Terminal(new Token("Si", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Si);
	Terminal* T_Osino = new Terminal(new Token("Osino", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Osino);
	Terminal* T_LeerTeclado = new Terminal(new Token("LeerTeclado", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_LeerTeclado);
	Terminal* T_EscribirPantalla = new Terminal(new Token("EscribirPantalla", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_EscribirPantalla);
	Terminal* T_Hacer = new Terminal(new Token("Hacer", TipoToken::PalabraReservada, 0));
	terminales.push_back(T_Hacer);
	Terminal* T_Mas = new Terminal(new Token("+", TipoToken::Operador, 0));
	terminales.push_back(T_Mas);
	Terminal* T_Menos = new Terminal(new Token("-", TipoToken::Operador, 0));
	terminales.push_back(T_Menos);
	Terminal* T_Numero = new Terminal(new Token("Numero", TipoToken::ConstanteEntera, 0));
	terminales.push_back(T_Numero);
	Terminal* T_Por = new Terminal(new Token("*", TipoToken::Operador, 0));
	terminales.push_back(T_Por);
	Terminal* T_Entre = new Terminal(new Token("/", TipoToken::Operador, 0));
	terminales.push_back(T_Entre);
	Terminal* T_Modulo = new Terminal(new Token("%", TipoToken::Operador, 0));
	terminales.push_back(T_Modulo);
	Terminal* T_MenorIgual = new Terminal(new Token("<=", TipoToken::Operador, 0));
	terminales.push_back(T_MenorIgual);
	Terminal* T_MayorIgual = new Terminal(new Token(">=", TipoToken::Operador, 0));
	terminales.push_back(T_MayorIgual);
	Terminal* T_IgualIgual = new Terminal(new Token("==", TipoToken::Operador, 0));
	terminales.push_back(T_IgualIgual);
	Terminal* T_Diferente = new Terminal(new Token("!=", TipoToken::Operador, 0));
	terminales.push_back(T_Diferente);
	Terminal* T_Menor = new Terminal(new Token("<", TipoToken::Operador, 0));
	terminales.push_back(T_Menor);
	Terminal* T_Mayor = new Terminal(new Token(">", TipoToken::Operador, 0));
	terminales.push_back(T_Mayor);
	Terminal* T_Or = new Terminal(new Token("||", TipoToken::Operador, 0));
	terminales.push_back(T_Or);
	Terminal* T_And = new Terminal(new Token("&&", TipoToken::Operador, 0));
	terminales.push_back(T_And);

	//No Terminales

	NoTerminal* P = new NoTerminal(NoTerminales::P);
	NoTerminal* BS = new NoTerminal(NoTerminales::BS);
	NoTerminal* LS = new NoTerminal(NoTerminales::LS);
	NoTerminal* S = new NoTerminal(NoTerminales::S);
	NoTerminal* SD = new NoTerminal(NoTerminales::SD);
	NoTerminal* SA = new NoTerminal(NoTerminales::SA);
	NoTerminal* SC = new NoTerminal(NoTerminales::SC);
	NoTerminal* SM = new NoTerminal(NoTerminales::SM);
	NoTerminal* SL = new NoTerminal(NoTerminales::SL);
	NoTerminal* SE = new NoTerminal(NoTerminales::SE);
	NoTerminal* SHM = new NoTerminal(NoTerminales::SHM);
	NoTerminal* TD = new NoTerminal(NoTerminales::TD);
	NoTerminal* VA = new NoTerminal(NoTerminales::VA);
	NoTerminal* RD = new NoTerminal(NoTerminales::RD);
	NoTerminal* A = new NoTerminal(NoTerminales::A);
	NoTerminal* EM = new NoTerminal(NoTerminales::EM);
	NoTerminal* T = new NoTerminal(NoTerminales::T);
	NoTerminal* LT = new NoTerminal(NoTerminales::LT);
	NoTerminal* OP1 = new NoTerminal(NoTerminales::OP1);
	NoTerminal* F = new NoTerminal(NoTerminales::F);
	NoTerminal* LF = new NoTerminal(NoTerminales::LF);
	NoTerminal* OP2 = new NoTerminal(NoTerminales::OP2);
	NoTerminal* SUBBS = new NoTerminal(NoTerminales::SUBBS);
	NoTerminal* ELSE = new NoTerminal(NoTerminales::ELSE);
	NoTerminal* OL = new NoTerminal(NoTerminales::OL);
	NoTerminal* C = new NoTerminal(NoTerminales::C);
	NoTerminal* OP3 = new NoTerminal(NoTerminales::OP3);
	NoTerminal* OP4 = new NoTerminal(NoTerminales::OP4);
	NoTerminal* LOL = new NoTerminal(NoTerminales::LOL);
	NoTerminal* LC = new NoTerminal(NoTerminales::LC);
	
	//Regla 0: <P> → Programa ( ) <BS>
	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Programa;
	produccion[1] = T_ParentesisAbierto;
	produccion[2] = T_ParentesisCerrado;
	produccion[3] = BS;
	reglasGramaticales[0] = new Regla(P, produccion, cantidadProducciones);

	//Regla 1: <BS> → { <LS> }
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_CorchetesAbierto;
	produccion[1] = LS;
	produccion[2] = T_CorchetesCerrado;
	reglasGramaticales[1] = new Regla(BS, produccion, cantidadProducciones);
	
	//Regla 2: <LS> → <S> <LS>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = S;
	produccion[1] = LS;
	reglasGramaticales[2] = new Regla(LS, produccion, cantidadProducciones);


	//Regla 3: <LS> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[3] = new Regla(LS, produccion, cantidadProducciones);


	//Regla 4: <S> → <SD>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SD;
	reglasGramaticales[4] = new Regla(S, produccion, cantidadProducciones);


	//Regla 5: <S> → <SA>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SA;
	reglasGramaticales[5] = new Regla(S, produccion, cantidadProducciones);


	//Regla 6: <S> → <SC>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SC;
	reglasGramaticales[6] = new Regla(S, produccion, cantidadProducciones);


	//Regla 7: <S> → <SM>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SM;
	reglasGramaticales[7] = new Regla(S, produccion, cantidadProducciones);


	//Regla 8: <S> → <SL>
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SL;
	reglasGramaticales[8] = new Regla(S, produccion, cantidadProducciones);


	//Regla 9: <S> → <SE>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SE;
	reglasGramaticales[9] = new Regla(S, produccion, cantidadProducciones);


	//Regla 10: <S> → <SHM>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = SHM;
	reglasGramaticales[10] = new Regla(S, produccion, cantidadProducciones);

	
	//Regla 11: <SD> → <TD> <VA> <RD> ;
	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = TD;
	produccion[1] = VA;
	produccion[2] = RD;
	produccion[3] = T_PuntoYComa;
	reglasGramaticales[11] = new Regla(SD, produccion, cantidadProducciones);
	
	//Regla 12: <TD> → entero

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Entero;
	reglasGramaticales[12] = new Regla(TD, produccion, cantidadProducciones);

	//Regla 13: <RD> → , <VA> <RD>

	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Coma;
	produccion[1] = VA;
	produccion[2] = RD;
	reglasGramaticales[13] = new Regla(RD, produccion, cantidadProducciones);

	//Regla 14: <RD> → LAMBDA

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[14] = new Regla(RD, produccion, cantidadProducciones);

	//Regla 15: <VA> → id <A>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Id;
	produccion[1] = A;
	reglasGramaticales[15] = new Regla(VA, produccion, cantidadProducciones);

	reglasGramaticales[15]->setPlantilla(produccion[0], T_Entero,new Terminal(new Token("Declaracion", 200, 0)), NULL, TiposDeCuadruplos::Declaracion);

	//Regla 16: <A> → = <EM>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Igual;
	produccion[1] = EM;
	reglasGramaticales[16] = new Regla(A, produccion, cantidadProducciones);

	reglasGramaticales[16]->setPlantilla(NULL, produccion[1], produccion[0], NULL, TiposDeCuadruplos::Asignacion);

	//Regla 17: <A> → LAMBDA

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[17] = new Regla(A, produccion, cantidadProducciones);


	//Regla 18: <SA> → id = <EM> ;

	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Id;
	produccion[1] = T_Igual;
	produccion[2] = EM;
	produccion[3] = T_PuntoYComa;
	reglasGramaticales[18] = new Regla(SA, produccion, cantidadProducciones);

	reglasGramaticales[18]->setPlantilla(produccion[0], produccion[2], produccion[1], NULL, TiposDeCuadruplos::Asignacion);

	//Regla 19: <SM> → Mientras ( <EM> ) <SUBBS>

	cantidadProducciones = 5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Mientras;
	produccion[1] = T_ParentesisAbierto;
	produccion[2] = EM;
	produccion[3] = T_ParentesisCerrado;
	produccion[4] = SUBBS;
	reglasGramaticales[19] = new Regla(SM, produccion, cantidadProducciones);

	// Regla 20 : <SUBBS> → <S>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = S;
	reglasGramaticales[20] = new Regla(SUBBS, produccion, cantidadProducciones);

	// Regla 21 : <SUBBS> → <BS>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = BS;
	reglasGramaticales[21] = new Regla(SUBBS, produccion, cantidadProducciones);

	// Regla 22 : <SC> → Si ( <EM> ) <SUBBS> <ELSE>

	cantidadProducciones = 6;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Si;
	produccion[1] = T_ParentesisAbierto;
	produccion[2] = EM;
	produccion[3] = T_ParentesisCerrado;
	produccion[4] = SUBBS;
	produccion[5] = ELSE;
	reglasGramaticales[22] = new Regla(SC, produccion, cantidadProducciones);

	// Regla 23 : <ELSE> → Osino <SUBBS>

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Osino;
	produccion[1] = SUBBS;
	reglasGramaticales[23] = new Regla(ELSE, produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	
	//Regla 24: <ELSE> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[24] = new Regla(ELSE, produccion, cantidadProducciones);
	
	
	//Regla: 25 SL -> LeerTeclado (id) ;

	cantidadProducciones = 5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_LeerTeclado;
	produccion[1] = T_ParentesisAbierto;
	produccion[2] = T_Id;
	produccion[3] = T_ParentesisCerrado;
	produccion[4] = T_PuntoYComa;
	reglasGramaticales[25] = new Regla(SL, produccion, cantidadProducciones);

	reglasGramaticales[25]->setPlantilla(produccion[2], NULL, produccion[0], NULL, TiposDeCuadruplos::Lectura);

	//Regla: 26 SE -> EscribirPantalla( <EM> );
	cantidadProducciones =5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_EscribirPantalla;
	produccion[1] = T_ParentesisAbierto;
	produccion[2] = EM;
	produccion[3] = T_ParentesisCerrado;
	produccion[4] = T_PuntoYComa;
	reglasGramaticales[26] = new Regla(new NoTerminal(NoTerminales::SE), produccion, cantidadProducciones);
	
	reglasGramaticales[26]->setPlantilla(produccion[0], produccion[2], NULL, NULL, TiposDeCuadruplos::Escritura);

	//Regla 27: <SHM> → Hacer <SUBBS> Mientras ( <EM> ) ;
	cantidadProducciones = 7;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Hacer;
	produccion[1] = SUBBS;
	produccion[2] = T_Mientras;
	produccion[3] = T_ParentesisAbierto;
	produccion[4] = EM;
	produccion[5] = T_ParentesisCerrado;
	produccion[6] = T_PuntoYComa;
	reglasGramaticales[27] = new Regla(SHM, produccion, cantidadProducciones);



	//Regla 28: <EM> → <OL> <LOL>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = OL;
	produccion[1] = LOL;
	reglasGramaticales[28] = new Regla(EM, produccion, cantidadProducciones);

	reglasGramaticales[28]->setPlantilla(reglasGramaticales[28]->getNoTerminal(), produccion[0], NULL, produccion[1], TiposDeCuadruplos::Operacion);

	//REGLA 29: OL -> <C> <LC>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = C;
	produccion[1] = LC;
	reglasGramaticales[29] = new Regla(OL, produccion, cantidadProducciones);

	reglasGramaticales[29]->setPlantilla(reglasGramaticales[29]->getNoTerminal(), produccion[0], NULL, produccion[1],TiposDeCuadruplos::Operacion);


	//Regla 30: <LOL> → <OP1> <OL> <LOL>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = OP1;
	produccion[1] = OL;
	produccion[2] = LOL;
	reglasGramaticales[30] = new Regla(LOL, produccion, cantidadProducciones);

	reglasGramaticales[30]->setPlantilla(reglasGramaticales[30]->getNoTerminal(), produccion[1], NULL, produccion[2], TiposDeCuadruplos::Operacion);

	//Regla 31: LOL -> Lambda
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[31] = new Regla(LOL, produccion, cantidadProducciones);

	// REGLA 32 : C -> <T> <LT>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T;
	produccion[1] = LT;
	reglasGramaticales[32] = new Regla(C, produccion, cantidadProducciones);

	reglasGramaticales[32]->setPlantilla(reglasGramaticales[32]->getNoTerminal(), produccion[0], NULL, produccion[1], TiposDeCuadruplos::Operacion);

	//Regla 33: <LC> → <OP2> <C> <LC>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = OP2;
	produccion[1] = C;
	produccion[2] = LC;
	reglasGramaticales[33] = new Regla(LC, produccion, cantidadProducciones);

	reglasGramaticales[33]->setPlantilla(reglasGramaticales[33]->getNoTerminal(), produccion[1], NULL, produccion[2], TiposDeCuadruplos::Operacion);

	//Regla 34: LC -> Lambda
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[34] = new Regla(LC, produccion, cantidadProducciones);

	//Regla 35: OP1 -> ||
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Or;
	reglasGramaticales[35] = new Regla(OP1, produccion, cantidadProducciones);

	//Regla 36: OP1 -> &&
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_And;
	reglasGramaticales[36] = new Regla(OP1, produccion, cantidadProducciones);

	//Regla 37: <T> → <F> <LF>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = F;
	produccion[1] = LF;
	reglasGramaticales[37] = new Regla(T, produccion, cantidadProducciones);

	reglasGramaticales[37]->setPlantilla(reglasGramaticales[37]->getNoTerminal(), produccion[0], NULL, produccion[1], TiposDeCuadruplos::Operacion);

	//Regla 38: <LT> → <OP3> <T> <LT>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = OP3;
	produccion[1] = T;
	produccion[2] = LT;
	reglasGramaticales[38] = new Regla(LT, produccion, cantidadProducciones);

	reglasGramaticales[38]->setPlantilla(reglasGramaticales[38]->getNoTerminal(), produccion[1], NULL, produccion[2], TiposDeCuadruplos::Operacion);

	//Regla 39: <LT> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[39] = new Regla(LT, produccion, cantidadProducciones);

	//Regla 40 op2-> <=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_MenorIgual;
	reglasGramaticales[40] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 41 op2-> >=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_MayorIgual;
	reglasGramaticales[41] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 42 op2-> ==
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_IgualIgual;
	reglasGramaticales[42] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 43 op2-> !=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Diferente;
	reglasGramaticales[43] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 44 op2-> <
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Menor;
	reglasGramaticales[44] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 45 op2-> >
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Mayor;
	reglasGramaticales[45] = new Regla(OP2, produccion, cantidadProducciones);

	//Regla 46: <F> → ( <EM> )
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_ParentesisAbierto;
	produccion[1] = EM;
	produccion[2] = T_ParentesisCerrado;
	reglasGramaticales[46] = new Regla(F, produccion, cantidadProducciones);


	reglasGramaticales[46]->setPlantilla(reglasGramaticales[46]->getNoTerminal(), produccion[1], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL, TiposDeCuadruplos::Asignacion);

	//Regla 47: <F> → Numero
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Numero;
	reglasGramaticales[47] = new Regla(F, produccion, cantidadProducciones);

	reglasGramaticales[47]->setPlantilla(reglasGramaticales[47]->getNoTerminal(), produccion[0], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL, TiposDeCuadruplos::Asignacion);

	//Regla 48: <F> → id
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Id;
	reglasGramaticales[48] = new Regla(F, produccion, cantidadProducciones);

	reglasGramaticales[48]->setPlantilla(reglasGramaticales[48]->getNoTerminal(), produccion[0], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL, TiposDeCuadruplos::Asignacion);

	//Regla 49: <LF> → <OP4> <F> <LF>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = OP4;
	produccion[1] = F;
	produccion[2] = LF;
	reglasGramaticales[49] = new Regla(LF, produccion, cantidadProducciones);

	reglasGramaticales[49]->setPlantilla(reglasGramaticales[49]->getNoTerminal(), produccion[1], NULL, produccion[2], TiposDeCuadruplos::Operacion);


	//Regla 50: <LF> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[50] = new Regla(LF, produccion, cantidadProducciones);


	//Regla 51: <OP3> → +
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Mas;
	reglasGramaticales[51] = new Regla(OP3, produccion, cantidadProducciones);



	//Regla 52: <OP3> → -
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Menos;
	reglasGramaticales[52] = new Regla(OP3, produccion, cantidadProducciones);


	//Regla 53: <OP4> → *
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Por;
	reglasGramaticales[53] = new Regla(OP4, produccion, cantidadProducciones);	


	//Regla 54: <OP4> → /
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Entre;
	reglasGramaticales[54] = new Regla(OP4, produccion, cantidadProducciones);	


	//Regla 55: <OP4> → %
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = T_Modulo;
	reglasGramaticales[55] = new Regla(OP4, produccion, cantidadProducciones);
	

}


void AnalizadorSintactico::llenarMatriz()
{
	/*for (unsigned int j = 0; j < terminales.size(); j++) {
		cout << "\t" << terminales[j]->getID() << "\t";
	}*/
	//cout << endl << endl;
	for (int i = 0; i < NoTerminales::Cantidad; i++) {		
		//cout << NombresNoTerminales[i] << "\t";
		for (unsigned int j = 0; j < terminales.size(); j++) {
			Terminal* temp = terminales[j];
			string id = temp->getID();
			int r = buscarEnReglas(i, (id));
			matriz[i][temp->getID()] = r;
			//cout << "\t" << matriz[i][temp->getID()] << "\t";
		}
		//cout << endl;
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
	NombresNoTerminales[NoTerminales::P] = "P";
	NombresNoTerminales[NoTerminales::BS] = "BS";
	NombresNoTerminales[NoTerminales::LS] = "LS";
	NombresNoTerminales[NoTerminales::S] = "S";
	NombresNoTerminales[NoTerminales::SD] = "SD";
	NombresNoTerminales[NoTerminales::SA] = "SA";
	NombresNoTerminales[NoTerminales::SC] = "SC";
	NombresNoTerminales[NoTerminales::SM] = "SM";
	NombresNoTerminales[NoTerminales::SL] = "SL";
	NombresNoTerminales[NoTerminales::SE] = "SE";
	NombresNoTerminales[NoTerminales::SHM] = "SHM";
	NombresNoTerminales[NoTerminales::TD] = "TD";
	NombresNoTerminales[NoTerminales::VA] = "VA";
	NombresNoTerminales[NoTerminales::RD] = "RD";
	NombresNoTerminales[NoTerminales::A] = "A";
	NombresNoTerminales[NoTerminales::EM] = "EM";
	NombresNoTerminales[NoTerminales::LOL] = "LOL";
	NombresNoTerminales[NoTerminales::LC] = "LC";
	NombresNoTerminales[NoTerminales::T] = "T";
	NombresNoTerminales[NoTerminales::LT] = "LT";
	NombresNoTerminales[NoTerminales::OP1] = "OP1";
	NombresNoTerminales[NoTerminales::F] = "F";
	NombresNoTerminales[NoTerminales::LF] = "LF";
	NombresNoTerminales[NoTerminales::OP2] = "OP2";
	NombresNoTerminales[NoTerminales::SUBBS] = "SUBBS";
	NombresNoTerminales[NoTerminales::ELSE] = "ELSE";
	NombresNoTerminales[NoTerminales::OL] = "OL";
	NombresNoTerminales[NoTerminales::C] = "C";
	NombresNoTerminales[NoTerminales::OP3] = "OP3";
	NombresNoTerminales[NoTerminales::OP4] = "OP4";

}

AnalizadorSintactico::AnalizadorSintactico()
{
	llenarNombresNoTerminales();
	llenarReglas();
	llenarMatriz();
	
	voltear = false;

	noTerminalBase = new NoTerminal(NoTerminales::P);
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

	for (size_t i = 0; i < listaCuadruplos.size() - 1; i++)
	{
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

void AnalizadorSintactico::llenarCuadruplos(int nregla, ElementoGramatical** produccion , vector<Terminal*>* entrada, int i, ElementoGramatical* tope)
{
	Terminal* terminal = (*entrada)[i];
	Cuadruplo* cuadruplo = reglasGramaticales[nregla]->getCuadruplo();

	Terminal* T_Igual = new Terminal(new Token("=", TipoToken::Operador, 0));
	//Terminal* T_Si = new Terminal(new Token("Si", TipoToken::Operador, 0));
	//Terminal* T_Osino = new Terminal(new Token("Osino", TipoToken::Operador, 0));
	 
	switch (nregla) {
	/*case 0:
		break;
	case 1:
		break;*/
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
	/*case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;*/
	case 15:
		//voltearTemporal();
		cuadruplo->Resultado = terminal;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 16:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		cuadruplo->Resultado = listaCuadruplos[listaCuadruplos.size() - 1]->Resultado;
		cuadruplo->Operando1 = produccion[1];
		listaCuadruplos.push_back(cuadruplo);
		break;
	/*case 17:
		break;*/
	case 18:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		cuadruplo->Resultado = terminal;
		cuadruplo->Operando1 = produccion[2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 19:
		cuadruplo = new Cuadruplo(
			produccion[2],
			NULL,
			new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Mientras);
		listaCuadruplos.push_back(cuadruplo);
		break;
		/*
	case 20:
		break;
	case 21:
		break;*/
	case 22:
	// crear Bloques
		cuadruplo = new Cuadruplo(
			produccion[2],
			NULL,
			new Terminal(new Token("Si", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Si);
		listaCuadruplos.push_back(cuadruplo);
		//teminar Bloques
	break;
	case 23:
	// crear Bloques
		cuadruplo = new Cuadruplo(
			produccion[1],
			NULL,
			new Terminal(new Token("Osino", TipoToken::PalabraReservada, 0)),
			NULL,
			TiposDeCuadruplos::Osino);
		listaCuadruplos.push_back(cuadruplo);

	break;
	//teminar Bloques
	
		/*
	case 24:
		break;*/
	case 25:
		//voltearTemporal();
		cuadruplo->Resultado = (*entrada)[i + 2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 26:

		voltear = true;
		voltearDesde = (int)listaCuadruplos.size();

		cuadruplo->Operando1 = produccion[2];
		listaCuadruplos.push_back(cuadruplo);
		break;
	/*case 27:
		break;*/
	case 28:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 29:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
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
	/*case 35:
		break;
	case 36:
		break;*/
	case 37:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[0];
		cuadruplo->Operando2 = produccion[1];
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
	/*case 40:
		break;
	case 41:
		break;
	case 42:
		break;
	case 43:
		break;
	case 44:
		break;
	case 45:
		break;*/
	case 46:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = produccion[1];
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 47:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = terminal;
		listaCuadruplos.push_back(cuadruplo);
		break;
	case 48:
		cuadruplo->Resultado = tope;
		cuadruplo->Operando1 = terminal;
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
	/*case 51:
		break;
	case 52:
		break;
	case 53:
		break;
	case 54:
		break;
	case 55:
		break;*/
	default:
		//voltearTemporal();
		break;
	}
	/*cout << "Regla: " << nregla << endl;
	imprimirCuadruplos();
	cout << "------------------" << endl;*/
}

bool AnalizadorSintactico::Analizar(vector<Token*> entrada)
{

	vector<Terminal*> terminalesEntrada;
	for (unsigned int i = 0; i < entrada.size(); i++) {
		terminalesEntrada.push_back(new Terminal(entrada[i]));
	}
	vaciarPila();
	pila.push(noTerminalBase);
	unsigned int i = 0;
	int regla;
	while (i < entrada.size()) 
	{
		if (pila.empty())
		{
			cout << "1 - Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
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
					return false;	//error

				}
				else
				{
					int x = ((NoTerminal*)(pila.top()))->getID();
					string y = terminalesEntrada[i]->getID();
					regla = matriz[x][y];
					if (regla == -1) {

						cout << "3 - Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
						return false; // error
					}
					else
					{
						/*if (regla == 18 || regla == 16)
							voltear = true;
						else if (regla == 36 || regla == 37 || regla == 38 || regla == 39) {
							voltear = false;
							if (!listaCuadruplosTemporal.empty())
								for (int i = listaCuadruplosTemporal.size(); i >= 0; i--)
									listaCuadruplos.push_back(listaCuadruplosTemporal[i]);
						}*/

						ElementoGramatical** produccion = reglasGramaticales[regla]->getProduccion();
						int nproducciones = reglasGramaticales[regla]->getNumeroProducciones();

						ElementoGramatical* tope = pila.top();

						llenarCuadruplos(regla, produccion,&terminalesEntrada, i, tope);
						pila.pop();

						for (int i = 0; i < reglasGramaticales[regla]->getNumeroProducciones(); i++)
							if (produccion[nproducciones - i - 1] != LAMBDA)
								pila.push(produccion[nproducciones - i - 1]);
						//imprimirPila();
					}
				}
			}
		}
	}
	optimizar();

	return pila.size() == 0;
	/*if (pila.size() == 0) {
		return true;
	}
	else
	{
		if (buscarRegla(((NoTerminal*)(pila.top()))->getID(),LAMBDA))
			return true;
		cout << "Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
		while (!pila.empty()) 
			pila.pop();
			
		return false;
	}*/
}

vector<Cuadruplo*> AnalizadorSintactico::Cuadruplos()
{
	return this->listaCuadruplos;
}

void AnalizadorSintactico::imprimirReglas()
{
	cout << "################### Reglas Gramaticales" << endl;
	for (int i = 0; i < cantidadReglas; i++) {
		cout << i << ":\t";
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
			cout << NombresNoTerminales[t->getID()] << "(" << e << ")" << endl;
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
				cout << i << "\t: " << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Resultado))->getID()];
			cout << "(" << listaCuadruplos[i]->Resultado << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operando1 == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operando1->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando1))->getToken()->getLexema());
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operando1))->getID()];
			cout << "(" << listaCuadruplos[i]->Operando1 << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operador == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operador->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operador))->getToken()->getLexema());
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operador))->getID()];
			cout << "(" << listaCuadruplos[i]->Operador << ")" << "\t";
		}
		if (listaCuadruplos[i]->Operando2 == NULL)
			cout << "NULL\t\t";
		else
		{
			if (listaCuadruplos[i]->Operando2->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando2))->getToken()->getLexema());
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operando2))->getID()];
			cout << "(" << listaCuadruplos[i]->Operando2 << ")" << "\t";
		}
		cout << endl;
	}
}
