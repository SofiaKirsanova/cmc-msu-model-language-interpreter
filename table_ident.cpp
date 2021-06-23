#include "table_ident.h"

table_ident TID(1000); 

table_ident::table_ident(int max_size)
{
	p = new Ident[size = max_size];
	top = 0;
}

table_ident::~table_ident()
{
	delete []p;
}

Ident& table_ident::operator[] (int k)
{
	return p[k];
}

void table_ident::reset()
{
	delete []p;
}

void table_ident::print()
{
	for (int j = 1;j < top;j++)
		cout << p[j].get_value();
}

int table_ident::put(const char *buf) // проверка слова есть ли оно в таблице идентефикаторов или нужно его добавить в конец таблицы
{
	for (int j = 0; j < top; j++)
	{
		if (!strcmp(buf, p[j].get_name()))
		{
			return j;
		}
	}
	p[top].put_name(buf);
	top++;
	return top-1;
}		