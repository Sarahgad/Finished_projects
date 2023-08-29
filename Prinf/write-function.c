#include "main.h"
/**
 * _printchar - writes the character c to stdout
 * @x: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printchar(char x)
{
	return (write(1, &x, 1));
}
