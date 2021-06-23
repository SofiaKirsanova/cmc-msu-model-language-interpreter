#include "lex.h"

Lex::Lex()
{
	t_lex = LEX_NULL;
	v_lex = 0;
}

Lex::Lex(type_of_lex t)
{
	t_lex = t;
	v_lex = 0;
}

Lex::Lex(type_of_lex t, int v)
{
	t_lex = t;
	v_lex = v;
}

Lex::Lex(type_of_lex t, char * tmp)
{
	t_lex = t;
	str_lex = new char[1000];
	str_lex = strcpy(str_lex, tmp);
}

type_of_lex Lex::get_type()
{
	return t_lex;
}

char * Lex::get_str()
{
	return str_lex;
}

int Lex::get_value()
{
	return v_lex;
}

/*bool Lex::is_declare()
{
	return declare;
}

void Lex::put_declare()
{
	declare = true;
}*/

std::ostream& operator << (std::ostream &s, Lex l)
{
	const char * translator[] = {"", "and", "boolean", "do", "else", "if", "false", "int", "not", "or", "program", "read", "true", "while", "write", "string", "goto", ";", ",", "=", "(", ")", "{", "}", "==", "<", ">", "+", "-", "*", "/", "%", "\\*", "*\\", "<=", "!=", ">=", "+=", "-=", "\"", ":", "NUM", "ID", "LABEL", "&ID", "GO", "FGO", "EOF"};
	if(l.t_lex == LEX_ID)
		s << "(" << translator[l.t_lex] << " name: " << TID[l.v_lex].get_name() << " type: " << TID[l.v_lex].get_type() << ");" << std::endl;
	else if ((l.t_lex == LEX_STR && l.v_lex != 15) || (l.t_lex == LEX_COLON)) 
		s << "(" << translator[l.t_lex] << ", " << l.str_lex << "); \n";
		s << "(" << translator[l.t_lex] << ", " << TSTR[l.v_lex] << "); \n";
	else
		s << "(" << translator[l.t_lex] << ", " << l.v_lex << "); \n";
	return s;
}