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
			"Error: Can't open file %s\n", argv[1]);
			exit(98);
			break;
		case 2:
			dprintf(STDERR_FILENO,
			"Error: Can't read the file %s\n", argv[1]);
			exit(98);
			break;
		case 3:
			dprintf(STDERR_FILENO,
			"Error: %s is not elf file\n", argv[1]);
			exit(98);
			break;
		case 4:
			dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
			exit(100);
			break;
		default:
			break;
	}
}
/**
 * is_elf - checks for elf file
 * @buff: buffer
 * @argv: arguments
 *
 * Return: None.
 */
void is_elf(char *buff, char *argv[])
{
	int i;
	char magic[] = {0x7f, 0x45, 0x4c, 0x46};

	for (i = 0; i < 4; i++)
	{
		if (magic[i] != buff[i])
			log_error(3, argv, 0);
	}
}
/**
 * print_magic_no - prints the magic number
 * @buff: buffer
 *
 * Return: None
 */
void print_magic_no(char *buff)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:  ");
	for (i = 0; i < 16; i++)
	{
		printf(" %02x", buff[i]);
	}
	printf("\n");
}
/**
 * print_class - prints class
 * @class: class
 *
 * Return: None
 */
void print_class(char class)
{
	printf("  Class:                             ");
	if (class == 0x01)
		printf("ELF32\n");
	else if (class == 0x02)
		printf("ELF64\n");
}
/**
 * print_data - prints data
 * @data: data
 *
 * Return: None
 */
void print_data(char data)
{
	printf("  Data:                              ");
	if (data == 0x01)
		printf("2's complement, little endian\n");
	else if (data == 0x02)
		printf("2's complement, big endian\n");
}
/**
 * print_ver - prints version
 * @ver: ver
 *
 * Return: None
 */
void print_ver(char ver)
{
	printf("  Version:                           ");
	if (ver == 0x01)
		printf("1 (current)\n");
	else if (ver == 0x00)
		printf("0 (Invalid)\n");
}
/**
 * get_osabi - returns the name of osabi
 * @osabi: requesed osabi index
 *
 * Return: name of osabi
*/
char *get_osabi(char osabi)
{
	switch (osabi)
	{
		case 0x00:	return "UNIX - System V";
		case 0x01:	return "UNIX - HP-UX";
		case 0x02:	return "UNIX - NetBSD";
		case 0x03:	return "Linux";
		case 0x04:	return "UNIX - GNU Hurd";
		case 0x06:	return "UNIX - Solaris";
		case 0x07:	return "UNIX - AIX";
		case 0x08:	return "UNIX - IRIX";
		case 0x09:	return "UNIX - FreeBSD";
		case 0x0A:	return "UNIX - TRU64";
		case 0x0B:	return "Novell - Modesto";
		case 0x0C:	return "Novell - Modesto";
		case 0x0D:	return "VMS - OpenVMS";
		case 0x0E:	return "HP - Non-Stop Kernel";
		case 0x0F:	return "AROS";
		case 0x10:	return "FenixOS";
		case 0x11:	return "Nuxi CloudABI";
		case 0x12:	return "Stratus Technologies OpenVOS";
		default:	return NULL;
	}
}
/**
 * print_osabi - prints OS/ABI
 * @osabi: osabi
 *
 * Return: None
 */
void print_osabi(char osabi)
{
	char *osabi_name;

	printf("  OS/ABI:                            ");
	osabi_name = get_osabi(osabi);
	if (osabi_name)
		printf("%s\n", osabi_name);
	else if (!osabi_name)
		printf("<unknown: %x>\n", osabi);
}
/**
 * print_abi_ver - prints ABI version
 * @abi_ver: abi version
 *
 * Return: None
 */
void print_abi_ver(char abi_ver)
{
	printf("  ABI Version:                       ");
	printf("%x\n", abi_ver);
}
/**
 * get_type_value - gets the type value
 * @buff: buffer
 *
 * Return: the value of type
 */
unsigned int get_type_value(char *buff)
{
	unsigned int value = 0;

	if (buff[5] == 0x01)
	{
		value = buff[0x11] << 8;
		value |= buff[0x10];
	}
	else if (buff[5] == 0x02)
	{
		value = buff[0x10] << 8;
		value |= buff[0x11];
	}
	return (value);
}
/**
 * print_type - prints the type
 * @buff: buffer
 *
 * Return: None
*/
void print_type(char *buff)
{
	unsigned int type;
	char *type_name = NULL;

	type = get_type_value(buff);
	switch (type)
	{
		case 0x0000:
			type_name = "NONE (None)";
			break;
		case 0x0001:
			type_name = "REL (Relocatable file)";
			break;
		case 0x0002:
			type_name = "EXEC (Executable file)";
			break;
		case 0x0003:
			type_name = "DYN (Shared object file)";
			break;
		case 0x0004:
			type_name = "CORE (Core file)";
			break;
		default:
			break;
	}
	printf("  Type:                              ");
	if (type_name)
		printf("%s\n", type_name);
	else
	{
		if (type >= 0xFE00 && type <= 0xFEFF)
			printf("OS Specific: (%x)\n", type);
		else if (type >= 0xFF00 && type <= 0xFFFF)
			printf("Processor specific: (%x)\n", type);
		else
			printf("<unknown>: %x\n", type);
	}
}
/**
 * print_entry - prints entry
 * @buff: buffer
 *
 * Return: None
*/
void print_entry(char *buff)
{
	int start, i;

	printf("  Entry point address:               0x");
	if (buff[5] == 0x01)
	{
		start = 26;
		for (i = start; i >= 22; i--)
		{
			if (buff[i] > 0)
				printf("%x", buff[i]);
			else if (buff[i] < 0)
				printf("%x", 256 + buff[i]);
		}
		if (buff[7] == 6)
			printf("00");
	}
	else if (buff[5] == 0x02)
	{
		start = 26;
		for (i = start; i > 23; i--)
		{
			if (buff[i] >= 0)
				printf("%02x", buff[i]);
			else if (buff[i] < 0)
				printf("%02x", 256 + buff[i]);
		}
	}
	printf("\n");
}
/**
 * main -  displays the information contained in the ELF header
 *         at the start of an ELF file
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char buff[27];
	ssize_t rd;
	int f_src;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: elf_header elf_filename");
		exit(98);
	}

	f_src = open(argv[1], O_RDONLY);
	if (f_src < 0)
		log_error(1, argv, 0);
	lseek(f_src, 0, SEEK_SET);
	rd = read(f_src, buff, 27);
	if (rd == -1)
		log_error(2, argv, 0);
	is_elf(buff, argv);
	print_magic_no(buff);
	print_class(buff[4]);
	print_data(buff[5]);
	print_ver(buff[6]);
	print_osabi(buff[7]);
	print_abi_ver(buff[8]);
	print_type(buff);
	print_entry(buff);

	close(f_src);
	return (0);
}
