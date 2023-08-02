#include "lists.h"

/**
*function that finds the loop in a linked list
*The address of the node where the loop starts, or NULL if there is no loop
*
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *white = head;
listint_t *beige = head;
if (!head)
return (NULL);
 while (white && beige && beige->next)
{
beige = beige->next->next;
white = white->next;
if (beige == white)
{
white = head;
while (white != beige)
{
white = white->next;
beige = beige->next;
}
return (beige);
}
}
return (NULL);
}
