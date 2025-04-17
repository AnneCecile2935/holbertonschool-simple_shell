#include <stdio.h>
#include <stdlib.h>
int main ()
{
	char *ligne; /**sotcke ligne lue */
	size_t taille; /** stocke la taille nécessaire pour les lignes */
	size_t lu;/** stocke nombre de caractères lus */

	ligne = NULL;
	taille = 0;
	while (1) /** boucle qui continue jusqu'à ce que la conditon de sortie soit trouvée */
	{
		printf("$ ");
		lu = getline(&ligne, &taille, stdin); /**lit et alloue mémoire pour stocker ligne lue */	
		if (lu == -1) /** verif si getline a rencontré une erreur ou fin fichier */
		printf("\n[Fin de l'entrée détectée- EOF détecté]\n");
		break; 
	}
	printf("Vous avez tapé %s\n", ligne); /**test */
	free(ligne);
	return (0);
}