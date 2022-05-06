#include "DecodeImageAction.hpp"

#include "DataObject.hpp"
#include "ImageObject.hpp"

DecodeImageAction::DecodeImageAction(std::shared_ptr<DataObject> object)
    : mObject(object)
{
}

std::shared_ptr<ActionObject> DecodeImageAction::perform() {
    // Decode the image
    // ...
    std::shared_ptr<unsigned char[]> decodedImageData;
    size_t decodedLength = 1000;

    ImageObject* imageObject = new ImageObject(mObject->url(), mObject->mimeType(), decodedImageData, decodedLength, 100, 100, 4);
    return std::shared_ptr<ActionObject>(imageObject);
}
