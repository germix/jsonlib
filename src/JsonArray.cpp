////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonArray.cpp
//
// Representa un array en un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonArray.h"
#include "JsonValue.h"

JsonArray::JsonArray()
{
}
JsonArray::~JsonArray()
{
    for(unsigned int i = 0; i < values.size(); i++)
        delete values[i];

    values.clear();
}
int JsonArray::size() const
{
    return values.size();
}
JsonValue* JsonArray::at(int index) const
{
    return values.at(index);
}
void JsonArray::appendValue(JsonValue* value)
{
    if(value != NULL)
        values.push_back(value);
}
