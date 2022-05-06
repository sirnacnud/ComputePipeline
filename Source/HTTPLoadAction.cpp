#include "HTTPLoadAction.hpp"

#include "DataObject.hpp"

HTTPLoadAction::HTTPLoadAction(const std::string& url)
    : mURL(url)
{
}

std::shared_ptr<ActionObject> HTTPLoadAction::perform() {
    // Load file from HTTP request
    // Detect mimetype
    // ...
    MimeType mimeType = JSON;
    std::shared_ptr<unsigned char[]> loadedData;
    size_t dataLength = 1000;
    
    return std::shared_ptr<DataObject>(new DataObject(mURL, mimeType, loadedData, dataLength));
}
