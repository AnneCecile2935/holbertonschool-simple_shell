#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * my_getline - function to prints lines of file
 * @lineptr: pointer to poiter to caractères, to store adresse of string is read
 * @n: size of buffer pointed lineptr
 * @stream: poiteur to the file is read
 */

ssize_t my_getline(char**lineptr, size_t *n, FILE*stream)
{
	ssize_t i;
	size_t new_size;
	char *new_ptr;
	size_t pos = 0; /**position dans le buffer*/
	ssize_t bytes_read;/**nb octets lu */
	char buffer [128]; /**buffer pour stocker les données lues */
	if (lineptr == NULL || n == NULL || stream == NULL) /** vérifier que les pointeurs ne sont pas null */
	return (-1);
	if (*lineptr == NULL || *n == 0) /**allocation initiale du buffer */
	{
	*n = 128;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)/**echec de l'allocation */
	return (-1);
	}
while ((bytes_read = read(fileno(stream), buffer, sizeof(buffer))) > 0) /** lecture du fichier tant qu'il y a des octects à lire */
{
	while (pos + bytes_read >= *n) /**Agrandir le buffer si besoin */
	{
		new_size = *n * 2;
		new_ptr = realloc(*lineptr, new_size);
		if (new_ptr == NULL)
		return (-1);
		*lineptr = new_ptr;
	*n = new_size;
	}
	for (i = 0; i < bytes_read; i++) /**copie des caractères lus dans le buffer */
	{
		(*lineptr)[pos++] = buffer[i];
		if (buffer[i] == '\n') /** si nouvelle ligne, terminer la lecture */
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
	}
}
		if (pos == 0 && bytes_read == 0) /** si fin de fichier ou aucun caract lus */
		return (-1);
	if (bytes_read == -1)
	return (-1);
			(*lineptr)[pos] = '\0';
		return (pos);
}


	/** if (fgets(*lineptr, *n, stream) == NULL)
	return (-1);
	len = strlen (*lineptr);

	while (len > 0 && (*lineptr)[len - 1] != '\n' && !feof(stream))
	{
		*n = *n *2;
		tmp = realloc(*lineptr, *n);
		if (tmp == NULL)
		return (-1);
		*lineptr = tmp;
		if (fgets(*lineptr + len, *n - len, stream) == NULL)
		break;
		len = strlen(*lineptr);
	}
	return (len);
}*/
void run_prompt() {
	char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf("$ "); // Afficher le symbole $ à chaque nouvelle attente de commande
        fflush(stdout); // Forcer le vidage du tampon de sortie

        read = my_getline(&line, &len, stdin);

        if (read == -1) {
            if (feof(stdin)) {
                printf("\nFin de fichier atteinte (Ctrl+D).\n");
            } else {
                printf("Erreur de lecture ou fin de fichier\n");
            }
            free(line);
            break;
        }

        printf("%s\n", line); // Afficher la commande entrée par l'utilisateur

        // Libérer la mémoire allouée par my_getline
        free(line);
        line = NULL;
        len = 0;
    }
}
int main ()
{
	run_prompt();
	return (0);
}
