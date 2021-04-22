/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_create_node
*/

#include "lily.h"
#include <malloc.h>

lily_list *lily_create_node(void *data)
{
    lily_list *node = malloc(sizeof(lily_list));

    if (!node)
        return (NULL);
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}