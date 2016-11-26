#include "stdafx.h"
#include "Codigos.h"
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

Source* Codigos::Source9()
{
	stringstream ss;

	ss << "entero a;\n";

	return new Source(ss.str(), true, false, false);
}

Source* Codigos::Source10()
{
	stringstream ss;

	ss << "entero a = 5;\n";

	return new Source(ss.str(), true, false, false);
}

Source* Codigos::Source11()
{

	stringstream ss;

	ss << "entero a, b = 3;\n";

	return new Source(ss.str(), true, false, false);
}


Source* Codigos::Source12()
{
	stringstream ss;

	ss << "entero a = 5 * 3;\n";

	return new Source(ss.str(), true, false, false);
}

Source* Codigos::Source13()
{
	stringstream ss;

	ss << "Programa(){entero a;}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source14()
{
	stringstream ss;

	ss << "Programa(){entero i = 4; Si(4){i = 1;}Osino{i = 2;}}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source15()
{
	stringstream ss;

	ss << "Programa(){";
	ss << "entero num1 = 4;"; 
	ss << "entero num2 = 10;"; 
	ss << "entero num3 = 2;";
	ss << "Si(num1){"; 
	ss << "Si(num2){";
	ss << "entero a;";
	ss << "}Osino{";
	ss << "entero b;";
	ss << "}";
	ss << "}Osino{ ";
	ss << "Si(num1) {entero c;}Osino{entero d;}}}\n";

	return new Source(ss.str(), true);
}

Source* Codigos::Source16()
{
	stringstream ss;

	ss << "Programa(){int a;}\n";

	return new Source(ss.str(), true, false, false);
}