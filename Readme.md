# Task Scheduler

This project is an extension of the [Generic HTTP Server in C++ Project](https://github.com/black-operative/Generic-HTPP-Server-in-CPP) and it aims to create a simple, minimalist and generic task scheduling application which uses a built in HTTP server using C++.

## Installation

You can use the following methods to clone this repo to your local machine :

1. HTTP Clone

    ```bash
    git clone https://github.com/rudrakshm64/Generic-HTTP-Server-In-C.git
    ```

2. GitHub Desktop
    - File
        - `Alt + f`
    - Clone Repository  
        - `Alt + f` + `n`
        - `Ctrl + Shift + O`
    - URL Tab
    - Repo URL ***or*** Username + Repo name :  
        - `https://github.com/rudrakshm64/Generic-HTTP-Server-In-C.git`
        - `rudrakshm64/Generic-HTTP-Server-In-C`
    - Local Path, pick any location that you want

3. GitHub CLI

    ```bash
    gh repo clone rudrakshm64/Generic-HTTP-Server-In-C
    ```

## Features

- [**OOP**](https://en.wikipedia.org/wiki/Object-oriented_programming) Architecture
- [**POSIX / UNIX**](https://en.wikipedia.org/wiki/Unix_domain_socket) Socket architecture
- [**IPV4**](https://en.wikipedia.org/wiki/IPv4) Protocol
- [**GNU/Linux**](https://en.wikipedia.org/wiki/Linux) Runtime Environment
- Static Website hosting

## Code Organization

The Project is divided into 4 Parts :

- ### Header Files

- ### Source Files

- ### Build Files

- ### Static Website Files

## Class Structure

The class which is used to implement the Object Oriented Approach to the project has the following structure :

### Private Properties

```plaintext
- server_socket_fd : Socket file descriptor for server
- client_socket_fd : Socket file descriptor for client
- server_addr      : Server Address structure
- server_addr_len  : Server Address structure length
- response         : HTTP response structure
- file_reader      : Input File stream for file reading
- file_path        : Path to file
```

### Public Methods (Brief)

This sections briefly shows and explains the available Methods defined in the HTTP_Server class. The entire documentation is available in the [Extended Section](#public-methods-extended)

```plaintext
- init_server()        -> Initializes the basic configurations for server
- start_server()       -> Starts the server for active connections
- accept_client()      -> Accepts a client connection for providing services
- handle_client()      -> Handles an established client connection and provides services 
- send_response()      -> Sends an HTTP response with appropriate formatting
- send_file_res()      -> Sends the content of a file as an HTTP response
- not_found_res()      -> Returns HTTP Error 404 : Not Found Page to client
- illegal_method_res() -> Returns HTTP Error 405 : Method Not Allowed Page to client
- close_server()       -> Closes active connections and shuts down the server
```

## Custom Datatype

`HTTP_Response` is a structure containing the 3 required components of an HTTP response. It was created to simplify the process of creating a response object to send over the network.

```cpp
struct HTTP_Response {
    string header;
    string content_type;
    string body;
};
```

`HTTP_Response` is a C++ Structure that contains 3 string properties:
<pre>
<code>- header       : Defines <a href = "https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Evolution_of_HTTP">HTTP Version</a> to be used and <a href = 'https://developer.mozilla.org/en-US/docs/Web/HTTP/Status'>HTTP Response status code</a>
- content_type : Defines type of content being sent using HTTP response according to <a href = 'https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types'>Media / MIME Types</a>
- body         : Content to be sent using HTTP response
</code>
</pre>

## Macro Definitions

The following macro definitions are used in the project :

```plaintext
-> BUFFER_SIZE          16384                                  - 16 Kilo Bytes         
-> CONTENT_HTML         "text/html"                            - HTTP Request : content Type HTML
-> CONTENT_CSS          "text/css"                             - HTTP Request : content Type CSS  
-> CONTENT_JS           "application/javascript"               - HTTP Request : content Type JavaScript
-> HTTP_STATUS_OK_200   "HTTP/1.1 200 OK\r\n"                  - HTTP 200 OK Response Header
-> HTTP_STATUS_ERR_404  "HTTP/1.1 404 NOT FOUND\r\n"           - HTTP 404 Not Found Response Header
-> HTTP_STATUS_ERR_405  "HTTP/1.1 405 METHOD NOT ALLOWED\r\n"  - HTTP 405 Method Not Allowed Response Header
```

## StdLib Functions / Data Structures used

### 1. socket()

```c
int socket(int domain, int type, int protocol)
```

Creates a socket :

- **Domain   :** Communication domain type eg : AF_INET : IPV4 type Domain to use
- **Type     :** Socket type to use        eg : TCP / UDP / RAW etc
- **Protocol :** Protocol for socket ops   eg : 0 for default TCP/IP
- Returns fle descriptor for new socket created

### 2. sockaddr_in

```c
struct sockaddr_in {
    sin_family;
    sin_port;
    sin_addr;
}
```

Contains information about protocol types, address usage and requested subnet :

- **sin_family :** Communications domain type eg : AF_INET : IPV4 type Domain to use
- **sin_port   :** Port number in Network byte order (BIG  ENDIAN i.e. First number stored first. Need to convert this to LITTLE ENDIAN i.e. Last number stored first, for CPU Execution)
- **sin_addr   :** IP Address for socket, changes depending on connection type (WiFi / Ethernet)
- ***Note*** : Data Structure used for server_addr Private property

### 3. bind()

```c
int bind(int socket, const struct sockaddr *address, socklen_t address_len)
```

Allots network port to a socket for communication :

- **socket**      : Socket file descriptor value
- **address**   : Address of sockaddr struct type to interpret domain, protocol and address types (GPIO considerate measure)
- **address_len** : Length of address struct before hand
- Returns status (0 for successful, -1 for failure)

### 4. listen()

```c
int listen(int socket, int backlog)
```

Opens socket at network port alloted to certain number of connections

- **socket  :** Socket file descriptor value
- **backlog :** Max number of connections the socket can accept
- Returns status (0 for successful, -1 for failure)

### 5. accept()

Allows connection from client to socket listening at alloted network port :

```c
int accept(int socket, struct sockaddr *_Nullable restrict address, socklen *_Nullable restrict address_len)
```

- **socket      :** Socket file descriptor value
- **address     :** Address of sockaddr struct type from client with limited access
- **address_len :** Length of address struct passed before hand
- Returns file descriptor for accepted socket or -1 on failure

### 6. recv()

Reads messages received on target socket into target buffer

```c
size_t recv(int socket, void buffer[], size_t buffer_len, int flags)
```

- **socket :** Socket to receive messages from
- **buffer :** Message buffer to store received message data into
- **buffer_len :** Message buffer length
- **flags :**  Control flags to be used when receiving messages
- Returns the number of bytes received from the socket or -1 on failure

### 7. sscanf()

Parses and scans formatted input according to desired format :

```c
int sscanf(const char *target, const char *restrictor_format, char *destination1, char *destination2,......)
```

- **target :** Buffer to scan
- **restrictor_format :** Required format to scan and match required segments
- **destination1, destination2, destination3, ..... :** Series of buffers, where the results must be stored
- Returns number of items successfully matched from **buffer** and stored in **destination buffers**

### 8. snprintf()

Formats and stores a series of characters into a buffer, with an upper bound on the number of characters written:

```c
int snprintf(char *buffer, size_t buffer_size, const char *format, char *destination1, char *destination2,......)
```

- **buffer :** Destination Buffer where the formatted output will be stored.
- **buffer_size :** The maximum number of characters to write, including  null-terminator (`'\0'`).
- **format :** The format string specifying how to format the output (similar to `printf`).
- **destination1, destination2, destination3, ..... :** Series of buffers containing values to be formatted according to the format string.
- Returns number of characters written to buffer. If this value is less than `buffer_size` : successful write and if this value is more, then output was truncate.

### 9. send()

Sends a message to target socket in connected state :

```c
size_t send(int socket, const void buffer[], size_t buffer_len, int flags)
```

- **socket :** Socket file descriptor value
- **buffer :** Buffer containing the message to be sent
- **buffer_len :** Length of the buffer containing the message
- **flags :** Control flags used to control the send operation
- Returns number of bytes on success, -1 on failure.

### 10. std::ifstream::open()

Opens the file identified by the provided argument :

```cpp
void open(const string& file_name, ios_base::openmode mode = ios_base::in)
```

- **file_name :** Name of the file to be opened.
- **mode** : Mode in which to open the file (By default file is open in read).
- Does ***NOT*** return any status code. Must use [```std::ifstream::is_open()```](#11-stdifstreamis_open) to check for operation status.

### 11. std::ifstream::is_open()

Returns whether the input file stream currently has a file open for operations :

```cpp
bool is_open() const
```

- Returns `True` if a file is open for operations, `False` otherwise.

### 12. std::getline()

Reads strings from target input stream and stores them in a buffer :

```cpp
istream& getline(istream& input_stream, string& str)
```

- **input_stream :** istream object from which characters are read
- **str :** string to store read characters into (Will replace all the contents already in str).
- Returns `input_stream` itself, sets internal state flags appropriately upon success / failure.

### 13. std::ifstream::close()

Closes the file currently open for operations by an ifstream object :

```cpp
void close()
```

- Does ***NOT*** return any status code. Must use [```std::ifstream::is_open()```](#11-stdifstreamis_open) to check for operation status.

### 14. close()

Closes any required and open process / file / directory using OS file descriptors :

```c
int close(int file_descriptor)
```

- **file_descriptor :** Target / Process to close
- Returns status (0 for successful, -1 for failure)

## Public Methods (Extended)

### 1. HTTP_Server::init_server()

Initializes the HTTP_Server instance with basic configurations.

```cpp
int init_server()
```

- Creates a new socket by invoking [`socket()`](#1-socket).
- Stores created socket information in [`HTTP_Server::server_socket_fd`](#private-properties).
- Initializes [`HTTP_Server::server_addr`](#private-properties) structure.
- Returns status (0 for successful, -1 for failure)

### 2. HTTP_Server::start_server()

Starts server for accepting HTTP requests from clients.

```cpp
int start_server()
```

- Binds [`HTTP_Server::server_socket_fd`](#private-properties) to port `3000` using [`HTTP_Server::server_addr`](#private-properties) structure by invoking [`bind()`](#3-bind).
- Enables server wait for connections by invoking [`listen()`](#4-listen).
- Returns status (0 for successful, -1 for failure)

### 3. HTTP_Server::accept_client()

Accepts connections from clients to server for serving requests.

```cpp
void accept_client()
```

- Accepts connections from clients by invoking [`accept()`](#5-accept).
- Stores client information in [`HTTP_Server::client_socket_fd`](#private-properties).
- Checks if the connection was established.
- Invokes [`HTTP_Server::handle_client()`](#4-http_serverhandle_client).
- Does NOT return any status code.

### 4. HTTP_Server::handle_client()

Handles client connections and process HTTP requests from clients.

```cpp
void handle_client()
```

- Reads client requests by invoking [`recv()`](#6-recv).
- Extracts HTTP headers (Method, Path, Version) from the request buffer by invoking [`sscanf()`](#7-sscanf).
- Checks for valid HTTP Method supported (i.e. `GET`).
- Sets `HTTP_Server::file_path` private property to appropriate request path.
- Invokes [`HTTP_Server::send_file_res()`](#3-send_file_res).
- Does NOT return any status code.

### 5. HTTP_Server::send_response()

Constructs and sends HTTP responses to client socket. Responses consist of HTTP header, content and body

```cpp
int send_response()
```

- Formats an HTTP Response header using [`HTTP_Server::response`](#private-properties) structure.
- Formats an HTTP Response body using [`HTTP_Server::response`](#private-properties) structure.
- Sends the HTTP Response header and body by invoking [`send()`](#9-send).
- Returns status (0 for successful, -1 for failure).

### 6. HTTP_Server::send_file_res()

Sends the content of a requested file as an HTTP response with [appropriate headers](#macro-definitions) and formatting.

```c
int send_file_res()
```

- Performs checks and opens file at `HTTP_Server::file_path` using `HTTP_Server::file_reader`.
- Extracts content from file by invoking [`getline()`](#12-stdgetline).
- Sets `HTTP_Server::response` structure with [appropriate headers](#macro-definitions) and content data.
- Invokes [`HTTP_Server::send_response()`](#5-http_serversend_response).
- Closes file open in `HTTP_Server::file_reader` using [`close()`](#13-stdifstreamclose).
- Returns status (0 for successful, -1 for failure)

### 7. HTTP_Server::not_found_res()

Constructs and sends an Error 404 Not Found HTTP response to client socket.

```c
int not_found_res()
```

- Sets `HTTP_Server::response` structure with [appropriate headers](#macro-definitions) and content data.
- Invokes [`HTTP_Server::send_response()`](#5-http_serversend_response).
- Returns status (0 for successful, -1 for failure)

### 8. illegal_method_res()

Constructs and sends a Error 405 Method not allowed HTTP response to client socket.

```c
int illegal_method_res() 
```

- Sets `HTTP_Server::response` structure with appropriate headers and content data.
- Invokes [`HTTP_Server::send_response()`](#5-http_serversend_response).
- Returns status (0 for successful, -1 for failure)

### 9. HTTP_Server::close_server()

Closes all active connections, frees occupied TCP/IP Port and shuts down the server.

- Invokes [`close()`](#14-close) on `HTTP_Server::client_socket_fd`.
- Invokes [`close()`](#14-close) on `HTTP_Server::server_socket_fd`.
- Clears `HTTP_Server::server_addr` structure.
- Checks and closes any files open in `HTTP_Server::file_reader`.
- Does NOT return any status code.
