/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

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