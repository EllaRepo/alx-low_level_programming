#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

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
 * @elf_header: points elf header
 * @argv: arguments
 *
 * Return: None.
 */
void is_elf(Elf64_Ehdr *elf_header, char *argv[])
{
	int i;
	char magic[] = {0x7f, 0x45, 0x4c, 0x46};

	for (i = 0; i < 4; i++)
	{
		if (magic[i] != elf_header->e_ident[i])
			log_error(3, argv, 0);
	}
	if ((elf_header->e_ident[4] + '0') == '0')
		exit(98);
}
/**
 * print_magic_no - prints the magic number
 * @elf_header: points to elf header
 *
 * Return: None
 */
void print_magic_no(Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:  ");
	for (i = 0; i < 16; i++)
	{
		printf(" %02x", elf_header->e_ident[i]);
	}
	printf("\n");
}
/**
 * print_class - prints class
 * @class: class
 *
 * Return: None
 */
void print_class(unsigned char class)
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
void print_data(unsigned char data)
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
void print_ver(unsigned char ver)
{
	printf("  Version:                           %d", (int) ver);
	if ((int) ver == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}
/**
 * get_osabi - returns the name of osabi
 * @osabi: requesed osabi index
 *
 * Return: name of osabi
*/
char *get_osabi(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_NONE:	return "UNIX - System V";
		case ELFOSABI_HPUX:	return "UNIX - HP-UX";
		case ELFOSABI_NETBSD:	return "UNIX - NetBSD";
		case ELFOSABI_GNU:	return "UNIX - GNU";
		case ELFOSABI_SOLARIS:	return "UNIX - Solaris";
		case ELFOSABI_AIX:	return "UNIX - AIX";
		case ELFOSABI_IRIX:	return "UNIX - IRIX";
		case ELFOSABI_FREEBSD:	return "UNIX - FreeBSD";
		case ELFOSABI_TRU64:	return "UNIX - TRU64";
		case ELFOSABI_MODESTO:	return "Novell - Modesto";
		case ELFOSABI_OPENBSD:	return "UNIX - OpenBSD";
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
void print_osabi(unsigned char osabi)
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
void print_abi_ver(unsigned char abi_ver)
{
	printf("  ABI Version:                       ");
	printf("%d\n", abi_ver);
}
/**
 * print_type - prints the type
 * @elf_header: points to elf header
 *
 * Return: None
*/
void print_type(Elf64_Ehdr *elf_header)
{
	unsigned char type = elf_header->e_ident[0x10];
	char *type_name = NULL;

	type = (elf_header->e_ident[5] == 0x01) ?
		elf_header->e_ident[0x10] : elf_header->e_ident[0x11];
	switch (type)
	{
		case 0x00:
			type_name = "NONE (None)";
			break;
		case 0x01:
			type_name = "REL (Relocatable file)";
			break;
		case 0x02:
			type_name = "EXEC (Executable file)";
			break;
		case 0x03:
			type_name = "DYN (Shared object file)";
			break;
		case 0x04:
			type_name = "CORE (Core file)";
			break;
		default:
			break;
	}
	printf("  Type:                              ");
	if (type_name)
		printf("%s\n", type_name);
	else
		printf("<unknown>: %x\n", type);
}
/**
 * print_entry - prints entry
 * @elf_header: points to elf header
 *
 * Return: None
*/
void print_entry(Elf64_Ehdr *elf_header)
{
	unsigned long int entry;

	printf("  Entry point address:               ");

	entry = elf_header->e_entry;
	if (elf_header->e_ident[5] == 0x02)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}
	if (elf_header->e_ident[4] == 0x01)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
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
	Elf64_Ehdr *elf_header;
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
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close(f_src);
		log_error(1, argv, 0);
	}
	lseek(f_src, 0, SEEK_SET);
	rd = read(f_src, elf_header, sizeof(Elf64_Ehdr));
	if (rd == -1)
		log_error(2, argv, 0);
	is_elf(elf_header, argv);
	print_magic_no(elf_header);
	print_class(elf_header->e_ident[4]);
	print_data(elf_header->e_ident[5]);
	print_ver(elf_header->e_ident[6]);
	print_osabi(elf_header->e_ident[7]);
	print_abi_ver(elf_header->e_ident[8]);
	print_type(elf_header);
	print_entry(elf_header);

	close(f_src);
	return (0);
}
