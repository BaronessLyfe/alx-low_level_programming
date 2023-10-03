
#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed,NULL = 0
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t lc;
ssize_t w;
ssize_t t;
lc = open(filename, O_RDONLY);
if (lc == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(lc, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(lc);
return (w);
}
