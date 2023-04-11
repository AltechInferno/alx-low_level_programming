#include "main.h"

/**
 * print_file_contents - reads a text file and prints a specified number of letters
 * @filename: name of the file to be read
 * @letters: number of letters to be printed
 * Return: number of letters printed. Returns 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);

    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * (letters));
    if (!buffer)
        return (0);

    bytes_read = read(fd, buffer, letters);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    close(fd);

    free(buffer);
    return (bytes_written);
}

