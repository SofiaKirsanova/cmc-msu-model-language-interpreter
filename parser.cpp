#include "parser.h"
//#include <stack>

template <class T, class T_EL>
void from_st(T & st, T_EL & i)
{
    i = st.top(); // взятие верхнего элемента стека
    st.pop();
}

void Parser::gl() 
{
    //cout << "I'm hear1" << endl;
    curr_lex = scan.get_lex(); // идем в scanner.cpp 
    cout << curr_lex;
    c_type = curr_lex.get_type();
    c_val = curr_lex.get_value(); // номер слова в таблице TID
    c_str = curr_lex.get_str();
    //cout << "pozition: " << c_val << endl;
}
Parser::Parser (const char *program): scan(program), prog(1000)  {}

void Parser::analyze()
{
<<<<<<< HEAD
    gl();
    cout << "////////////////////// SCAN //////////////////////" << endl;
    Prog();
    cout << endl << "////////////////////// POLIZ //////////////////////" << endl;
    prog.print();
    //close(fp);
=======
    cout << "/////////////////////// SCAN //////////////////////" << endl;
    gl();
    Prog();
    if((err_parser == false) && (scan.err_scaner == false))
    {
        err_parser = (err_parser && scan.err_scaner);
        cout << endl << "////////////////////// POLIZ //////////////////////" << endl;
        prog.print();   
        //close(fp);
    }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
}

void Parser::Prog()
{
<<<<<<< HEAD
    if (c_type == LEX_PROGRAM)
        gl();
    else
        throw curr_lex;
    if(c_type == LEX_LBRACE)
    {
        gl();
        D1(); // объявление переменных разного типа
        B();
    }
    else
        throw curr_lex;
    if(c_type != LEX_RBRACE)
        throw curr_lex;
=======
    try
    {
        if (c_type == LEX_PROGRAM)
            gl();
        else
            throw curr_lex;
        
        if(c_type == LEX_LBRACE)
        {
            gl();
            D1(); // объявление переменных разного типа
            B();
        }
        else
            throw curr_lex;
        if(c_type != LEX_RBRACE)
            throw curr_lex;
        else
        {
            gl();
            if(c_type != LEX_EOF)
            {
                throw " Program finished with ERRORS ";
            }
        }
        if(TL.check_TL() == false)
        {
            throw " Some COLONS weren't identificated ";
        }
    }
    catch(Lex l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem" << l << "Wrong rule for program" << "\x1b[0m" << endl;
        err_parser = true;
        //gl();
    }
    catch(char *l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
        err_parser = true;
        //gl();
    }
    catch(const char *l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
        err_parser = true;
        //gl();
    }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
}

void Parser::D1() // поле переменных
{
<<<<<<< HEAD
    while ((c_type == LEX_INT) || (c_type == LEX_BOOLEAN) || (c_type == LEX_STR))
    {

        D();
        if(c_type != LEX_SEMICOLON)
            throw curr_lex;
        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
=======
    try
    {
        while ((c_type == LEX_INT) || (c_type == LEX_BOOLEAN) || (c_type == LEX_STR))
        {    
            D(); 
            if(c_type != LEX_SEMICOLON)
                throw curr_lex;
            prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
            gl();
        }
    }
    catch(Lex l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem" << l << "Wrong rule for initialization" << "\x1b[0m" << endl;
        err_parser = true;
        gl();
    }
    catch(const char *l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
        err_parser = true;
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
        gl();
    }
    //S();
}

void Parser::D()
{
    type_of_lex tmp = c_type;
    if (c_type == LEX_INT || c_type == LEX_BOOLEAN || c_type == LEX_STR)
    {
        gl();
        st_lex.push(tmp);
        if(c_type == LEX_ID)
        {
<<<<<<< HEAD
        	//cout << "OLD_TMP: " << tmp << endl;
        	TID[c_val].put_type(tmp);
        }
        Perem();
        check_declare(tmp);
        //cout << "SSSS"<< endl;
        //cout << "   " << curr_lex << endl;
=======
            
        	//cout << "OLD_TMP: " << tmp << endl;
            TID[c_val].put_declare();
        	TID[c_val].put_type(tmp);
        }
        //cout<< "Lex "<< curr_lex;
        Perem();
        //check_declare(tmp);
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
        while (c_type == LEX_COMMA)
        {
            //throw "we are gere";
            gl();
            st_lex.push(tmp);
            //cout << "CVAL:  " << c_val << endl;
<<<<<<< HEAD
            if(c_type == LEX_ID)
	        	TID[c_val].put_type(tmp);
            //throw "it is ok";
            //throw "here";
            Perem();
            check_declare(tmp);
=======
            try
            {
                if(c_type == LEX_ID)
                {
                    //cout << " c_val = "<< c_val << endl;
                    if (TID[c_val].get_declare() == true)
                        throw " Twise initializated ";
                    TID[c_val].put_declare();
                    TID[c_val].put_type(tmp);
                }
            }
            catch(const char *l)
            {   
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                while (c_type != LEX_COMMA)
                    gl();
            }
            //throw "it is ok";
            //throw "here";
            Perem();
            //check_declare(tmp);
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
        }
        //cout << "TTTTTTTTTTT" << endl;
        //throw "befode";
    }
    else
        throw curr_lex;
}

void Parser::Perem()
{
    
    int tmp_c_val = c_val;
    if (c_type == LEX_ID)
    {
        st_int.push(c_val);
        gl();
        if (c_type == LEX_ASSIGN)
        {
        	st_lex.push(TID[tmp_c_val].get_type());
        	//cout << TID[tmp_c_val].get_type() << endl;
        	st_lex.push(LEX_ID);
            prog.push_back(Lex(POLIZ_ADRESS, tmp_c_val));
            tmp_c_val = c_val;
            gl();
            Const();
            prog.push_back(Lex(LEX_ASSIGN, LEX_ASSIGN));
        }
    }
    else 
<<<<<<< HEAD
        throw curr_lex;
=======
        {
            if ( c_type == LEX_COMMA || c_type == LEX_SEMICOLON){}
            else
                throw curr_lex;
        }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    //throw "leaving";
}

void Parser::Const()
{
    if(c_type == LEX_STR)
    {
        st_lex.push(LEX_STR);
        eq_type();
        prog.push_back(curr_lex);
        gl();
    }
    else 
    if (c_type == LEX_TRUE)
    {
        st_lex.push(LEX_BOOLEAN);
        eq_type();
        prog.push_back(Lex(LEX_TRUE, LEX_TRUE));
        gl();
    }
    else 
    if (c_type == LEX_FALSE)
    {
        st_lex.push(LEX_BOOLEAN);
        eq_type();
        prog.push_back(Lex(LEX_FALSE, LEX_FALSE));
        gl();
    }
    else 
    if (c_type == LEX_NUM)
    {
        //cout << curr_lex;
        st_lex.push(LEX_INT);
        eq_type();
        prog.push_back(curr_lex);
        gl();
    }
    else 
        throw curr_lex;
}

void Parser::B() 
{
<<<<<<< HEAD
    while(c_type != LEX_RBRACE)
=======
    while(c_type != LEX_RBRACE && c_type != LEX_EOF)
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    {
        //cout << "TTTTTTTTTTT" << endl;
        S();
    }
<<<<<<< HEAD
=======
    //cout << "TTTTTTTTTTT" << endl;
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
}

void Parser::S()
{
<<<<<<< HEAD
    int pl0,pl1,pl2,pl3;
    if (c_type == LEX_RBRACE)
    {

    }
    else if(c_type == LEX_IF)
    {
        gl();
        Eor();
        eq_bool();
        pl2 = prog.get_free();
        prog.blank();
        prog.push_back((Lex(POLIZ_FGO, POLIZ_FGO)));
        if(c_type == LEX_LBRACE)
        {
            gl();
            S();
            if (c_type != LEX_SEMICOLON)
            {
                throw curr_lex;
            }
            prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
            gl();
            //cout << "qwerty" << curr_lex << endl;
            pl3 = prog.get_free();
            if (c_type != LEX_RBRACE)
            {
                throw curr_lex;
            }

            gl();
            if(c_type == LEX_ELSE)
            {
                gl();
                if(c_type == LEX_LBRACE)
                {
                    prog.blank();
                    prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
                    prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl2);
                    gl();
                    S();
                    prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl3);
                }
                if (c_type != LEX_SEMICOLON)
                {
                    throw curr_lex;
                }
                prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                gl();
                if (c_type != LEX_RBRACE)
                {
                    throw curr_lex;
                }
                gl();
            }
            else 
            {
                prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl2);
                S();
            }
        }
        else throw curr_lex;
    }
    else if(c_type == LEX_WHILE)
    {
        pl0 = prog.get_free();
        gl();
        Eor();
        eq_bool();
        pl1 = prog.get_free();
        prog.blank();
        prog.push_back(Lex(POLIZ_FGO, POLIZ_FGO));
        if (c_type == LEX_LBRACE)
        {
            gl();
            S();
            prog.push_back(Lex(POLIZ_LABEL, pl0));
            prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
            prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl1);
            if (c_type != LEX_SEMICOLON)
                throw curr_lex;
            prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
            gl();
            if (c_type != LEX_RBRACE)
                throw curr_lex;
            gl();
        }
        else 
            throw curr_lex;
    }
    else if (c_type == LEX_DO)
    {
        gl();
        pl0 = prog.get_free();
        if (c_type == LEX_LBRACE)
        {
            gl();
            S();
            /*prog.push_back(Lex(POLIZ_LABEL, pl0));
            prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
            prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl1);*/
            if (c_type != LEX_SEMICOLON)
                throw curr_lex;
            prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
            gl();
            if (c_type != LEX_RBRACE)
                throw curr_lex;
            gl();
        }
        else 
            throw curr_lex;
        if (c_type == LEX_WHILE)
        {
            gl();
            //cout << "QWERTY:    " << curr_lex << endl;
            if (c_type == LEX_LPAREN)
            {    
                Eor();
                eq_bool();
                pl1 = prog.get_free();
                prog.push_back(Lex(POLIZ_LABEL, pl1 + 4));
                prog.push_back(Lex(POLIZ_FGO, POLIZ_FGO));
                prog.push_back(Lex(POLIZ_LABEL, pl0));
                prog.push_back(Lex(POLIZ_GO, POLIZ_GO));   
                /*cout << "QWERTY:    " << curr_lex << endl;         
                if (c_type != LEX_RPAREN)
                    throw curr_lex;
                cout << "QWERTY:    " << curr_lex << endl;
                gl();*/
                //cout << "QWERTY:    " << curr_lex << endl;
                if (c_type != LEX_SEMICOLON)
                    throw curr_lex;
                prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                gl();
            }
            else 
                throw curr_lex;
        }
    }
    else if(c_type == LEX_READ)
    {
        gl();
        if(c_type == LEX_LPAREN)
        {
            gl();
            if(c_type == LEX_ID)
            {
                check_id_in_read();
                prog.push_back(Lex(POLIZ_ADRESS, c_val));
                gl();
            }
            else 
                throw curr_lex;
            if(c_type == LEX_RPAREN)
            {
                gl();
                prog.push_back(Lex(LEX_READ, LEX_READ));
            }
            else
                throw curr_lex;
        }
        else throw curr_lex;
    }
    else if(c_type == LEX_WRITE)
    {   
        //cout << "I AM IN WRITE" << endl;
        gl();
        //cout << "current lex" << curr_lex;
        if(c_type == LEX_LPAREN)
        {
            gl();
            //cout << "       " << curr_lex << endl;
            E();
            //cout << "       " << curr_lex << endl;
            if (c_type == LEX_RPAREN)
            {
                gl();
                prog.push_back(Lex(LEX_WRITE, LEX_WRITE));
            }
            else 
                throw curr_lex;
        }
        else 
            throw curr_lex;
    }
    else if(c_type == LEX_ID)
    {
        type_of_lex tmp = TID[c_val].get_type();
        //check_id();
        //cout << TID[c_val] << endl;
        st_lex.push(tmp);
        st_lex.push(LEX_ID);
        prog.push_back(Lex(POLIZ_ADRESS, c_val));

        gl();
        if (c_type == LEX_ASSIGN)
        {
            gl();
            Eor();
            eq_type();
            prog.push_back(Lex(LEX_ASSIGN, LEX_ASSIGN));
        }
        else 
        if(c_type == LEX_PLUSEQ)
        {
            //int tmp_c_val = c_val;
            if (tmp == LEX_BOOLEAN) throw "you can't do uno plus with bool";
            gl();
            Eor();
            eq_type();
            prog.push_back(Lex(LEX_PLUSEQ, LEX_PLUSEQ));
        }
        else
        if(c_type == LEX_MINUSEQ)
        {
            //int tmp_c_val = c_val;
            if(tmp == LEX_BOOLEAN) throw "you can't do uno minus with bool";
            if(tmp != LEX_STR)
            {
                gl();
                Eor();
                eq_type();
                prog.push_back(Lex(LEX_MINUSEQ, LEX_MINUSEQ));
            }
            else
                throw "you can't do uno minus with string";
        }
        else
            throw curr_lex;
    }
    else if (c_type == LEX_SEMICOLON)
    {
        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
        gl();
    }
    else if (c_type == LEX_GOTO)
    {
        int i;
        char * g = scan.g_label();
        for (i = 0; i < TL.top; i++)
        {
            if (!strcmp(TL[i].get_name(), g))
            {
                break;
            }
        }
        if (i == TL.top)
        {
            TL.put(g);
        }
        prog.push_back(Lex(LEX_GOTO, i));
        prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
        gl();
        if (c_type != LEX_SEMICOLON)
        {
            throw "Expected semicolon";
        }
        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
        gl();
    }
    else if (c_type == LEX_COLON)
    {
        char * g = c_str;
        int pol = prog.get_free(), i;
        for (i = 0; i < TL.top; i++)
        {
            if (!strcmp(TL[i].get_name(), g))
            {
                if(TL[i].get_declare())
                {
                    throw "Twice";
                }
                else
                    break;
            }
        }
        if (i == TL.top)
        {
            TL.put(c_str);
        }
        TL[i].put_position(pol);
        gl();
    }
    else 
        throw curr_lex;
}

void Parser::Eor()
{
    Eand();
    while(c_type == LEX_OR)
    {
        st_lex.push(c_type);
        gl(); 
        Eor(); 
        check_op();
    }
}

=======
    try
    {
        int pl0,pl1,pl2,pl3;
        if (c_type == LEX_RBRACE)
        {

        }
        else if(c_type == LEX_IF)
        {
            try
            {
                gl();
                Eor();
                eq_bool();
                pl2 = prog.get_free();
                prog.blank();
                prog.push_back((Lex(POLIZ_FGO, POLIZ_FGO)));
                if(c_type == LEX_LBRACE)
                {
                    gl();
                    S();
                    while (c_type == LEX_SEMICOLON)
                    {
                        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                        gl();
                        S();
                    }
                    //cout << "qwerty" << curr_lex << endl;
                    pl3 = prog.get_free();
                    if (c_type != LEX_RBRACE)
                    {
                        throw curr_lex;
                    }

                    gl();
                    if(c_type == LEX_ELSE)
                    {
                        gl();
                        if(c_type == LEX_LBRACE)
                        {
                            prog.blank();
                            prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
                            prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl2);
                            gl();
                            S();
                            while (c_type == LEX_SEMICOLON)
                            {
                                prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                                gl();
                                S();
                            }
                            prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl3);
                        }
                        if (c_type != LEX_RBRACE)
                        {
                            throw curr_lex;
                        }
                        gl();
                    }
                    else 
                    {
                        prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl2);
                        //gl();
                        S();
                    }
                }
                else throw curr_lex;
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for IF " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for IF " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if(c_type == LEX_WHILE)
        {
            try
            {
                pl0 = prog.get_free();
                gl();
                Eor();
                eq_bool();
                pl1 = prog.get_free();
                prog.blank();
                prog.push_back(Lex(POLIZ_FGO, POLIZ_FGO));
                if (c_type == LEX_LBRACE)
                {
                    gl();
                    S();
                    while (c_type == LEX_SEMICOLON)
                    {
                        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                        gl();
                        S();
                    }
                    prog.push_back(Lex(POLIZ_LABEL, pl0));
                    prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
                    prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl1);
                    if (c_type != LEX_RBRACE)
                        throw curr_lex;
                    gl();
                    S();
                }
                else 
                    throw curr_lex;
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for WHILE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for WHILE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if (c_type == LEX_DO)
        {
            try
            {
                gl();
                pl0 = prog.get_free();
                if (c_type == LEX_LBRACE)
                {
                    gl();
                    S();
                    //cout << "L: " << curr_lex << endl;
                    /*prog.push_back(Lex(POLIZ_LABEL, pl0));
                    prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
                    prog.push_back(Lex(POLIZ_LABEL, prog.get_free()), pl1);*/
                    while (c_type == LEX_SEMICOLON)
                    {
                        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                        gl();
                        S();
                    }
                    
                    if (c_type == LEX_RBRACE)
                    {
                        //cout << "L: " << endl;
                        gl();
                    }
                    else
                    {
                        throw curr_lex;

                    }
                }
                else 
                    throw curr_lex;
                //cout << "currr" << curr_lex << endl;
                if (c_type == LEX_WHILE)
                {
                    gl();
                    //cout << "QWERTY:    " << curr_lex << endl;
                    if (c_type == LEX_LPAREN)
                    {    
                        Eor();
                        eq_bool();
                        pl1 = prog.get_free();
                        prog.push_back(Lex(POLIZ_LABEL, pl1 + 4));
                        prog.push_back(Lex(POLIZ_FGO, POLIZ_FGO));
                        prog.push_back(Lex(POLIZ_LABEL, pl0));
                        prog.push_back(Lex(POLIZ_GO, POLIZ_GO));   
                        /*cout << "QWERTY:    " << curr_lex << endl;         
                        if (c_type != LEX_RPAREN)
                            throw curr_lex;
                        cout << "QWERTY:    " << curr_lex << endl;
                        gl();*/
                        //cout << "QWERTY:    " << curr_lex << endl;
                        if (c_type != LEX_SEMICOLON)
                            throw curr_lex;
                        prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                        gl();
                        S();
                    }
                    else
                    {
                        //cout << "RRRRRRRR" << curr_lex << endl; 
                        throw curr_lex;
                    }
                }
                else
                {
                    throw curr_lex;
                } 
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for DO_WHILE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for DO_WHILE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if(c_type == LEX_READ) // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        {
            try
            {
                gl();
                if(c_type == LEX_LPAREN)
                {
                    gl();
                    if(c_type == LEX_ID)
                    {
                        check_id_in_read();
                        prog.push_back(Lex(POLIZ_ADRESS, c_val));
                        gl();
                    }
                    else 
                        throw curr_lex;
                    if(c_type == LEX_RPAREN)
                    {
                        gl();
                        prog.push_back(Lex(LEX_READ, LEX_READ));
                    }
                    else
                        throw curr_lex;
                }
                else 
                    throw curr_lex;
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for READ " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for READ " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if(c_type == LEX_WRITE)
        {   
            try
            {
                //cout << "I AM IN WRITE" << endl;
                gl();
                //cout << "current lex" << curr_lex;
                if(c_type == LEX_LPAREN)
                {
                    gl();
                    //cout << "       " << curr_lex << endl;
                    Eor();
                    while(c_type == LEX_COMMA)
                    {
                        gl();
                        Eor();
                    }
                    //cout << "       " << curr_lex << endl;
                    if (c_type == LEX_RPAREN)
                    {
                        prog.push_back(Lex(LEX_WRITE, LEX_WRITE));
                        gl();
                        //S();
                    }
                    else 
                        throw curr_lex;
                }
                else 
                    throw curr_lex;
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for WRITE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for WRITE " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if(c_type == LEX_ID)
        {
            try
            {
                //check_id();
                if(TID[c_val].get_declare() == false)
                {
                    throw " Not declared ";
                }
                type_of_lex tmp = TID[c_val].get_type();
                //check_id();
                //cout << TID[c_val] << endl;
                st_lex.push(tmp);
                st_lex.push(LEX_ID);
                prog.push_back(Lex(POLIZ_ADRESS, c_val));

                gl();
                if (c_type == LEX_ASSIGN)
                {
                    gl();
                    Eor();
                    eq_type();
                    prog.push_back(Lex(LEX_ASSIGN, LEX_ASSIGN));
                }
                else 
                if(c_type == LEX_PLUSEQ)
                {
                    //int tmp_c_val = c_val;
                    if (tmp == LEX_BOOLEAN) throw "you can't do uno plus with bool";
                    if(tmp != LEX_STR)
                    {
                        gl();
                        Eor();
                        eq_type();
                        prog.push_back(Lex(LEX_PLUSEQ, LEX_PLUSEQ));
                    }
                    else
                        throw "you can't do uno plus with string";
                }
                else
                if(c_type == LEX_MINUSEQ)
                {
                    //int tmp_c_val = c_val;
                    if(tmp == LEX_BOOLEAN) throw "you can't do uno minus with bool";
                    if(tmp != LEX_STR)
                    {
                        gl();
                        Eor();
                        eq_type();
                        prog.push_back(Lex(LEX_MINUSEQ, LEX_MINUSEQ));
                    }
                    else
                        throw "you can't do uno minus with string";
                }
                else
                    throw curr_lex;
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for ASSIGN " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for ASSIGN " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if (c_type == LEX_SEMICOLON)
        {
            prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
            gl();
        }
        else if (c_type == LEX_GOTO) // check declare TL
        {
            try
            {
                int i;
                char *g = scan.g_label();
                //cout << "YYYYYYYYYYYYYYY" << endl;
                for (i = 0; i < TL.top; i++)
                {
                    if (!strcmp(TL[i].get_name(), g))
                    {
                        break;
                    }
                }
                if (i == TL.top)
                {
                    TL.put(g);
                }
                prog.push_back(Lex(LEX_GOTO, i));
                prog.push_back(Lex(POLIZ_GO, POLIZ_GO));
                gl();
                if (c_type != LEX_SEMICOLON)
                {
                    throw "Expected semicolon";
                }
                prog.push_back(Lex(LEX_SEMICOLON, LEX_SEMICOLON));
                gl();
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for GOTO " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for GOTO " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else if (c_type == LEX_COLON)
        {
            try
            {
                char * g = c_str;
                int pol = prog.get_free(), i;
                for (i = 0; i < TL.top; i++)
                {
                    if (!strcmp(TL[i].get_name(), g))
                    {
                        if(TL[i].get_declare())
                        {
                            throw "Twice";
                        }
                        else
                            break;
                    }
                }
                if (i == TL.top)
                {
                    TL.put(c_str);
                }
                TL[i].put_position(pol);
                TL[i].put_declare();
                gl();
            }
            catch(Lex l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for COLON " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(const char *l)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << l << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
            catch(char c)
            {
                cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for COLON " << "\x1b[0m" << endl;
                err_parser = true;
                gl();
            }
        }
        else 
            throw curr_lex;
    }
    catch(Lex l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected lexem " << l << " Wrong rule for EXPRESSION " << "\x1b[0m" << endl;
        err_parser = true;
        gl();
        while((c_type != LEX_SEMICOLON) && (c_type != LEX_RBRACE) && (c_type != LEX_EOF))
        {
            gl();
            //cout << "GGGGG" << endl;
        }
    }
    catch(const char *l)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << l << "\x1b[0m" << endl;
        err_parser = true;
        gl();
        while((c_type != LEX_SEMICOLON) && (c_type != LEX_RBRACE) && (c_type != LEX_EOF))
        {
            gl();
            //cout << "GGGGG" << endl;
        }
    }
    catch(char c)
    {
        cout << "\x1b[37;41m" << "Line: " << scan.count_str << " Column: " << scan.count_col << " Unexpected symbol " << c << " Wrong rule for EXPRESSION " << "\x1b[0m" << endl;
        err_parser = true;
        gl();
        while((c_type != LEX_SEMICOLON) && (c_type != LEX_RBRACE) && (c_type != LEX_EOF))
        {
            gl();
            //cout << "GGGGG" << endl;
        }
    }
}

void Parser::Eor()
{
    Eand();
    while(c_type == LEX_OR)
    {
        st_lex.push(c_type);
        gl(); 
        Eor(); 
        check_op();
    }
}

>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
void Parser::Eand()
{
    E();
    while(c_type == LEX_AND)
    {
        st_lex.push(c_type);
        gl(); 
        E(); 
        check_op();
    }
}

void Parser::E()
{
<<<<<<< HEAD
    E1();
    if(c_type == LEX_EQ || c_type == LEX_LSS || c_type == LEX_GTR || 
        c_type == LEX_LEQ || c_type == LEX_GEQ || c_type == LEX_NEQ) 
=======
    //cout << "E " << endl;
    E1();
    if(c_type == LEX_EQ || c_type == LEX_LSS || c_type == LEX_GTR || 
        c_type == LEX_LEQ || c_type == LEX_GEQ || c_type == LEX_NEQ || c_type == LEX_ASSIGN || c_type == LEX_PLUSEQ || c_type == LEX_MINUSEQ) 
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    {
        st_lex.push(c_type);
        gl(); 
        E1(); 
        check_op();
    }
}

void Parser::E1()
{
    T();
    //cout << "FFFFFFFFFFF" << endl;
    while (c_type == LEX_PLUS || c_type == LEX_MINUS || c_type == LEX_OR)
    {
        st_lex.push(c_type);
        gl();
        T();
        check_op();
    }
}

void Parser::T()
{
    F();
    while (c_type == LEX_MULT || c_type == LEX_DIV || c_type == LEX_AND || c_type == LEX_MOD)
    {
        //cout << "TTTTTTTTTTT" << endl;
        st_lex.push(c_type);
        gl();
        F();
        check_op(); //правильный ли результат выражения
    }
    //cout << "FFFFFFFFFFF" << endl;
}


void Parser::F()
{
    if (c_type == LEX_ID)
    {
        //check_id();
        //cout << "C_VAL_A: " << c_val << endl;
    	type_of_lex tmp = TID[c_val].get_type();
    	//cout << "TMP: " << tmp << endl;
    	st_lex.push(tmp);
        prog.push_back(Lex(curr_lex));
        gl();
        //cout << curr_lex << endl;
    }
    else if (c_type == LEX_STR)
    {
        st_lex.push(LEX_STR);
        prog.push_back(curr_lex);
        //cout <<"            " << curr_lex;
        gl();
    }
    else if (c_type == LEX_NUM)
    {
        st_lex.push(LEX_INT);
        prog.push_back(curr_lex);
        gl();
    }
    else if (c_type == LEX_TRUE)
    {
        st_lex.push(LEX_BOOLEAN);
        prog.push_back(Lex(LEX_TRUE, LEX_TRUE));
        gl();
    }
    else if (c_type == LEX_FALSE)
    {
        st_lex.push(LEX_BOOLEAN);
        prog.push_back(Lex(LEX_FALSE, LEX_FALSE));
        gl(); 
    }
    else if (c_type == LEX_NOT)
    {
        gl();
        F();
        check_not();
    }
    else if (c_type == LEX_LPAREN)
    {
        gl();
        E();
        if (c_type == LEX_RPAREN)
            gl();
        else 
<<<<<<< HEAD
            throw curr_lex;
=======
        {
            //cout << "RRTRTRTR" << endl;
            throw curr_lex;
        }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    }
    else
        throw curr_lex;
}
////////////////////////////////////////// функции для проверки

void Parser::check_declare(type_of_lex type) // проверка, что переменная объявлена
{
    int i;
    while (!st_int.empty()) 
    {
        from_st(st_int, i);
        if (TID[i].get_declare())
<<<<<<< HEAD
            throw "twice";
=======
            throw curr_lex;
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
        else
        {
            TID[i].put_declare();
            TID[i].put_type(type);
        }
    }
}

/*void Parser::check_declare_label(char * ) // проверка, что метка объявлена
<<<<<<< HEAD
{
    for (int i = 0; i < top; i++)
    {
        if (TL[i].)
        if (TL[i].get_declare())
            throw "twice";
        else
        {
            TL[i].put_declare();
            TL[i].put_type(type);
        }
    }
}*/
=======
{
    for (int i = 0; i < top; i++)
    {
        if (TL[i].)
        if (TL[i].get_declare())
            throw "twice";
        else
        {
            TL[i].put_declare();
            TL[i].put_type(type);
        }
    }
}*/

void Parser::check_id() // проверка объявлены переменные или нет. Есть ли в таблицах
{
	
    cout << "c_val: " << c_val << endl;
    if (TID[c_val].get_declare() == true)
        st_lex.push(TID[c_val].get_type());
    else  
        throw "Not declared";
}
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2

/*void Parser::check_id() // проверка объявлены переменные или нет. Есть ли в таблицах
{
<<<<<<< HEAD
	
    if (TID[c_val].get_declare() == true)
        st_lex.push(TID[c_val].get_type());
    else  
        throw "Not declared";
}*/

void Parser::check_op() // выражение операция выражение
{
=======
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    type_of_lex t1, t2, op, result = LEX_BOOLEAN; 
    from_st(st_lex, t2);
    from_st(st_lex, op);
    from_st(st_lex, t1);
    //cout << t1 << ' ' << op << ' ' << t2 << endl;
    if (t1 == t2)
    {
        if (t1 == LEX_INT)
        {
<<<<<<< HEAD
            if (op == LEX_PLUS || op == LEX_MINUS || op == LEX_MULT || op == LEX_DIV || op == LEX_MOD)
                result = LEX_INT;
            else if (op == LEX_AND || op == LEX_OR) 
                throw "Wrong types in op";
=======
            if (op == LEX_PLUS || op == LEX_MINUS || op == LEX_MULT || op == LEX_DIV || op == LEX_MOD /*|| op == LEX_ASSIGN || c_type == LEX_PLUSEQ || c_type == LEX_MINUSEQ*/)
                result = LEX_INT;
            else if (op == LEX_AND || op == LEX_OR) 
            {
                throw " Wrong types in op ";
            }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
            else
                result = LEX_BOOLEAN;
        }
        if (t1 == LEX_BOOLEAN)
        {
<<<<<<< HEAD
            if (op == LEX_AND || op == LEX_OR || op == LEX_EQ || op == LEX_NEQ)
                result = LEX_BOOLEAN;
            else 
                throw "Wrong types in op";
        }
        if (t1 == LEX_STR)
        {
            if (op == LEX_PLUS)
=======
            if (op == LEX_AND || op == LEX_OR || op == LEX_EQ || op == LEX_NEQ /*|| op == LEX_ASSIGN*/)
                result = LEX_BOOLEAN;
            else 
                throw " Wrong types in op ";
        }
        if (t1 == LEX_STR)
        {
            if (op == LEX_PLUS /*|| op == LEX_ASSIGN*/)
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
                result = LEX_STR;
            else if (op == LEX_EQ || op == LEX_NEQ || op == LEX_GTR || op == LEX_LSS || op == LEX_GEQ || op == LEX_LEQ)
                result = LEX_BOOLEAN;
            else 
<<<<<<< HEAD
                throw "Wrong types in op";
=======
                throw " Wrong types in op ";
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
        }
        st_lex.push(result);
        if (op >= words_size)
        {
            prog.push_back(Lex(op, op % words_size + 1));
        }
        else 
            prog.push_back(Lex(op, op));
    }
    else
<<<<<<< HEAD
        throw "Wrong types in op";
=======
    {
        //cout << "SONYA" << endl;
        throw " Wrong types in op ";
    }
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
    //cout << result << endl;
}

void Parser::check_not() // проверка, что первое выражение not 
{
    if (st_lex.top() != LEX_BOOLEAN)
        throw "Wrong type is in not";
    else 
        prog.push_back(Lex(LEX_NOT, LEX_NOT));
}

void Parser::eq_type() // проверка присваивания и равенства (выражение = выражение)
{
    type_of_lex t = st_lex.top();
   	st_lex.pop();
    //cout << "LLLLLLLLLLLLLLL" << t << endl;
    if(st_lex.top() != LEX_ID)
    	throw "Wrong types are in :=";
    st_lex.pop();
    //cout << "GFGFGFGFGF" << st_lex.top();
    if (t != st_lex.top())
        throw "Wrong types are in :=";
    st_lex.pop();
}

void Parser::eq_bool() // проверка что вверху стека находится условный оператор или оператор цикла
{
    if (st_lex.top() != LEX_BOOLEAN)
        throw "Expression is not boolean";
    st_lex.pop();
}

void Parser::check_id_in_read() // проверка что переменная объявлена => ее можно считывать
{
    if (!TID[c_val].get_declare())
        throw "Not declared";
}
