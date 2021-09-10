////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonFile.cpp
//
// Archivo JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonFile.h"
#include "JsonParser.h"
#include "JsonValue.h"

#include <stdio.h>

JsonFile::JsonFile() : value(NULL)
{
}
JsonFile::~JsonFile()
{
    if(value)
        delete value;
}
JsonValue* JsonFile::load(const std::string& fname)
{
    if(value)
    {
        delete value;
        value = NULL;
    }
    FILE* fp = fopen(fname.c_str(), "r");
    if(fp)
    {
        // Get size
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        
        // Read file
        std::string buf;
        buf.resize(size+1);
        fread((void*)&buf[0], 1, size, fp);
        buf[size] = 0;
        fclose(fp);
        
        // Parse file
        value = JsonParser().parse(buf);
    }
    return value;
}
