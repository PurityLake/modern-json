#ifndef __HPP_JSONARRAY__
#define __HPP_JSONARRAY__

#include <memory>
#include <sstream>
#include <vector>

#include "JSONValue.hpp"

namespace json {

class _JSONArray : public _JSONValue, public std::enable_shared_from_this<_JSONArray> {
private:
    std::vector<std::shared_ptr<_JSONValue>> value;

    _JSONArray(std::vector<std::shared_ptr<_JSONValue>> v) {
        value = std::vector<std::shared_ptr<_JSONValue>>(v);
    }

public:
    _JSONArray() : value({}) { }

    virtual std::shared_ptr<_JSONValue> operator+(const std::shared_ptr<_JSONValue> &b) override {
        std::string str = b->type();
        if (str == "array") {
            std::shared_ptr<_JSONArray> arr = std::static_pointer_cast<_JSONArray>(b);
            value.reserve(value.size() + arr->value.size());
            value.insert(value.end(), arr->value.begin(), arr->value.end());
            return this->shared_from_this();
        }
        value.push_back(b);
        return this->shared_from_this();
    }

    virtual std::string to_string() const override {
        std::stringstream ss;
        ss << "[ ";
        int i = 0;
        for (const auto &v: value) {
            ss << v->to_string();
            if (i + 1 < value.size()) ss << ", ";
            else ss << " ";
            ++i;
        }
        ss << "]";
        return ss.str();
    }

    virtual std::string type() const override {
        return "array";
    }
};

using JSONArray = std::shared_ptr<_JSONArray>;

static inline JSONArray json_array() {
    return std::make_shared<_JSONArray>();
}

} // namepsace json

#endif /* __HPP_JSONARRAY__ */