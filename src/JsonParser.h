////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonParser.h
//
// Analizador sintáctico para el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_PARSER_H___
#define ___JSON_PARSER_H___
#include <string>
#include "JsonToken.h"
#include "JsonLexer.h"

class JsonValue;
class JsonArray;
class JsonObject;

class JsonParser
{
    JsonToken tok;
    JsonLexer lex;
public:
    /**
     * Constructor.
     */
    JsonParser();

    /**
     * Destructor.
     */
    ~JsonParser();
public:
    /**
     * Decodes a JSON string.
     * 
     * @param s The JSON string being decoded.
     * @return Decoded JSON value
     */
    JsonValue* parse(const std::string& s);
private:
    void next();
    void match(int t);

    JsonValue* parseValue();
    JsonArray* parseArray();
    JsonObject* parseObject();
};

#endif // ___JSON_PARSER_H___
