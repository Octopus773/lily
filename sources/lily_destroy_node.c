/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_destroy_node
*/

#include "lily.h"

void lily_destroy_node(lily_list *node)
{
    if (!node)
        return;
    free(node);
}