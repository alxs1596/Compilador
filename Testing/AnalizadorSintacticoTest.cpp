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
		
		TEST_METHOD(testAnalizar1)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
 
			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		TEST_METHOD(testAnalizar2)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		TEST_METHOD(testAnalizar3)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("b", TipoToken::Identificador));
			vectorToken.push_back(new Token("=", TipoToken::Operador));
			vectorToken.push_back(new Token("5", TipoToken::ConstanteEntera));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		TEST_METHOD(testAnalizar4)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("int", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = false;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

		TEST_METHOD(testAnalizar5)
		{

			// Si se da un int en vez de entero da un bucle infinito
			//Arrange

			AnalizadorSintactico* analizaSintactico = new AnalizadorSintactico();
			vector<Token*> vectorToken;
			vectorToken.push_back(new Token("entero", TipoToken::PalabraReservada));
			vectorToken.push_back(new Token("a", TipoToken::Identificador));
			vectorToken.push_back(new Token(";", TipoToken::Delimitador));

			bool esperado = true;
			//Act

			bool respuesta = analizaSintactico->Analizar(vectorToken);

			//Assert

			Assert::AreEqual(esperado, respuesta);
		}

	};
}