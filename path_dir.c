#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	

void print_path_directories(void)
{
	char *path_env;
	char *path_copy;
	char *token;

	path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "PATH variable not found\n");
		return;
	}
	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	free(path_copy);
}
typedef struct path_node
{
	char *dir;
	struct  path_node *next;

}path_node;

path_node *add_node_end(path_node **head, const char *dir)
{
	path_node *new_node;
	path_node *temp;
	new_node = malloc(sizeof(path_node));
	if (!new_node)
		return (NULL);
	new_node->dir = strdup(dir);
	new_node->next = NULL;
		if (*head == NULL)
			*head = new_node;
		else
		{
			 temp = *head;
			 while (temp->next)
				temp = temp->next;
			temp->next = new_node;
			 
		}
		return (new_node);
	}
	
int main (void)
{
	print_path_directories();
	return (0);
}