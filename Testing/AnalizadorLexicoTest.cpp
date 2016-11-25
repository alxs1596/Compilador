#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Compilador/AnalizadorLexico/AnalizadorLexico.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{		
	TEST_CLASS(AnalizadorLexicoTest)
	{
	private:
		string path = "C:\\Users\\alxs1\\Source\\Repos\\Compilador 24-11-16\\Testing\\";
	public:
		TEST_METHOD(testLexico1)
		{

			AnalizadorLexico lexico;
			
			vector<Token*> tokens = lexico.ejecutar(path +  "Source1.txt");

			Assert::AreEqual(14, (int)tokens.size());
		}
		TEST_METHOD(testLexico2)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source2.txt");

			Assert::AreEqual(21, (int)tokens.size());
		}
		TEST_METHOD(testLexico3)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source3.txt");

			Assert::AreEqual(24, (int)tokens.size());
		}
		TEST_METHOD(testLexico4)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source4.txt");

			Assert::AreEqual(18, (int)tokens.size());
		}
		TEST_METHOD(testLexico5)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source5.txt");

			Assert::AreEqual(42, (int)tokens.size());
		}
		TEST_METHOD(testLexico6)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source6.txt");

			Assert::AreEqual(72, (int)tokens.size());
		}
		TEST_METHOD(testLexico7)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source7.txt");

			Assert::AreEqual(50, (int)tokens.size());
		}
		TEST_METHOD(testLexico8)
		{

			AnalizadorLexico lexico;

			vector<Token*> tokens = lexico.ejecutar(path + "Source8.txt");

			Assert::AreEqual(13, (int)tokens.size());
		}
		//TEST_METHOD(testEsBlancoCorrecto)
		//{
		//	//Arrange
		//	AnalizadorLexico analizador;
		//	char blanco1 = ' ';
		//	char blanco2 = '\t';
		//	char blanco3 = '\n';
		//	bool esperado = true;
		//	//Act
		//	bool res1 = analizador.esBlanco(blanco1);
		//	bool res2 = analizador.esBlanco(blanco2);
		//	bool res3 = analizador.esBlanco(blanco3);
		//	//Assert
		//	Assert::AreEqual(esperado, res1);
		//	Assert::AreEqual(esperado, res2);
		//	Assert::AreEqual(esperado, res3);
		//}
		//TEST_METHOD(testEsBlancoIncorrecto)
		//{
		//	//Arrange
		//	AnalizadorLexico analizador;
		//	char caracter = '@';
		//	bool esperado = false;
		//	//Act
		//	bool res = analizador.esBlanco(caracter);
		//	//Assert
		//	Assert::AreEqual(esperado, res);
		//}
		
	};
}