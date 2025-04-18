#include "main.h"
/**
*_strchr - a function that locates a character in a string.
*@s: pointer
*@c: value
*Return: s new value of s.
*/
char *_strchr(char *s, char c)
{
while (*s != '\0') // tant que le pointeur parcourt la chaine et qu'il ne tombe pas sur la fin de la chaine
{
if (*s == c) // est-ce que le caractère pointé par s est égal à c
{
return (s); // dans ce cas on retourne le pointeur s qui pointe vers c
}
else
s++; // sinon on passe au caractère suivant
}
if (*s == c) // si le caractère c est trouvé après la boucle, donc en fin de chaîne
return (s); // on retourne le pointeur s
else
return (0); // sinon on retourne une valeur nulle
}