#include "lists.h"

/**
*function that frees a listint_t list
*function sets the head to NULL
*/
void free_listint2(listint_t **head)
{
listint_t *temp;
if (head == NULL)
return;
while (*head)
{
temp = (*head)->next;
free(*head);
*head = temp;
}
*head = NULL;
}
