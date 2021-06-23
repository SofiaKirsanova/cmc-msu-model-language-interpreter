#include "table_label.h"
using namespace std;

table_label TL(1000);
Label::Label()
{
	declare = false;
}

char * Label::get_name()
{
	return name;
}

void Label::put_name(const char * n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

bool Label::get_declare()
{
	return declare;
}

void Label::put_declare()
{
	declare = true;
}

int Label::get_position()
{
	return position;
}

void Label::put_position(int p)
{
	position = p;
}


table_label::table_label(int max_size)
{
	l = new Label[size = max_size];
	top = 0;
}

table_label::~table_label()
{
	delete []l;
}

Label& table_label::operator[] (int k)
{
	return l[k];
}

void table_label::reset()
{
	delete []l;
}

void table_label::print()
{
	for (int j = 1; j < top;j++)
		cout << l[j].get_position();
}

bool table_label::check_TL()
{
	for(int i = 0; i < top; i++)
	{
		if(l[i].get_declare() == false)
		{
			return false;
		}
	}
	return true;
}
int table_label::put(const char *buf) // проверка слова есть ли оно в таблице идентефикаторов или нужно его добавить в конец таблицы
{
	for (int j = 0; j < top; j++)
	{
		if (!strcmp(buf, l[j].get_name()))
		{
			return j;
		}
	}
	l[top].put_name(buf);
	top++;
	return top-1;
}		