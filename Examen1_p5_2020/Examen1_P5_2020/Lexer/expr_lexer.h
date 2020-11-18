#ifndef _EXPR_LEXER_H
#define _EXPR_LEXER_H
#include <iostream>
#include <string>
#include <istream>
#include "expr_tokens.h"
class ExprLexer
{
public:
    ExprLexer(std::istream& input): input(input)
    {}

    std::string getText()
    { return text; }

    int getNextChar()
    { return input.get(); }

    void ungetChar(int ch)
    { input.unget(); }

    void reportError(int ch) 
    {
        std::cerr << "Error: Invalid character: '" << ch << "'\n";
    }
    
    ExprToken getNextToken();
    static const char *tokenToString(Token tk);

private:
    std::string text;
    std::istream& input;
};
#endif
