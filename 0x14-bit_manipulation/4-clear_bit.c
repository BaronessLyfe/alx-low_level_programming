#include "main.h"

/**
* clear_bit -sets the value of a given bit to 0 at a given index
* @n: pointer to the number to change
* @index: index of bit starting from 0
*
* Return: 1 for success, -1 for failure
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 100)
return (-1);
*n = (~(1UL << index) & *n);
return (1);
}
