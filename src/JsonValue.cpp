////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonValue.cpp
//
// Representa un valor en un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonValue.h"
#include "JsonArray.h"
#include "JsonObject.h"
#include "JsonException.h"

JsonValue::JsonValue() : type(TYPE_NULL)
{
}
JsonValue::JsonValue(bool v) : type(TYPE_BOOL)
{
    bValue = v;
}
JsonValue::JsonValue(int v) : type(TYPE_NUMBER)
{
    nValue = v;
}
JsonValue::JsonValue(double v) : type(TYPE_NUMBER)
{
    nValue = v;
}
JsonValue::JsonValue(JsonArray* v) : type(TYPE_ARRAY)
{
    aValue = v;
}
JsonValue::JsonValue(JsonObject* v) : type(TYPE_OBJECT)
{
    oValue = v;
}
JsonValue::JsonValue(const std::string& v) : type(TYPE_STRING)
{
    sValue = v;
}
JsonValue::~JsonValue()
{
    if(type == TYPE_ARRAY) delete aValue;
    if(type == TYPE_OBJECT) delete oValue;
}
bool        JsonValue::toBool() const
{
    if(type == TYPE_BOOL)
        return bValue;
    throw JsonException("Value is not a boolean");
}
int         JsonValue::toInt() const
{
    if(type == TYPE_NUMBER)
        return (int)nValue;
    throw JsonException("Value is not a number");
}
double      JsonValue::toDouble() const
{
    if(type == TYPE_NUMBER)
        return (double)nValue;
    throw JsonException("Value is not a number");
}
std::string JsonValue::toString() const
{
    if(type == TYPE_STRING)
        return sValue;
    throw JsonException("Value is not a string");
}
JsonArray*  JsonValue::toArray() const
{
    if(type == TYPE_ARRAY)
        return aValue;
    throw JsonException("Value is not an array");
}
JsonObject* JsonValue::toObject() const
{
    if(type == TYPE_OBJECT)
        return oValue;
    throw JsonException("Value is not an object");
}
