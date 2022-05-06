#ifndef DECODE_JSON_ACTION_HPP
#define DECODE_JSON_ACTION_HPP

#include "Action.hpp"

class DataObject;

/// Decodes a JSON object from data
class DecodeJsonAction: public Action {
public:
    DecodeJsonAction(std::shared_ptr<DataObject> object);
    
    virtual std::shared_ptr<ActionObject> perform();

private:
    std::shared_ptr<DataObject> mObject;
};

#endif
