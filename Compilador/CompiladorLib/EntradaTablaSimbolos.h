#include <string>

using namespace std;

namespace compilador {

	class EntradaTablaSimbolos
	{
	private:
		
	public:
		EntradaTablaSimbolos(string lexema, int lineaDeclaracion, int offset);
		~EntradaTablaSimbolos();


		int offset; //Posicion en la pila
		int tipo; //entero = 1
		int lineaDeclaracion;
		int lineaPrimeraAsignacion;
		string lexema;
	};

}

