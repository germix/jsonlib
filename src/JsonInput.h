////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonInput.h
//
// Buffer de entrada para parsear el formato JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_INPUT_H___
#define ___JSON_INPUT_H___
#include <string>

#define EOF (-1)

class JsonInput
{
public:
    unsigned int pos;
    int line;
    int column;
    std::string buffer;
    int skip;
public:
    JsonInput();
    ~JsonInput();
public:
    void init(const std::string& s);
    int  peek();
    int  read();
};

#endif // ___JSON_INPUT_H___
