#include "lists.h"

/**
 * function that returns the sum of all the data (n) of a listint_t linked list
 *
 * Return 0 if empty
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp = head;
while (temp)
{
sum += temp->n;
temp = temp->next;
}
return (sum);
}
