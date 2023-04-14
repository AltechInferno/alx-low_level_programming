#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void display_elf_header_info(const Elf64_Ehdr *elf_header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\nClass: %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("Data: %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "2's complement, big-endian");
    printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", elf_header->e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("Type: 0x%x\n", elf_header->e_type);
    printf("Entry point address: 0x%lx\n", elf_header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        display_error("Failed to open file");
    }

    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        display_error("Failed to read ELF header");
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        display_error("Failed to reset file position");
    }

    // Check if the file is an ELF file
    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        display_error("Not an ELF file");
    }

    display_elf_header_info(&elf_header);

    close(fd);
    return 0;
}
