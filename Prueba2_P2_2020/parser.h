#ifndef _EXPR_PARSER_H
#define _EXPR_PARSER_H

#include <iosfwd>
#include "lexer.h"

class Parser
{
private:
    Lexer& lexer;
    Token currToken;

public:
 Parser(Lexer& lex) : lexer(lex){}  
    void parse();
    void input();
    void stm_list();
    void stm_list_p(); // Gramatica cambiada
    void stm_p();//Gramatica cambiada
    void stm();
    void assign();
    void fun_decl();
    void arg();
    void expr();
    void expr_p(); // Gramatica Cambiada
    void term();
    void term_p(); // Gramatica cambiada
    void factor();

};

#endif
