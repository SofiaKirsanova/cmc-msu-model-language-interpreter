#pragma once
//#ifndef LEX_H
#define LEX_H
#include <iostream>
#include <string>
#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include <stack>
//#include <algorithm>
//#include "type_of_lex.h"
#include "table_ident.h"
#include "table_str.h"
//extern const char * translator[];
extern table_ident TID;
extern table_str TSTR;

class Lex
{
	type_of_lex t_lex;
	int v_lex = 0;
	char * str_lex;
	bool declare = false;
public:
	Lex();
	Lex(type_of_lex t);
	Lex(type_of_lex t, int v);
	Lex(type_of_lex t, char * tmp);
	/*bool is_declare();
	void put_declare();*/
	type_of_lex get_type();
	int get_value();
	char * get_str();
	friend std::ostream& operator << (std::ostream &s, Lex l);
};
