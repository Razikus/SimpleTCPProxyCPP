//
// Created by adam on 17.03.19.
//

#ifndef SOCKETER_SERVER_H
#define SOCKETER_SERVER_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "ServerClient.h"

class Server {
    private:
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    int new_socket;
    int valread;
    int port;
public:
    Server(int port);

public:
    bool bindTo();
    bool startListening(int queue);
    ServerClient* acceptConnection();

};


#endif //SOCKETER_SERVER_H
