#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* create_buffer - Allocates 1024 bytes for a buffer.
* @file: The name of the file buffer is storing chars for.
* close_file - Closes file descriptors. 
* @lc: The file descriptor to be closed.
* main - Copies the contents of a file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Description: If the argument count is incorrect - exit code 97.
* If file_from does not exist or cannot be read - exit code 98.
* If file_to cannot be created or written to - exit code 99.
* If file_to or file_from cannot be closed - exit code 100.
*
* Return: A pointer to the newly-allocated buffer.
*/

char *create_buffer(char *file);
void close_file(int lc);

char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}

void close_file(int lc)
{
int b;
b = close(lc);
if (b == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", lc);
exit(100);
}
}

int main(int argc, char *argv[])
{
int from, lk, r, w;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
lk = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
w = write(lk, buffer, r);
if (lk == -1 || w == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

r = read(from, buffer, 1024);
lk = open(argv[2], O_WRONLY | O_APPEND);
} while (r > 0);

free(buffer);
close_file(from);
close_file(lk);

return (0);
}
