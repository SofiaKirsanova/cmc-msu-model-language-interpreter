#include "parser.h"
//#include "table_ident.h"
#include <cstring>

extern table_ident TID;
extern table_str TSTR;

class Executer
{
	Lex pc_el;
public:
	void execute(Poliz &prog);
};