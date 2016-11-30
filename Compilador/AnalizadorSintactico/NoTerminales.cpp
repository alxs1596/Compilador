#include "stdafx.h"
#include "NoTerminales.h"

using namespace compilador::sintactico;

vector<NoTerminal*>* NoTerminales::Todos()
{
	auto r = new vector<NoTerminal*>();

	r->push_back(P);
	r->push_back(BS);
	r->push_back(LS);
	r->push_back(S);
	r->push_back(SD);
	r->push_back(SA);
	r->push_back(SC);
	r->push_back(SM);
	r->push_back(SL);
	r->push_back(SE);
	r->push_back(SHM);
	r->push_back(TD);
	r->push_back(VA);
	r->push_back(RD);
	r->push_back(A);
	r->push_back(EM);
	r->push_back(T);
	r->push_back(LT);
	r->push_back(OP1);
	r->push_back(F);
	r->push_back(LF);
	r->push_back(OP2);
	r->push_back(SUBBS);
	r->push_back(ELSE);
	r->push_back(OL);
	r->push_back(C);
	r->push_back(OP3);
	r->push_back(OP4);
	r->push_back(LOL);
	r->push_back(LC);

	return r;
}