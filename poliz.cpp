#include "poliz.h"

//using namespace std;

Poliz::Poliz ( int max_size ) 
{
	p = new Lex [size = max_size];
	free = 0; 
}	

Poliz::~Poliz()
{ 
	delete []p; 
}

void Poliz::push_back(Lex l)
{ 
	p[free]=l; 
	++free;
}

void Poliz::push_back(Lex l, int place) 
{ 
	p[place]=l; 
}

void Poliz::blank()
{ 
	++free;
}

int Poliz::get_free() 
{ 
	return free; 
}

Lex& Poliz::operator[](int index)
{
	if (index > size)
		throw "POLIZ: out of array";
	else if (index > free)
		throw "POLIZ: indefinite element of array";
	else 
		return p[index];
}

void Poliz::print() 
{
	for (int i = 0; i < free; ++i)
		cout << p[i]; 
<<<<<<< HEAD
=======

>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
}

int Poliz::Size()
{
	return free;
}

Lex& Poliz::last_elem()
{
	return p[free];
}


