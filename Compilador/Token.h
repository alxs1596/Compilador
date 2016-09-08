#pragma once
class Token
{
public:
	Token();
	~Token();

	Token(std::string lexema, int tipo_token);
	const std::string& getLexema() const;
	void setLexema(const std::string& lexema);
	int getTipo() const;
	void setTipo(int tipo);
private:
	std::string PalabraLexema;
	int Tipo;
};

