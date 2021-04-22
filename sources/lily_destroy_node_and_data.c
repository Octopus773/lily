/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_node_and_data
*/

#include "lily.h"
#include <malloc.h>

void lily_destroy_node_and_data(lily_list **node, void destroy(void *))
{
    if (!node || !destroy || !*node)
        return;
    if ((*node)->data)
        (*destroy)((*node)->data);
    free(*node);
    *node = NULL;
}