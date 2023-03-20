#include "httpcon.h"

HttpCon::HttpCon(const std::string& url, const std::string& api_key) {
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        //set authentication header
        auth_header = "Authorization: Bearer " + api_key;

    }
}

HttpCon::~HttpCon() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
}

std::string HttpCon::sendGetRequest() {
    if (curl) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpCon::writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, auth_header.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
            return "";
        }
        return response;
    }
    return "";
}

std::string HttpCon::sendPostRequest(const std::string& data, const std::string& contentType) {
    if (curl) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpCon::writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, auth_header.c_str());
        headers = curl_slist_append(headers, ("Content-Type: " + contentType).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
            return "";
        }
        curl_slist_free_all(headers);
        return response;
    }
    return "";
}

size_t HttpCon::writeCallback(char* ptr, size_t size, size_t nmemb, std::string* userdata) {
    // Calculate the size of the data received
    size_t dataSize = size * nmemb;

    // Append the received data to the string buffer
    userdata->append(ptr, dataSize);

    // Return the size of the data received
    return dataSize;
}