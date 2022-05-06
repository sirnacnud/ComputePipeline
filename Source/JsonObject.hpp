#ifndef JSON_OBJECT_HPP
#define JSON_OBJECT_HPP

#include "ActionObject.hpp"

/// Decoded JSON
class JsonObject: public ActionObject {
public:
    JsonObject(const std::string& url, MimeType mimeType);

    /// Gets whether or not the key is present in the JSON
    bool hasKey(const std::string& key) const;
    
    /// Gets the bool value for a key
    /// @returns True if the key is present, false otherwise
    bool boolValue(const std::string& key) const;
    
    /// Gets the int value for a key
    /// @returns Int value if the key is present, zero otherwise
    int intValue(const std::string& key) const;
    
    /// Gets the string value for a key
    /// @returns String value if the key is present, empty string otherwise
    std::string stringValue(const std::string& key) const;
    
    /// Gets the JSON object value for a key
    /// @returns JSON object if the key is present, empty shared_ptr otherwise
    std::shared_ptr<JsonObject> objectValue(const std::string& key) const;
    
    /// Gets the array value for a key
    /// @returns Vector if the key is present, empty vector otherwise
    template <typename T>
    std::vector<T> arrayValue(const std::string& key) const {
        return std::vector<T>();
    }
};

#endif
