#pragma once
#ifndef TABLE_LABEL_H
#define TABLE_LABEL_H

//#include "ident.h"
//#include "lex.h"
//#include "type_of_lex.h"
#include <iostream>
#include <cstring>

class Label
{
	char * name;
	bool declare; // есть ли label:
	int position;
public:
	Label();
	char *get_name();
	void put_name(const char * n);

	bool get_declare();
	void put_declare();
	int get_position();
	void put_position(int p);
};

class table_label
{
	Label * l;
	int size;
public: 
	int top;
	table_label(int max_size);
	~table_label();
	void reset();
	Label& operator[] (int k);
	void print();
	int put(const char *buf);
	bool check_TL();
};

#endif