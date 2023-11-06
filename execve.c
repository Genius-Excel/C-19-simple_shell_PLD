#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	char *lineptr = NULL;

	size_t n;

	ssize_t get_line_val;

	char *token;

	char *command_args[1024];

	while (1)
	{
		printf("(Shell)$ ");

		get_line_val = getline(&lineptr, &n, stdin);

		if (get_line_val == EOF || get_line_val == -1)
		{
			//perror("getline Failed");
			free(lineptr);
			exit(0);
		}
//		printf("%s\n", lineptr);
		int i = 0;

		token = strtok(lineptr, " \n\t");

		while(token != NULL && i < 1024)
		{
			command_args[i] = strdup(token); /*Populate the array with the tokens*/
			token = strtok(NULL, " \n\t");

			i += 1;
		}
		command_args[i] = NULL;

		char *cmd;
		strcpy(cmd, command_args[0]);

		strcat(cmd, "/bin");
		
		execve(cmd, command_args, environ);
	}

	free(lineptr);
	return (0);

}
