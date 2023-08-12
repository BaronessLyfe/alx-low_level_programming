#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

/**
*program that displays the information contained in the ELF header at the start of an ELF file.
*elf_header elf_filename
*Displayed information: (no less, no more, do not include trailing whitespace)
*Entry point address
*Format: the same as readelf -h (version 2.26.1)
*If the file is not an ELF file, or on error, exit with status code 98 and display a comprehensive error message to stderr
*You are allowed to use lseek once
*You are allowed to use read a maximum of 2 times at runtime
*You are allowed to have as many functions as you want in your source file
*You are allowed to use printf
*man elf, readelf
*/

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    
    printf("Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "Unknown");
    printf("Version: %d\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
    
    printf("Type: ");
    switch (header->e_type) {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("Unknown\n"); break;
    }
    
    printf("Entry point address: 0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];
    int lc = open(filename, O_RDONLY);
    if (lc == -1) {
        print_error("Failed to open the file");
    }

    Elf64_Ehdr header;
    ssize_t num_read = read(fd, &header, sizeof(header));
    if (num_read != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&header);

    close(lc);
    return 0;
}
