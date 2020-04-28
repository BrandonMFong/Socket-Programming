#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "config.h"


char* ExitString = "!exit!";
int sock, addrsize;
struct sockaddr_in addr; //https://www.daniweb.com/programming/software-development/threads/223615/socket-programming-error
const struct sockaddr_in  * casted_addr = (struct sockaddr_in  * ) &addr;
char buf[MsgSize];
ssize_t bytes_read = 0;

void Disconnect()
{
	// Shutdown
	if(shutdown(sock, 1) == -1)
	{
		perror("Error on Shutdown");
		exit(-1);
	}
	printf("Closed connection\n\n");
	close(sock);
}

void IsExit(char* string)
{
	if (strstr(string, ExitString) != NULL)
	{
		printf("\nExiting program!\n"); 
		Disconnect();
		exit(0);
	}
}

void PutMessage()
{
	FILE *MessageFile = fopen(".\\Message.txt", "w"); // write only 
	char msg[MsgSize];
	printf("Enter Message: ");
	fgets(msg, MsgSize, stdin);
	IsExit(msg);
	fwrite(msg , 1 , sizeof(msg) , MessageFile );
	fclose(MessageFile);
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

void ConnectSocket()
{
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PortNum);
	addr.sin_addr.s_addr = inet_addr(JasonIPAddress);
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
	{
		perror("Error occured on connect");
		exit(-1);
	}
}

void GetMessage(char * str)
{
	FILE *MessageFile = fopen(".\\Message.txt", "r"); // read only 
	fseek(MessageFile, 0, SEEK_SET);
	fread(str, MsgSize, 1, MessageFile);
	fclose(MessageFile);
}

void SendMessage()
{
	GetMessage(buf);
	send(sock, buf, MsgSize, 0);
}

void ReceiveMessage()
{
	recv(sock, buf, 80, 0);
    printf("\n\nServer message: %s\n\n",buf ); 
}


void ClearString(char* string)
{
	memset(string, 0, strlen(string));
}

void Greetings()
{
	printf("\n\nWelcome, enter '!exit!' to exit the program when prompted.\n\n");
}
