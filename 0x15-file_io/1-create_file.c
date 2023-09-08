#include "main.h"

/**
* create_file - Creates a file.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string to write to the file.
*
* Return: If the function fails =-1 or 1(success)
*/
int create_file(const char *filename, char *text_content)
{
int lc, w, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}
lc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
w = write(lc, text_content, len);
if (lc == -1 || w == -1)
return (-1);
close(lc);
return (1);
}
