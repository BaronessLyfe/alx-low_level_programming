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
int lc;
ssize_t c, v;
char *buf

lc= open(filename, O_RDONLY);
if (lc == -1)
return (0);
buffer = malloc(sizeof(char) * letters);
c= read(lc, buf, letters)
v = write(STDOUT_FILENO, buf, c);

free(buf);
close(lc);
return (v);
}
