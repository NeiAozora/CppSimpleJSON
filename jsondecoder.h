#ifndef JSON_DECODER_H
#define JSON_DECODER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

namespace JSON {

    enum class ValueType {
        Null,
        Boolean,
        Number,
        String,
        Array,
        Object
    };

    class Value {
    public:
        ValueType type;

        union {
            bool booleanValue;
            double numberValue;
            std::string* stringValue;
            std::vector<Value>* arrayValue;
            std::map<std::string, Value>* objectValue;
        };

        Value();
        ~Value();

        void setNull();
        void setBoolean(bool value);
        void setNumber(double value);
        void setString(const std::string& value);
        void setArray(const std::vector<Value>& value);
        void setObject(const std::map<std::string, Value>& value);

        std::string toString() const;

        void iterateValue(const std::function<void(const Value&)>& callback) const;
    };

    class Decoder {
    public:
        Value decode(const std::string& json) const;

    private:
        size_t skipWhitespace(const std::string& json, size_t position) const;
        Value decodeValue(const std::string& json, size_t& position) const;
        Value decodeNull(const std::string& json, size_t& position) const;
        Value decodeBoolean(const std::string& json, size_t& position) const;
        Value decodeNumber(const std::string& json, size_t& position) const;
        Value decodeString(const std::string& json, size_t& position) const;
        Value decodeArray(const std::string& json, size_t& position) const;
        Value decodeObject(const std::string& json, size_t& position) const;

        void throwError(const std::string& message, size_t position) const;
    };

    class JSONDecodeError : public std::runtime_error {
    public:
        explicit JSONDecodeError(const std::string& message);
    };

} // namespace JSON

#endif // JSON_DECODER_H
