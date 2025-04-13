#ifndef _AMLL_LOOT_H
#define _AMLL_LOOT_H
#include "src/table.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Attempts to initialize the provided `lootTable` for the given source of loot, version, and biome, and returns whether
        it was successful.
    This operation is expensive, so if you plan to bruteforce loot seeds, I recommended first initializing all loot tables
   	    and *then* beginning your bruteforce.
    After calling this, the loot table must be freed with `freeLootTable(...)`before it can be reinitialized or destroyed.*/
bool initializeLootTable(LootTable *lootTable, enum Source source, enum Version version, enum Biome biome);

/* Retrieves the loot for the given `lootTable` under the given `lootSeed`; stores up to `outputCapacity` items in
        the provided `output` array; and returns the number of items stored, or -1 if a failure occurred.   
   The loot table must be initialized via `initializeLootTable(...)` before calling this.*/
ssize_t getLoot(const LootTable *const lootTable, uint64_t lootSeed, Item *const output, size_t outputCapacity);

/* Attempts to free all dynamically-allocated memory contained within the provided `lootTable`, and returns whether it was successful.*/
bool freeLootTable(LootTable *const lootTable);

// bool freeOutput(Item *const output, size_t outputCapacity);

#ifdef __cplusplus
}
#endif

#endif