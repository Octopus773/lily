/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** lily_create_array_from_list
*/

#include "lily.h"
#include <malloc.h>

void **lily_create_array_from_list(lily_list *first)
{
    void **array;
    int size;
    int i;

    if (!first || !first->next)
        return (NULL);
    size = lily_get_list_length(first);
    array = malloc(sizeof(first->data) * (size + 1));
    if (!array)
        return (NULL);
    for (i = 0; i < size; i++, first = first->next) {
        if (!first->next) {
            free(array);
            return (NULL);
        }
        array[i] = first->data;
    }
    array[i] = NULL;
    return (array);
}