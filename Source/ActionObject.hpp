#ifndef ACTION_OBJECT_HPP
#define ACTION_OBJECT_HPP

#include <string>

#include "MimeType.hpp"

/// Base class for Action outputs
class ActionObject {
public:
    ActionObject(const std::string& url, MimeType mimeType);
    
    virtual ~ActionObject() {};

    /// Original URL for the resource
    const std::string& url();
    
    /// Mimetype of the resource
    MimeType mimeType();
    
private:
    std::string mURL;
    MimeType mMimeType;
};

#endif
