#pragma once
#ifndef TABLE_STR_H
#define TABLE_STR_H

//#include "lex.h"
//#include "type_of_lex.h"
#include <string>
#include <cstring>

using namespace std;

class table_str
{
	string *p;
	int size;
	int top;
public: 
	table_str(int max_size);
	~table_str();
	string& operator[] (int k);
	int put(string s);
	int put(const char * buf);
} /*TSTR(1000)*/;

#endif