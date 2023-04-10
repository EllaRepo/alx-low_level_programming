#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * log_error - prints errors
 * @err_code: error code
 * @argv: arguments
 * @fd: file descriptor
 *
 * Return: 0
 */
void log_error(int err_code, char *argv[], int fd)
{
	switch (err_code)
	{
		case 1:
			dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
			exit(98);
			break;
		case 2:
			dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
			exit(99);
			break;
		case 3:
			dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
			exit(100);
			break;
		default:
			break;
	}
}
/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char buff[1024];
	ssize_t rd, wr;
	int f_src, f_des, err;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	f_src = open(argv[1], O_RDONLY);
	f_des = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	if (f_src == -1)
		log_error(1, argv, 0);
	if (f_des == -1)
		log_error(2, argv, 0);
	rd = 1024;
	while (rd == 1024)
	{
		rd = read(f_src, buff, 1024);
		if (rd == -1)
			log_error(1, argv, 0);
		wr = write(f_des, buff, rd);
		if (wr == -1)
			log_error(2, argv, 0);
	}
	err = close(f_src);
	if (err == -1)
		log_error(3, argv, f_src);
	err = close(f_des);
	if (err == -1)
		log_error(3, argv, f_des);
	return (0);
}
