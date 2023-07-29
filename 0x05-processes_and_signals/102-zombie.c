#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * create_zombie - Create a zombie process and return its PID.
 *
 * Return: PID of the zombie process.
 */
pid_t create_zombie(void)
{
	pid_t pid = fork();

	if (pid > 0)
	{
		printf("Zombie process created, PID: %d\n", pid);
		return (pid);
	}
	else if (pid == 0)
	{
		exit(0);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	char count = 0;

	while (count < 5)
	{
		pid_t zombie_pid = create_zombie();

		count++;
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
