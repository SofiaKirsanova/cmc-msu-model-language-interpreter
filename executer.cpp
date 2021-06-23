#include "executer.h"

void Executer::execute ( Poliz & prog ) 
{
  	stack <int> args;
  	stack <string> args_str;
  	stack <int> args_reverse;
  	stack <string> args_str_reverse;
  	int i, j, h, index = 0, size = prog.get_free();
  	string str1,str2;
  	//cout << "SIZE: " << size << endl;
  	while ( index < size )
   	{
    	pc_el = prog[index];
    	//cout << "INDEX: " << index << "LEXEM: " << pc_el << endl;
    	switch ( pc_el.get_type () ) 
    	{
 
			case LEX_TRUE:
			case LEX_FALSE:
			case LEX_NUM: 
			case POLIZ_ADRESS: 
			case POLIZ_LABEL:
		        args.push( pc_el.get_value () );
		        break;
		 
		  	case LEX_ID:
			    i = pc_el.get_value ();
			    if (TID[i].get_assign ()) 
			    {
			    	if(TID[i].get_type() == LEX_STR)
			    	{
			    		str1 = TSTR[TID[i].get_value()];
		  				args_str.push(str1);
			    	}
					args.push (TID[i].get_value ());

			    }
			    else
			      throw "POLIZ: indefinite identifier";
				
			  break;
			case LEX_NOT:
			  	i = args.top();
			    args.pop();
			    args.push( !i );
			    break;

			case LEX_OR:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( j || i );
			    break;

			case LEX_AND:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( j && i );
			    break;

			case POLIZ_GO:
			    i = args.top();
			    args.pop();
			    index = i - 1;
			    break;

			case POLIZ_FGO:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    if ( !j ) index = i-1;
			    break;

			case LEX_GOTO:
				i = pc_el.get_value();
				args.push(TL[i].get_position());
				break;

			case LEX_WRITE:
				//cout << "::::::::::::" << endl;
				while (!args_str.empty())
				{
					str1 = args_str.top();
					args_str.pop();
					//cout << "RRRRRRRRRRRR1" << endl;
					j = args.top();
					//cout << "RRRRRRRRRRRR2" << endl;
					//cout << "fgfgfggfgffgf" << j << endl;
					args.pop();
					//cout << "RRRRRRRRRRRR3" << endl;
					args_str_reverse.push(str1);
					//cout << "RRRRRRRRRRRR4" << endl;

				}
				
				while(!args.empty())
				{
					j = args.top();
				    args.pop();
				    args_reverse.push(j);
				}

				while(!args_str_reverse.empty())
				{
					str1 = args_str_reverse.top();
				    args_str_reverse.pop();
				    cout << str1 << ' ';
				    cout << str1 << endl;
				}

				while(!args_reverse.empty())
				{
					j = args_reverse.top();
				    args_reverse.pop();
				    cout << j << ' ';
				}
				//cout << endl;
				    cout << j << endl;
				}
			    break;
			/*case LEX_WRITELN:
				if (!args_str.empty())
				{
					str1 = args_str.top();
					args_str.pop();
					j = args.top();
					args.pop();
					cout << str1 << endl;
				}
				else 
				{
					j = args.top();
				    args.pop();
				    cout << j << endl;
				}
			    break;
			*/
			case LEX_READ:
			    int k;
			    i = args.top ();
			    args.pop();
				cout << endl;
			    if ( TID[i].get_type () == LEX_INT ) 
			    {
			        cin >> k;
			    }
			    else
			    if(TID[i].get_type () == LEX_STR)
			    {
			    	cin >> str1;
			    	k = TSTR.put(str1);
			    }
			    else
			    {
			        string j;
			        while (1)
			        {
			            cin >> j;
			            if (j != "true" && j != "false")
			            {
			                cout << "Error in input:true/false" << endl;
			                continue;
			            }
			            k = (j == "true")? 1 : 0 ;
			            break;
			        }
			    }
			      TID[i].put_value (k);
			      TID[i].put_assign ();
			      break;

			case LEX_PLUS:
				i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			   
			    if(!args_str.empty())
			    {
			    	str1 = args_str.top();
			    	args_str.pop();
			    	str2 = args_str.top();
			    	args_str.pop();
			    	args_str.push(str2 + str1);


			    	args.push(TSTR.put(str2+str1));
			    }
			    else
			    {
				    args.push (i + j);
			    }
			    
			    break;

			case LEX_MULT:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( i * j );
			    break;

			case LEX_MINUS:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( j - i );
			    break;

			case LEX_DIV:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    if (i) {
			      args.push(j / i);
			      break;
			    }
			    else
			      throw "POLIZ: divide by zero";

			case LEX_MOD:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    if (i) {
			      args.push(j % i);
			      break;
			    }
			    else
			      throw "POLIZ: mod by zero";

			case LEX_MINUSEQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    h = TID[j].get_value();
			    TID[j].put_value(h - i);
			    TID[j].put_assign();
			    break;

			case LEX_PLUSEQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    h = TID[j].get_value();
			    TID[j].put_value(h + i);
			    TID[j].put_assign();
			    break;

			case LEX_EQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    if(!args_str.empty())
			    {
			    	str1 = args_str.top();
			    	args_str.pop();

			    	str2 = args_str.top();
			    	args_str.pop();
			    	//args_str.push(str2 + str1);
			    	args.push(str1 == str2);
			    }
			    else
			    {
			    	args.push ( i == j);
				}
			    break;
			case LEX_LSS:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();

			    if(!args_str.empty())
			    {
			    	str1 = args_str.top();
			    	args_str.pop();
			    	str2 = args_str.top();
			    	args_str.pop();
			    	args.push(str2 < str1);
			    }
			    else
			    {
			    	args.push ( j < i);
				}
			    break;
			case LEX_GTR:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();

			    if(!args_str.empty())
			    {
			    	str1 = args_str.top();
			    	args_str.pop();
			    	str2 = args_str.top();
			    	args_str.pop();
			    	args.push(str2 > str1);
			    }
			    else
			    {
			    	args.push ( j > i);
				}
			    break;
			case LEX_LEQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( j <= i );
			    break;

			case LEX_GEQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();
			    args.push ( j >= i );
			    break;

			case LEX_NEQ:
			    i = args.top();
			    args.pop();
			    j = args.top();
			    args.pop();

			    if(!args_str.empty())
			    {
			    	str1 = args_str.top();
			    	args_str.pop();
			    	str2 = args_str.top();
			    	args_str.pop();
			    	args.push(str1 != str2);
			    }
			    else
			    {
			    	args.push ( i != j);
				}
			    break;
			case LEX_STR:
				i = pc_el.get_value();
				str1 = TSTR[i];
				args_str.push(str1);
				args.push(i);
				break;
			case LEX_ASSIGN:
				if(!args_str.empty())
				{
					str1 = args_str.top();
					args_str.pop();
				}
					i = args.top();
			   		args.pop();
			   		j = args.top();
			    	args.pop();
			    	TID[j].put_value(i);
			    	TID[j].put_assign(); 
			   
			    break;
			case LEX_SEMICOLON:
				//cout << "gfgfgfgfg" << pc_el << endl;
				//i = args.top();
			   	//args.pop();
				if(!args.empty())
				{
					throw "POLIZ: Too much elems";
				}
				break;
			   	
			default:
			{
			    throw "POLIZ: unexpected elem";
			}
		}
		++index;
	};
}
