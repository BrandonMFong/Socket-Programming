// M1 receives text
// Jason

#include "Server.h"

int main() 
{
    char msg[100] = "";

    // ReverseString(msg);

    // printf("%s", msg);

    OpenSocket();
    BindSocket();
    
    while(1)
    {
        ListenToSocket();
    }

   return 0;
}

