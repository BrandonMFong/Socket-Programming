#include <stdio.h>
#include <string.h>

char* ExitString = "!exit!";

void ClearString(char* string)
{
	memset(string, 0, strlen(string));
}

void Greetings()
{
	printf("\n\nWelcome, enter '!exit!' to exit the program when prompted.\n\n");
}

void IsExit(char* string)
{
	if (strstr(string, ExitString) != NULL)
	{
		printf("\nExiting program!\n"); exit(0);
	}
}