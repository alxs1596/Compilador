#include "stdafx.h"
#include "AnalizadorSintactico.h"

#include <iostream>

using namespace std;

void AnalizadorSintactico::llenarReglas()
{

	this->cantidadReglas = 56;

	reglasGramaticales = new Regla*[cantidadReglas];

	ElementoGramatical** produccion;
	int cantidadProducciones = 0;

	
	//Regla 0: <P> → Programa ( ) <BS>
	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Programa", TipoToken::PalabraReservada,0));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[2] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[3] = new NoTerminal(NoTerminales::BS);
	reglasGramaticales[0] = new Regla(new NoTerminal(NoTerminales::P), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[2]);


	//Regla 1: <BS> → { <LS> }
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("{", TipoToken::Delimitador, 0));
	produccion[1] = new NoTerminal(NoTerminales::LS);
	produccion[2] = new Terminal(new Token("}", TipoToken::Delimitador, 0));
	reglasGramaticales[1] = new Regla(new NoTerminal(NoTerminales::BS), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[2]);


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
	produccion[3] = new  Terminal(new Token(";", TipoToken::Delimitador, 0));
	reglasGramaticales[11] = new Regla(new NoTerminal(NoTerminales::SD), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[3]);
	//Regla 12: <TD> → entero

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new  Terminal(new Token("entero", TipoToken::PalabraReservada, 0));
	reglasGramaticales[12] = new Regla(new NoTerminal(NoTerminales::TD), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 13: <RD> → , <VA> <RD>

	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token(",", TipoToken::Delimitador, 0));
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
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador, 0));
	produccion[1] = new NoTerminal(NoTerminales::A);
	reglasGramaticales[15] = new Regla(new NoTerminal(NoTerminales::VA), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	reglasGramaticales[15]->setPlantilla(produccion[0], new Terminal(new Token("entero", TipoToken::PalabraReservada, 0)), new Terminal(new Token("Declaracion", 200, 0)), NULL);

	//Regla 16: <A> → = <EM>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("=", TipoToken::Operador, 0));
	produccion[1] = new NoTerminal(NoTerminales::EM);
	reglasGramaticales[16] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	reglasGramaticales[16]->setPlantilla(NULL, produccion[1], produccion[0], NULL);

	//Regla 17: <A> → LAMBDA

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[17] = new Regla(new NoTerminal(NoTerminales::A), produccion, cantidadProducciones);


	//Regla 18: <SA> → id = <EM> ;

	cantidadProducciones = 4;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador, 0));
	produccion[1] = new Terminal(new Token("=", TipoToken::Operador, 0));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(";", TipoToken::Delimitador, 0));
	reglasGramaticales[18] = new Regla(new NoTerminal(NoTerminales::SA), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);

	reglasGramaticales[18]->setPlantilla(produccion[0], produccion[2], produccion[1], NULL);

	//Regla 19: <SM> → Mientras ( <EM> ) <SUBBS>

	cantidadProducciones = 5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[4] = new NoTerminal(NoTerminales::SUBBS);
	reglasGramaticales[19] = new Regla(new NoTerminal(NoTerminales::SM), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);

	// Regla 20 : <SUBBS> → <S>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::S);
	reglasGramaticales[20] = new Regla(new NoTerminal(NoTerminales::SUBBS), produccion, cantidadProducciones);

	// Regla 21 : <SUBBS> → <BS>

	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::BS);
	reglasGramaticales[21] = new Regla(new NoTerminal(NoTerminales::SUBBS), produccion, cantidadProducciones);

	// Regla 22 : <SC> → Si ( <EM> ) <SUBBS> <ELSE>

	cantidadProducciones = 6;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Si", TipoToken::PalabraReservada, 0));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[4] = new NoTerminal(NoTerminales::SUBBS);
	produccion[5] = new NoTerminal(NoTerminales::ELSE);
	reglasGramaticales[22] = new Regla(new NoTerminal(NoTerminales::SC), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);

	// Regla 23 : <ELSE> → Osino <SUBBS>

	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Osino", TipoToken::PalabraReservada, 0));
	produccion[1] = new NoTerminal(NoTerminales::SUBBS);
	reglasGramaticales[23] = new Regla(new NoTerminal(NoTerminales::ELSE), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	
	//Regla 24: <ELSE> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[24] = new Regla(new NoTerminal(NoTerminales::ELSE), produccion, cantidadProducciones);
	
	
	//Regla: 25 SL -> LeerTeclado (id) ;

	cantidadProducciones = 5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("LeerTeclado", TipoToken::PalabraReservada, 0));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[2] = new Terminal(new Token("id", TipoToken::Identificador, 0));
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[4] = new Terminal(new Token(";", TipoToken::Delimitador, 0));
	reglasGramaticales[25] = new Regla(new NoTerminal(NoTerminales::SL), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[2]);
	terminales.push_back((Terminal*)produccion[3]);
	terminales.push_back((Terminal*)produccion[4]);

	reglasGramaticales[25]->setPlantilla(produccion[2], NULL, produccion[0], NULL);

	//Regla: 26 SE -> EscribirPantalla( <EM> );
	cantidadProducciones =5;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("EscribirPantalla", TipoToken::PalabraReservada, 0));
	produccion[1] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[2] = new NoTerminal(NoTerminales::EM);
	produccion[3] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[4] = new Terminal(new Token(";", TipoToken::Delimitador, 0));
	reglasGramaticales[26] = new Regla(new NoTerminal(NoTerminales::SE), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[1]);
	terminales.push_back((Terminal*)produccion[3]);
	terminales.push_back((Terminal*)produccion[4]);

	reglasGramaticales[26]->setPlantilla(produccion[0], produccion[2], NULL, NULL);

	//Regla 27: <SHM> → Hacer <SUBBS> Mientras ( <EM> ) ;
	cantidadProducciones = 7;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Hacer", TipoToken::PalabraReservada, 0));
	produccion[1] = new NoTerminal(NoTerminales::SUBBS);
	produccion[2] = new Terminal(new Token("Mientras", TipoToken::PalabraReservada, 0));
	produccion[3] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[4] = new NoTerminal(NoTerminales::EM);
	produccion[5] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	produccion[6] = new Terminal(new Token(";", TipoToken::Delimitador, 0));
	reglasGramaticales[27] = new Regla(new NoTerminal(NoTerminales::SHM), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[2]);
	terminales.push_back((Terminal*)produccion[3]);
	terminales.push_back((Terminal*)produccion[5]);
	terminales.push_back((Terminal*)produccion[6]);


	//Regla 28: <EM> → <OL> <LOL>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OL);
	produccion[1] = new NoTerminal(NoTerminales::LOL);
	reglasGramaticales[28] = new Regla(new NoTerminal(NoTerminales::EM), produccion, cantidadProducciones);

	reglasGramaticales[28]->setPlantilla(reglasGramaticales[28]->getNoTerminal(), produccion[0], NULL, produccion[1]);

	//Regla 29: <LOL> → <OP1> <OL> <LOL>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP1);
	produccion[1] = new NoTerminal(NoTerminales::OL);
	produccion[2] = new NoTerminal(NoTerminales::LOL);
	reglasGramaticales[29] = new Regla(new NoTerminal(NoTerminales::LOL), produccion, cantidadProducciones);

	reglasGramaticales[29]->setPlantilla(reglasGramaticales[29]->getNoTerminal(), produccion[1], NULL, produccion[2]);

	//Regla 30: <LT> → <OP3> <T> <LT>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP3);
	produccion[1] = new NoTerminal(NoTerminales::T);
	produccion[2] = new NoTerminal(NoTerminales::LT);
	reglasGramaticales[30] = new Regla(new NoTerminal(NoTerminales::LT), produccion, cantidadProducciones);

	reglasGramaticales[30]->setPlantilla(reglasGramaticales[30]->getNoTerminal(), produccion[1], NULL, produccion[2]);

	//Regla 31: <LT> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[31] = new Regla(new NoTerminal(NoTerminales::LT), produccion, cantidadProducciones);

	//Regla 32: <OP3> → +
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("+", TipoToken::Operador, 0));
	reglasGramaticales[32] = new Regla(new NoTerminal(NoTerminales::OP3), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 33: <OP3> → -
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("-", TipoToken::Operador, 0));
	reglasGramaticales[33] = new Regla(new NoTerminal(NoTerminales::OP3), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 34: <T> → <F> <LF>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::F);
	produccion[1] = new NoTerminal(NoTerminales::LF);
	reglasGramaticales[34] = new Regla(new NoTerminal(NoTerminales::T), produccion, cantidadProducciones);

	reglasGramaticales[34]->setPlantilla(reglasGramaticales[34]->getNoTerminal(), produccion[0], NULL, produccion[1]);

	//Regla 35: <LF> → <OP4> <F> <LF>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP4);
	produccion[1] = new NoTerminal(NoTerminales::F);
	produccion[2] = new NoTerminal(NoTerminales::LF);
	reglasGramaticales[35] = new Regla(new NoTerminal(NoTerminales::LF), produccion, cantidadProducciones);


	reglasGramaticales[35]->setPlantilla(reglasGramaticales[35]->getNoTerminal(), produccion[1], NULL, produccion[2]);

	//Regla 36: <LF> → LAMBDA
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[36] = new Regla(new NoTerminal(NoTerminales::LF), produccion, cantidadProducciones);


	//Regla 37: <F> → ( <EM> )
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("(", TipoToken::Delimitador, 0));
	produccion[1] = new NoTerminal(NoTerminales::EM);
	produccion[2] = new Terminal(new Token(")", TipoToken::Delimitador, 0));
	reglasGramaticales[37] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	terminales.push_back((Terminal*)produccion[2]);

	reglasGramaticales[37]->setPlantilla(reglasGramaticales[37]->getNoTerminal(), produccion[1], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL);

	//Regla 38: <F> → Numero
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("Numero", TipoToken::ConstanteEntera, 0));
	reglasGramaticales[38] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	reglasGramaticales[38]->setPlantilla(reglasGramaticales[38]->getNoTerminal(), produccion[0], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL);

	//Regla 39: <F> → id
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("id", TipoToken::Identificador, 0));
	reglasGramaticales[39] = new Regla(new NoTerminal(NoTerminales::F), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);

	reglasGramaticales[39]->setPlantilla(reglasGramaticales[39]->getNoTerminal(), produccion[0], new Terminal(new Token("=", TipoToken::Operador, 0)), NULL);

	//Regla 40: <OP4> → *
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("*", TipoToken::Operador, 0));
	reglasGramaticales[40] = new Regla(new NoTerminal(NoTerminales::OP4), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 41: <OP4> → /
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("/", TipoToken::Operador, 0));
	reglasGramaticales[41] = new Regla(new NoTerminal(NoTerminales::OP4), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);


	//Regla 42: <OP4> → %
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("%", TipoToken::Operador, 0));
	reglasGramaticales[42] = new Regla(new NoTerminal(NoTerminales::OP4), produccion, cantidadProducciones);

	terminales.push_back((Terminal*)produccion[0]);
	
	// REGLA 43 : C -> <T> <LT>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::T);
	produccion[1] = new NoTerminal(NoTerminales::LT); 
	reglasGramaticales[43] = new Regla(new NoTerminal(NoTerminales::C), produccion, cantidadProducciones);

	reglasGramaticales[43]->setPlantilla(reglasGramaticales[43]->getNoTerminal(), produccion[0], NULL, produccion[1]);

	//Regla 44: LC -> Lambda
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[44] = new Regla(new NoTerminal(NoTerminales::LC), produccion, cantidadProducciones);

	//Regla 45 op2-> <=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("<=", TipoToken::Operador, 0));
	reglasGramaticales[45] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 46 op2-> >=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token(">=", TipoToken::Operador, 0));
	reglasGramaticales[46] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 47 op2-> ==
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("==", TipoToken::Operador, 0));
	reglasGramaticales[47] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 48 op2-> !=
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("!=", TipoToken::Operador, 0));
	reglasGramaticales[48] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 49 op2-> <
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("<", TipoToken::Operador, 0));
	reglasGramaticales[49] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 50 op2-> >
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token(">", TipoToken::Operador, 0));
	reglasGramaticales[50] = new Regla(new NoTerminal(NoTerminales::OP2), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//REGLA 51: OL -> C <LC>
	cantidadProducciones = 2;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::C);
	produccion[1] = new NoTerminal(NoTerminales::LC);
	reglasGramaticales[51] = new Regla(new NoTerminal(NoTerminales::OL), produccion, cantidadProducciones);

	reglasGramaticales[51]->setPlantilla(reglasGramaticales[51]->getNoTerminal(), produccion[0], NULL, produccion[1]);

	//Regla 52: LOL -> Lambda
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = LAMBDA;
	reglasGramaticales[52] = new Regla(new NoTerminal(NoTerminales::LOL), produccion, cantidadProducciones);

	//Regla 53: OP1 -> ||
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("||", TipoToken::Operador, 0));
	reglasGramaticales[53] = new Regla(new NoTerminal(NoTerminales::OP1), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 54: OP1 -> &&
	cantidadProducciones = 1;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new Terminal(new Token("&&", TipoToken::Operador, 0));
	reglasGramaticales[54] = new Regla(new NoTerminal(NoTerminales::OP1), produccion, cantidadProducciones);
	terminales.push_back((Terminal*)produccion[0]);

	//Regla 55: <LC> → <OP2> <C> <LC>
	cantidadProducciones = 3;
	produccion = new ElementoGramatical*[cantidadProducciones];
	produccion[0] = new NoTerminal(NoTerminales::OP2);
	produccion[1] = new NoTerminal(NoTerminales::C);
	produccion[2] = new NoTerminal(NoTerminales::LC);
	reglasGramaticales[55] = new Regla(new NoTerminal(NoTerminales::LC), produccion, cantidadProducciones);

	reglasGramaticales[55]->setPlantilla(reglasGramaticales[55]->getNoTerminal(), produccion[1], NULL, produccion[2]);
}

void AnalizadorSintactico::llenarMatriz()
{
	for (unsigned int j = 0; j < terminales.size(); j++) {
		cout << "\t" << terminales[j]->getID() << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < NoTerminales::Cantidad; i++) {		
		cout << NombresNoTerminales[i] << "\t";
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
	noTerminalBase = new NoTerminal(NoTerminales::P);
}

AnalizadorSintactico::~AnalizadorSintactico()
{
}

void AnalizadorSintactico::vaciarPila() {
	while (!pila.empty())
		pila.pop();
}

void AnalizadorSintactico::llenarCuadruplos(int nregla, Terminal * terminal)
{
	Regla* regla = reglasGramaticales[nregla];
	Cuadruplo* cuadruplo  = regla->getCuadruplo();
	ElementoGramatical* produccion = regla->getProduccion()[0];
	NoTerminal* noT = regla->getNoTerminal();

	if (cuadruplo != NULL) {
		if (produccion->getTipo() == TERMINAL) {
			if (cuadruplo->Resultado != NULL)
			if (cuadruplo->Resultado->getTipo() == TERMINAL) {
				if (((Terminal*)(cuadruplo->Resultado))->getToken()->getTipo() == TipoToken::Identificador)
					cuadruplo->Resultado = terminal;
			}
			if (cuadruplo->Operando1 != NULL)
			if (cuadruplo->Operando1->getTipo() == TERMINAL) {
				int tipo = ((Terminal*)(cuadruplo->Operando1))->getToken()->getTipo();
				if ((tipo == TipoToken::Identificador) || (tipo == TipoToken::ConstanteEntera))
					cuadruplo->Operando1 = terminal;
			}
			if (cuadruplo->Resultado == NULL)
			if (((Terminal*)produccion)->getToken()->getLexema() == "=") {
				cuadruplo->Resultado = listaCuadruplos[listaCuadruplos.size() - 1]->Resultado;
			}
		}
		
	
		/*if (voltear)
			listaCuadruplosTemporal.push_back(cuadruplo);
		else*/
			listaCuadruplos.push_back(cuadruplo);
	}
	else {
		if (produccion == LAMBDA) {
			for (int i = listaCuadruplos.size() - 1; i >= 0; i--) {
				if (listaCuadruplos[i]->Operando2 != NULL)
				if (((NoTerminal*)(listaCuadruplos[i]->Operando2))->getID() == regla->getNoTerminal()->getID()) {
					listaCuadruplos[i]->Operador = new Terminal(new Token("=", TipoToken::Operador, 0));
					listaCuadruplos[i]->Operando2 = NULL;
					break;
				}
			}
		}
		else {
			if (produccion->getTipo() == TERMINAL)
				if (((Terminal*)produccion)->getToken()->getTipo() == TipoToken::Operador) {
					
					for (int i = listaCuadruplos.size() - 1; i >= 0; i--) {
						if (listaCuadruplos[i]->Operando2 != NULL)
						if (((NoTerminal*)(listaCuadruplos[i]->Operando2))->getID() == regla->getNoTerminal()->getID()) {
							listaCuadruplos[i]->Operador = terminal;
							break;
						}
					}
				}
		}
	}
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
			cout << "Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
			return false;
		}
		else
		{
			if ((pila.top()->getTipo() == TERMINAL) && (((Terminal*)(pila.top()))->getToken()->esIgual(entrada[i]))) {
				pila.pop();
				i++;
			}
			else
			{
				if ((pila.top()->getTipo() == TERMINAL)) {
					cout << "Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
					return false;	//error

				}
				else
				{
					int x = ((NoTerminal*)(pila.top()))->getID();
					string y = terminalesEntrada[i]->getID();
					regla = matriz[x][y];
					if (regla == -1) {

						cout << "Aqui esta tu error esta en la linea : " << entrada[i]->getLinea() << endl;
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
						llenarCuadruplos(regla,terminalesEntrada[i]);
						pila.pop();

						for (int i = 0; i < reglasGramaticales[regla]->getNumeroProducciones(); i++)
							if (reglasGramaticales[regla]->getProduccion()[reglasGramaticales[regla]->getNumeroProducciones() - i - 1] != LAMBDA)
								pila.push(reglasGramaticales[regla]->getProduccion()[reglasGramaticales[regla]->getNumeroProducciones() - i - 1]);
					}
				}
			}
		}
	}
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

void AnalizadorSintactico::imprimirCuadruplos()
{
	cout << endl << "Lista Cuadruplos" << endl;
	for (int i = 0; i < listaCuadruplos.size(); i++) {
		
		if (listaCuadruplos[i]->Resultado == NULL)
			cout << "NULL\t";
		else
		{
			if (listaCuadruplos[i]->Resultado->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Resultado))->getToken()->getLexema()) << "\t";
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Resultado))->getID()] << "\t";
		}
		if (listaCuadruplos[i]->Operando1 == NULL)
			cout << "NULL\t";
		else
		{
			if (listaCuadruplos[i]->Operando1->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando1))->getToken()->getLexema()) << "\t";
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operando1))->getID()] << "\t";
		}
		if (listaCuadruplos[i]->Operador == NULL)
			cout << "NULL\t";
		else
		{
			if (listaCuadruplos[i]->Operador->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operador))->getToken()->getLexema()) << "\t";
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operador))->getID()] << "\t";
		}
		if (listaCuadruplos[i]->Operando2 == NULL)
			cout << "NULL\t";
		else
		{
			if (listaCuadruplos[i]->Operando2->getTipo() == TERMINAL)
				cout << (((Terminal*)(listaCuadruplos[i]->Operando2))->getToken()->getLexema()) << "\t";
			else
				cout << NombresNoTerminales[((NoTerminal*)(listaCuadruplos[i]->Operando2))->getID()] << "\t";
		}
		cout << endl;
	}
}
