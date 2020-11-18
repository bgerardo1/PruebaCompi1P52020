#ifndef _PARSER_H
#define _PARSER_H

#include <iosfwd>
#include "expr_lexer.h"

class Parser
{
public:
    Parser(Lexer& lexer, std::ostream& out): lexer(lexer), out(out)
    {}

    int parse();
    void input();
    void eol();
    void stm_list();
    void stm_list_p();
    void stm_p();
    void stm();
    void assign();
    void fun_decl();
    void arg();
    void expr();
    void expr_p(); 
    void term();
    void term_p(); 
    void factor();

private:
    Lexer& lexer;
    std::ostream& out;
    Symbol currToken;
};

#endif
