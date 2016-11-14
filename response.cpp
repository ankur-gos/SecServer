#include "response.h"


response::response(string code, string content_type, string body){
    this->code = code;
    this->content_type = content_type;
    this->body = body;
}

string response::generate_response(){
    vector<string> strs = new vector<string>();
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
    resp.append(" \r\n");
    resp.append("Content-Type: ");
    resp.append(content_type);
    resp.append("\r\n\r\n");
    resp.append(body);
    return string_util().vector_concat(reverse(strs.begin(), strs.end()));
}