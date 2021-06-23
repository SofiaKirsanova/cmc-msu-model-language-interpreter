extern table_ident TID;
#pragma once
//#include "parser.h"
#include "executer.h"
//extern table_ident TID;
class Interpretator 
{
	Parser pars;
	//Scanner scan;
	Executer E;
public:
	Interpretator (const char * program);
	void interpretation();
}; 
