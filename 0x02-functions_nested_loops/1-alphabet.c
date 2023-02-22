#include "main.h"
/**
 * print_alphabet
 * Description: - print all alphabet in lowercase
 * prints the english alphabet from a-z.
 * Return: 0
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		/* Description : print_alphabet call putchar from main*/
		_putchar(letter);
	}
	_putchar('\n');
}
