#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Compilador/AnalizadorSintactico/AnalizadorSintactico.h"
#include <vector>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(AnalizadorSintacticoTest)
	{
	public:
		
		//Declaracion de variables
		TEST_METHOD(testAnalizar1)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
 
			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		//Declaracion de variable con asignacion
		TEST_METHOD(testAnalizar2) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = false;
			//Act
			
				bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

				Assert::AreEqual(esperado, respuesta);
		}

		//Declaracion de variables y declaracion de variable con asignacion
		TEST_METHOD(testAnalizar3) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(",", TipoToken::Delimitador));
			vectorToken.push_back(new Token("b", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("3", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}


		//Declaracion de variable con asignacion de una operacion matematica
		TEST_METHOD(testAnalizar4) {

			// No termina
			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token("*", TipoToken::Operador));
			vectorToken.push_back(new Token("3", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		// Programa(){int a;}
		TEST_METHOD(testAnalizar5) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));

			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		//probando si funciona el if else con imprimir pantalla
		TEST_METHOD(testAnalizar6) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("i", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("i", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("1", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("i", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("2", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));


			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}



		TEST_METHOD(testAnalizar7) {

			//Arrange
			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("Programa", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("4", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("num2", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("10", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("num3", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("2", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token("num2", TipoToken::Identificador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("b", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Si", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("(", TipoToken::Delimitador));
			vectorToken.push_back(new Token("num1", TipoToken::Identificador));
			vectorToken.push_back(new Token(")", TipoToken::Delimitador));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("c", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("Osino", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("{", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("d", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));
			vectorToken.push_back(new Token("}", TipoToken::Delimitador));


			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}
	};
}