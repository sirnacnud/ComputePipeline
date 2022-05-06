#include "PipelineTask.hpp"

#include "Action.hpp"
#include "ActionFactory.hpp"
#include "ContainerObject.hpp"

PipelineTask::PipelineTask(const std::string& url, const ActionFactory& factory)
    : mFactory(factory)
    , mURL(url)
{
}

std::shared_ptr<ActionObject> PipelineTask::run() {
    std::shared_ptr<ActionObject> actionObject;
    
    // Make initial action from URL
    if (std::shared_ptr<Action> action = mFactory.makeInitialAction(mURL); action) {
        actionObject = action->perform();
        
        // If we have a container, process list the of action objects
        if (std::shared_ptr<ContainerObject> containerObject = std::dynamic_pointer_cast<ContainerObject>(actionObject); containerObject) {
            actionObject = processContainer(containerObject);
        } else {
            action = mFactory.makeAction(actionObject);
            actionObject = processAction(action);
        }
    }

    return actionObject;
}

std::shared_ptr<ActionObject> PipelineTask::processAction(std::shared_ptr<Action> action) {
    std::shared_ptr<ActionObject> actionObject;

    while (action) {
        actionObject = action->perform();
        action = mFactory.makeAction(actionObject);
    }

    return actionObject;
}

std::shared_ptr<ActionObject> PipelineTask::processContainer(std::shared_ptr<ContainerObject> containerObject) {
    std::vector<std::shared_ptr<ActionObject>> processedObjects;
    
    for (std::shared_ptr<ActionObject> actionObject : containerObject->objects()) {
        std::shared_ptr<Action> action = mFactory.makeAction(actionObject);
        processedObjects.push_back(processAction(action));
    }
    
    return std::shared_ptr<ActionObject>(new ContainerObject(containerObject->url(), BUNDLE, processedObjects));
}
