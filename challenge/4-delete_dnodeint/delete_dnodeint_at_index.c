#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node = *head;
    unsigned int i = 0;

    if (!head || !*head)
        return (-1);

    while (node && i < index)
    {
        node = node->next;
        i++;
    }

    if (!node)
        return (-1);

    if (node->prev)
        node->prev->next = node->next;
    else
        *head = node->next;

    if (node->next)
        node->next->prev = node->prev;

    free(node);
    return (1);
}
