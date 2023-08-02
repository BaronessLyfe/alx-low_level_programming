vi #include "lists.h"

/**
* function that returns the nth node of a listint_t linked list
* index is the index of the node, starting at 0
*
* if the node does not exist, return NULL
*/
int pop_listint(listint_t **head)
{
listint_t *temp;
int num;
if (!head || !*head)
return (0);
num = (*head)->n;
temp = (*head)->next;
free(*head);
*head = temp;
return (num);
}
