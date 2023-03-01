#include <stdio.h>

/**
 * main - appends src to dest
 * 
 * Return: Always 0
 */
char *_strcat(char *dest, char *src) {
  char *dest_end = dest;

  // Find the end of the dest string
  while (*dest_end != '\0') {
    dest_end++;
  }

  // Append the src string to dest
  while (*src != '\0') {
    *dest_end = *src;
    dest_end++;
    src++;
  }

  // Add a terminating null byte
  *dest_end = '\0';

  return dest;
}

int main() {
  char dest[20] = "hello";
  char src[10] = " world";

  printf("%s\n", _strcat(dest, src));  // Output: "hello world"
  return 0;
}

