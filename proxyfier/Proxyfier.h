//
// Created by adam on 17.03.19.
//

#ifndef SOCKETER_PROXY_H
#define SOCKETER_PROXY_H
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
class Proxyfier {
public:
    int port;
    std::string address;
    struct sockaddr_in serv_addr;
    int sock;

    Proxyfier(int port, const std::string &address);
    bool bindTo();
    bool connectTo();

};


#endif //SOCKETER_PROXY_H
