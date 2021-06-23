#include "interpretator.h"
Interpretator::Interpretator (const char * program):pars(program)
{
	//throw "I am here";
};

void Interpretator::interpretation()
{
	pars.analyze();
	if(pars.err_parser == false)
    {
        cout << "/////////////////////// EXECUTER //////////////////////" << endl;
        try
        {
        	E.execute(pars.prog);
        	//cout << endl;
        	cout << "END OF PROGRAMM " << endl;   
        }
        catch(const char * c)
        {
        	cout << "\x1b[37;41m" << c << "\x1b[0m" << endl;
        }
        //close(fp);
    }
}