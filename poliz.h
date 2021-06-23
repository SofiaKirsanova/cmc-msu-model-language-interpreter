// для польской записи

#pragma once

#include "scanner.h"
//#include "lex.h"
//#include "type_of_lex.h"
//s#include "table_ident.h"

using namespace std;

class Poliz {
	Lex *p; int size; int free;
public:
	Poliz ( int max_size );
	~Poliz();
	void push_back(Lex l);
	int Size();
	void push_back(Lex l, int place);
	int get_free();
	void blank();
	Lex& operator[] ( int index );
	void print();
	Lex& last_elem();
};


