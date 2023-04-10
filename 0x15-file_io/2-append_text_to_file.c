#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename:  the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success
 *         -1 on failure, if filename is NULL
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr, len;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	for (len = 0; text_content && text_content[len]; len++)
		;
	if (len)
	{
		wr = write(fd, text_content, len);
		if (wr == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
