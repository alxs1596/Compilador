
#include <vector>
#include <algorithm>

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
			vector<char>* blancos;
		public:
			vector<char>* Letras();
			vector<char>* Delimitadores();
			vector<char>* Operadores();
			vector<char>* Numeros();
			vector<char>* Todo();
			vector<char>* Blancos();
			Alfabeto();
			~Alfabeto();
			static void agregarVectorAVector(vector<char>* a, vector<char>* b);
			static vector<char>* VectorMenos(vector<char>* a, vector<char> b);
			static vector<char>* VectorMenos(vector<char>* a, char b);
			static void ordenar(vector<char>*);
		};

	}
}