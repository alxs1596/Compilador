#pragma once

#include "../AnalizadorSintactico/AnalizadorSintactico.h"
#include "../AnalizadorLexico/AnalizadorLexico.h"
#include "../AnalizadorSemantico/AnalizadorSemantico.h"

using namespace compilador::sintactico;
using namespace compilador::lexico;
using namespace compilador::semantico;


class Temporal
{
public:
	Temporal(NoTerminal* n, int o):noTerminal(n), offset(o) {}
	NoTerminal* noTerminal;
	int offset;

};
class Compilador
{
private:
	string getComandoID(string lexema, Cuadruplo* cuadruplo);
	string getComandoTemporal(Temporal*);

	string generarOperacion(Cuadruplo*, vector<Temporal*>* temporales, int& temporalOffset);
	string generarMientras(Cuadruplo*, vector<Temporal*>* temporales, int& temporalOffset);
	string generarSi(Cuadruplo * cuadruplo, vector<Temporal*>* temporales, int & temporalOffset);


	string suma(string res, string op1, string op2);
	string resta(string res, string op1, string op2);
	string multiplicacion(string res, string op1, string op2);
	string division(string res, string op1, string op2);
	string modulo(string res, string op1, string op2);
	string menor(string res, string op1, string op2, Cuadruplo*);
	string mayor(string res, string op1, string op2, Cuadruplo*);
	string menorigual(string res, string op1, string op2,Cuadruplo*);
	string mayorigual(string res, string op1, string op2,Cuadruplo*);
	string igualigual(string res, string op1, string op2,Cuadruplo*);
	string diferente(string res, string op1, string op2,Cuadruplo*);
	string and(string res, string op1, string op2);
	string or(string res, string op1, string op2);

	Temporal* buscarTemporal(vector<Temporal*>* lista, NoTerminal* nt);

	string generarCodigo(vector<Cuadruplo*> cuadruplos);

	void compilarASM(string codigoASM, string);

public:
	Compilador();
	~Compilador();
	
	bool compilar(string ruta);
};

