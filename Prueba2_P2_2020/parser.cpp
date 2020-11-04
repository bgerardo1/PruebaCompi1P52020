#include "parser.h"

void Parser::parse() {
    currToken= lexer.getNextToken();
    input();
    if (currToken ==  Token::Eof)
    {
        std::cout << "-----------FIN------------"<< std:: endl;

    }
  
} 

void Parser::input(){
    stm_list();
}

void Parser::stm_list(){

    stm();
    stm_list_p();
}

void Parser::stm_list_p(){
  
    if (currToken ==  Token::Semicolon)
    {
        currToken = lexer.getNextToken();
        stm_list();
        if (currToken ==  Token::Semicolon)
        {
             currToken = lexer.getNextToken();
             stm_list_p();
        }
        
    }
    else
    {
        /* epsilon*/
    }
    
}

void Parser::stm(){
assign();
stm_p();
}

void Parser:: stm_p(){
    fun_decl();
if (currToken ==  Token::KwPrint)
{
    currToken = lexer.getNextToken();
    expr();
    stm_p();
}



}
void Parser::assign(){
    if (currToken ==  Token::Ident)
    {
        currToken = lexer.getNextToken();

        if (currToken ==  Token::OpAssign)
        {  
            currToken = lexer.getNextToken();
            expr();
        }

        if (currToken == Token::OpenPar){
            currToken = lexer.getNextToken();
            arg();
            if (currToken == Token::ClosePar){
            currToken = lexer.getNextToken();
                if (currToken ==  Token::OpAssign){
                    currToken = lexer.getNextToken();
                    expr();
                }
            
            }
        }


    }

}

void Parser::fun_decl(){
  
    if (currToken ==  Token::Ident)
    {
        currToken = lexer.getNextToken();
        if (currToken == Token::OpenPar){
            currToken = lexer.getNextToken();
            arg();
            if (currToken == Token::ClosePar){
            currToken = lexer.getNextToken();
                if (currToken ==  Token::OpAssign){
                    currToken = lexer.getNextToken();
                    expr();
                }
            
            }
        }
    }
    
}

void Parser::arg(){
  
    if (currToken ==  Token::Number)
    {
        currToken = lexer.getNextToken();
    }
     else if (currToken ==  Token::Ident)
    {
        currToken = lexer.getNextToken();
    }
    
}

void Parser::expr(){
   
    term();
    expr_p();
}

void Parser::expr_p(){
 
    if (currToken ==  Token::OpAdd)
    {
        currToken = lexer.getNextToken();
        term();
        expr_p();
    }
    else if (currToken ==  Token::OpSub)
    {
        currToken = lexer.getNextToken();
        term();
        expr_p();
    }
    else
    {
        //epsilon
    }
    
    
    
}

void Parser:: term(){
   
    factor();
    term_p();
}

void Parser::term_p(){
  
    if (currToken ==  Token::OpMul)
    {
        currToken = lexer.getNextToken();
        factor();
        term_p();
    }
    else
    {
        //epsilon
    }
    
   
}

void Parser::factor(){
  
if (currToken ==  Token::Ident){
    currToken = lexer.getNextToken();
}

if (currToken ==  Token::Number)
{
    currToken = lexer.getNextToken();
}
else if (currToken == Token::OpenPar)
{
    currToken = lexer.getNextToken();
    expr();
    if (currToken == Token::ClosePar)
    {
        currToken = lexer.getNextToken();
    }
       
}

}




    