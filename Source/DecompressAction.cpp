#include "DecompressAction.hpp"

#include "DataObject.hpp"
#include "MimeType.hpp"

DecompressAction::DecompressAction(std::shared_ptr<DataObject> object)
    : mObject(object)
{
}

std::shared_ptr<ActionObject> DecompressAction::perform() {
    // Decompress data
    // Detect new mime type
    // ...
    std::shared_ptr<unsigned char[]> decompressedData;
    size_t decompressedLength = 1000;
    MimeType newMimeType = BIN;

    return std::shared_ptr<DataObject>(new DataObject(mObject->url(), newMimeType, decompressedData, decompressedLength));
}
