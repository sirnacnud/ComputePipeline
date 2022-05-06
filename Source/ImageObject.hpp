#ifndef IMAGE_OBJECT_HPP
#define IMAGE_OBJECT_HPP

#include "DataObject.hpp"

/// Decoded Image
class ImageObject : public DataObject {
public:
    ImageObject(const std::string& url, MimeType mimeType, std::shared_ptr<unsigned char[]> data, size_t length, unsigned int width, unsigned int height, unsigned int bytesPerPixel);
    
    /// Width of image
    unsigned int width() const;
    
    /// Height of image
    unsigned int height() const;
    
    /// Bytes per pixel of image
    unsigned int bytesPerPixel() const;

private:
     unsigned int mWidth;
     unsigned int mHeight;
     unsigned int mBytesPerPixel;
};

#endif
