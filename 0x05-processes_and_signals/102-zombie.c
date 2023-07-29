#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - a C function that runs an infinite while loop.
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
 * create_zombie - a C function that creates a zombie process and
 * return its PID.
 *
 * Return: PID of the zombie process.
 */
pid_t create_zombie(void)
{
	pid_t pid = fork();

	if (pid > 0)
	{
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
 * main - a C program that creates five zombie processes and displays
 * their PIDs.
 *
 * Return: Always 0.
 */
int main(void)
{
	char count = 0;
	pid_t zombie_pids[5];

	while (count < 5)
	{
		zombie_pids[count] = create_zombie();
		printf("Zombie process created, PID: %d\n", zombie_pids[count]);
		count++;
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
