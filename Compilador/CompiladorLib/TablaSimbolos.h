
#include <vector>

#include "EntradaTablaSimbolos.h"

using namespace std;

namespace compilador {

	class TablaSimbolos
	{
	private:
		vector<EntradaTablaSimbolos>* variables;

	public:
		int linea;
		int nbloque;
		TablaSimbolos* padre;
		TablaSimbolos(int linea) : linea(linea) {}
		TablaSimbolos(TablaSimbolos* padre, int nbloque, int linea) : padre(padre), nbloque(nbloque), linea(linea) {}
		TablaSimbolos(TablaSimbolos* padre);
		~TablaSimbolos();
		bool fueDeclarada(string lexema);
	};

}