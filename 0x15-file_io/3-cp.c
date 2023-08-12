#include "main.h"
#include <stdlib.h>

/**
* main - copy info from file_from to file_to.
* @zz: number of arguments
* @ll: array of arguments
* Return: Always 0.
*/

int main(int zz, char **ll)
{
int file_from, file_to;
ssize_t  l_read = 1024, l_write, close_file;
char content[1024];

if (zz != 3)
{ dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97); }
file_from = open(ll[1], O_RDONLY);
if (file_from == -1)
{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", ll[1]),
exit(98); }
file_to = open(ll[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (file_to == -1)
{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ll[2]);
exit(99); }
while (l_read == 1024)
{
l_read = read(file_from, content, 1024);
if (l_read == -1)
{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", ll[1]);
exit(98); }
l_write = write(file_to, content, l_read);
if (l_write == -1)
{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ll[2]);
exit(99); }
}
close_file = close(file_from);
if (close_file == -1)
{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_from);
exit(100); }
close_file = close(file_to);
if (close_file == -1)
{ dprintf(STDERR_FILENO, "Error: Can't close fd  %d\n", file_to);
exit(100); }
return (0);
}
