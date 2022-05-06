#ifndef BUNDLE_LOAD_ACTION_HPP
#define BUNDLE_LOAD_ACTION_HPP

#include "Action.hpp"

#include <string>

/// Action to load a bundle from disk
class BundleLoadAction: public Action {
public:
    BundleLoadAction(const std::string& url);
    
    virtual std::shared_ptr<ActionObject> perform();
    
private:
    std::string mURL;
};

#endif
