#ifndef HTTPCON_H
#define HTTPCON_H

#include <iostream>
#include <string>
#include <curl/curl.h>

class HttpCon {
public:
    HttpCon(const std::string& url);
    ~HttpCon();
    std::string sendGetRequest();
    std::string sendPostRequest(const std::string& data, const std::string& contentType);
    

private:
    CURL* curl;
    static size_t writeCallback(char* ptr, size_t size, size_t nmemb, std::string* userdata);
};

#endif
