/**
 * set_bit -sets a bit at a given index
 * @n: integer pointer
 * @index: the index
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if ((sizeof(n) * 8) < index)
		return (-1);
	*n = *n | (1 << index);
	return (1);
}

