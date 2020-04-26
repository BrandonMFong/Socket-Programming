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
    char msg[100] = "";
    char* ExitString = "!exit!";

    OpenSocket();
    ConnectSocket();

    while (1)
    {
        puts("[Enter message to send to server]");
        fgets(msg, 100, stdin);

        IsExit(msg); // checks exit string then

        printf("\nYour Message: %s\n", msg);

        // Do stuff to send to server
        SendMessage(msg); // ERROR IS MESSAGE SIZE
        ReceiveMessage();

        ClearString(msg);
    }

    return 0;
}
