////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonObject.h
//
// Representa un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_OBJECT_H___
#define ___JSON_OBJECT_H___
#include <map>
#include <string>

class JsonValue;
class JsonArray;
class JsonObject;

typedef std::map<std::string, JsonValue*> JsonValueMap;

class JsonObject
{
public:
    std::map<std::string, JsonValue*> values;
public:
    /**
     * Constructor.
     */
    JsonObject();

    /**
     * Destructor.
     */
    ~JsonObject();
public:
    /**
     * Returns true if the key is defined.
     * 
     * @param key Key
     * @return true|false
     */
    bool has(const std::string& key) const;

    /**
     * Get value.
     * 
     * @param key Key
     * @return Value or null if the key is not defined
     */
    JsonValue* getValue(const std::string& key) const;

    /**
     * Get value as boolean.
     * 
     * @param key Key
     * @return Boolean value
     */
    bool getValueAsBool(const std::string& key) const;

    /**
     * Get value as integer number.
     * 
     * @param key Key
     * @return Integer number value
     */
    int getValueAsInt(const std::string& key) const;

    /**
     * Get value as double number.
     * 
     * @param key Key
     * @return Double number value
     */
    double getValueAsDouble(const std::string& key) const;

    /**
     * Get value as string.
     * 
     * @param key Key
     * @return String value
     */
    std::string getValueAsString(const std::string& key) const;

    /**
     * Get value as array.
     * 
     * @param key Key
     * @return Array value
     */
    JsonArray* getValueAsArray(const std::string& key) const;

    /**
     * Get value as object.
     * 
     * @param key Key
     * @return Object value
     */
    JsonObject* getValueAsObject(const std::string& key) const;

    /**
     * Get values.
     *
     * @return Map of values
     */
    const JsonValueMap& getValues() const { return values; }

    /**
     * Insert value or replace if it exists.
     * 
     * @param key Key
     * @param value Value
     */
    void insertValue(const std::string& key, JsonValue* value);
};

#endif // ___JSON_OBJECT_H___
