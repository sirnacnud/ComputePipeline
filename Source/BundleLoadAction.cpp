#include "BundleLoadAction.hpp"

#include "ContainerObject.hpp"

BundleLoadAction::BundleLoadAction(const std::string& url)
    : mURL(url)
{
}

std::shared_ptr<ActionObject> BundleLoadAction::perform() {
    // Load contents of Bundle and put in a flat list
    // Files will be loaded using the FileLoadAction
    // ...
    
    std::vector<std::shared_ptr<ActionObject>> objects;
    return std::shared_ptr<ContainerObject>(new ContainerObject(mURL, BUNDLE, objects));
}
