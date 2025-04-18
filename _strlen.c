#include "lists.h"
/**
*_strlen - return the lenght of a string
*@s : parameter function
*Return: return the result , the length.
*/
int _strlen(const char *s)
{
int len = 0;
while (s[len] != '\0') 
{
len++; 
}
return (len); 
}