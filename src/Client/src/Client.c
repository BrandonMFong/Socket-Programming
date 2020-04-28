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
    while (1)
    {
        PutMessage();
        OpenSocket();
        ConnectSocket();
        SendMessage(); 
        ReceiveMessage();
        Disconnect();
    }
    return 0;
}
