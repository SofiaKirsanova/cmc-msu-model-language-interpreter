#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <cstring>

#include "table_label.h"
/*#include "table_label.h"
#include "type_of_lex.h"
#include "ident.h"
#include "table_ident.h"
#include "table_str.h"
#include "lex.h"

#include "scanner.h"
#include "poliz.h"
#include "parser.h"*/
#include "interpretator.h"

#include "table_label.cpp"
#include "ident.cpp"
#include "table_ident.cpp"
#include "table_str.cpp"
#include "lex.cpp"

#include "scanner.cpp"
#include "poliz.cpp"
#include "parser.cpp"
#include "interpretator.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
	char str[100];
	/*try
	{*/
		if (argc == 2)
		{
			strcpy(str, argv[1]);
			strcat(str,".txt");
			Interpretator Model(str);
			Model.interpretation();
		}
		else
			cout << "Wrong file" << endl;
		return 0;
	/*}
	catch(int line, int column, char c, char *rule)
	{

		cout << "\x1b[37;41m" << "Line: " << line << " Column: " << column << " Unexpected symbol" << c << "Rule: " << rule << "\x1b[0m" << endl;
    	return 1;
 	}
  	catch(int line, int column, Lex l, char *rule)
  	{
  		cout << "\x1b[37;41m" << "Line: " << line << " Column: " << column << " Unexpected lexeme" << l << "Rule: " << rule << "\x1b[0m" << endl;
    	return 1;
 	}
  	catch(int line, int column, const char *source)
  	{
   		cout << "\x1b[37;41m" << "Line: " << line << " Column: " << column << source << "\x1b[0m"<< endl;
    	return 1;
	}
	return 0;
}
	return 0;*/
}
