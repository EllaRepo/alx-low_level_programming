#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - creates a file
 * @filename:  the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success
 *         0 on failure, if filename is NULL
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wr, len;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	for (len = 0; filename && filename[len]; len++)
		;
	wr = write(fd, text_content, len);
	close(fd);
	if (wr == -1)
		return (-1);
	return (1);
}
