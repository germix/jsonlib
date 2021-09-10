////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonArray.h
//
// Representa un array en un objeto JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_ARRAY_H___
#define ___JSON_ARRAY_H___
#include <vector>

class JsonValue;

class JsonArray
{
    std::vector<JsonValue*> values;
public:
    /**
     * Constructor.
     */
    JsonArray();

    /**
     * Destructor.
     */
    ~JsonArray();
public:
    /**
     * Get array size.
     * 
     * @return Array size
     */
    int size() const;

    /**
     * Get value at index.
     * 
     * @param index Index of the value
     * @return Value
     */
    JsonValue* at(int index) const;

    /**
     * Append a new value.
     * 
     * @param value Value to append
     */
    void appendValue(JsonValue* value);
};

#endif // ___JSON_ARRAY_H___
