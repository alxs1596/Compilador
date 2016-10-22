#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Compilador/AnalizadorSintactico/Terminal.h"
#include <regex>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(TerminalTest)
	{
	public:

		TEST_METHOD(testTerminalConstructorIdentificador)
		{
			
			//Arrange
			Token* token = new Token("variable", TipoToken::Identificador,0);
			string esperado = "id";
			//Act

			Terminal terminal(token);

			//Assert

			Assert::AreEqual(esperado, terminal.getID());

		}

		TEST_METHOD(testTerminalConstructorNumero)
		{
			//Arrange
				Token* token = new Token("5", TipoToken::ConstanteEntera,0);
				string esperado = "Numero";
			//Act

				Terminal terminal(token);

			//Assert

				Assert::AreEqual(esperado, terminal.getID());
		}

		TEST_METHOD(testTerminalConstructorDiferenteNumero)
		{
			//Arrange
			Token* token = new Token("holis", TipoToken::ConstanteEntera,0);
			string esperado = "Numero";

			regex entero("[[:digit:]]+");
			//Act

			Terminal terminal(token);

			//Assert

			Assert::AreNotEqual(true, regex_match(token->getLexema(), entero));
			
		}

		TEST_METHOD(testTerminalConstructorOtro)
		{
			//Arrange
			Token* token = new Token("+", TipoToken::Operador,0);
			string esperado = token->getLexema();
			//Act

			Terminal terminal(token);

			//Assert

			Assert::AreEqual(esperado, terminal.getID());
		}

	};
}