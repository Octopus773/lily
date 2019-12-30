/*
** EPITECH PROJECT, 2019
** task1 day13
** File description:
** none
*/

#include "lily.h"

void lily_destroy_node(lily_list *node)
{
    if (!node)
        return;
    free(node);
}