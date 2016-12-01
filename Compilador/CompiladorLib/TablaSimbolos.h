
#include <vector>

#include "EntradaTablaSimbolos.h"

using namespace std;

namespace compilador {

	class TablaSimbolos
	{
	private:
		
	public:
		int linea;
		int nbloque;
		TablaSimbolos* padre;
		TablaSimbolos(int linea) : linea(linea) {}
		TablaSimbolos(TablaSimbolos* padre, int nbloque, int linea) : padre(padre), nbloque(nbloque), linea(linea) {}
		TablaSimbolos(TablaSimbolos* padre);
		~TablaSimbolos();
		vector<EntradaTablaSimbolos*>* variables;
		EntradaTablaSimbolos* fueDeclarada(string lexema);
	};

}