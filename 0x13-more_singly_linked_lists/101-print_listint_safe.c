#include "lists.h"
#include <stdio.h>

/**
*function that prints a listint_t linked list in a loop
*Go through he list once
*
*Return 98 if failed .
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *Tom, *jerry;
size_t nodes = 1;
if (head == NULL || head->next == NULL)
return (0);
Tom = head->next;
jerry = (head->next)->next;
while (hare)
{
if (Tom == jerry)
{
Tom = head;
while (Tom != jerry)
{
nodes++;
Tom = jerry->next;
jerry = jerry->next;
}
Tom = Tom->next;
while (Tom != jerry)
{
nodes++;
Tom = Tom->next;
}
return (nodes);
}
Tom = Tom->next;
jerry = (jerry->next)->next;
}
return (0);
}
size_t print_listint_safe(const listint_t *head)
{
size_t nodes, index = 0;
nodes = looped_listint_len(head);
if (nodes == 0)
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
printf("-> [%p] %d\n", (void *)head, head->n);
}
return (nodes);
}
