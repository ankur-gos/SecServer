response::response(string code, string content_type, string body){
    this->code = code;
    this->content_type = content_type;
    this->body = body;
}

response::generate_response(){
    vector<string> strs = new vector<string>();
    strs.push_back("HTTP/1.1 ");
    resp.append(code);
    string hdr_msg;
    switch(code.front()){
    case '2':
        hdr_msg = "Success";
    default:
        hdr_msg = "Failure";
    }
    resp.append(" ");
    resp.append()
}