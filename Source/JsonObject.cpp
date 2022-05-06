#include "JsonObject.hpp"

JsonObject::JsonObject(const std::string& url, MimeType mimeType)
    : ActionObject(url, mimeType)
{
}

bool JsonObject::hasKey(const std::string& key) const {
    return false;
}

bool JsonObject::boolValue(const std::string& key) const {
    return false;
}

int JsonObject::intValue(const std::string& key) const {
    return 0;
}

std::string JsonObject::stringValue(const std::string& key) const {
    return std::string();
}

std::shared_ptr<JsonObject> JsonObject::objectValue(const std::string& key) const {
    return std::shared_ptr<JsonObject>();
}
