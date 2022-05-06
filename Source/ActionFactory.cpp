#include "ActionFactory.hpp"

#include "ActionObject.hpp"
#include "BundleLoadAction.hpp"
#include "DataObject.hpp"
#include "DecodeImageAction.hpp"
#include "DecodeJsonAction.hpp"
#include "DecompressAction.hpp"
#include "FileLoadAction.hpp"
#include "ImageObject.hpp"
#include "JsonObject.hpp"
#include "HTTPLoadAction.hpp"

static const char* FILE_PREFIX = "file://";
static const char* HTTP_PREFIX = "http://";
static const char* HTTPS_PREFIX = "https://";
static const char* BUNDLE_PREFIX = "bundle://";

std::shared_ptr<Action> ActionFactory::makeInitialAction(const std::string& url) const {
    if (url.compare(0, strlen(FILE_PREFIX), FILE_PREFIX) == 0) {
        return std::shared_ptr<Action>(new FileLoadAction(url));
    } else if (url.compare(0, strlen(HTTP_PREFIX), HTTP_PREFIX) == 0 || url.compare(0, strlen(HTTPS_PREFIX), HTTPS_PREFIX) == 0) {
        return std::shared_ptr<Action>(new HTTPLoadAction(url));
    } else if (url.compare(0, strlen(BUNDLE_PREFIX), BUNDLE_PREFIX) == 0) {
        return std::shared_ptr<Action>(new BundleLoadAction(url));
    } else {
        return std::shared_ptr<Action>();
    }
}

std::shared_ptr<Action> ActionFactory::makeAction(std::shared_ptr<ActionObject> object) const {
    if (std::shared_ptr<DataObject> dataObject = std::dynamic_pointer_cast<DataObject>(object); dataObject) {
        return makeAction(dataObject);
    } else if (std::dynamic_pointer_cast<ImageObject>(object)) {
        // No further actions for decoded image
        return std::shared_ptr<Action>();
    } else if (std::dynamic_pointer_cast<JsonObject>(object)) {
        // No further actions for decoded json
        return std::shared_ptr<Action>();
    } else {
        return std::shared_ptr<Action>();
    }
}

std::shared_ptr<Action> ActionFactory::makeAction(std::shared_ptr<DataObject> object) const {
    switch (object->mimeType()) {
    case BMP:
        return std::shared_ptr<Action>(new DecodeImageAction(object));
    case BZIP:
        return std::shared_ptr<Action>(new DecompressAction(object));
    case BZIP2:
        return std::shared_ptr<Action>(new DecompressAction(object));
    case GIF:
        return std::shared_ptr<Action>(new DecodeImageAction(object));
    case JPG:
        return std::shared_ptr<Action>(new DecodeImageAction(object));
    case PNG:
        return std::shared_ptr<Action>(new DecodeImageAction(object));
    case JSON:
        return std::shared_ptr<Action>(new DecodeJsonAction(object));
    default:
        return std::shared_ptr<Action>();
    }
}
