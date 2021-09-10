////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonValue.h
//
// Representa un valor en un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_VALUE_H___
#define ___JSON_VALUE_H___
#include <string>

class JsonArray;
class JsonObject;

class JsonValue
{
    enum
    {
        TYPE_NULL = 0,
        TYPE_BOOL = 1,
        TYPE_ARRAY = 2,
        TYPE_NUMBER = 3,
        TYPE_OBJECT = 4,
        TYPE_STRING = 5,
    };
    int type;
    union
    {
        bool bValue;
        double nValue;
        JsonArray* aValue;
        JsonObject* oValue;
    };
    std::string sValue;
public:
    /**
     * Construct a JSON value as null.
     */
    JsonValue();

    /**
     * Construct a JSON value as boolean.
     */
    JsonValue(bool v);

    /**
     * Construct a JSON value as integer number.
     */
    JsonValue(int v);

    /**
     * Construct a JSON value as double-precision floating-point number.
     */
    JsonValue(double v);

    /**
     * Construct a JSON value as string.
     */
    JsonValue(const std::string& v);

    /**
     * Construct a JSON value as JSON array.
     */
    JsonValue(JsonArray* v);

    /**
     * Construct a JSON value as JSON object.
     */
    JsonValue(JsonObject* v);

    /**
     * Destructor.
     */
    ~JsonValue();
public:
    /**
     * Returns true if the value is null.
     */
    bool isNull() const { return type == TYPE_NULL; }

    /**
     * Returns true if the value is a boolean.
     */
    bool isBool() const { return type == TYPE_BOOL; }

    /**
     * Returns true if the value is a number.
     */
    bool isNumber() const { return type == TYPE_NUMBER; }

    /**
     * Returns true if the value is a string.
     */
    bool isString() const { return type == TYPE_STRING; }

    /**
     * Returns true if the value is an array.
     */
    bool isArray() const { return type == TYPE_ARRAY; }

    /**
     * Returns true if the value is an object.
     */
    bool isObject() const { return type == TYPE_OBJECT; }

    /**
     * Return value as boolean.
     */
    bool        toBool() const;

    /**
     * Return value as integer.
     */
    int         toInt() const;

    /**
     * Return value as double.
     */
    double      toDouble() const;

    /**
     * Return value as string
     */
    std::string toString() const;

    /**
     * Return value as array.
     */ 
    JsonArray*  toArray() const;

    /**
     * Return value as object.
     */
    JsonObject* toObject() const;
};

#endif // ___JSON_VALUE_H___
