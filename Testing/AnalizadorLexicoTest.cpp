#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Compilador/AnalizadorLexico/AnalizadorLexico.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(AnalizadorLexicoTest)
	{
	public:
		TEST_METHOD(testEsBlancoCorrecto)
		{
			//Arrange
			AnalizadorLexico analizador;
			char blanco1 = ' ';
			char blanco2 = '\t';
			char blanco3 = '\n';
			bool esperado = true;
			//Act
			bool res1 = analizador.esBlanco(blanco1);
			bool res2 = analizador.esBlanco(blanco2);
			bool res3 = analizador.esBlanco(blanco3);
			//Assert
			Assert::AreEqual(esperado, res1);
			Assert::AreEqual(esperado, res2);
			Assert::AreEqual(esperado, res3);
		}
		TEST_METHOD(testEsBlancoIncorrecto)
		{
			//Arrange
			AnalizadorLexico analizador;
			char caracter = '@';
			bool esperado = false;
			//Act
			bool res = analizador.esBlanco(caracter);
			//Assert
			Assert::AreEqual(esperado, res);
		}
		
	};
}