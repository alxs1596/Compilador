#include <string>
#include <sstream>

using namespace std;

class Source {
public:
	Source(string codigo, bool lexicoValido, bool sintacticoValido, bool semanticoValido) :
		codigo(codigo),
		lexicoValido(lexicoValido),
		sintacticoValido(sintacticoValido),
		semanticoValido(semanticoValido) {}
	Source(string codigo, bool valido):
		codigo(codigo),
		lexicoValido(valido),
		sintacticoValido(valido),
		semanticoValido(valido) {}
	string Codigo() { return codigo; }
	bool LexicoValido() { return lexicoValido; }
	bool SintacticoValido() { return sintacticoValido; }
	bool SemanticoValido() { return semanticoValido; }
private:
	string codigo;
	bool lexicoValido;
	bool sintacticoValido;
	bool semanticoValido;
};

class Codigos
{
public:
	Codigos();
	~Codigos();

	static Source* Source1();
	static Source* Source2();
	static Source* Source3();
	static Source* Source4();
	static Source* Source5();
	static Source* Source6();
	static Source* Source7();
	static Source* Source8();
	static Source* Source9();
	static Source* Source10();
	static Source* Source11();
	static Source* Source12();
	static Source* Source13();
	static Source* Source14();
	static Source* Source15();
	static Source* Source16();

private:

};
