/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_node_and_data
*/

#include "lily.h"

void lily_destroy_node_and_data(lily_list *node)
{
    if (!node)
        return;
    if (node->data)
        free(node->data);
    free(node);
}