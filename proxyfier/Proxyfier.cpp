//
// Created by adam on 17.03.19.
//

#include "Proxyfier.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>


Proxyfier::Proxyfier(int port, const std::string &address) : port(port), address(address) {
    this->port = port;
    this->address = address;
}

bool Proxyfier::bindTo() {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return false;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, address.c_str(), &serv_addr.sin_addr)<=0)
    {
        return false;
    }
    return true;
}

bool Proxyfier::connectTo() {
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return false;
    }
    return true;
}
