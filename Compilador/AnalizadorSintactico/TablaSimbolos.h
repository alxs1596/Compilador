
#include <vector>

#include "EntradaTablaSimbolos.h"

using namespace std;

class TablaSimbolos
{
private:
	vector<EntradaTablaSimbolos>* variables;
	TablaSimbolos* padre;
public:
	TablaSimbolos(TablaSimbolos* padre);
	~TablaSimbolos();
	bool fueDeclarada(string lexema);
};

