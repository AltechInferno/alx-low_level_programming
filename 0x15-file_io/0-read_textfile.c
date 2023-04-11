#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads and prints text from a file.
 * @filename: Pointer to the filename string.
 * @letters: Number of letters to read and print.
 *
 * Return: If successful, the actual number of bytes read and printed.
 *         Otherwise, 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_desc, read_bytes, write_bytes;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	file_desc = open(filename, O_RDONLY);
	read_bytes = read(file_desc, buffer, letters);
	write_bytes = write(STDOUT_FILENO, buffer, read_bytes);

	if (file_desc == -1 || read_bytes == -1 || write_bytes == -1 || write_bytes != read_bytes)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(file_desc);

	return (write_bytes);
}

