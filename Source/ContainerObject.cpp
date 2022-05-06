#include "ContainerObject.hpp"

ContainerObject::ContainerObject(const std::string& url, MimeType mimeType, const std::vector<std::shared_ptr<ActionObject>>& objects)
    : ActionObject(url, mimeType)
    , mObjects(objects)
{
}

const std::vector<std::shared_ptr<ActionObject>>& ContainerObject::objects() const {
    return mObjects;
}
