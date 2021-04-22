/*
** EPITECH PROJECT, 2021
** library lily
** File description:
** lily_get_node_from_data
*/

#include "lily.h"

lily_list *lily_get_node_from_data(lily_list *first, void *data)
{
    FOREACH(void, data_node, node, first)
        if (data_node == data)
            return (node);
    ENDFOREACH(node, first)
    return (NULL);
}