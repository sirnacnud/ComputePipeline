#ifndef CONTAINER_OBJECT_HPP
#define CONTAINER_OBJECT_HPP

#include "ActionObject.hpp"

#include <vector>

/// Container Object creates from a Bundle
class ContainerObject: public ActionObject {
public:
    ContainerObject(const std::string& url, MimeType mimeType, const std::vector<std::shared_ptr<ActionObject>>& objects);
    
    /// Gets all objects in the container
    const std::vector<std::shared_ptr<ActionObject>>& objects() const;
    
private:
    std::vector<std::shared_ptr<ActionObject>> mObjects;
};

#endif
