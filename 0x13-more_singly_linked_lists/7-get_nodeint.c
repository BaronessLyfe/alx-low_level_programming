#include "lists.h"


/**
* index of the node,staring from 0
*
* Return NULL if node soesnt not exist
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;
listint_t *temp = head;
while (temp && i < index)
{
temp = temp->next;
i++;
}
return (temp ? temp : NULL);
}
