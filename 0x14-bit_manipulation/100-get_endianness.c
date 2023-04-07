#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian
 *	   1 if little endian
 */
int get_endianness(void)
{
	short int wd = 0x0001;
	char *c = (char *) &wd;

	return (c[0] ? 1 : 0);
}
