////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonLexer.h
//
// Analizador léxico para el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_LEXER_H___
#define ___JSON_LEXER_H___
#include <string>
#include "JsonToken.h"
#include "JsonInput.h"

class JsonLexer
{
    JsonInput in;
public:
    JsonLexer();
    ~JsonLexer();
public:
    bool init(const std::string& s);
    JsonToken nextToken();
};

#endif // ___JSON_LEXER_H___
