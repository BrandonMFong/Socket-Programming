
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
    if(bind(sock, (struct sockaddr *)&addr, sizeof(struct socketaddr_in)) == -1)
    {
        perror("Error in bind");
        exit(-1);
    }
}

void ListenToSocket()
{
    while(1)
    {
        if(listen(sock, 1) == -1)
        {
            perror("on listen");
            exit(-1);
        }

        addrsize = sizeof(struct sockaddr_in);
        clientsock = accept(sock, ) // TODO continue from here
    }
}


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
