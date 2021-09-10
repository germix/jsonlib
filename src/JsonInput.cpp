////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonInput.cpp
//
// Buffer de entrada para parsear el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonInput.h"
#include <wchar.h>

JsonInput::JsonInput()
{
}
JsonInput::~JsonInput()
{
}
void JsonInput::init(const std::string& s)
{
    pos = 0;
    line = 0;
    column = 0;
    buffer = s;
}
int JsonInput::peek()
{
    if(pos < buffer.size())
    {
#if 0
        return buffer.at(pos);
#else
        skip = 1;
        int ch = buffer.at(pos);
        if(ch == '\\' && pos+5 < buffer.size())
        {
            if(buffer.at(pos+1) == 'u' && isdigit(buffer.at(pos+2)))
            {
                std::string s;
                s += buffer.at(pos+2);
                s += buffer.at(pos+3);
                s += buffer.at(pos+4);
                s += buffer.at(pos+5);
                ch = strtol(s.c_str(), NULL, 16);
                skip = 6;
            }
        }
        return ch;
#endif
    }
    return EOF;
}
int JsonInput::read()
{
    int c = peek();
    pos += skip;
    column++;
    if(c == '\n')
    {
        line++;
        column = 0;
    }
    return c;
}
