// M1 receives text
// Jason
// must use gcc Server.c -lnsl -lsocket -lresolv to compile
// https://cboard.cprogramming.com/cplusplus-programming/128326-undefined-symbol-when-compiling-socket-program.html

#include "Server.h"

int main() 
{
    char msg[100] = "";

    // ReverseString(msg);

    // printf("%s", msg);

    OpenSocket();
    BindSocket();
    
    InitListen();
    AcceptClientConnection();

    ReceiveMessage();
    SendMessage();

    Disconnect();

   return 0;
}

