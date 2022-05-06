#include "DecodeJsonAction.hpp"

#include "DataObject.hpp"
#include "JsonObject.hpp"

DecodeJsonAction::DecodeJsonAction(std::shared_ptr<DataObject> object)
    : mObject(object)
{
}

std::shared_ptr<ActionObject> DecodeJsonAction::perform() {
    // Decode json to custom data structure not implemented here
    // We would then pass this in to JsonObject
    // ...
    return std::shared_ptr<ActionObject>(new JsonObject(mObject->url(), mObject->mimeType()));
}
