#include <string>

struct response{
    response(string code, string content_type, string body);
    string code;
    string content_type;
    string body;
}