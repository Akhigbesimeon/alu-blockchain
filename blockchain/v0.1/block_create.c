#include "blockchain.h"
#include <string.h>
#include <time.h>
#include <llist.h>

/**
 * block_create - Creates a Block structure and initializes it.
 * @prev: A pointer to the previous Block in the Blockchain.
 * @data: Points to a memory area to duplicate in the Block's data.
 * @data_len: Stores the number of bytes to duplicate in data.
 *
 * Return: A pointer to the allocated Block, or NULL upon failure.
 */
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
    block_t *block;
    uint32_t copy_len;

    /* Allocate memory for the new block and initialize to zero */
    block = calloc(1, sizeof(*block));
    if (!block)
        return (NULL);

    /* Initialize block info based on previous block and defaults */
    block->info.index = prev->info.index + 1;
    block->info.difficulty = 0;
    block->info.timestamp = time(NULL);
    block->info.nonce = 0;
    memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);

    /* Handle data duplication with bounds checking */
    copy_len = data_len > BLOCKCHAIN_DATA_MAX ? BLOCKCHAIN_DATA_MAX : data_len;
    block->data.len = copy_len;
    
    if (data && copy_len > 0)
        memcpy(block->data.buffer, data, copy_len);

    /* 
     * Note: block->hash is already fully zeroed by calloc, 
     * satisfying the requirement without an explicit memset.
     */

    return (block);
}
