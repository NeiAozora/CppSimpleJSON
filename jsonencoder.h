#ifndef JSON_ENCODER_H
#define JSON_ENCODER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

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

    private:
        void cleanup();
    };

    class Encoder {
    public:
        std::string encode(const Value& value) const;

    private:
        std::string encodeNull() const;
        std::string encodeBoolean(bool value) const;
        std::string encodeNumber(double value) const;
        std::string encodeString(const std::string& value) const;
        std::string encodeArray(const std::vector<Value>& value) const;
        std::string encodeObject(const std::map<std::string, Value>& value) const;
    };

} // namespace JSON

#endif // JSON_ENCODER_H
