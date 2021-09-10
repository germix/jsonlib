////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonWriter.h
//
// Escritor de archivo JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_WRITER_H___
#define ___JSON_WRITER_H___
#include <stdio.h>
#include <string>

class JsonValue;

class JsonWriter
{
    FILE* fp;
    int identation;
    int tabSize;
    bool isStartLine;
public:
    /**
     * Constructor.
     */
    JsonWriter();

    /**
     * Destructor.
     */
    ~JsonWriter();
public:
    /**
     * Write JSON into a file
     * 
     * @param value Value
     * @param fileName File name
     */
    bool write(JsonValue* value, const std::string& fileName);
private:
    void nl();
    void print(const std::string& s);
    void print(JsonValue* value);
};

#endif // ___JSON_WRITER_H___
