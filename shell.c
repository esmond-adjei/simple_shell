#include <unistd.h>
#include "shell.h"

/**
 * main - runs a shell program
 * Description - A shell program that takes input (command)
 * with getline, creates a token and executes the command
 * in a child process
 * Return: 0
 */
int main(void)
{
	size_t len;
	ssize_t readline;
	char *inputcmd = NULL;
	char **tkncommand;

	while (1)
	{
		/* read input command as string */
		printf("($) ");
		readline = getline(&inputcmd, &len, stdin);
		if (readline == -1)
		{
			free(inputcmd);
			exit(EXIT_SUCCESS);
		}

		/* tokenize the command string */
		tkncommand = tokenize_string(inputcmd);

		/* execute tokenized command and arguments*/
		execute_cmd(tkncommand);
	}
	free(inputcmd);
	free(tkncommand);
	return (0);
}
