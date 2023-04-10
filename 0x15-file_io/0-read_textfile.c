#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: filename
 * @letters: the number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 *         0 file can not be opened or read, if filename is NULL,
 *           if write fails or does not write the expected amount of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t rd, wr;
	int fd;

	if (!filename || letters < 1)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (!buff)
		return (0);
	rd = read(fd, buff, letters);
	wr = write(STDOUT_FILENO, buff, rd);
	close(fd);
	free(buff);
	if (wr != rd)
		return (0);

	return (wr);
}
