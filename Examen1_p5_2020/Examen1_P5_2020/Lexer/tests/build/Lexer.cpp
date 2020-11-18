#include "Lexer.h"

enum class State {
    start_q0,
    arith_q0,
    arith_q6,
    arith_q7,
    bcomment_q0,
    bcomment_q1,
    bcomment_q2,
    identifier_q0,
    identifier_q2,
    identifier_q3,
    lcomment_q0,
    number_q0,
    number_q1,
    number_q2,
    number_q4,
};

Token Lexer::getNextToken()
{
    text = "";
    State state = State::start_q0;
    int ch = getNextChar();

    while (true) {
        switch (state) {
            // start
            case State::start_q0:
                text="";
                if ((ch == '\n') || (ch == ' ')) {
                    state = State::start_q0;
                    ch = getNextChar();
                }
                else if (ch == EOF) {
                    text += ch;
                    return Token::Eof;
                }
                else {
                    state = State::identifier_q0;
                }
                break;
            // arith
            case State::arith_q0:
                if (ch == '/') {
                    text += ch;
                    state = State::arith_q6;
                    ch = getNextChar();
                }
                else if (ch == '-') {
                    text += ch;
                    return Token::OpSub;
                }
                else if (ch == '+') {
                    text += ch;
                    return Token::OpAdd;
                }
                else if (ch == '(') {
                    text += ch;
                    return Token::OpenPar;
                }
                else if (ch == '*') {
                    text += ch;
                    return Token::OpMul;
                }
                else if (ch == ')') {
                    text += ch;
                    return Token::ClosePar;
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::arith_q6:
                if (ch == '!') {
                    text += ch;
                    state = State::arith_q7;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::OpDiv;
                }
                break;
            case State::arith_q7:
                if (ch == '!') {
                    text += ch;
                    state = State::bcomment_q0;
                    ch = getNextChar();
                }
                else {
                    state = State::lcomment_q0;
                }
                break;
            // bcomment
            case State::bcomment_q0:
                if (ch == '!') {
                    state = State::bcomment_q2;
                    ch = getNextChar();
                }
                else if (ch == EOF) {
                    state = State::bcomment_q1;
                    ch = getNextChar();
                }
                else {
                    state = State::bcomment_q0;
                    ch = getNextChar();
                }
                break;
            case State::bcomment_q1:
                state = State::start_q0;
                break;
            case State::bcomment_q2:
                if (ch == '!') {
                    state = State::bcomment_q0;
                    ch = getNextChar();
                }
                else {
                    state = State::start_q0;
                }
                break;
            // identifier
            case State::identifier_q0:
                if (ch == '$') {
                    text += ch;
                    state = State::identifier_q2;
                    ch = getNextChar();
                }
                else {
                    state = State::number_q0;
                }
                break;
            case State::identifier_q2:
                if (((ch >= 'a') && (ch <= 'z')) || (ch == '_')) {
                    text += ch;
                    state = State::identifier_q3;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::identifier_q3:
                if (((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')) || (ch == '_')) {
                    text += ch;
                    state = State::identifier_q3;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::Ident;
                }
                break;
            // lcomment
            case State::lcomment_q0:
                if (ch == '\n') {
                    text += ch;
                    state = State::start_q0;
                    ch = getNextChar();
                }
                else {
                    state = State::lcomment_q0;
                    ch = getNextChar();
                }
                break;
            // number
            case State::number_q0:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::number_q1;
                    ch = getNextChar();
                }
                else {
                    state = State::arith_q0;
                }
                break;
            case State::number_q1:
                if (ch == '.') {
                    text += ch;
                    state = State::number_q2;
                    ch = getNextChar();
                }
                else if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::number_q1;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::Number;
                }
                break;
            case State::number_q2:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::number_q4;
                    ch = getNextChar();
                }
                else {
                    reportError(ch);
                    ch = getNextChar();
                    state = State::start_q0;
                }
                break;
            case State::number_q4:
                if ((ch >= '0') && (ch <= '9')) {
                    text += ch;
                    state = State::number_q4;
                    ch = getNextChar();
                }
                else {
                    ungetChar(ch);
                    return Token::Number;
                }
                break;
        }
    }

}

const char *Lexer::tokenToString(Token tk)
{
    switch (tk) {
        case Token::Number: return "Number";
        case Token::OpDiv: return "OpDiv";
        case Token::OpSub: return "OpSub";
        case Token::Eof: return "Eof";
        case Token::OpAdd: return "OpAdd";
        case Token::OpenPar: return "OpenPar";
        case Token::Ident: return "Ident";
        case Token::OpMul: return "OpMul";
        case Token::ClosePar: return "ClosePar";
        default: return "Unknown";
    }
    
}
