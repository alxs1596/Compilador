#pragma once
#define TERMINAL true
#define NOTERMINAL false

enum ElementosGramaticales
{

};

class ElementoGramatical
{
private:
	// Terminal = true, NoTerminal = false
	bool tipo;
public:
	ElementoGramatical(bool tipo) { this->tipo = tipo; }
	~ElementoGramatical();

	bool getTipo() { return tipo; }
};

