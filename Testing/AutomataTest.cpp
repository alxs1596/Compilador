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
		// Agregar el estado -1 para que la prueba sea correcta
		TEST_METHOD(testAutomataObetenerTipoEstadoIncial)
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
			
			Assert::AreEqual(0, res);
		}

		TEST_METHOD(testAutomataReiniciarTodo)
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
			automata->mover('a');
			int estadoDespuesMover = automata->estado();
			automata->reset();
			int estadoAutomata = automata->estado();
			//Assert

			Assert::AreEqual(estadoAutomata,estadoAutomata);
		}
		TEST_METHOD(testAutomataMover)
		{
			//Arrange
			int tipoLetra = 0;
			int NumeroEstados = 2;
			vector<int> EstadosFinales;
			EstadosFinales.push_back(1);
			int inicial = 0;

			Matriz matriz;
			matriz[0][1] = new vector<int>();
			matriz[0][1]->push_back(Tipos::LETRA);

			map<char, int> Alfabeto;
			Alfabeto['a'] = Tipos::LETRA;


			Automata *automata = new Automata(Alfabeto, NumeroEstados, EstadosFinales, inicial, matriz);
			//Act
			int estadoInicial = automata->estado();
			automata->mover('a');
			int estadoDespuesMover = automata->estado();
			//Assert
			Assert::AreNotEqual(estadoInicial,estadoDespuesMover);
		}
		// Modificar el mover
		TEST_METHOD(testAutomataMoverIncorrecto)
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
			int estadoInicial = automata->estado();
			bool respuesta = automata->mover('c');
			int estadoDespuesMover = automata->estado();
			//Assert
			Assert::AreEqual(false, respuesta);
		}
		TEST_METHOD(testAutomataEsEstadoFinalCorrecto)
		{
			//Arrange
			int tipoLetra = Tipos::LETRA;
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
			bool mover = automata->mover('a');
			//Assert
			Assert::IsTrue(automata->esEstadoFinal());
		}
		//MODIFICAR EL MOVER PARA QUE ESTE TEST FUNCIONE CORRECTMENTE
		TEST_METHOD(testAutomataEsEstadoFinalIncorrecto)
		{

			//Arrange
			int tipoLetra = Tipos::LETRA;
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
			bool mover = automata->mover(';');
			//Assert
			Assert::AreEqual(false,automata->esEstadoFinal());
		}
		TEST_METHOD(testAutomataEstadoActual)
		{

			//Arrange
			int tipoLetra = Tipos::LETRA;
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
			bool mover = automata->mover('a');
			//Assert
			Assert::AreEqual(true, automata->esEstadoFinal());
		}

	};
}