#include "DataObject.hpp"

DataObject::DataObject(const std::string& url, MimeType mimeType, std::shared_ptr<unsigned char[]> data, size_t length)
    : ActionObject(url, mimeType)
    , mData(data)
    , mLength(length)
{
}

std::shared_ptr<unsigned char[]> DataObject::data() const {
    return mData;
}

size_t DataObject::length() const {
    return mLength;
}
