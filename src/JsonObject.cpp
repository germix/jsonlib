////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonObject.cpp
//
// Representa un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "JsonObject.h"
#include "JsonValue.h"
#include "JsonException.h"

JsonObject::JsonObject()
{
}
JsonObject::~JsonObject()
{
    for(std::map<std::string,JsonValue*>::const_iterator it = values.begin(); it != values.end(); it++)
    {
        delete it->second;
    }
    values.clear();
}
bool JsonObject::has(const std::string& key) const
{
    std::map<std::string, JsonValue*>::const_iterator it = values.find(key);
    if(it == values.end())
    {
        return false;
    }
    return true;
}
JsonValue* JsonObject::getValue(const std::string& key) const
{
    std::map<std::string, JsonValue*>::const_iterator it = values.find(key);
    if(it == values.end())
    {
        throw JsonException("Key \"" + key + "\" does not exists");
    }
    return it->second;
}
bool JsonObject::getValueAsBool(const std::string& key) const
{
    return getValue(key)->toBool();
}
int JsonObject::getValueAsInt(const std::string& key) const
{
    return getValue(key)->toInt();
}
double JsonObject::getValueAsDouble(const std::string& key) const
{
    return getValue(key)->toDouble();
}
std::string JsonObject::getValueAsString(const std::string& key) const
{
    return getValue(key)->toString();
}
JsonArray* JsonObject::getValueAsArray(const std::string& key) const
{
    return getValue(key)->toArray();
}
JsonObject* JsonObject::getValueAsObject(const std::string& key) const
{
    return getValue(key)->toObject();
}
void JsonObject::insertValue(const std::string& key, JsonValue* value)
{
    if(value != NULL)
    {
        std::map<std::string, JsonValue*>::const_iterator it = values.find(key);
        if(it != values.end())
        {
            delete it->second;
        }
        values[key] = value;
    }
}
