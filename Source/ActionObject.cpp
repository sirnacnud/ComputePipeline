#include "ActionObject.hpp"

ActionObject::ActionObject(const std::string& url, MimeType mimeType)
    : mURL(url)
    , mMimeType(mimeType)
{
}

const std::string& ActionObject::url() {
    return mURL;
}

MimeType ActionObject::mimeType() {
    return mMimeType;
}
