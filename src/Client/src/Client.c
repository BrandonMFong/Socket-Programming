// M2 sends text
// Volta
/* 
 * Goal is to take user input from here and send it to Server.c
 * 
 */
#include "Client.h"

int main() 
{
    Greetings();
    int x = 0;
    while (1)
    {
        printf("Enter 1 to send: ");
        scanf("%d", &x);
        OpenSocket();
        ConnectSocket();
        SendMessage(); 
        printf("Enter 1 to read server message back: ");
        scanf("%d", &x);
        ReceiveMessage();
        Disconnect();
    }

    return 0;
}
