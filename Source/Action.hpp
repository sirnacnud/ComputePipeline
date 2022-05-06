#ifndef ACTION_HPP
#define ACTION_HPP

#include <memory>

class ActionObject;

/// Base class for all actions
class Action {
public:
    virtual ~Action() {};
    
    /// Performs the action
    /// @returns Action ouput as an ActionObject
    virtual std::shared_ptr<ActionObject> perform() = 0;
};

#endif
