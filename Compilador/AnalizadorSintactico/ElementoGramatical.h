#pragma once
#define TERMINAL true
#define NOTERMINAL false

namespace compilador {
	namespace sintactico {

		class ElementoGramatical
		{
		private:
			// Terminal = true, NoTerminal = false
			bool tipo;
			//NoTerminal* padre;
		public:
			ElementoGramatical(bool tipo) { this->tipo = tipo; }// this->padre = NULL;

			~ElementoGramatical();

			virtual ElementoGramatical* clonar() { return 0; }

			//const NoTerminal* getPadre() { return padre; }
			//void setPadre(NoTerminal* _p) { padre = _p; }
			bool getTipo() { return tipo; }
		};

	}
}