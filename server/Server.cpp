//
// Created by adam on 17.03.19.
//

#include <iostream>
#include "Server.h"

bool Server::bindTo() {
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return false;
    }
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return false;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        return false;
    }
    return true;
}

Server::Server(int port) : port(port) {
    this->port = port;
}

bool Server::startListening(int queue) {
    if (listen(server_fd, queue) < 0) {
        perror("listen");
        return false;
    }
    return false;
}

ServerClient* Server::acceptConnection() {
    ServerClient* client = new ServerClient();
    int new_socket = -1;
    if ((new_socket = accept(server_fd, (struct sockaddr *) &client->address, (socklen_t *) &client->addrlen)) < 0) {
        return nullptr;
    }
    client->socket = new_socket;
    return client;
}

//valread = read( new_socket , buffer, 1024);
//printf("%s\n",buffer );
//send(new_socket , hello , strlen(hello) , 0 );
//printf("Hello message sent\n");