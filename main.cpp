#include <iostream>

using namespace std;

/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include "response.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1000];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    for (;;)
    {
        newsockfd = accept(sockfd,
                           (struct sockaddr *)&cli_addr,
                           &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");
        auto pid = fork();
        if (pid < 0)
        {
            error("Error on fork");
        }
        if (pid == 0)
        {
            close(sockfd);
            bzero(buffer, 1000);
            n = read(newsockfd, buffer, 999);
            if (n < 0)
                error("ERROR reading from socket");
            printf("Here is the message: %s\n", buffer);
            response* resp = new response("200", "text/html", "Hello world!");
            string resp_str = resp->generate_response();
            cout << resp_str;
            n = write(newsockfd, resp_str.c_str(), resp_str.length());
            if (n < 0)
                error("ERROR writing to socket");
            close(newsockfd);
            exit(0);
        }
        else
        {
            close(newsockfd);
        }
    }
    close(sockfd);
    return 0;
}