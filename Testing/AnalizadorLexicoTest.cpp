#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Compilador/AnalizadorLexico/AnalizadorLexico.h"

#include <sstream>

#include "Codigos.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace Testing
{		
	TEST_CLASS(AnalizadorLexicoTest)
	{
	public:
		TEST_METHOD(testLexico1)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source1();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(),res);
		}
		TEST_METHOD(testLexico2)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source2();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico3)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source3();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico4)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source4();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico5)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source5();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico6)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source6();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico7)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source7();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
		TEST_METHOD(testLexico8)
		{
			AnalizadorLexico lexico;

			Source* source = Codigos::Source8();

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
	};
}