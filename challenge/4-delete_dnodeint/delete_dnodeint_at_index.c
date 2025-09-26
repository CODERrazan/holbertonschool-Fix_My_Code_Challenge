#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    /* Traverse to the node at the given index */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If index is out of bounds */
    if (current == NULL)
        return (-1);

    /* If deleting the head node */
    if (current == *head)
        *head = current->next;

    /* Update previous node's next pointer */
    if (current->prev != NULL)
        current->prev->next = current->next;

    /* Update next node's previous pointer */
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
