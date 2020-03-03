#ifndef __HPP_JSONNUMBER__
#define __HPP_JSONNUMBER__

#include <memory>
#include <string>
#include <type_traits>

#include "JSONValue.hpp"

namespace json {

template <typename Number, typename std::enable_if<std::is_arithmetic<Number>::value>::type* = nullptr>
class _JSONNumber : public _JSONValue, public std::enable_shared_from_this<_JSONNumber<Number>> {
private:
    Number value;

public:
    _JSONNumber() : value(0) { }
    _JSONNumber(Number n) : value(n) { }
    virtual ~_JSONNumber() { }

    virtual std::string to_string() const override {
        return std::to_string(value);
    }

    virtual std::string type() const override {
        if constexpr(std::is_integral<Number>::value) {
            return "int";
        } else {
            return "float";
        }
    }

    virtual std::shared_ptr<_JSONValue> operator+(const std::shared_ptr<_JSONValue> &b) override {
        return this->shared_from_this();
    }
};

template <typename Number>
using JSONNumber = std::shared_ptr<_JSONNumber<Number>>;

template <typename Number, typename std::enable_if<std::is_arithmetic<Number>::value>::type* = nullptr>
static inline JSONNumber<Number> json_number(Number a) {
    return std::make_shared<_JSONNumber<Number>>(a);
}

} // namespace json

#endif /* __HPP_JSONNUMBER__ */