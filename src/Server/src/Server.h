
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int sock, clientsock, mlen, addrsize, msgct, chc, chct;
struct sockaddr_in addr;
char ch, buf[80];

void Dorev(char * string, int begin, int end) // recurse 
{
    char temp;
    if (begin >= end) return;

    temp = string[begin];
    string[begin] = string[end];
    string[end] = temp;
    Dorev(string, ++begin, --end);
}

void ReverseString(char * message)
{
    Dorev(message,0, strlen(message) - 1);
}

void OpenSocket()
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        perror("Error in opening socket");
        exit(-1);
    }
}

void BindSocket()
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5022);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
    {
        perror("Error in bind");
        exit(-1);
    }
}

void InitListen()
{
    if(listen(sock, 1) == -1)
    {
        perror("Error on listen");
        exit(-1);
    }
}

void AcceptClientConnection()
{
    addrsize = sizeof(struct sockaddr_in);
    clientsock = accept(sock, (struct sockaddr *)&addr, &addrsize); // TODO continue from here
    if(clientsock == -1)
    {
        perror("Error on accept");
        exit(-1);
    }

    printf("Connection made with client %s\n", inet_ntoa(addr.sin_addr));
}

void ReceiveMessage()
{
    recv(clientsock, buf, 80, 0);
    printf("Client message: %s\n",buf ); 
}

void SendMessage()
{
    ReverseString(buf);
    send(clientsock, buf , 80, 0);
}

void Disconnect()
{
    close(clientsock);
    // close(sock);
}


