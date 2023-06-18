# CPPSimpleJSON

CPPSimpleJSON is a Simple lightweight and easy-to-use C++ library for encoding and decoding JSON data.

## Features

- Encode JSON data from C++ objects to JSON strings.
- Decode JSON strings into C++ objects representing JSON data.
- Support for JSON value types: Null, Boolean, Number, String, Array, and Object.
- Error handling for invalid JSON input during decoding.

## Installation

1. Clone the repository:


```bash

git clone 

```
2. Include the  header file in your C++ project:

```cpp
#include "path/to/yourheader.h"

```

Usage
-----

To encode JSON data:

1. Create a `JSON::Value` object and set its value based on the desired JSON type.
2. Create an instance of the `JSON::Encoder` class.
3. Encode the `JSON::Value` object using the `encode()` method to obtain the JSON string representation.

```cpp
JSON::Value value;
// Set the value based on the desired JSON type

JSON::Encoder encoder;
std::string jsonString = encoder.encode(value);

```

To decode JSON data:

1. Create an instance of the `JSON::Decoder` class.
2. Decode a JSON string into a `JSON::Value` object using the `decode()` method.
3. Access the decoded JSON data using the `JSON::Value` object.

```cpp
JSON::Decoder decoder;
JSON::Value value = decoder.decode(jsonString);

// Access the decoded JSON data
// Based on the value type, use appropriate methods and member variables of the `JSON::Value` object

```

Please refer to the library's documentation for detailed usage instructions and examples.

Error Handling
--------------

The library includes basic error handling for invalid JSON input during decoding. If an error occurs, a `JSON::JSONDecodeError` exception is thrown. It is recommended to catch this exception and handle the error gracefully.

```cpp
try {
    JSON::Decoder decoder;
    JSON::Value value = decoder.decode(jsonString);
    // Handle the decoded JSON data
} catch (const JSON::JSONDecodeError& error) {
    // Handle the decoding error
}

```

Contributing
------------

Contributions to CPPSimpleJSON are welcome! If you have suggestions, bug reports, or want to contribute code, please submit an issue or a pull request to the repository.

License
-------

This project is licensed under the [MIT License](LICENSE).
