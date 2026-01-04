#ifndef METEOR_HTTP_PARSER
#define METEOR_HTTP_PARSER

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <ostream>
#include <string>
#include <locale>
#include <iostream>
#include <unordered_map>

#include "macros.hpp"
#include "http_data_struct.hpp"

void parameters_parsing(const std::string& parameters, std::unordered_map<std::string, std::string>& output){
    if(parameters != ""){
            uint32_t lastSpaceParameters = 0;
            uint32_t nextSpaceParameters = 0;

            while(true){
                bool flagBreak;

                nextSpaceParameters = parameters.find("=", lastSpaceParameters); 

                std::string key = parameters.substr(lastSpaceParameters, nextSpaceParameters - lastSpaceParameters);

                if (parameters.find("&", nextSpaceParameters) == std::string::npos){
                    lastSpaceParameters = nextSpaceParameters;
                    nextSpaceParameters = parameters.size();
                    flagBreak = true;
                } else {
                    lastSpaceParameters = nextSpaceParameters;
                    nextSpaceParameters = parameters.find("&", lastSpaceParameters);
                    flagBreak = false;
                }

                std::string value = parameters.substr(lastSpaceParameters + 1, nextSpaceParameters - lastSpaceParameters - 1);

                output[key] = value;

                lastSpaceParameters = nextSpaceParameters + 1;

                if (flagBreak){
                    break;
                }
            }
        }
}

void parsing(const std::string& input, httpData* data){
    uint32_t lastSpace = input.find(" ");
    uint32_t nextSpace;

    //parser method

    std::string method = input.substr(0, lastSpace);

    if(method == "GET"){
        data->method = GET;
    } 
    else if (method == "POST"){
        data->method = POST;
    } 
    else if (method == "PUT"){
        data->method = PUT;
    } 
    else if (method == "DELETE"){
        data->method = DELETE;
    }
    else if (method == "PATCH"){
        data->method = PATCH;
    }
    else if (method == "OPTIONS"){
        data->method = OPTIONS;
    }
    else if (method == "HEAD"){
        data->method = HEAD;
    }
    else if (method == "CONNECT"){
        data->method = CONNECT;
    }
    else if (method == "TRACE"){
        data->method = TRACE;
    } else {
        data->method = 0;
    }

    //parser path

    if ( input.find("?") == std::string::npos || input.find("?", lastSpace) > input.find(" ", lastSpace+1) ){
        nextSpace = input.find(" ", lastSpace+1);
    } else {
        nextSpace = input.find("?", lastSpace);
    }

    std::string path = input.substr(lastSpace + 1, nextSpace - lastSpace - 1);
    data->path = path;

    //parser GET parameters

    if (data->method == GET){
        lastSpace = nextSpace;
        nextSpace = input.find(" ", lastSpace+1);

        parameters_parsing(input.substr(lastSpace + 1, nextSpace - lastSpace - 1), data->parameters);
    }
    
    //parser protocol

    lastSpace = nextSpace;
    nextSpace = input.find("\r\n", lastSpace);

    std::string protocol = input.substr(lastSpace + 1, nextSpace - lastSpace - 1);

    if (protocol == "HTTP/1.0"){
        data->protocol = HTTP10;
    }    
    if (protocol == "HTTP/1.1"){
        data->protocol = HTTP11;
    }
    if (protocol == "HTTP/2"){
        data->protocol = HTTP2;
    }
    if (protocol == "HTTP/3"){
        data->protocol = HTTP3;
    }

    //parser header

    while (true) {
        lastSpace = nextSpace + 2;
        nextSpace = input.find("\r\n", lastSpace);
        if(lastSpace == nextSpace){
            break;
        }
        std::string header = input.substr(lastSpace, nextSpace - lastSpace);
        
        std::string key = header.substr(0, header.find(":"));
        std::string value = header.substr(header.find(" ")+1, header.size() - header.find(" ") - 1);

        data->headers[key] = value;
    }

    // parser POST html-form

    if (data->method == POST && data->headers["Content-Type"] == "application/x-www-form-urlencoded"){
        lastSpace = nextSpace+2;
        nextSpace = input.find("\r\n", lastSpace);
        parameters_parsing(input.substr(lastSpace, nextSpace-lastSpace), data->parameters);
    }
}

#endif