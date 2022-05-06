#ifndef DECOMPRESS_ACTION_HPP
#define DECOMPRESS_ACTION_HPP

#include "Action.hpp"

class DataObject;

/// Decompresses data
class DecompressAction: public Action {
public:
    DecompressAction(std::shared_ptr<DataObject> object);
    
    virtual std::shared_ptr<ActionObject> perform();

private:
    std::shared_ptr<DataObject> mObject;
};

#endif
