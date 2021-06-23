#include "ident.h"

Ident::Ident()
{
	declare = false;
	assign = false;
}

char * Ident::get_name()
{
	return name;
}

/*char * Ident::get_value_str()
{
	return c_str;
}

void Ident::put_value_str(string c)
{
	c_str = c;
}
*/
void Ident::put_name(const char *n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

bool Ident::get_declare()
{
	return declare;
}

void Ident::put_declare()
{
	declare = true;
}

bool Ident::get_assign()
{
	return assign;
}

void Ident::put_assign()
{
	assign = true;
}

type_of_lex Ident::get_type()
{
	return type;
}

void Ident::put_type(type_of_lex t)
{
	type = t;
}

int Ident::get_value()
{
	return value;
}

void Ident::put_value(int v)
{
	value = v;
}

