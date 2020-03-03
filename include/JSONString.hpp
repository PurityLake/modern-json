#ifndef __HPP_JSONSTRING__
#define __HPP_JSONSTRING__

#include <string>
#include <type_traits>

#include "JSONValue.hpp"

namespace json {

class _JSONString : public _JSONValue, public std::enable_shared_from_this<_JSONString> {
private:
    std::string value;

public:
    _JSONString() : value("") { }
    _JSONString(char *c) : value(c) { }
    _JSONString(std::string s) : value(s) { }

    virtual ~_JSONString() { }

    virtual std::string to_string() const override {
        return value;
    }

    virtual std::string type() const override {
        return "string";
    }

    virtual std::shared_ptr<_JSONValue> operator+(const std::shared_ptr<_JSONValue> &b) override {
        return this->shared_from_this();
    }
};

using JSONString = std::shared_ptr<_JSONString>;

static inline JSONString json_string(std::string a) {
    return std::make_shared<_JSONString>(a);
}

}

#endif /* __HPP_JSONSTRING__ */