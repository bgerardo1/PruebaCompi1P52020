#include "expr_parser.h"

int Parser::parse(){
    currToken= lexer.getNextToken();
    input();
    if (currToken ==  Symbol::Eof)
    {
         return 0;

    }
}
void Parser::input(){
    stm_list();
}

void Parser::eol(){
 while (currToken ==  Symbol::Eol)
    {
        currToken = lexer.getNextToken();
    }

   
}

void Parser::stm_list(){

    stm();
    stm_list_p();  
}

void Parser::stm_list_p(){
 if (currToken ==  Symbol::Eol)
    {
        currToken = lexer.getNextToken();
        eol();
        stm();
    }
    stm();
   
}

void Parser::stm(){
    if (currToken ==  Symbol::Eol)
    {
        currToken = lexer.getNextToken();
        eol();

    }
assign();
stm_p();
}

void Parser::stm_p(){
    
fun_decl();
if (currToken == Symbol ::Print)
{
    currToken = lexer.getNextToken();
    if (currToken == Symbol ::OpenPar)
    {
        currToken = lexer.getNextToken();
        expr();

        if (currToken == Symbol ::ClosePar)
        {
            currToken = lexer.getNextToken();
        }
        else
        {
            throw "error";
        }
        
        
    }
    
}

}


void Parser::assign(){
    
    if (currToken ==  Symbol::Ident)
    {
        currToken = lexer.getNextToken();

        if (currToken ==  Symbol::OpAssign)
        {  
            currToken = lexer.getNextToken();
            expr();
        }
        else{ 
            throw "error";

        }


    }

}

void Parser::fun_decl(){
  
  
    if (currToken ==  Symbol::Ident)
    {
        currToken = lexer.getNextToken();
        if (currToken == Symbol::OpenPar){
            currToken = lexer.getNextToken();
            arg();
            if (currToken == Symbol::ClosePar){
            currToken = lexer.getNextToken();
            }
        }
    }
    
}


void Parser::arg(){
  
  
    if (currToken ==  Symbol::Number)
    {
        currToken = lexer.getNextToken();
    }
     else if (currToken ==  Symbol::Ident)
    {
        currToken = lexer.getNextToken();
    }
    
}

void Parser::expr(){
   
    term();
    expr_p();
}

void Parser::expr_p(){
 
    if (currToken ==  Symbol::OpAdd)
    {
        currToken = lexer.getNextToken();
        term();
        expr_p();
    }
    else if (currToken ==  Symbol::OpSub)
    {
        currToken = lexer.getNextToken();
        term();
        expr_p();
    }
   
    
    
}

void Parser:: term(){
   
    factor();
    term_p();
}

void Parser::term_p(){
  
    if (currToken ==  Symbol::OpMul)
    {
        currToken = lexer.getNextToken();
        factor();
        term();
    }
    else if (currToken ==  Symbol::OpDiv)
    {
        currToken = lexer.getNextToken();
        factor();
        term();
    }
    
   
}

void Parser::factor(){
  
if (currToken ==  Symbol::Ident){
    currToken = lexer.getNextToken();
}

if (currToken ==  Symbol::Number)
{
    currToken = lexer.getNextToken();
}
else if (currToken == Symbol::OpenPar)
{
    currToken = lexer.getNextToken();
    expr();
    if (currToken == Symbol::ClosePar)
    {
        currToken = lexer.getNextToken();
    }

    
       
}

}

