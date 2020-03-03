#ifndef __HPP__JSONOBJECT__
#define __HPP__JSONOBJECT__

#include <JSONValue.hpp>
#include <JSONString.hpp>

#include <iostream>
#include <sstream>

namespace json {

class _JSONObject : public _JSONValue, public std::enable_shared_from_this<_JSONObject> {
private:
    std::vector<std::pair<JSONString, JSONValue>> obj;

public:
    _JSONObject() { }
    virtual ~_JSONObject() { }

    virtual std::string to_string() const override {
        std::stringstream ss;
        ss << "{\n";
        for (const auto& [k, v] : obj) {
            ss << "    " << k->to_string() << ": " << v->to_string() << ",\n";
        }
        ss << "}";
        return ss.str();
    }

    virtual std::string type() const override {
        return "object";
    }

    virtual std::shared_ptr<_JSONValue> operator+(const std::shared_ptr<_JSONValue> &b) override {
        return this->shared_from_this();
    }
};

using JSONObject = std::shared_ptr<_JSONObject>;

static inline JSONObject json_object() {
    return std::make_shared<_JSONObject>();
}

} // namepsace json

#endif /* __HPP__JSONOBJECT__ */