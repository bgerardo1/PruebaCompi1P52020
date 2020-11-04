#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include <iosfwd>
#include "lexer.h"

class Parser {
public:
	Parser(Lexer &lexer): lexer (lexer) { }
	void parse();

private:
	Lexer &lexer;
	Token currToken;

public:
void input();
void opt_eol();
void stm_list();
void stm();
void assign();
void fun_decl();
void opt_arg_list();
void arg_list();
void arg();
void expr();
void term();
void factor();
};


#endif
