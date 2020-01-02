/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_sort_list
*/

#include "lily.h"

static int lily_is_sort_list(lily_list *st, int cmp(void *, void *), bool az)
{
    lily_list *one = st;
    lily_list *two;
    int ret = 1;

    if (!st || !st->next || !cmp)
        return (-2);
    if (az)
        ret = -1;
    two = st->next;
    for (int i = 1; two != st; i++) {
        if (!two->next || !two->data || !one->data)
            return (-1);
        if ((*cmp)(one->data, two->data) * ret < 0)
            return (i);
        one = two;
        two = two->next;
    }
    return (-1);
}

static int lily_sort_list(lily_list **first, int cmp(void *, void *), bool az)
{
    lily_list *one;
    int index_sort;

    if (!first || !*first || !cmp)
        return (-1);
    index_sort = lily_is_sort_list(*first, cmp, az);
    for (int i = 0; index_sort != -1; i++) {
        one = lily_get_node_from_index(*first, index_sort);
        if (lily_mov_node(first, one, index_sort - 1))
            return (-1);
        index_sort = lily_is_sort_list(*first, cmp, az);
    }
    return (0);
}

int lily_sort_list_az(lily_list **first, int cmp(void *, void *))
{
    return (lily_sort_list(first, cmp, true));
}

int lily_sort_list_za(lily_list **first, int cmp(void *, void *))
{
    return (lily_sort_list(first, cmp, false));
}