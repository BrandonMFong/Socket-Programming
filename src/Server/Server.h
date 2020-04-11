
#include <stdio.h>
#include <string.h>

void Dorev(char* string, int begin, int end) // recurse 
{
    char temp = "";
    if (begin >= end) return;

    temp = string[begin];
    string[begin] = string[end];
    string[end] = temp;
    Dorev(string, ++begin, --end);
}

void ReverseString(char * message)
{
    Dorev(message,0, strlen(message) - 1);
}
