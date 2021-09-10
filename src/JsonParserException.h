////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonParserException.h
//
// Excepción JSON del parser
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_PARSER_EXCEPTION_H___
#define ___JSON_PARSER_EXCEPTION_H___
#include <string>
#include "JsonException.h"

class JsonParserException : public JsonException
{
    int line;
    int column;
public:
    JsonParserException(int line, int column, const std::string& message);
    ~JsonParserException();
public:
    int getLine() const { return line; }
    int getColumn() const { return column; }
};

#endif // ___JSON_PARSER_EXCEPTION_H___
