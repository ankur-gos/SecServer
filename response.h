#include <string>
#include <vector>
#include <algorithm>
#include "string_util.h"

struct response{
    string code;
    string content_type;
    string body;

    response(string code, string content_type, string body);
    string generate_response();
};