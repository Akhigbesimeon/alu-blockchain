#include "blockchain.h"
#include <stdio.h>

/**
 * block_mine - mines a block with requisite difficulty
 * @block: pointer to block to mine
 */
void
block_mine(block_t *block)
{
	uint64_t nonce = 0;
	uint8_t hash[SHA256_DIGEST_LENGTH];

	while (1) {
		block->info.nonce = nonce;
		block_hash(block, hash);
		
		if (hash_matches_difficulty(hash, block->info.difficulty))
			break;
			
		nonce++;
	}
	
	/* Copy the resulting hash to the block's hash field */
	memcpy(block->hash, hash, SHA256_DIGEST_LENGTH);

	/* Print the required "Block mined" output line if expected here */
	printf("Block mined: [%u] ", block->info.difficulty);
	for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		printf("%02x", hash[i]);
	}
	printf("\n");
}
