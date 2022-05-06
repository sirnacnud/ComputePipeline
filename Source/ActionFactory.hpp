#ifndef ACTION_FACTORY_HPP
#define ACTION_FACTORY_HPP

#include <memory>

class Action;
class ActionObject;
class DataObject;

/// ActionFactory handles creating Actions from either the initial URL or furtther action outputs (ActionObject)
class ActionFactory {
public:
    std::shared_ptr<Action> makeInitialAction(const std::string& url) const;
    
    std::shared_ptr<Action> makeAction(std::shared_ptr<ActionObject> object) const;
    
private:
    std::shared_ptr<Action> makeAction(std::shared_ptr<DataObject> ojbect) const;
};

#endif
