#ifndef __TOKENS_H__
#define __TOKENS_H__

enum class Token {
    Number,
    OpDiv,
    OpSub,
    Eof,
    OpAdd,
    OpenPar,
    Ident,
    OpMul,
    ClosePar,
};
#endif