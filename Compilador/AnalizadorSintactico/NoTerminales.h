#pragma once

#include <vector>

#include "NoTerminal.h"

using namespace std;

namespace compilador {
	namespace sintactico {

		class NoTerminales
		{
		public:
			NoTerminal* P = new NoTerminal("P");
			NoTerminal* BS = new NoTerminal("BS");
			NoTerminal* LS = new NoTerminal("LS");
			NoTerminal* S = new NoTerminal("S");
			NoTerminal* SD = new NoTerminal("SD");
			NoTerminal* SA = new NoTerminal("SA");
			NoTerminal* SC = new NoTerminal("SC");
			NoTerminal* SM = new NoTerminal("SM");
			NoTerminal* SL = new NoTerminal("SL");
			NoTerminal* SE = new NoTerminal("SE");
			NoTerminal* SHM = new NoTerminal("SHM");
			NoTerminal* TD = new NoTerminal("TD");
			NoTerminal* VA = new NoTerminal("VA");
			NoTerminal* RD = new NoTerminal("RD");
			NoTerminal* A = new NoTerminal("A");
			NoTerminal* EM = new NoTerminal("EM");
			NoTerminal* T = new NoTerminal("T");
			NoTerminal* LT = new NoTerminal("LT");
			NoTerminal* OP1 = new NoTerminal("OP1");
			NoTerminal* F = new NoTerminal("F");
			NoTerminal* LF = new NoTerminal("LF");
			NoTerminal* OP2 = new NoTerminal("OP2");
			NoTerminal* SUBBS = new NoTerminal("SUBBS");
			NoTerminal* ELSE = new NoTerminal("ELSE");
			NoTerminal* OL = new NoTerminal("OL");
			NoTerminal* C = new NoTerminal("C");
			NoTerminal* OP3 = new NoTerminal("OP3");
			NoTerminal* OP4 = new NoTerminal("OP4");
			NoTerminal* LOL = new NoTerminal("LOL");
			NoTerminal* LC = new NoTerminal("LC");
			NoTerminal* SUBBSVacio = new NoTerminal("SUBBSVacio");
			NoTerminal* noTerminalBase = P;
			const int Count = 31;

			vector<NoTerminal*>* Todos();
		};




	}
}
