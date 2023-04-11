#include "main.h"

/**
 * create_file - Creates a file with specified permissions and writes content.
 * @filename: Name of the file to create.
 * @text_content: NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, nletters, rwr;

	if (!filename)
		return (-1);

	/* Open the file with specified permissions or create it if not exist */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = ""; /* If text_content is NULL, create an empty file */

	/* Count number of characters in text_content */
	for (nletters = 0; text_content[nletters]; nletters++)
		;

	/* Write text_content to the file */
	rwr = write(fd, text_content, nletters);
	if (rwr == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
