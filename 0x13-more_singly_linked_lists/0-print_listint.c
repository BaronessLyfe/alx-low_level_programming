#include "lists.h"

/**
* print_listint-prints all the elements of a linked list
* @h: linked list to print
*
* Return:the number of nodes
*/
size_t print_listint(const listint_t *h)
{
size_t num = 0;
while (h)
{
ptintf("%d\n", h->n);
num++;
h = h->next;
}
return (num);
}
