#ifndef _LLIST_H_
#define _LLIST_H_

#include <stddef.h>

/**
 * node_func_t - Prototype for a function applied to a node's data
 * @data: Pointer to the node's data
 * @arg: Extra argument
 * Return: 0 on success, otherwise 1
 */
typedef int (*node_func_t)(void *data, void *arg);

/**
 * node_dtor_t - Prototype for a function that frees a node's data
 * @data: Pointer to the node's data
 */
typedef void (*node_dtor_t)(void *data);

#define MT_SUPPORT_FALSE 0
#define MT_SUPPORT_TRUE  1
#define ADD_NODE_FRONT 0
#define ADD_NODE_BACK  1

typedef struct node_s
{
    void *data;
    struct node_s *next;
} node_t;

typedef struct llist_s
{
    unsigned int nb_nodes;
    node_t *head;
    node_t *tail;
    unsigned char mt_safe;
} llist_t;

llist_t *llist_create(int mt_safe);
int llist_add_node(llist_t *list, void *data, int mode);
int llist_destroy(llist_t *list, int free_data, node_dtor_t dtor);
int llist_for_each(llist_t *list, node_func_t func, void *arg);
int llist_size(llist_t *list);
void *llist_get_head(llist_t *list);

#endif /* _LLIST_H_ */
