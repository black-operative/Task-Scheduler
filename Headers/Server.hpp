/*** Include Guards ***/

#pragma once
#ifndef SERVER
#define SERVER

/*** Includes ***/

// #include "../Headers/Header.hpp"
#include <string>
#include <fstream>
#include <netinet/in.h>

// #include 

/*** Data ***/

using std::string;
using std::ifstream;

#define PORT 3000   

struct  HTTP_Response {
    string header;
    string content_type;
    string body;
};

/*** Data ***/

class HTTP_Server {
    private:
        int                server_socket_fd = -1;
        int                client_socket_fd = -1;
        struct sockaddr_in server_addr;
        socklen_t          server_addr_len;
        HTTP_Response      response;
        ifstream           file_reader;
        string             file_path;

    public:
        int  init_server();
        int  start_server();
        void accept_client();
        void handle_client();
        int  send_response();
        int  send_file_res();
        int  not_found_res();
        int  illegal_method_res();
        void close_server();
};

#endif