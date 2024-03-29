#include "main.h"

/**
 * append_text_to_file - Appends text to end of a file
 * @filename: The name of the file
 * @text_content: The NULL terminated string to add at end of file
 * Author: Abukari Wunpini Alhassan
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, length = 0;

	if (filename == NULL)
	{
		/* If filename is NULL, then return -1 */
		return (-1);
	}

	if (text_content != NULL)
	{
		/* Calculate the length of the text_content */
		while (text_content[length])
			length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
	{
		/* If failed to open the file, then return -1 */
		return (-1);
	}

	write_status = write(file_descriptor, text_content, length);
	if (write_status == -1)
	{
		/* If failed to write to the file, then return -1 */
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);

	/* Return 1 on success */
	return (1);
}


