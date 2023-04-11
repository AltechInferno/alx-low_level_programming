#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates memory for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Failed to allocate memory for buffer\n");
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 *
 * @fd: File descriptor to close.
 */
void close_file(int fd)
{
	int result;

	result = close(fd);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, exit code 97.
 *              If file_from does not exist or cannot be read, exit code 98.
 *              If file_to cannot be created or written to, exit code 99.
 *              If file_to or file_from cannot be closed, exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer();
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Failed to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Failed to write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
