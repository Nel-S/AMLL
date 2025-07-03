#ifndef _AMLL_LOOT_H
#define _AMLL_LOOT_H
#include "src/table.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Attempts to initialize the provided `lootTable` for the given source of loot, version, and biome, and returns whether
        it was successful.
    This operation is expensive, so if you plan to bruteforce loot seeds, first initialize all loot tables
   	    and *then* begin your bruteforce.
    After calling this, the loot table must be freed with `freeLootTable(...)`before it can be reinitialized or destroyed.*/
bool initializeLootTable(LootTable *lootTable, enum Source source, enum Version version, enum Biome biome);

/* Attempts to initialize the provided `outputArray`, so it can properly handle the memory allocations needed for storing attributes.
    Returns whether it was successful.*/
bool initializeOutputArray(Item *const outputArray, size_t outputArrayCapacity);

/* Retrieves the loot for the given `lootTable` under the given `lootSeed`; stores up to `outputCapacity` items in
        the provided `output` array; and returns the number of items stored, or -1 if a failure occurred.   
   The loot table must be initialized via `initializeLootTable(...)` before calling this.*/
ssize_t getLoot(const LootTable *const lootTable, uint64_t lootSeed, Item *const output, size_t outputCapacity);

// Attempts to free all dynamically-allocated memory contained within the provided `lootTable`, and returns whether it was successful.
bool freeLootTable(LootTable *const lootTable);

// Attempts to free all dynamically-allocated memory contained within the provided `outputArray`, and returns whether it was successful.
bool freeOutputArray(Item *const outputArray, size_t outputArrayCapacity);

#ifdef __cplusplus
}
#endif

#endif