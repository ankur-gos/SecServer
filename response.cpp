#include "response.h"


response::response(string code, string content_type, string body){
    this->code = code;
    this->content_type = content_type;
    this->body = body;
}

string response::generate_response(){
    vector<string> strs;
    strs.push_back("HTTP/1.1 ");
    strs.push_back(code);
    string hdr_msg;
    switch(code.front()){
    case '2':
        hdr_msg = "Success";
    default:
        hdr_msg = "Failure";
    }
    strs.push_back(hdr_msg);
    strs.push_back(" \r\n");
    strs.push_back("Content-Type: ");
    strs.push_back(content_type);
    strs.push_back("\r\n\r\n");
    strs.push_back(body);
    reverse(strs.begin(), strs.end());
    return string_util().vector_concat(strs);
}