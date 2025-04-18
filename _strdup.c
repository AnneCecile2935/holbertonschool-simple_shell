#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * _strdup - function that returns a pointer to a newly allocated in memory
 *which contains a copy of the string givent as a parameter.
 * @str: parameter of char
 * * Return: ptr
 */
char *_strdup(char *str)
{
int len = 0; /**calcul longueur chaine*/
int i = 0; // utiliser pour copier la chaine
char *cpy;
if (str == NULL)
{
return (NULL); // si la chaine est nulle, on renvoie null
}
while (str[len]) // compte la longueur de la chaine
len++;
cpy = malloc(len + 1); // alloue la mémoire pour la longueur de la nouvelle chaine copiée
if (cpy == NULL) // vérifié si la chaine est nulle
{
return (NULL);
}
for (i = 0; i <= len; i++) // parcours la chaine src \0 compris(<=)
{
cpy[i] = src[i]; // copie chaque caractère de src dans cpy 
}
return (cpy); // renvoie la nouvelle chaine copiée
}