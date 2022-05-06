#ifndef FILE_LOAD_ACTION_HPP
#define FILE_LOAD_ACTION_HPP

#include "Action.hpp"
#include "MimeType.hpp"

#include <string>

/// Loads a file from the file system
class FileLoadAction: public Action {
public:
    FileLoadAction(const std::string& url);
    
    virtual std::shared_ptr<ActionObject> perform();
    
private:
    MimeType determineMimeType(const std::string& url);
    bool doesExtensionMatch(const std::string& url, const char* extension);
    
private:
    std::string mURL;
};

#endif
