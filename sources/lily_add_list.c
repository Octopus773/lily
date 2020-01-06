/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_add_list
*/

#include "lily.h"

static void set_list(lily_list *node_fst, lily_list *fst_s, int index, int size)
{
    lily_list *node;

    if ((index < 0 && index >= size * -1) || index >= size) {
        fst_s->prev->next = node_fst->next;
        node_fst->next->prev = fst_s->prev;
        node_fst->next = fst_s;
        fst_s->prev = node_fst;
    }
    else {
        fst_s->prev->next = node_fst;
        node_fst->prev->next = fst_s;
        node = fst_s->prev;
        fst_s->prev = node_fst->prev;
        node_fst->prev = node;
    }
}

int lily_add_list(lily_list **first_dest, lily_list *first_src, int index)
{
    int size_dest;
    lily_list *node_fst;

    if (!first_dest || !first_src)
        return (-1);
    if (!*first_dest) {
        *first_dest = first_src;
        return (0);
    }
    size_dest = lily_get_list_length(*first_dest);
    node_fst = lily_get_node_from_index(*first_dest, index);
    set_list(node_fst, first_src, index, size_dest);
    if (node_fst == *first_dest && (index < size_dest * -1 || index == 0))
        *first_dest = first_src;
    return (0);
}