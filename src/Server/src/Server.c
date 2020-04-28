// M1 receives text
// Jason
// must use gcc Server.c -lnsl -lsocket -lresolv to compile
// https://cboard.cprogramming.com/cplusplus-programming/128326-undefined-symbol-when-compiling-socket-program.html

#include "Server.h"

int main() 
{
    OpenSocket();
    BindSocket();
    InitListen();
    while(1)
    {
        AcceptClientConnection();
        ReceiveMessage();
        SendMessage();
        Disconnect();
    }
   return 0;
}

