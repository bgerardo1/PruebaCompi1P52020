#include "parser.h"
#include <iostream> 
#include <fstream>

void Parser::parse(){
currToken = lexer.getNextToken();
if (currToken== Token::Eof)
{
 throw ::std::string(".........Fin........");
}
}

void Parser::input(){
    //stm_list();
    opt_eol();
}

void Parser::opt_eol(){
    if (currToken == Token::Eol)
    {
        currToken = lexer.getNextToken();
    }
    else
    {
        /* code */
    }
}


    

