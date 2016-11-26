#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Compilador/AnalizadorSintactico/AnalizadorSintactico.h"
#include "../Compilador/AnalizadorLexico/AnalizadorLexico.h"
#include <vector>
#include "Codigos.h"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(AnalizadorSintacticoTest)
	{
	private:
		void test(Source* source) {
			AnalizadorLexico lexico;
			AnalizadorSintactico sintactico;

			auto tokens = lexico.analizar(source->Codigo());

			auto cuadruplos = sintactico.Analizar(tokens);

			bool res = sintactico.getError();

			Assert::AreEqual(!source->SintacticoValido(), res);
		}
	public:
		TEST_METHOD(testSintactico1) { test(Codigos::Source1()); }
		TEST_METHOD(testSintactico2) { test(Codigos::Source2()); }
		TEST_METHOD(testSintactico3) { test(Codigos::Source3()); }
		TEST_METHOD(testSintactico4) { test(Codigos::Source4()); }
		TEST_METHOD(testSintactico5) { test(Codigos::Source5()); }
		TEST_METHOD(testSintactico6) { test(Codigos::Source6()); }
		TEST_METHOD(testSintactico7) { test(Codigos::Source7()); }
		TEST_METHOD(testSintactico8) { test(Codigos::Source8()); }
		TEST_METHOD(testSintactico9) { test(Codigos::Source9()); }
		TEST_METHOD(testSintactico10) { test(Codigos::Source10()); }
		TEST_METHOD(testSintactico11) { test(Codigos::Source11()); }
		TEST_METHOD(testSintactico12) { test(Codigos::Source12()); }
		TEST_METHOD(testSintactico13) { test(Codigos::Source13()); }
		TEST_METHOD(testSintactico14) { test(Codigos::Source14()); }
		TEST_METHOD(testSintactico15) { test(Codigos::Source15()); }
		TEST_METHOD(testSintactico16) { test(Codigos::Source16()); }

		/*
		TEST_METHOD(testAnalizarSintactico1)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada,0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador,0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador,0));
 
			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		//Declaracion de variable con asignacion
		TEST_METHOD(testAnalizarSintactico2) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada,0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));

			bool esperado = false;
			//Act
			
				bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

				Assert::AreEqual(esperado, respuesta);
		}

		//Declaracion de variables y declaracion de variable con asignacion
		TEST_METHOD(testAnalizarSintactico3) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(",", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("b", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("3", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));

			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}


		//Declaracion de variable con asignacion de una operacion matematica
		TEST_METHOD(testAnalizarSintactico4) {

			// No termina
			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token("*", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("3", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));

			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		// Programa(){int a;}
		TEST_METHOD(testAnalizarSintactico5) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));

			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		//probando si funciona el if else con imprimir pantalla
		TEST_METHOD(testAnalizarSintactico6) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("i", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("i", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("1", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("i", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("2", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));


			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}



		TEST_METHOD(testAnalizarSintactico7) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("num2", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("10", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("num3", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token("=", TipoToken::Operador, 0));
			vectorToken.push_back(new Token("2", TipoToken::ConstanteEntera, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("num2", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("b", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("c", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("d", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));


			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		TEST_METHOD(testAnalizarSintactico8)
		{

			
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("int", TipoToken::PalabraReservada, 0));
			vectorToken.push_back(new Token("a", TipoToken::Identificador, 0));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador, 0));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador, 0));
			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}
		*/
	};
}