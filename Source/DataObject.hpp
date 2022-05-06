#ifndef DATA_OBJECT_HPP
#define DATA_OBJECT_HPP

#include "ActionObject.hpp"

/// Represents raw data
class DataObject : public ActionObject {
public:
    DataObject(const std::string& url, MimeType mimeType, std::shared_ptr<unsigned char[]> data, size_t length);
    
    /// Gets the buffer for the data
    std::shared_ptr<unsigned char[]> data() const;
    
    /// Gets the length of the data in bytes
    size_t length() const;

private:
     std::shared_ptr<unsigned char[]> mData;
     size_t mLength;
};

#endif
