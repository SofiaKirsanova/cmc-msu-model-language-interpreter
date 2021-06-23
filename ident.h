#pragma once
#ifndef IDENT_H
#define IDENT_H
#include <iostream>
//#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
//#include "lex.h"
#include "type_of_lex.h"
class Ident
{
	char * name;
	bool declare; // вернет true, если в поле лежит слово/число
	type_of_lex type;
	bool assign; // вернет true, если этим полям присвоены значения
	int value;
	string c_str;
public:
	Ident();
	char *get_name(); 
	void put_name(const char *n);

	bool get_declare();
	void put_declare();

	bool get_assign();
	void put_assign();

	type_of_lex get_type();
	void put_type(type_of_lex t);

	int get_value();
	void put_value(int v);

	//char * get_value_str();
	//void put_value_str(string c);
};
#endif
