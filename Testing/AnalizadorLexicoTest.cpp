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
	private:
		void test(Source* source){
			AnalizadorLexico lexico;

			lexico.analizar(source->Codigo());

			bool res = lexico.getError();

			Assert::AreEqual(!source->LexicoValido(), res);
		}
	public:
		TEST_METHOD(testLexico1) { test(Codigos::Source1()); }
		TEST_METHOD(testLexico2) { test(Codigos::Source2()); }
		TEST_METHOD(testLexico3) { test(Codigos::Source3()); }
		TEST_METHOD(testLexico4) { test(Codigos::Source4()); }
		TEST_METHOD(testLexico5) { test(Codigos::Source5()); }
		TEST_METHOD(testLexico6) { test(Codigos::Source6()); }
		TEST_METHOD(testLexico7) { test(Codigos::Source7()); }
		TEST_METHOD(testLexico8) { test(Codigos::Source8()); }
		TEST_METHOD(testLexico9) { test(Codigos::Source9()); }
		TEST_METHOD(testLexico10) { test(Codigos::Source10()); }
		TEST_METHOD(testLexico11) { test(Codigos::Source11()); }
		TEST_METHOD(testLexico12) { test(Codigos::Source12()); }
		TEST_METHOD(testLexico13) { test(Codigos::Source13()); }
		TEST_METHOD(testLexico14) { test(Codigos::Source14()); }
		TEST_METHOD(testLexico15) { test(Codigos::Source15()); }
		TEST_METHOD(testLexico16) { test(Codigos::Source16()); }
		
	};
}