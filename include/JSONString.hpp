#ifndef __HPP_JSONSTRING__
#define __HPP_JSONSTRING__

#include <string>
#include <type_traits>

#include "JSONValue.hpp"

class JSONString : public _JSONValue {
private:
    std::string value;

public:
    JSONString() : value("") { }
    JSONString(char *c) : value(c) { }
    JSONString(std::string s) : value(s) { }

    virtual ~JSONString() { }

    virtual std::string to_string() const override {
        return value;
    }

    virtual std::string type() const override {
        return "string";
    }
};

#endif /* __HPP_JSONSTRING__ */