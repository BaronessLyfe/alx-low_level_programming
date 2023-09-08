#include "main.h"

/**
* set_bit-sets the value of a bit to 1 at a given index
* @n:pointer to the number
* @index:index is the index starting from 0,to set to 1
*
* Return: 1 for success, -1 for failure
*/
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 100)
return (-1);
*n = ((1UL << index) | *n);
return (1);
}
