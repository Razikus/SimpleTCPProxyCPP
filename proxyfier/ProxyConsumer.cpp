//
// Created by adam on 17.03.19.
//

#include <thread>
#include "ProxyConsumer.h"

void ProxyConsumer::consume() {
    proxy.bindTo();
    proxy.connectTo();
    std::thread ptoc(&ProxyConsumer::moveStreamFromTo, this, proxy.sock, client.socket);
    std::thread ctop(&ProxyConsumer::moveStreamFromTo, this, client.socket, proxy.sock);
    ptoc.join();
    ctop.join();
}


ProxyConsumer::ProxyConsumer(ServerClient &client, Proxyfier &proxy) : client(client), proxy(proxy) {}

void ProxyConsumer::moveStreamFromTo(int from, int to) {
    char buffer[8096];
    int ret;
    while((ret = read(from, buffer, sizeof(buffer) -1)) > 0) {
        buffer[ret] = 0x00;
        send(to, buffer, ret, 0);
    }

}

