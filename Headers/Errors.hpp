#pragma once

enum class ERROR_CODE {
    SOCKET_CREATE = 10000,
    SOCKET_OPTION,
    SOCKET_BIND,
    SOCKET_LISTEN,
    SOCKET_ACCEPT,
    SOCKET_CONNECT,
    SOCKET_SEND,
    SOCKET_RECV,
    SOCKET_CLOSE,
    FILE_NOT_FOUND,
    FILE_NOT_OPEN,
    SERVER_SEND_RESPONSE,
    SERVER_SEND_FILE_RESPONSE,
    SERVER_NOT_FOUND_RESPONSE,
};

inline const char* GET_ERROR_MESSAGE(ERROR_CODE code) {
    switch (code) {
        case ERROR_CODE::SOCKET_CREATE:             return "Socket Error  : Cannot create socket";
        case ERROR_CODE::SOCKET_OPTION:             return "Socket Error  : Cannot set socket options";  
        case ERROR_CODE::SOCKET_BIND:               return "Socket Error  : Cannot bind socket";
        case ERROR_CODE::SOCKET_LISTEN:             return "Socket Error  : Cannot activate socket to listen";
        case ERROR_CODE::SOCKET_ACCEPT:             return "Socket Error  : Cannot accept client connections";
        case ERROR_CODE::SOCKET_CONNECT:            return "Socket Error  : Cannot connect to server";
        case ERROR_CODE::SOCKET_SEND:               return "Socket Error  : Cannot send traffic to connection";
        case ERROR_CODE::SOCKET_RECV:               return "Socket Error  : Cannot receive traffic from connection";
        case ERROR_CODE::SOCKET_CLOSE:              return "Socket Error  : Cannot close socket";
        case ERROR_CODE::FILE_NOT_FOUND:            return "File Error    : File can't be found";
        case ERROR_CODE::FILE_NOT_OPEN:             return "File Error    : File can't be opened";
        case ERROR_CODE::SERVER_SEND_RESPONSE:      return "Server Error  : Failed to send HTTP response";
        case ERROR_CODE::SERVER_SEND_FILE_RESPONSE: return "Server Error  : Failed to send file response";
        case ERROR_CODE::SERVER_NOT_FOUND_RESPONSE: return "Server Error  : Failed to find requested resource";
        default:                                    return "Unknown error";
    }
}