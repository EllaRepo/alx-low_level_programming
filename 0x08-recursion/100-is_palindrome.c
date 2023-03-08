#include <stdio.h>
/**
 * _is_palindrome - Checks if a string is a palindrome
 * @s: Point to the string
 * @es: Point to the end of the string
 *
 * Return: 1 if the string is a palindrome
 *         0 otherwise
 */
int _is_palindrome(char *s, char *es)
{
	if (*s != *es)
		return (0);
	if (s == es || s + 1 == es)
		return (1);
	s++, es--;
	return (_is_palindrome(s, es));
}
/**
 * point_to_last - Places a pointer pointing to the last element
 * @s: Point to the string
 *
 * Return: None
 */
char *point_to_last(char *s)
{
	if (*s == '\0')
		return (s);
	s++;
	return (point_to_last(s));
}
/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: Point to the string
 *
 * Return: 1 if the string is a palindrome
 *         0 otherwise
 */
int is_palindrome(char *s)
{
	char *tmp;

	if (*s == '\0')
		return (1);

	tmp = s;
	tmp = point_to_last(tmp);
	tmp--;
	return (_is_palindrome(s, tmp));
}
