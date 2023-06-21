#include "main.h"
/**
*_memset - this function fills
* the first n bytes of the memory portion
* pointed to by s with constant byte b
*@s:target
*@b: constant byte
*@n:number of byte
*Return: this returns new value of target
*/

char *_memset(char *s, char b, unsigned int n)
{
	while (n)
	{
		s[n - 1] = b;
		n--;
	}
	return (s);
}
