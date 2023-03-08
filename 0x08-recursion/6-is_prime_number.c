/**
 * _is_prime_number- Checks if a number is a prime number
 * @n: The number
 * @i: Integer number starting from 2
 *
 * Return: 1 if the number if prime
 *        -1 otherwise
 */
int _is_prime_number(int n, int i)
{
	if (n <= 1)
		return (0);
	if (n == 2 || n == i)
		return (1);
	if (n % i == 0)
		return (0);
	return (_is_prime_number(n, i + 1));
}
/**
 * is_prime_number - Checks if a number is a prime number
 * @n: The number
 *
 * Return: 1 if the number if prime
 *        -1 otherwise
 */
int is_prime_number(int n)
{
	return (_is_prime_number(n, 2));
}
