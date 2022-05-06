#ifndef DECODE_IMAGE_ACTION_HPP
#define DECODE_IMAGE_ACTION_HPP

#include "Action.hpp"

class DataObject;

/// Decodes an Image from data
class DecodeImageAction: public Action {
public:
    DecodeImageAction(std::shared_ptr<DataObject> object);
    
    virtual std::shared_ptr<ActionObject> perform();

private:
    std::shared_ptr<DataObject> mObject;
};

#endif
