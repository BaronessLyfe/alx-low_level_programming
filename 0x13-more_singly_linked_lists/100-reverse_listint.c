#include "lists.h"

/**
*function that reverses a listint_t linked list
*use 1 loop,malloc or free or arrays
*declare maximu of two variables in the function

* Return
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *backward = NULL;
listint_t *forward = NULL;
while (*head)
{
next = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = next;
}
*head = prev;
return (*head);
}
