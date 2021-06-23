#include "table_str.h"
//#include <string>
table_str TSTR(1000);

table_str::table_str(int max_size)
{
	p = new string[size = max_size];
	top = 1;
}

table_str::~table_str()
{
	delete []p;
}

string& table_str::operator[] (int k)
{
	return p[k];
}

int table_str::put(const char * buf)
{
	p[top].assign(buf, strlen(buf));
	++top;
	return top - 1;
}

int table_str::put(string s)
{
	p[top] = s;
	++top;
	return top - 1;
}
