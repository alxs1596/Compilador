#include "stdafx.h"
#include "AnalizadorSemantico.h"


AnalizadorSemantico::AnalizadorSemantico()
{
}


AnalizadorSemantico::~AnalizadorSemantico()
{
}

void AnalizadorSemantico::analizar(vector<Cuadruplo*>* cuadruplos)
{

	foreach(var cuadruplo in cuadruplos)
	{
		if (cuadruplo.tipo == TiposDeCuadruplos.Declaracion)
		{
			var token = ((Terminal)cuadruplo.Resultado).token;
			if (cuadruplo.Resultado.GetType() == typeof(Terminal))
				if (cuadruplo.Bloque.fueDeclarada(token.Lexema))
				{
					throw new Exception("Variable ya declarada");
				}
				else
				{
					EntradaTablaSimbolos entrada = new EntradaTablaSimbolos(token.Lexema, token.Linea, offset++);
					cuadruplo.Bloque.variables.Add(entrada);
				}
		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Asignacion)
		{
			if (cuadruplo.Resultado.GetType() == typeof(Terminal))
			{
				var token = ((Terminal)cuadruplo.Resultado).token;
				if (cuadruplo.Bloque.fueDeclarada(token.Lexema))
				{
					var bloque = cuadruplo.Bloque;
					while (bloque != null)
					{
						var res = bloque.variables.Where(x = > x.lexema == token.Lexema).ToList();
						if (res.Count > 1) throw new Exception("Mas de una variable");
						else if (res.Count == 1)
						{
							if (res[0].lineaPrimeraAsignacion == -1)
								res[0].lineaPrimeraAsignacion = token.Linea;
							break;
						}
						else if (res.Count == 0) bloque = bloque.padre;
					}
				}
				else
				{
					throw new Exception("Variable no declarada");
				}
			}

		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Operacion)
		{
			if (cuadruplo.Resultado.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Resultado;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
			if (cuadruplo.Operando1.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Operando1;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
			if (cuadruplo.Operando2.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Operando2;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Lectura)
		{
			if (cuadruplo.Resultado.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Resultado;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Escritura)
		{
			if (cuadruplo.Operando1.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Operando1;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Mientras)
		{
			if (cuadruplo.Operando1.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Operando1;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
		}
		else if (cuadruplo.tipo == TiposDeCuadruplos.Si)
		{
			if (cuadruplo.Operando1.GetType() == typeof(Terminal))
			{
				Terminal t = (Terminal)cuadruplo.Operando1;
				if (t.token.Tipo == TipoToken.Identificador)
				{
					if (!cuadruplo.Bloque.fueDeclarada(t.token.Lexema))
						throw new Exception("Variable no declarada");
				}
			}
		}
	}
}