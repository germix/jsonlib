////////////////////////////////////////////////////////////////////////////////////////////////////
//
// JsonException.h
//
// Excepción JSON
//
// Autor: Germán Martínez
// Licencia: GPL-3.0
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ___JSON_EXCEPTION_H___
#define ___JSON_EXCEPTION_H___
#include <string>
#include <exception>

class JsonException : public std::exception
{
    std::string message;
public:
    JsonException(const std::string& message);
    ~JsonException();
public:
    const char* what() const { return message.c_str(); }
    std::string getMessage() const { return message; }
};

#endif // ___JSON_EXCEPTION_H___
