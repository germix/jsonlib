////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonToken.h
//
// Token JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_TOKEN_H___
#define ___JSON_TOKEN_H___
#include <string>

enum
{
    JSON_TOK_EOF = 256,
    JSON_TOK_NULL,
    JSON_TOK_TRUE,
    JSON_TOK_FALSE,
    JSON_TOK_NUMBER,
    JSON_TOK_STRING,
};

class JsonToken
{
public:
    int             tok;
    std::string     lexeme;
    int             line;
    int             column;
public:
    JsonToken();
    JsonToken(int t, const std::string& s);
    JsonToken(int t, const std::string& s, int l, int c);
    JsonToken(const JsonToken& t);
    ~JsonToken();
public:
    operator int() const;
    JsonToken& operator = (const JsonToken& t);
};

#endif // ___JSON_TOKEN_H___
