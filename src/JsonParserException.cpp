////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonParserException.cpp
//
// Excepción JSON del parser
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonParserException.h"

JsonParserException::JsonParserException(int ___line, int ___column, const std::string& ___message)
: JsonException(___message)
, line(___line)
, column(___column)
{
}
JsonParserException::~JsonParserException()
{
}
