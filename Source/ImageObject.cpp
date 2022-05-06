#include "ImageObject.hpp"

ImageObject::ImageObject(const std::string& url, MimeType mimeType, std::shared_ptr<unsigned char[]> data, size_t length, unsigned int width, unsigned int height, unsigned int bytesPerPixel)
    : DataObject(url, mimeType, data, length)
    , mWidth(width)
    , mHeight(height)
    , mBytesPerPixel(bytesPerPixel)
{
}

unsigned int ImageObject::width() const {
    return mWidth;
}

unsigned int ImageObject::height() const {
    return mHeight;
}

unsigned int ImageObject::bytesPerPixel() const {
    return mBytesPerPixel;
}
