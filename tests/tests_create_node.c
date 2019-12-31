/*
** EPITECH PROJECT, 2019
** tests library lily
** File description:
** lily_create_node
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "lily.h"

Test(tests_lily_create_node, create_a_node, .init = cr_redirect_stdout)
{
    char *ret = "This is my data";
    lily_list *node = lily_create_node(ret);
    cr_assert_not_null(node, "The result was %p. Expected not NULL", node);
    cr_expect_null(node->next, "The node->next was not NULL. Expected NULL");
    cr_expect_null(node->prev, "The node->prev was not NULL. Expected NULL");
    cr_expect(ret == node->data, "The node->data was %p. Expected %p", node->data, ret);
}

Test(tests_lily_create_node, create_a_node_with_data_NULL, .init = cr_redirect_stdout)
{
    char *ret = NULL;
    lily_list *node = lily_create_node(ret);
    cr_assert_not_null(node, "The result was %p. Expected not NULL", node);
    cr_expect_null(node->next, "The node->next was not NULL. Expected NULL");
    cr_expect_null(node->prev, "The node->prev was not NULL. Expected NULL");
    cr_expect(ret == node->data, "The node->data was %p. Expected %p", node->data, ret);
}