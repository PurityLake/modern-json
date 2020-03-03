#ifndef __HPP_JSONVALUE__
#define __HPP_JSONVALUE__

#include <memory>
#include <string>

class _JSONValue {
public:
    _JSONValue() = default;
    virtual ~_JSONValue() { }
    virtual std::string to_string() const = 0;
    virtual std::string type() const = 0;

    virtual std::shared_ptr<_JSONValue> operator+(const std::shared_ptr<_JSONValue> &b) = 0;
};

using JSONValue = std::shared_ptr<_JSONValue>;

inline JSONValue operator+(JSONValue& a, JSONValue& b) {
    return *a + b;
}

#endif /* __HPP_JSONVALUE__ */