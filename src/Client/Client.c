// M2 sends text
// Volta
/* 
 * Goal is to take user input from here and send it to Server.c
 * 
 */
#include <stdio.h>
#include "Client.h"

int main() 
{

   char msg[100] = "";

   puts("[Enter message to send to server]");
   fgets(msg, 100, stdin);

   printf("\nYour Message: %s\n", msg);

   // Do stuff to send to server

   return 0;
}