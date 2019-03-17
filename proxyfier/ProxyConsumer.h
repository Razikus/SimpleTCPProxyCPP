//
// Created by adam on 17.03.19.
//

#ifndef SOCKETER_PROXYCONSUMER_H
#define SOCKETER_PROXYCONSUMER_H

#include <iostream>
#include "../server/ServerClient.h"
#include "Proxyfier.h"

class ProxyConsumer {
public:
    ServerClient& client;
    Proxyfier& proxy;
    void consume();
    void moveStreamFromTo(int from, int to);
    ProxyConsumer(ServerClient &client, Proxyfier &proxy);
};


#endif //SOCKETER_PROXYCONSUMER_H
