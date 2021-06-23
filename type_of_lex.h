#pragma once
#ifndef TYPE_OF_LEX_H
#define TYPE_OF_LEX_H

<<<<<<< HEAD
const char * translator[] = {"", "and", "boolean", "do", "else", "if", "false", "int", "not", "or", "program", "read", "true", "while", "write", "string", "goto", ";", ",", "=", "(", ")", "{", "}", "==", "<", ">", "+", "-", "*", "/", "%", "\\*", "*\\", "<=", "!=", ">=", "+=", "-=", "\"", ":", "NUM", "ID", "LABEL", "&ID", "GO", "FGO"};  

=======
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
enum type_of_lex
{
	LEX_NULL, // 0
	LEX_AND, // 1
	LEX_BOOLEAN, // 2
	LEX_DO, // 3
	LEX_ELSE, // 4
	LEX_IF, // 5
	LEX_FALSE, // 6
	LEX_INT, // 7
	LEX_NOT, // 8 
	LEX_OR, // 9
	LEX_PROGRAM, // 10
	LEX_READ, // 11
	LEX_TRUE, // 12
	LEX_WHILE, // 13
	LEX_WRITE, // 14
	LEX_STR, // 15
	LEX_GOTO, // 16
	LEX_SEMICOLON, // 17
	LEX_COMMA, // 18
	LEX_ASSIGN, // 19
	LEX_LPAREN, // 20
	LEX_RPAREN, // 21
	LEX_LBRACE, // 22
	LEX_RBRACE, // 23
	LEX_EQ, // 24
	LEX_LSS, // 25
	LEX_GTR, // 26
	LEX_PLUS, // 27
	LEX_MINUS, // 28
	LEX_MULT, // 29
	LEX_DIV, // 30
	LEX_MOD, // 31
	LEX_FRONTSLASH, // 32
	LEX_BACKSLASH, // 33
	LEX_LEQ, // 34
	LEX_NEQ, // 35
	LEX_GEQ, // 36
	LEX_PLUSEQ, // 37
	LEX_MINUSEQ, // 38
	LEX_QUOTE, //39
	LEX_COLON, // 40
	LEX_NUM, // 41
	LEX_ID, //42
	POLIZ_LABEL, // 43 | нужен для ссылок на номера элементов ПОЛИЗа
	POLIZ_ADRESS, // 44 | для обозначения операндов адресов
	POLIZ_GO, // 45 | для реализации goto, ссылка на конкретную лексему в ПОЛИЗе
<<<<<<< HEAD
	POLIZ_FGO // 46 | условный переход по false
=======
	POLIZ_FGO, // 46 | условный переход по false
	LEX_EOF
>>>>>>> eeebab909fe7122eee4f058ac63cabf0306ab0a2
};
#endif