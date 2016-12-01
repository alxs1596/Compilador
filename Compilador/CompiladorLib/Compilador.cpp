#include "stdafx.h"
#include "Compilador.h"


Compilador::Compilador()
{
}


Compilador::~Compilador()
{
}


string Compilador::generarCodigo(vector<Cuadruplo*> cuadruplos)
{
	stringstream res;

	res << ".486" << "\n";
	res << ".model flat, stdcall; 32 bit memory model" << "\n";
	res << "option casemap: none; case sensitive" << "\n";

	res << "include \\masm32\\include\\windows.inc; always first" << "\n";
	res << "include \\masm32\\macros\\macros.asm; MASM support macros" << "\n";

	res << "include \\masm32\\include\\masm32.inc" << "\n";
	res << "include \\masm32\\include\\gdi32.inc" << "\n";
	res << "include \\masm32\\include\\user32.inc" << "\n";
	res << "include \\masm32\\include\\kernel32.inc" << "\n";
	res << "include \\masm32\\include\\msvcrt.inc" << "\n";

	res << "includelib \\masm32\\lib\\masm32.lib" << "\n";
	res << "includelib \\masm32\\lib\\gdi32.lib" << "\n";
	res << "includelib \\masm32\\lib\\user32.lib" << "\n";
	res << "includelib \\masm32\\lib\\kernel32.lib" << "\n";
	res << "includelib \\masm32\\lib\\msvcrt.lib" << "\n";

	res << ".code; Tell MASM where the code starts" << "\n";



	res << "start:; The CODE entry point to the program" << "\n";

	res << "call main" << "\n";

	res << "exit" << "\n";



	res << "main proc" << "\n";


	res << "PUSH EBP; GUARDO EL VALOR DE EBP" << "\n";
	res << "MOV EBP,ESP" << "\n";

	res << "\n";

	for (size_t i = 0; i < cuadruplos.size(); i++)
	{
		Cuadruplo* cuadruplo = cuadruplos[i];
		switch (cuadruplo->tipo)
		{
		case TiposDeCuadruplos::Asignacion:
			if (cuadruplo->Resultado->getTipo() == TERMINAL)
			{
				if (cuadruplo->Operando1->getTipo() == TERMINAL)
				{
					Terminal* op1 = (Terminal*)cuadruplo->Operando1;
					if (op1->getToken()->getTipo() == TipoToken::Identificador)
					{

					}
					else
					{
						string lexema = ((Terminal*)cuadruplo->Resultado)->getToken()->getLexema();
						int offset = cuadruplo->bloque->fueDeclarada(lexema)->offset * 4;
						res << "MOV DWORD PTR[EBP-" << offset << "], " << op1->getToken()->getLexema() << "\n";
					}
				}
				else
				{

				}
			}
			else
			{

			}
			break;
		case TiposDeCuadruplos::Operacion:
			break;
		case TiposDeCuadruplos::Lectura:
			break;
		case TiposDeCuadruplos::Escritura:
			break;
		case TiposDeCuadruplos::Declaracion:
			res << "MOV EAX, 0" << "\n";
			res << "PUSH EAX" << "\n";
			break;
		case TiposDeCuadruplos::Mientras:
			break;
		case TiposDeCuadruplos::Si:
			break;
		case TiposDeCuadruplos::Osino:
			break;
		default:
			break;
		}
		res << "\n";
	}

	res << "ret" << "\n";

	res << "main endp" << "\n";

	res << "end start" << "\n";

	return res.str();
}