#ifndef HATH_HTTPREQUEST_H
#define HATH_HTTPREQUEST_H

#include <string>
#include <map>
#include <memory>
#include <vector>

#include "util.h"
#include "URL.h"

class HTTPRequest : public std::enable_shared_from_this<HTTPRequest>
{
public:
    typedef std::map<std::string, std::string, ci_less> header_map;

    HTTPRequest(std::string method = "", std::string url = "", header_map headers = header_map{}, std::vector<char> body = {}, bool upgrade = false);

    std::shared_ptr<HTTPRequest> header(std::string field, std::string value);

    std::vector<char> toHTTP();

    std::string method;
    URL url;
    header_map headers;
    std::vector<char> body;

    bool upgrade;
};

#endif //HATH_HTTPREQUEST_H
