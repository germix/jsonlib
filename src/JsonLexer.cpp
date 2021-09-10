////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonLexer.cpp
//
// Analizador léxico para el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonLexer.h"
#include "JsonParserException.h"

static int is_eof(int c){return (c == (-1));}
static int is_blank(int c){return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == '\n');}
static int is_digit(int c) { return (c >= '0' && c <= '9'); }

JsonLexer::JsonLexer()
{
}
JsonLexer::~JsonLexer()
{
}
bool JsonLexer::init(const std::string& s)
{
    in.init(s);
    return true;
}
JsonToken JsonLexer::nextToken()
{
    int c;
    int tok = 0;
    int line = in.line;
    int column = in.column;
    std::string lexeme;

    while(tok == 0)
    {
        c = in.peek();
        line = in.line;
        column = in.column;

        if(is_eof(c))
        {
            tok = JSON_TOK_EOF;
            lexeme = "<EOF>";
        }
        else if(is_blank(c))
        {
            in.read();
        }
        else if(is_digit(c) || c == '-')
        {
            lexeme += in.read();
            while(is_digit(in.peek()) || in.peek() == '.')
            {
                lexeme += in.read();
            }
            tok = JSON_TOK_NUMBER;
        }
        else if(c == '\"')
        {
            in.read(); // Salta '\"'
            while(1)
            {
                c = in.peek();
                if(c == '\"' || c == EOF)
                {
                    break;
                }
                else if(c == '\\')
                {
                    in.read();
                    lexeme += in.read();
                }
                else
                {
                    lexeme += in.read();
                }
            }
            if(c == EOF)
            {
                throw JsonParserException(line, column, "Expected \'\"\', but found \'<EOF>\'");
            }
            else if(c == '\"')
            {
                in.read();
                tok = JSON_TOK_STRING;
            }
        }
        else if(isalpha(c))
        {
            lexeme += in.read();
            while(isalpha(in.peek()))
            {
                lexeme += in.read();
            }
            if(lexeme == "null")
            {
                tok = JSON_TOK_NULL;
            }
            else if(lexeme == "true")
            {
                tok = JSON_TOK_TRUE;
            }
            else if(lexeme == "false")
            {
                tok = JSON_TOK_FALSE;
            }
            else
            {
                throw JsonParserException(line, column, "Unrecognized keyword \'"+lexeme+"\'");
            }
        }
        else
        {
            tok = in.read();
            lexeme += char(tok);
        }
    }
    return JsonToken(tok, lexeme, line, column);
}
