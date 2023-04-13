#include "elf_b.h"
#include "elf_a.h"

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * display_version - Prints the version of an ELF header.
 * @ident: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *ident)
{
	printf("  Version Information: %d",
			ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * close_elf_file - Closes an ELF file.
 * @fd: The file descriptor of the ELF file.
 */
void close_elf_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Failed to close file descriptor %d\n", fd);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *	ELF header at the start of an ELF file.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * Return: 0 on success.
 */
int main(__silent int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, read_result;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(fd);
		dprintf(STDERR_FILENO, "Error: Failed to allocate memory for ELF header\n");
		exit(98);
	}
	read_result = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_elf_file(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: File not found\n", argv[1]);
		exit(98);
	}

	check_elf_ident(header->e_ident);
	printf("ELF Header Information:\n");
	print_magic_number(header->e_ident);
	print_class_type(header->e_ident);
	print_data_encoding(header->e_ident);
	display_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi_version(header->e_ident);
	print_file_type(header->e_type, header->e_ident);
	print_entry_point(header->e_entry, header->e_ident);

	free(header);
	close_elf_file(fd);
	return (0);
}
