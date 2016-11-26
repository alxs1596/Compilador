
#include <vector>

using namespace std;

namespace compilador {

	namespace lexico {

		class Alfabeto
		{
		private:
			vector<char>* letras;
			vector<char>* delimitadores;
			vector<char>* operadores;
			vector<char>* numeros;
			vector<char>* todo;
		public:
			vector<char>* Letras();
			vector<char>* Delimitadores();
			vector<char>* Operadores();
			vector<char>* Numeros();
			vector<char>* Todo();
			Alfabeto();
			~Alfabeto();
		};

	}
}