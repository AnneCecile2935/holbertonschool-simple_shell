#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * split_string - function to split string
 * @str: pointeur string
 * @return: char
 */
char **split_string(const char *str) {
	char *copy; /**copie entrée */
	char **result; /**tableau pointeur pour stocker mots */
    char *token; /**pointeur stocker mots */
    int i = 0; /**parcourt tableau */
	int capacity;/** capa du tableau */
	const char *delim = " "; /**delimiteur espace */
	printf("Chaîne d'entrée: %s\n", str);
copy = strdup(str); /**copie de la chaine */
if (copy == NULL)
{
perror("strdup"); /** si echoue affiche erreur */
exit(EXIT_FAILURE);
}
capacity = 10;
result = malloc(capacity * sizeof(char*)); /**allocation mémoire pour 10 */
    if (result == NULL) {
      
		perror("malloc");
        exit(EXIT_FAILURE);
    }
	 token = strtok(copy, delim); /**découpe la chaine en prenant en compte la copy et le delimiteur */
    while (token != NULL) {
		printf("Mot trouvé: %s\n", token); 
       if (i >= capacity) /** est ce que le tableau a besoin d'être agrandit?  */
	   {
		capacity *=2;
		result = realloc(result, capacity * sizeof(char *)); /**reallocation de mémoire */
		if (result == NULL)
		{
		perror("realloc");
		exit(EXIT_FAILURE);
		}
	}
		
	    result[i++] = strdup(token); /** création du mot trouvé dans la copie dans le tableau */
        token = strtok(NULL, delim); /**continuer à découper la chaine */
    }

    result[i] = NULL; /**fin des mots */

   free(copy);
   return (result);
}
int main() {
    const char *line = "Hello world, how are you today? aujourd'hui je vais très bien ce  matin. j'ai hate à demain soir.";
    
    // Appeler la fonction split_string pour découper la ligne en mots
    char **words = split_string(line);

    // Afficher les mots
    for (int i = 0; words[i] != NULL; i++) {
        printf("Mot %d: %s\n", i, words[i]);
        free(words[i]);  // Libérer chaque mot après utilisation
    }

    free(words);  // Libérer le tableau de mots
    return 0;
}