#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

char* ExitString = "!exit!";
int sock, addrsize;
struct sockaddr_in * addr;
char buf[80];

void ClearString(char* string)
{
	memset(string, 0, strlen(string));
}

void Greetings()
{
	printf("\n\nWelcome, enter '!exit!' to exit the program when prompted.\n\n");
}

void IsExit(char* string)
{
	if (strstr(string, ExitString) != NULL)
	{
		printf("\nExiting program!\n"); exit(0);
	}
}

void OpenSocket()
{
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == -1)
	{
		perror("Error occured at opening socket function...\n");
		exit(-1);
	}
}

void ConnectToInternet()
{
	addr.sin_family = AF_INET;
	addr.sin_port = htons(32351);
	addr.sin_addr.s_addr = inet_network("153.90.192.3");
	if(connect(sock, &addr, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Error occured on connect");
		exit(-1);
	}
}

