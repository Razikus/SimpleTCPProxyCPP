#include <iostream>
#include "server/Server.h"
#include "proxyfier/ProxyConsumer.h"
#include <thread>
template <typename T>
void print(const T &t) {
    std::cout << t << std::endl;
}

//Usage proxyfier onPort proxyPointPort proxyPointIP

int main(int argc, char *argv[]) {
    int port = atoi(argv[1]);
    int proxyPort = atoi(argv[2]);
    const char* ip = argv[3];
    Server* s = new Server(port);
    if(s->bindTo()) {
        s->startListening(10);
        while(true) {
            print("Accepting new connection...");
            ServerClient sock = *s->acceptConnection();
            Proxyfier proxyfier(proxyPort, ip);
            print("Connection accepted...");
            ProxyConsumer consumer(sock, proxyfier);
            print("Starting proxy thread...");
            std::thread{&ProxyConsumer::consume, &consumer}.detach();
            print("Thread supervisor started!");
        }

    }
    return 0;
};

