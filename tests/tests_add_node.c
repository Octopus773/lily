/*
** EPITECH PROJECT, 2019
** tests library lily
** File description:
** lily_add_node
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lily.h"

Test(tests_lily_add_node, create_a_list_from_NULL, .init = cr_redirect_stdout)
{
    char *ret = "This is my data";
    lily_list *first = NULL;
    lily_list *node = lily_create_node(ret);
    int chope = lily_add_node(&first, node, 7);

    cr_expect(chope == 0, "The function return value was %i, but expected 0", chope);
    cr_assert_not_null(node, "The node was NULL. Expected not NULL");
    cr_expect(first == node, "The first was not correct it was %p, but excpected %p", first, node);
    cr_expect(node->next == node, "The node->next was not correct");
    cr_expect(node->prev == node, "The node->prev was not correct");
    cr_expect(ret == node->data, "The node->data was %p. Expected %p", node->data, ret);
}

Test(tests_lily_add_node, add_a_node_to_existing_list_index_0, .init = cr_redirect_stdout)
{
    char *array[] = {"1", "2", "3", "4", 0};
    char *ret = "This is my data";
    lily_list *first = lily_create_list_from_array((void **)array);
    lily_list *second = lily_get_node_from_index(first, 0);
    lily_list *last = lily_get_node_from_index(first, -1);
    lily_list *node = lily_create_node(ret);
    int chope = lily_add_node(&first, node, 0);

    cr_expect(chope == 0, "The function return value was %i, but expected 0", chope);
    cr_assert_not_null(node, "The node was NULL. Expected not NULL");
    cr_expect(first == node, "The first was not correct it was %p, but excpected %p", first, node);
    cr_expect(node->next == second, "The node->next was not correct");
    cr_expect(node->prev == last, "The node->prev was not correct");
    cr_expect(last->next == node, "The last->next was not correct");
    cr_expect(second->prev == node, "The second->prev was not correct");
}

Test(tests_lily_add_node, add_a_node_to_existing_list_index_n1, .init = cr_redirect_stdout)
{
    char *array[] = {"1", "2", "3", "4", 0};
    char *ret = "This is my data";
    lily_list *first = lily_create_list_from_array((void **)array);
    lily_list *second = lily_get_node_from_index(first, 0);
    lily_list *last = lily_get_node_from_index(first, -1);
    lily_list *node = lily_create_node(ret);
    int chope = lily_add_node(&first, node, -1);

    cr_expect(chope == 0, "The function return value was %i, but expected 0", chope);
    cr_assert_not_null(node, "The node was NULL. Expected not NULL");
    cr_expect(first != node, "The first was not correct it was %p, but excpected different of %p", first, node);
    cr_expect(node->next == second, "The node->next was not correct");
    cr_expect(node->prev == last, "The node->prev was not correct");
    cr_expect(last->next == node, "The last->next was not correct");
    cr_expect(second->prev == node, "The second->prev was not correct");
}

Test(tests_lily_add_node, add_a_node_to_existing_list_but_node_already_in_list, .init = cr_redirect_stdout)
{
    char *array[] = {"1", "2", "3", "4", 0};
    lily_list *first = lily_create_list_from_array((void **)array);
    lily_list *node = lily_get_node_from_index(first, 2);
    int chope = lily_add_node(&first, node, -1);

    cr_expect(chope == -1, "The function return value was %i, but expected -1", chope);
}

Test(tests_lily_add_node, add_a_node_but_node_is_NULL, .init = cr_redirect_stdout)
{
    lily_list *first = NULL;
    lily_list *node = NULL;
    int chope = lily_add_node(&first, node, -1);

    cr_expect(chope == -1, "The function return value was %i, but expected -1", chope);
}