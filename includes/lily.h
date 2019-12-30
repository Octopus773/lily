/*
** EPITECH PROJECT, 2019
** task01
** File description:
** day10
*/

#ifndef _LILY_H_
#define _LILY_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct lily_list
{
    void *data;
    struct lily_list *prev;
    struct lily_list *next;
} lily_list;

lily_list *lily_create_node(void *data);

void lily_destroy_node(lily_list *node);

int lily_destroy_list(lily_list *list);

lily_list *lily_get_node_from_index(lily_list *first, int index);

int lily_add_node(lily_list **first, lily_list *node, int index);

int lily_get_list_length(lily_list *list);

int lily_get_index_from_node(lily_list *first, lily_list *node);

int lily_rem_node(lily_list **first, lily_list *node);

lily_list *lily_create_list_from_array(void **array);

int lily_mov_node(lily_list **first, lily_list *node, int new_index);

int lily_inv_list(lily_list **first);

#endif