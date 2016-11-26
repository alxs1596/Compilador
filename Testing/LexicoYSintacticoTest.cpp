#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../Compilador/AnalizadorLexico/AnalizadorLexico.h"
#include "../Compilador/AnalizadorSintactico/AnalizadorSintactico.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(LexicoYSintacticoTest)
	{
	public:
		/*
		TEST_METHOD(testCodigoFuenteDeclaracionAsignacionIncompleta)
		{
			//Arrange
			string codigoFuente = "entero a = ;";
			AnalizadorLexico lexico;
			AnalizadorSintactico sintactico;
			bool esperado = false;
			//Act
			vector<Token*> tokens = lexico.analizar(codigoFuente);
			bool res = sintactico.Analizar(tokens);
			//Assert
			Assert::AreEqual(esperado, res);
		}
		/*TEST_METHOD(testLexicoYSintactico1)
		{
			//Arrange
			AnalizadorLexico lexico;
			AnalizadorSintactico sintactico;
			bool esperado = true;
			//Act
			vector<Token*> tokens = lexico.ejecutar("..\\Users\\alxs1\\Source\\Repos\\Compilador\\Testing\\Source1.txt");
			bool res = sintactico.Analizar(tokens);
			//Assert
			int t = tokens.size();
			Assert::AreEqual(12, t);
			Assert::AreEqual(esperado, res);
		}*/

	};
}