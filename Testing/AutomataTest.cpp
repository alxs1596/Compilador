#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Compilador/AnalizadorLexico/Automata.h"
#include	<map>
#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(AutomataTest)
	{
	public:

		TEST_METHOD(testObetenerTipoEstadoIncial)
		{
			//Arrange
			int tipoLetra = 0;
			int NumeroEstados = 2;
			vector<int> EstadosFinales;
			EstadosFinales.push_back(1);
			int inicial = 0;

			Matriz matriz;
			matriz[0][1] = new vector<int>();
			matriz[0][1]->push_back(tipoLetra);

			map<char, int> Alfabeto;
			Alfabeto['a'] = tipoLetra;

			Automata *automata = new Automata(Alfabeto, NumeroEstados, EstadosFinales, inicial, matriz);
			
			//Act

			TipoToken tokenObtenido = automata->obtenerTipo();
			int res = tokenObtenido;
			
			//Assert
			
			Assert::AreEqual(-1, res);
		}

	};
}