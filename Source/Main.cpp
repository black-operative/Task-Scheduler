#include <iostream>
#include <memory>
#include <csignal>

#include "../Headers/Server.hpp"

using std::cout;
using std::endl;

std::unique_ptr<HTTP_Server>server = nullptr;

void exit_signal_handle(int signal) {
    if (signal == SIGINT) {
        cout << "\nServer shutting down..." << endl;
        server->close_server();
        cout << "Server shutdown complete." << endl;
        exit(EXIT_SUCCESS);
    }
}

int main() {
    std::signal(SIGINT, exit_signal_handle);

    server = std::make_unique<HTTP_Server>();

    int status_code = 0;

    status_code = server->init_server();
    if (status_code < 0) { return EXIT_FAILURE; }
    status_code = server->start_server();
    if (status_code < 0) { return EXIT_FAILURE; }
    server->accept_client();
    return EXIT_SUCCESS;
}