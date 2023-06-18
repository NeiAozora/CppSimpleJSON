CppSimpleJSON Encoder and Decoder Library Documentation
==============================================

The CppSimpleJSON Encoder and Decoder library provides functionality to encode and decode JSON data in C++.

Usage
-----

### JSON Encoder

To encode JSON data, follow these steps:

1. Include the `header.h` file:
    
    ```cpp
    #include "header.h"
    
    ```
2. Create a `JSON::Value` object and set its value:
    
    ```cpp
    JSON::Value value;
    value.setXXX(valueData);
    
    ```
    
    Replace `XXX` with the appropriate method for setting the value based on its type, such as `setNull()`, `setBoolean()`, `setNumber()`, `setString()`, `setArray()`, or `setObject()`.
3. Create an instance of the `JSON::Encoder` class:
    
    ```cpp
    JSON::Encoder encoder;
    
    ```
4. Encode the `JSON::Value` object into a JSON string:
    
    ```cpp
    std::string jsonString = encoder.encode(value);
    
    ```
    
    The `encode()` method returns the JSON string representation of the `JSON::Value` object.

### JSON Decoder

To decode JSON data, follow these steps:

1. Include the `header.h` file:
    
    ```cpp
    #include "header.h"
    
    ```
2. Create an instance of the `JSON::Decoder` class:
    
    ```cpp
    JSON::Decoder decoder;
    
    ```
3. Decode the JSON string into a `JSON::Value` object:
    
    ```cpp
    std::string jsonString = "{'key': 'value'}";
    JSON::Value value = decoder.decode(jsonString);
    
    ```
    
    The `decode()` method parses the JSON string and returns the corresponding `JSON::Value` object.
4. Access the decoded JSON data using the `JSON::Value` object:
    
    ```cpp
    // Example: Accessing a string value
    std::string strValue = *(value.stringValue);
    
    // Example: Accessing an array value
    for (const JSON::Value& element : *(value.arrayValue)) {
        // Perform operations on each array element
    }
    
    // Example: Accessing an object value
    for (const auto& pair : *(value.objectValue)) {
        std::string key = pair.first;
        const JSON::Value& objValue = pair.second;
        // Perform operations on each object element
    }
    
    ```
    
    Depending on the value type, access the JSON data using appropriate methods and member variables of the `JSON::Value` object.

Error Handling
--------------

The library provides basic error handling for invalid JSON data. If the JSON decoder encounters any errors during decoding, it throws a `JSON::JSONDecodeError` exception with an error message describing the issue.
To handle potential exceptions, wrap the decoding process with a try-catch block:

    ```cpp
    try {
        JSON::Decoder decoder;
        JSON::Value value = decoder.decode(jsonString);
        // Perform operations with the decoded JSON data
    } catch (const JSON::JSONDecodeError& error) {
        std::cerr << "Error decoding JSON: " << error.what() << std::endl;
    }
    ```

Note: Make sure to catch the JSON::JSONDecodeError exception to handle decoding errors specifically.