////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonWriter.cpp
//
// Escritor de archivo JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonWriter.h"
#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonObject.h"

JsonWriter::JsonWriter()
{
}

JsonWriter::~JsonWriter()
{
}

bool JsonWriter::write(JsonValue* value, const std::string& fileName)
{
    fp = fopen(fileName.c_str(), "w");
    if(fp)
    {
        identation = 0;
        tabSize = 4;
        isStartLine = true;

        print(value);

        fclose(fp);

        return true;
    }
    return false;
}

void JsonWriter::nl()
{
    print("\n");
    isStartLine = true;
}

void JsonWriter::print(const std::string& s)
{
    if(isStartLine)
    {
        isStartLine = false;

        int n = tabSize == 0 ? identation : (identation*tabSize);
        char ch = tabSize == 0 ? '\t' : ' ';

        for(int i = 0; i < n; i++)
        {
            fwrite(&ch, sizeof(char), 1, fp);
        }
    }
    fwrite(s.c_str(), sizeof(char), s.size(), fp);
}

void JsonWriter::print(JsonValue* value)
{
    if(value->isArray())
    {
        JsonArray* array = value->toArray();

        print("[");
        identation++;

        bool first = true;

        for(int i = 0; i < array->size(); i++)
        {
            if (!first)
                print(",");
            first = false;
            nl();

            print(array->at(i));
        }
        identation--;
        nl();
        print("]");
    }
    else if(value->isObject())
    {
        JsonObject* object = value->toObject();

        print("{");
        identation++;

        bool first = true;
        const JsonValueMap& ov = object->getValues();

        for (JsonValueMap::const_iterator it = ov.begin(); it != ov.end(); it++)
        {
            std::string k = it->first;
            JsonValue*  v = it->second;

            if (!first)
                print(",");
            first = false;
            nl();

            print("\"" + k + "\": ");
            print(v);
        }
        identation--;
        nl();
        print("}");
    }
    else if(value->isNull())
    {
        print("null");
    }
    else if(value->isBool())
    {
        bool v = value->toBool();

        if(v)
            print("true");
        else
            print("false");
    }
    else if(value->isString())
    {
        std::string v = value->toString();

        print("\"" + v + "\"");
    }
    else if(value->isNumber())
    {
        char sz[128];
        sprintf(sz, "%g", value->toDouble());

        print(sz);
    }
}
