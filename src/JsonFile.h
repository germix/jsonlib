////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonFile.h
//
// Archivo JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_FILE_H___
#define ___JSON_FILE_H___
#include <string>

class JsonValue;

class JsonFile
{
    JsonValue* value;
public:
    /**
     * Constructor.
     */
    JsonFile();

    /**
     * Destructor.
     */
    ~JsonFile();
public:
    /**
     * Decodes a JSON file.
     *
     * @param fname File name
     * @return Decoded JSON value
     */
    JsonValue* load(const std::string& fname);
};

#endif // ___JSON_FILE_H___
