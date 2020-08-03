#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define MAX_BUFFER_SIZE 2048


char web_page[] =
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>\r\n"
"<html><head><title>Image Filter</title>\r\n"
"<style>body {background-color: #FFFF00}</style></head>\r\n"
"<body><center><h1>Image Filter</h1><br>\r\n"
"</center></body></html>\r\n";

static const short TRUE = 1;
static const short FALSE = 0;
static const short PORT = 8080;


int main(int argc, char *argv[])
{
    // Addresses
    struct sockaddr_in server_address, client_address;
    socklen_t sin_len = sizeof(client_address);
    // File descriptor for the server and client
    int fd_server, fd_client;
    // Stores the content sent by the client
    char buffer[MAX_BUFFER_SIZE];
    // File descriptor for the image
    int fd_image;
    int on = 1;

    // Creating socket server
    fd_server = socket(AF_INET, SOCK_STREAM, 0);

    // Checking if something went wrong
    if (fd_server < 0)
    {
        perror("Socket");
        exit(1);
    }

    // Set up the socket properties
    setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));

    // Initialize server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Call bind
    if (bind(fd_server, (struct sockaddr* restrict) &server_address, sizeof(server_address)) == -1)
    {
        perror("Bind error");
        close(fd_server);
        exit(1);
    };

    // Start listening
    if (listen(fd_server, 10) == -1)
    {
        perror("Listening error");
        close(fd_server);
        exit(1);
    }

    printf("Listening in %s:%d\n", inet_ntoa(server_address.sin_addr), htons(server_address.sin_port));

    // Main loop
    while (TRUE)
    {
        // Acept client connection
        fd_client = accept(fd_server, (struct sockaddr*) &client_address, &sin_len);

        // Check if something went wrong
        if (fd_client == -1)
        {
            perror("Client connection failed...\n");
            continue;
        }

        printf("Client connected...\n");

        // Fork process
        if (!fork())
        {
            /* Child process */
            // Close that child process doesnt need it
            close(fd_server);
            // Clear buffer
            memset(buffer, 0, MAX_BUFFER_SIZE);
            // Read message
            read(fd_client, buffer, MAX_BUFFER_SIZE - 1);

            printf("Msg: %s\n", buffer);

            // Send icon
            if (!strncmp(buffer, "GET /favicon.ico", 16))
            {
                fd_image = open("favicon.ico", O_RDONLY);
                sendfile(fd_client, fd_image, NULL, 1500);
                close(fd_image);
            } else
            {
                // Send web page
                write(fd_client, web_page, sizeof(web_page) -1);
            }
            
            close(fd_client);
            printf("Bye client...\n");
            exit(0);
        }

        // Parent process
        close(fd_client);
    }

    return 0;
}
