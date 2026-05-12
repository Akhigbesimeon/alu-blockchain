#ifndef _LLIST_H_
#define _LLIST_H_

#include <stddef.h>

/* Use MT_SUPPORT_TRUE if the list should be thread-safe */
#define MT_SUPPORT_FALSE 0
#define MT_SUPPORT_TRUE  1

/* Node addition locations */
#define ADD_NODE_FRONT 0
#define ADD_NODE_BACK  1
#define ADD_NODE_INDEX 2

/**
 * struct node_s - singly linked list node
 * @data: pointer to the data stored in the node
 * @next: pointer to the next node
 */
typedef struct node_s
{
    void *data;
    struct node_s *next;
} node_t;

/**
 * struct llist_s - singly linked list structure
 * @nb_nodes: number of nodes in the list
 * @head: pointer to the first node
 * @tail: pointer to the last node
 * @mt_safe: thread-safety flag
 * @lock: mutex for thread-safety (if mt_safe is true)
 */
typedef struct llist_s
{
    unsigned int nb_nodes;
    node_t *head;
    node_t *tail;
    unsigned char mt_safe;
    /* Note: real implementation might include a pthread_mutex_t lock here */
} llist_t;

/* Function Prototypes */
llist_t *llist_create(int mt_safe);
int llist_add_node(llist_t *list, void *data, int mode);
int llist_destroy(llist_t *list, int free_data, void (*free_f)(void *));
void *llist_get_head(llist_t *list);

#endif /* _LLIST_H_ */
