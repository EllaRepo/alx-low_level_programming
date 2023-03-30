#include<stdio.h>

void print_before_main(void) __attribute__ ((constructor));

/**
 * print_before_main -  prints string before main function is executeds
 *
 * Return: None
 */
void print_before_main(void)
{
	printf("%s", "You're beat! and yet, you must allow,");
	printf("%s", "\nI bore my house upon my back!\n");
}
