#include "FileLoadAction.hpp"

#include "DataObject.hpp"

static const char* BMP_EXT = ".bmp";
static const char* BZIP_EXT = ".bzip";
static const char* BZIP2_EXT = ".bzip2";
static const char* GIF_EXT = ".gif";
static const char* JPG_EXT = ".jpg";
static const char* JSON_EXT = ".json";
static const char* PNG_EXT = ".png";

FileLoadAction::FileLoadAction(const std::string& url)
    : mURL(url)
{
}

std::shared_ptr<ActionObject> FileLoadAction::perform() {
    // Load file from filesystem
    // ...
    MimeType mimeType = determineMimeType(mURL);
    std::shared_ptr<unsigned char[]> loadedData;
    size_t dataLength = 1000;
    
    return std::shared_ptr<DataObject>(new DataObject(mURL, mimeType, loadedData, dataLength));
}

MimeType FileLoadAction::determineMimeType(const std::string& url) {
    if (doesExtensionMatch(url, BMP_EXT)) {
        return BMP;
    } else if (doesExtensionMatch(url, BZIP_EXT)) {
        return BZIP;
    } else if (doesExtensionMatch(url, BZIP2_EXT)) {
        return BZIP2;
    } else if (doesExtensionMatch(url, GIF_EXT)) {
        return GIF;
    } else if (doesExtensionMatch(url, JPG_EXT)) {
        return JPG;
    } else if (doesExtensionMatch(url, JSON_EXT)) {
        return JSON;
    } else if (doesExtensionMatch(url, PNG_EXT)) {
        return PNG;
    } else {
        return BIN;
    }
}
    
bool FileLoadAction::doesExtensionMatch(const std::string& url, const char* extension) {
    size_t extensionLength = strlen(extension);
    size_t urlLength = url.length();
    
    return (url.compare((urlLength - extensionLength), extensionLength, extension) == 0);
}
