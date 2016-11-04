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

		//TEST_METHOD(testCodigoFuenteDeclaracionAsignacionIncompleta)
		//{
		//	//Arrange
		//	string codigoFuente = "entero a = ;";
		//	AnalizadorLexico lexico;
		//	AnalizadorSintactico sintactico;
		//	bool esperado = false;
		//	//Act
		//	lexico.Analizar(codigoFuente, 0);
		//	bool res = sintactico.Analizar(lexico.listaTokens);
		//	//Assert
		//	Assert::AreEqual(esperado, res);
		//}

	};
}