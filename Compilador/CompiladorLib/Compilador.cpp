#include "stdafx.h"
#include "Compilador.h"


Compilador::Compilador()
{
}


Compilador::~Compilador()
{
}



string Compilador::getComandoID(string lexema, Cuadruplo* cuadruplo)
{
	stringstream ss;
	int offset = cuadruplo->bloque->fueDeclarada(lexema)->offset * 4;
	ss << "DWORD PTR[EBP-" << offset << "]";
	return ss.str();
}

string Compilador::getComandoTemporal(Temporal* t)
{
	stringstream ss;

	int offset = t->offset * 4;
	ss << "DWORD PTR[ESP-" << offset << "]";
	return ss.str();
}

string Compilador::suma(string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "ADD EAX, " << op2 << "\n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

string Compilador::resta(string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "SUB EAX, " << op2 << "\n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

string Compilador::multiplicacion(string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "MOV EBX, " << op2 << "\n";
	ss << "MUL EBX \n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

string Compilador::division(string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "MOV EBX, " << op2 << "\n";
	ss << "SUB EDX, EDX \n";
	ss << "DIV EBX \n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

string Compilador::modulo(string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "MOV EBX, " << op2 << "\n";
	ss << "SUB EDX, EDX \n";
	ss << "DIV EBX \n";
	ss << "MOV " << res << ", EDX" << "\n";
	return ss.str();
}

string Compilador::menor(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JL ES_MENOR_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "JMP MENOR_FIN_" << cuadruplo << "\n";
	ss << "ES_MENOR_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "MENOR_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador::mayor(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JG ES_MAYOR_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "JMP MAYOR_FIN_" << cuadruplo << "\n";
	ss << "ES_MAYOR_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "MAYOR_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador::menorigual(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JLE ES_MENORIGUAL_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "JMP MENORIGUAL_FIN_" << cuadruplo << "\n";
	ss << "ES_MENORIGUAL_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "MENORIGUAL_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador::mayorigual(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JGE ES_MAYORIGUAL_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "JMP MAYORIGUAL_FIN_" << cuadruplo << "\n";
	ss << "ES_MAYORIGUAL_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "MAYORIGUAL_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador::igualigual(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JE ES_IGUAL_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "JMP IGUAL_FIN_" << cuadruplo << "\n";
	ss << "ES_IGUAL_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "IGUAL_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador::diferente(string res, string op1, string op2, Cuadruplo* cuadruplo)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "CMP EAX, " << op2 << "\n";
	ss << "JE ES_DIFERENTE_" << cuadruplo << "\n";
	ss << "MOV " << res << ", 1" << "\n";
	ss << "JMP DIFERENTE_FIN_" << cuadruplo << "\n";
	ss << "ES_DIFERENTE_" << cuadruplo << ": \n";
	ss << "MOV " << res << ", 0" << "\n";
	ss << "DIFERENTE_FIN_" << cuadruplo << ": \n";
	return ss.str();
}

string Compilador:: and (string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "AND EAX, " << op2 << "\n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

string Compilador:: or (string res, string op1, string op2)
{
	stringstream ss;
	ss << "MOV EAX, " << op1 << "\n";
	ss << "OR EAX, " << op2 << "\n";
	ss << "MOV " << res << ", EAX" << "\n";
	return ss.str();
}

Temporal * Compilador::buscarTemporal(vector<Temporal*>* lista, NoTerminal * nt)
{
	vector<Temporal*> v = (*lista);
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i]->noTerminal == nt) return v[i];
	}
	return nullptr;
}


string Compilador::generarOperacion(Cuadruplo * cuadruplo, vector<Temporal*>* temporales, int& temporalOffset)
{
	string operando = cuadruplo->Operador->getID();

	string res = "";
	string op1 = "";
	string op2 = "";

	if (cuadruplo->Resultado->getID() == "id") {
		// id      id     op      id
		if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getID() == "id")
		{
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// id      id     op      numero
		else if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getID() == "Numero")
		{
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
		// id      numero op      id
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getID() == "id")
		{
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// id      numero op      numero
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getID() == "Numero")
		{
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
		// id      NT     op      NT
		else if (cuadruplo->Operando1->getTipo() == NOTERMINAL && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// id      NT     op      id
		else if (cuadruplo->Operando1->getTipo() == NOTERMINAL && cuadruplo->Operando2->getID() == "id") {
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// id      id     op      NT
		else if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// id      numero op      NT
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// id      NT     op      numero
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
	}
	else if (cuadruplo->Resultado->getTipo() == NOTERMINAL) {
		Temporal* temp = new Temporal((NoTerminal*)cuadruplo->Resultado, temporalOffset++);
		temporales->push_back(temp);
		// NT      id     op      id
		if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getID() == "id")
		{
			res = getComandoTemporal(temp); 
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// NT      id     op      numero
		else if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getID() == "Numero")
		{
			res = getComandoTemporal(temp);
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
		// NT      numero op      id
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getID() == "id")
		{
			res = getComandoTemporal(temp);
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// NT      numero op      numero
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getID() == "Numero")
		{
			res = getComandoTemporal(temp);
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
		// NT      NT     op      NT
		else if (cuadruplo->Operando1->getTipo() == NOTERMINAL && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Resultado));
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// NT      NT     op      id
		else if (cuadruplo->Operando1->getTipo() == NOTERMINAL && cuadruplo->Operando2->getID() == "id") {
			res = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Resultado));
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = getComandoID(((Terminal*)cuadruplo->Operando2)->getToken()->getLexema(), cuadruplo);
				
		}
		// NT      id     op      NT
		else if (cuadruplo->Operando1->getID() == "id" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Resultado));
			op1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// NT      numero op      NT
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Resultado));
			op1 = ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			op2 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando2));
				
		}
		// NT      NT     op      numero
		else if (cuadruplo->Operando1->getID() == "Numero" && cuadruplo->Operando2->getTipo() == NOTERMINAL) {
			res = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Resultado));
			op1 = getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1));
			op2 = ((Terminal*)cuadruplo->Operando2)->getToken()->getLexema();
				
		}
	}

	if (operando == "+") {
		return suma(res, op1, op2);
	}
	else if (operando == "-") {
		return resta(res, op1, op2);
	}
	else if (operando == "*") {
		return multiplicacion(res, op1, op2);
	}
	else if (operando == "/") {
		return division(res, op1, op2);
	}
	else if (operando == "%") {
		return modulo(res, op1, op2);
	}
	else if (operando == "<") {
		return menor(res, op1, op2, cuadruplo);
	}
	else if (operando == ">") {
		return mayor(res, op1, op2, cuadruplo);
	}
	else if (operando == "<=") {
		return menorigual(res, op1, op2, cuadruplo);
	}
	else if (operando == ">=") {
		return mayorigual(res, op1, op2, cuadruplo);
	}
	else if (operando == "==") {
		return igualigual(res, op1, op2, cuadruplo);
	}
	else if (operando == "!=") {
		return diferente(res, op1, op2, cuadruplo);
	}
	else if (operando == "&&") {
		return and(res, op1, op2);
	}
	else if (operando == "||") {
		return or(res, op1, op2);
	}
}

string Compilador::generarMientras(Cuadruplo * cuadruplo, vector<Temporal*>* temporales, int & temporalOffset)
{
	stringstream ss;
	if (cuadruplo->Operando1->getID() == "id") {
		ss << "MOV EAX, " << getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo) << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_MIENTRAS_" << cuadruplo->Operando2 << "\n\n";
	}
	else if (cuadruplo->Operando1->getID() == "Numero") {
		ss << "MOV EAX, " << ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema() << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_MIENTRAS_" << cuadruplo->Operando2 << "\n\n";
	}
	else if (cuadruplo->Operando1->getTipo() == NOTERMINAL) {
		ss << "MOV EAX, " << getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1)) << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_MIENTRAS_" << cuadruplo->Operando2 << "\n\n";
	}
	return ss.str();
}

string Compilador::generarSi(Cuadruplo * cuadruplo, vector<Temporal*>* temporales, int & temporalOffset)
{
	stringstream ss;
	if (cuadruplo->Operando1->getID() == "id") {
		ss << "MOV EAX, " << getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo) << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_SI_" << cuadruplo->Operando2 << "\n\n";
	}
	else if (cuadruplo->Operando1->getID() == "Numero") {
		ss << "MOV EAX, " << ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema() << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_SI_" << cuadruplo->Operando2 << "\n\n";
	}
	else if (cuadruplo->Operando1->getTipo() == NOTERMINAL) {
		ss << "MOV EAX, " << getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1)) << "\n";
		ss << "CMP EAX, 0 \n";
		ss << "JLE FIN_SI_" << cuadruplo->Operando2 << "\n\n";
	}
	return ss.str();
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

	vector<Temporal*>* temporales = new vector<Temporal*>();
	int temporalOffset = 1;

	for (size_t i = 0; i < cuadruplos.size(); i++)
	{
		Cuadruplo* cuadruplo = cuadruplos[i];
		switch (cuadruplo->tipo)
		{
		case TiposDeCuadruplos::Asignacion:
			// id   numero  =   null
			if (cuadruplo->Resultado->getID() == "id" && cuadruplo->Operando1->getID() == "Numero")
			{
				auto op1 = (Terminal*)cuadruplo->Operando1;
				string ID = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
				res << "MOV " << ID << ", " << op1->getToken()->getLexema() << "\n";
			}
			// id   id      =   null
			else if (cuadruplo->Resultado->getID() == "id" && cuadruplo->Operando1->getID() == "id")
			{
				string IDRes = getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo);
				string IDOp1 = getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
				res << "MOV " << IDRes << ", " << IDOp1 << "\n";
			}
			// id   NT      =   null
			//else if (cuadruplo.Resultado.Id == "id" && cuadruplo.Operando1.GetType() == typeof(NoTerminal)) ;
			// NT   numero  =   null
			//else if (cuadruplo.Resultado.GetType() == typeof(NoTerminal) && cuadruplo.Operando1.Id == "Numero") ;
			// NT   id      =   null
			//else if (cuadruplo.Resultado.GetType() == typeof(NoTerminal) && cuadruplo.Operando1.Id == "id") ;
			break;
		case TiposDeCuadruplos::Operacion:
			res << generarOperacion(cuadruplo, temporales, temporalOffset);
			break;
		case TiposDeCuadruplos::Lectura:
			res << "MOV " << getComandoID(((Terminal*)cuadruplo->Resultado)->getToken()->getLexema(), cuadruplo) << ", sval(input(\" : \")) \n" ;
			break;
		case TiposDeCuadruplos::Escritura:
			if (cuadruplo->Operando1->getID() == "id") {
				res << "print str$(";
				res << getComandoID(((Terminal*)cuadruplo->Operando1)->getToken()->getLexema(), cuadruplo);
			}
			else if (cuadruplo->Operando1->getID() == "Numero") {
				res << "print str$(";
				res << ((Terminal*)cuadruplo->Operando1)->getToken()->getLexema();
			}
			else if (cuadruplo->Operando1->getTipo() == NOTERMINAL) {
				res << "MOV EAX, " << getComandoTemporal(buscarTemporal(temporales, (NoTerminal*)cuadruplo->Operando1)) << "\n";
				res << "print str$(EAX";
			}
			res << "),13,10 \n";
			break;
		case TiposDeCuadruplos::Declaracion:
			res << "MOV EAX, 0" << "\n";
			res << "PUSH EAX" << "\n";
			break;
		case TiposDeCuadruplos::EtiquetaInicioMientras:
			res << "INICIO_MIENTRAS_" << cuadruplo->Operando1 << ": \n";
			break;
		case TiposDeCuadruplos::EtiquetaFinMientras:
			res << "JMP INICIO_MIENTRAS_" << cuadruplo->Operando1 << "\n";
			res << "FIN_MIENTRAS_" << cuadruplo->Operando1 << ": \n";
			break;
		case TiposDeCuadruplos::Mientras:
			res << generarMientras(cuadruplo, temporales, temporalOffset);
			break;
		case TiposDeCuadruplos::EtiquetaFinSi:
			if ((cuadruplos[i+1])->tipo == TiposDeCuadruplos::Osino)
				res << "JMP FIN_OSINO_" << cuadruplo->Operando1 << " \n";
			res << "FIN_SI_" << cuadruplo->Operando1 << ": \n";
			break;
		case TiposDeCuadruplos::Si:
			res << generarSi(cuadruplo, temporales, temporalOffset);
			break;
		case TiposDeCuadruplos::EtiquetaFinOsino:
			res << "FIN_OSINO_" << cuadruplo->Operando1 << ": \n";
			break;
		case TiposDeCuadruplos::Osino:

			break;
		case TiposDeCuadruplos::Destruccion:
			for (size_t variable = 0; variable < cuadruplo->bloque->variables->size(); variable++) {
				res << "POP EAX \n";
			}
			break;
		default:
			break;
		}
		res << "\n";
	}

	res << "POP EBP \n\n";

	res << "ret" << "\n";

	res << "main endp" << "\n";

	res << "end start" << "\n";

	return res.str();
}






bool Compilador::compilar(string ruta)
{
	AnalizadorLexico lexico;

	string codigoFuente = lexico.leerArchivo(ruta);

	auto tokens = lexico.analizar(codigoFuente);

	AnalizadorSintactico sintactico;

	auto cuadruplos = sintactico.Analizar(tokens);

	AnalizadorSemantico semantico;

	auto c = sintactico.Cuadruplos();

	semantico.analizar(&c);

	Compilador compilador;

	if (lexico.getError() || sintactico.getError() || semantico.error) {
		return false;
	}
	else {
		
		string codigoasm = generarCodigo(c);

		compilarASM(codigoasm, ruta);

		return true;
	}
}


void Compilador::compilarASM(string codigoASM, string ruta)
{
	
	ofstream file("ASM.asm");

	file << codigoASM << endl;

	file.close();

	system("ASM\\ml.exe /c /coff /Cp ASM.asm");
	system("ASM\\link.exe /subsystem:console ASM.obj");

	stringstream ss;
	ss << "rename \"ASM.exe\" \"";
	for (size_t i = 0; i < ruta.size(); i++) {
		if (ruta[i] == '.') break;
		ss << ruta[i];
	}
	ss << ".exe\"";
	system(ss.str().c_str());
	system("DEL ASM.asm");
	system("DEL ASM.obj");
	//system("ASM.exe");
}