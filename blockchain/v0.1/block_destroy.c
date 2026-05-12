#include <stdlib.h>
#include "blockchain.h"

/**
 * block_destroy - Deletes an existing Block
 * @block: Points to the Block to delete
 */
void block_destroy(block_t *block)
{
    /* Always check for NULL before freeing to prevent segmentation faults */
    if (block != NULL)
    {
        free(block);
    }
}
