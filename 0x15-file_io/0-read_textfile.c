#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed,otherwise 0.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *start;
ssize_t lc;
ssize_t q;
ssize_t v;
lc= open(filename, O_RDONLY);
if (lc == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
v = read(lc, start, letters);
q = write(STDOUT_FILENO, start, v);

free(start);
close(lc);
return (q);
}
