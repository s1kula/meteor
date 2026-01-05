#ifndef METEOR_HTTP_DATA 
#define METEOR_HTTP_DATA

#include <cstdint>
#include <string>
#include <unordered_map>

struct file {
    std::string contentDisposition; 
    std::string name; 
    std::string filename;
    std::string contentType;
    std::string binary;
};

struct httpData{
    uint16_t method;
    std::string path;
    uint16_t protocol;
    std::unordered_map<std::string, std::string> headers;
    std::unordered_map<std::string, std::string> parameters;
    std::unordered_map<std::string, file> files;
};

#endif