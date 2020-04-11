// M1 receives text
// Jason

#include <stdio.h>
#include "Server.h"

int main() 
{
    char msg[100] = "Hello, my name is Brandon Fong!";

    ReverseString(msg);

    printf("%s", msg);

   return 0;
}