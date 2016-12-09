#pragma once
#define TERMINAL true
#define NOTERMINAL false

#include <string>

using namespace std;

namespace compilador {
	namespace sintactico {

		class ElementoGramatical
		{
		private:
			// Terminal = true, NoTerminal = false
			bool tipo;
			
			//NoTerminal* padre;
		protected:
			string id;
		public:
			ElementoGramatical(bool tipo) { this->tipo = tipo; }// this->padre = NULL;

			~ElementoGramatical();

			virtual ElementoGramatical* clonar() { return 0; }

			//const NoTerminal* getPadre() { return padre; }
			//void setPadre(NoTerminal* _p) { padre = _p; }
			bool getTipo() { return tipo; }
			string getID() { return id; }
		};

	}
}