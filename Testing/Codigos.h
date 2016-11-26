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

private:

};

Codigos::Codigos()
{
}

Codigos::~Codigos()
{
}

Source* Codigos::Source1() {
	stringstream ss;

	ss << "Programa() {\n";
	ss << "\n";
	ss << "\tentero a = 5 + 8 * 3;";
	ss << "\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source2() {
	stringstream ss;

	ss << "Programa() {\n";
	ss << "\n";
	ss << "\tentero a = 5;\n";
	ss << "\tentero b = 6;\n";
	ss << "\ta = b + 1\n;";
	ss << "\n";
	ss << "}";

	return new Source(ss.str(), true);
}

Source* Codigos::Source3() {
	stringstream ss;

	ss << "Programa() {\n";
	ss << "\n";
	ss << "\tentero a = 0;\n";
	ss << "\tMientras(a <= 5) {\n";
	ss << "\t\ta = a + 1;\n";
	ss << "\t}\n";
	ss << "\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source4() {
	stringstream ss;

	ss << "Programa() {\n";
	ss << "\n";
	ss << "\tentero a;\n";
	ss << "\tLeerTeclado(a);\n";
	ss << "\tEscribirPantalla(a);\n";
	ss << "\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source5() {

	stringstream ss;

	ss << "Programa()\n";
	ss << "{\n";
	ss << "\tEscribirPantalla(5 <= 6);\n";
	ss << "\tentero a = 8 + 1;\n";
	ss << "\ta = 5 + 2 * 4;\n";
	ss << "\ta = 5 || (a && 2);\n";
	ss << "\tLeerTeclado(a);\n";
	ss << "}\n";

	return new Source(ss.str(), true);

}

Source* Codigos::Source6() {
	stringstream ss;

	ss << "Programa()\n";
	ss << "{\n";
	ss << "\tEscribirPantalla(5 <= 6);\n";
	ss << "\tentero a = 8 + 1;\n";
	ss << "\ta = 5 + 2 * 4;\n";
	ss << "\ta = 5 || (a && 2);\n";
	ss << "\ta = 1 + 2 - 3 * 4 / 5 % 6 < 7 > 8 <= 9 >= 10 == 11 != 12 && 13 || 14;\n";
	ss << "\tLeerTeclado(a);\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source7() {
	stringstream ss;

	ss << "Programa()\n";
	ss << "{\n";
	ss << "\tEscribirPantalla(5 <= 6);\n";
	ss << "\tentero a;// = 8+ 1;\n";
	ss << "\t//a = 5 + 2 * 4;\n";
	ss << "\t//a = 5 || (a && 2);\n";
	ss << "\ta = 1 + 2 - 3 * 4 / 5 % 6 < 7 > 8 <= 9 >= 10 == 11 != 12 && 13 || 14;\n";
	ss << "\tLeerTeclado(a);\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source8() {
	stringstream ss;

	ss << "Programa()\n";
	ss << "{\n";
	ss << "\t/*EscribirPantalla(5<=6);\n";
	ss << "\tentero a = 8+ 1;\n";
	ss << "\ta = 5 + 2 * 4;\n";
	ss << "\ta = 5 || (a && 2);\n";
	ss << "\ta = 1 + 2 - 3 * 4 / 5 % 6 < 7 > 8 <= 9 >= 10 == 11 != 12 && 13 || 14;\n";
	ss << "\tLeerTeclado(a);*/\n";
	ss << "\tSi(a == b) {\n";
	ss << "\t}\n";
	ss << "}\n";

	return new Source(ss.str(), true);
}

