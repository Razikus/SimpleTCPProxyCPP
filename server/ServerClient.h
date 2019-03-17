//
// Created by adam on 17.03.19.
//

#ifndef SOCKETER_SERVERCLIENT_H
#define SOCKETER_SERVERCLIENT_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


class ServerClient {
public:
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int socket;
    ServerClient();
};


#endif //SOCKETER_SERVERCLIENT_H
