////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonParser.cpp
//
// Analizador sintáctico para el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonParser.h"
#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonObject.h"
#include "JsonParserException.h"

JsonParser::JsonParser()
{
}
JsonParser::~JsonParser()
{
}
JsonValue* JsonParser::parse(const std::string& s)
{
    if(s.empty())
        return NULL;

    if(lex.init(s))
    {
        next();
        if(tok == '[' || tok == '{')
        {
            return parseValue();
        }
        throw JsonParserException(tok.line, tok.column, "Expected \'{\' or \'[\', but found \'" +tok.lexeme + "\'");
    }
    return NULL;
}
void JsonParser::next()
{
    tok = lex.nextToken();
}
void JsonParser::match(int t)
{
    if(tok != t)
    {
        char sz[2];
        sz[0] = t;
        sz[1] = '\0';
        throw JsonParserException(tok.line, tok.column, "Expected \'"+JsonToken(t, sz).lexeme+"\', but found \'"+tok.lexeme+"\'");
    }
    next();
}
JsonValue* JsonParser::parseValue()
{
    JsonValue* jv = NULL;

    if(tok == '[')
    {
        JsonArray* value;
        if(NULL != (value = parseArray()))
            jv = new JsonValue(value);
    }
    else if(tok == '{')
    {
        JsonObject* value;
        if(NULL != (value = parseObject()))
            jv = new JsonValue(value);
    }
    else if(tok == JSON_TOK_NULL)
    {
        jv = new JsonValue();
        next();
    }
    else if(tok == JSON_TOK_TRUE)
    {
        jv = new JsonValue(true);
        next();
    }
    else if(tok == JSON_TOK_FALSE)
    {
        jv = new JsonValue(false);
        next();
    }
    else if(tok == JSON_TOK_STRING)
    {
        jv = new JsonValue(tok.lexeme);
        next();
    }
    else if(tok == JSON_TOK_NUMBER)
    {
        jv = new JsonValue(strtod(tok.lexeme.c_str(), 0));
        next();
    }
    if(!jv)
    {
        throw JsonParserException(tok.line, tok.column, "Expected value, but found \'" + tok.lexeme + "\'");
    }
    return jv;
}
JsonArray* JsonParser::parseArray()
{
    JsonArray* arr = new JsonArray();
    try
    {
        match('[');
        while(tok != ']')
        {
            arr->appendValue(parseValue());

            if(tok != ']')
            {
                if(tok == ',')
                {
                    next();
                    if(tok == ']')
                        throw JsonParserException(tok.line, tok.column, "Invalid comma");
                }
                else
                {
                    throw JsonParserException(tok.line, tok.column, "Expected \',\' or \']\', but found \'" +tok.lexeme + "\'");
                }
            }
        }
        match(']');
    }
    catch(JsonParserException ex)
    {
        delete arr;
        throw ex;
    }
    return arr;
}
JsonObject* JsonParser::parseObject()
{
    JsonObject* obj = new JsonObject();

    try
    {
        match('{');
        while(tok != '}')
        {
            std::string key;

            // Obtener clave
            if(tok != JSON_TOK_STRING && tok != '}')
            {
                throw JsonParserException(tok.line, tok.column, "Expected string or \'}\', but found \'" + tok.lexeme + "\'");
            }
            key = tok.lexeme;
            next();
            match(':');
            
            // Insertar valor
            obj->insertValue(key, parseValue());

            if(tok != '}')
            {
                if(tok == ',')
                {
                    next();
                    if(tok == '}')
                        throw JsonParserException(tok.line, tok.column, "Invalid comma");
                }
                else
                {
                    throw JsonParserException(tok.line, tok.column, "Expected \',\' or \'}\', but found \'" +tok.lexeme + "\'");
                }
            }
        }
        match('}');
    }
    catch(JsonParserException ex)
    {
        delete obj;
        throw ex;
    }
    return obj;
}
