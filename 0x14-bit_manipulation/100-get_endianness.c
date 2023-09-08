#include "main.h"

/**
* get_endianness - checks the endianness,little or big
* Return: 0 for big, 1 for little
*/
int get_endianness(void)
{
unsigned int i = 3;
char *c = (char *) &i;
return (*c);
}
