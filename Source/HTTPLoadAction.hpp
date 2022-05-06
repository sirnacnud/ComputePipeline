#ifndef HTTP_LOAD_ACTION_HPP
#define HTTP_LOAD_ACTION_HPP

#include "Action.hpp"

#include <string>

/// Loads a resource from a HTTP request
class HTTPLoadAction: public Action {
public:
    HTTPLoadAction(const std::string& url);
    
    virtual std::shared_ptr<ActionObject> perform();
    
private:
    std::string mURL;
};

#endif
