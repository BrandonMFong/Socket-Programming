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
struct sockaddr_in addr; //https://www.daniweb.com/programming/software-development/threads/223615/socket-programming-error
const struct sockaddr_in  * casted_addr = (struct sockaddr_in  * ) &addr;
char buf[80];


void OpenSocket()
{
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock == -1)
	{
		perror("Error occured at opening socket function...\n");
		exit(-1);
	}
}

void ConnectSocket()
{
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("130.191.166.3");
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Error occured on connect");
		exit(-1);
	}
}

void SendMessage(char msg[100])
{
	send(sock, msg, 38, 0);
}

void ReceiveMessage()
{
	recv(sock, buf, 80, 0);
}

void CloseSocketConnection()
{
	// Shutdown
	if(shutdown(sock, 1) == -1)
	{
		perror("Error on Shutdown");
		exit(-1);
	}
	printf("Client is done \n");
	close(sock);
}

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
		printf("\nExiting program!\n"); 
		CloseSocketConnection();
		exit(0);
	}
}

