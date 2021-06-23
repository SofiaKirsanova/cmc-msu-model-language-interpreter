#pragma once
//весь первый этап. разбрасывание по стекам
//#include "table_label.h"
//#include "lex.h"
//#include "type_of_lex.h"
#include "table_label.h"
//#include "scanner.h"
#include "poliz.h"
//#include "table_ident.h"
//#include "table_str.h"
//#include "st.h"
//#include "poliz.h"
//#include "st.cpp"
#include <stack>


extern table_ident TID;
extern table_label TL;
<<<<<<< HEAD
extern table_str TSTR;
extern const char * translator[];
=======
/*extern table_str TSTR;
extern const char * translator[];*/
//extern const char * translator[];
//extern program fp;/////
//extern table_label TL;
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
extern int words_size;

/*
template <class T, int max_size> class Stack
{
	T s[max_size];
	int top;
public:
	Stack();
	void reset();
	void push(T i);
	T pop();
	bool is_empty();
	bool is_full();
	int get_top();
};
*/

class Parser
{
	Lex curr_lex;
	type_of_lex c_type;
	int c_val;
	char * c_str;
	stack <int> st_int;
	stack <type_of_lex> st_lex;
	//Stack <int,100> st_int;
	//Stack <type_of_lex,100> st_lex;
	//Stack <char *,100>st_string;
public: 
	Scanner scan;
	//void PeremS();
	/* void Opers();
	void Opis();
	void Opises();

	void Oper();*/
	//void SosOper();
	void Const();
	void Perem();
	void Prog();
	void P();
	void D1();
	void D();
	void B();
	void S();
	void E();
	void E1();
	void T();
	void F();
	void Eand();
	void Eor();

	void check_declare (type_of_lex type);
	//void check_id();
	void check_op();
	void check_not();
	void eq_type();
	void eq_bool();
	void check_id_in_read();

	void gl();
public:
	bool err_parser = false;
	Poliz prog;
	
	Parser (const char *program);
	void analyze();
};