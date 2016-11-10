#include <string>
#include <vector>

struct response{
    string code;
    string content_type;
    string body;

    response(string code, string content_type, string body);
    string generate_response();
}