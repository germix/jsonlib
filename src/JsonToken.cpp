////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonToken.cpp
//
// Token JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonToken.h"

JsonToken::JsonToken() : tok(JSON_TOK_EOF)
{
}
JsonToken::JsonToken(int t, const std::string& s) : tok(t), lexeme(s), line(-1), column(-1)
{
}
JsonToken::JsonToken(int t, const std::string& s, int l, int c) : tok(t), lexeme(s), line(l), column(c)
{
}
JsonToken::JsonToken(const JsonToken& t)
{
    operator = (t);
}
JsonToken::~JsonToken()
{
}
JsonToken::operator int() const
{
    return tok;
}
JsonToken& JsonToken::operator = (const JsonToken& t)
{
    tok = t.tok;
    lexeme = t.lexeme;
    line = t.line;
    column = t.column;
    return *this;
}
