/*
** EPITECH PROJECT, 2019
** library lily
** File description:
** header file
*/

#ifndef _LILY_H_
#define _LILY_H_

#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////
/// \brief void *data | lily_list *prev | lily_list *next
///
////////////////////////////////////////////////////////////
typedef struct lily_list
{
    void *data;
    struct lily_list *prev;
    struct lily_list *next;
} lily_list;

////////////////////////////////////////////////////////////
/// \brief Create a node with the pointer given as data
///
/// \param pointer to data
///
/// \return NULL if a problem occured, a pointer to the node otherwise
///
////////////////////////////////////////////////////////////
lily_list *lily_create_node(void *data);

////////////////////////////////////////////////////////////
/// \brief Destroy a node given as parameter, does not free the data
///
/// \param pointer to a node
///
////////////////////////////////////////////////////////////
void lily_destroy_node(lily_list **node);

////////////////////////////////////////////////////////////
/// \brief Destroy a node given as parameter, does free the data
///
/// \param pointer to a node
///
////////////////////////////////////////////////////////////
void lily_destroy_node_and_data(lily_list **node, void destroy(void *));

////////////////////////////////////////////////////////////
/// \brief Destroy a list with a pointer to an list's node,
/// does not free the data of the nodes
///
/// \param pointer to node
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_destroy_list(lily_list **list);

////////////////////////////////////////////////////////////
/// \brief Destroy a list with a pointer to an list's node,
/// does free the data of the nodes
///
/// \param pointer to node
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_destroy_list_and_data(lily_list **list, void destroy(void *));

////////////////////////////////////////////////////////////
/// \brief Get the node corresponding to the list's index
///
/// \param first node of a list, index of an node
///
/// \return NULL if a problem occured, the node otherwise
///
////////////////////////////////////////////////////////////
lily_list *lily_get_node_from_index(lily_list *first, int index);

////////////////////////////////////////////////////////////
/// \brief Add a node to a list, if *first is NULL it creates a list
///
/// \param pointer to first node of a list, pointer to the node to add,
/// index of where to add
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_add_node(lily_list **first, lily_list *node, int index);

////////////////////////////////////////////////////////////
/// \brief Get the length of a list from a list's node
///
/// \param pointer to a node which is in a list
///
/// \return -1 if a problem occured, the length of the list otherwise
///
////////////////////////////////////////////////////////////
int lily_get_list_length(lily_list *list);

////////////////////////////////////////////////////////////
/// \brief Get the index of an list's node
///
/// \param pointer to the first node of the list, pointer to a 
/// node which is in a list
///
/// \return -1 if a problem occured, the index of the node otherwise
///
////////////////////////////////////////////////////////////
int lily_get_index_from_node(lily_list *first, lily_list *node);

////////////////////////////////////////////////////////////
/// \brief Remove a node from a list
///
/// \param pointer to the first node of the list, pointer to the 
/// node to remove
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_rem_node(lily_list **first, lily_list *node);

////////////////////////////////////////////////////////////
/// \brief Create a list from an array
///
/// \param pointer to the start of the array
///
/// \return NULL if a problem occured, a pointer to the first
/// element pf the list otherwise
///
////////////////////////////////////////////////////////////
lily_list *lily_create_list_from_array(void **array);

////////////////////////////////////////////////////////////
/// \brief Move a node in a list
///
/// \param pointer to the start node of the list, pointer to
/// the node to move, the new index of the node
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_mov_node(lily_list **first, lily_list *node, int new_index);

////////////////////////////////////////////////////////////
/// \brief Inverse a list
///
/// \param pointer to the start node of the list
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_inv_list(lily_list **first);

////////////////////////////////////////////////////////////
/// \brief Sort a list the smallest data will be first
///
/// \param pointer to the start node of the list, pointer to a
/// function which can compare the data of two nodes and return an int
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_sort_list_az(lily_list **first, int cmp(void *, void *));

////////////////////////////////////////////////////////////
/// \brief Sort a list the biggest data will be first
///
/// \param pointer to the start node of the list, pointer to a
/// function which can compare the data of two nodes and return an int
///
/// \return -1 if a problem occured, 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_sort_list_za(lily_list **first, int cmp(void *, void *));

////////////////////////////////////////////////////////////
/// \brief Create an array from a list, the data of the type of
/// data's node must be the same
///
/// \param pointer to the start node of the list
///
/// \return NULL if a problem occured, a pointer to the array otherwise
///
////////////////////////////////////////////////////////////
void **lily_create_array_from_list(lily_list *first);

////////////////////////////////////////////////////////////
/// \brief Add a list to an other list at the index
///
/// \param pointer to the start node of the list_dest and and list_src and
/// an index
///
/// \return -1 if a problem occured, a 0 otherwise
///
////////////////////////////////////////////////////////////
int lily_add_list(lily_list **first_dest, lily_list *first_src, int index);

#endif //_LILY_H_