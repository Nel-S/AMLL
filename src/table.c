#include "table.h"
#include <string.h>

enum TableFlags {
	Sum_of_Entries_Weights = -1
};

bool copyItem(const Item *const oldItem, Item *const newItem) {
	if (!oldItem || !newItem) return false;
	// If attributes exist, copy them and their count
	if (oldItem->attributeCount > 0) {
		if (newItem->attributesCapacity < (size_t)oldItem->attributeCount) {
			if (!newItem->attributesCapacity) newItem->attributes = (Attribute *)calloc(oldItem->attributeCount, sizeof(Attribute));
			else newItem->attributes = (Attribute *)realloc(newItem->attributes, sizeof(Attribute)*oldItem->attributeCount);
			if (!newItem->attributes) return false;
			newItem->attributesCapacity = (size_t)oldItem->attributeCount;
		}
		memcpy(newItem->attributes, oldItem->attributes, sizeof(Attribute)*oldItem->attributeCount);
	}
	// Copy remaining statistics
	newItem->attributeCount = oldItem->attributeCount;
	newItem->containerIndex = oldItem->containerIndex;
	newItem->count = oldItem->count;
	newItem->type = oldItem->type;
	return true;
}

// To save on typing
static inline void setEntry(LootEntry *const entry, enum ItemType type, int minCount, int maxCount, int weight, int rarity, int minPossibleAttributes, int maxPossibleAttributes) {
	entry->type = type;
	entry->minCount = minCount;
	entry->maxCount = maxCount;
	entry->weight = weight;
	entry->rarity = rarity;
	entry->minPossibleAttributes = minPossibleAttributes;
	entry->maxPossibleAttributes = maxPossibleAttributes;
}

bool addLootToTable_BonusChest(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 10, lootTable->pools[0].maxRolls = 10;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-8
			setEntry(&lootTable->pools[0].entries[0], Item_Stick, 1, 3, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Oak_Planks, 1, 3, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Oak_Log, 1, 3, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Stone_Axe, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Wooden_Axe, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Stone_Pickaxe, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Wooden_Pickaxe, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Apple, 2, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Bread, 2, 3, 3, 1, 0, 0);
	return true;
}

bool addLootToTable_DesertPyramid(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-5
			setEntry(&lootTable->pools[0].entries[0], Item_Diamond, 1, 3, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Gold_Ingot, 2, 7, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Emerald, 1, 3, 2, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Bone, 4, 6, 20, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Rotten_Flesh, 3, 7, 16, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 6
			setEntry(&lootTable->pools[0].entries[6], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	if (version < Version_1_6_1) return true;
			// Entries 6-10
			setEntry(&lootTable->pools[0].entries[6], Item_Saddle, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Iron_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Golden_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Diamond_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[10], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_Fortress(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_6_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 5;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-10
			setEntry(&lootTable->pools[0].entries[0], Item_Diamond, 1, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Iron_Ingot, 1, 5, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Gold_Ingot, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Golden_Sword, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Golden_Chestplate, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Flint_and_Steel, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Nether_Wart, 3, 7, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Saddle, 1, 1, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Golden_Horse_Armor, 1, 1, 8, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Iron_Horse_Armor, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[10], Item_Diamond_Horse_Armor, 1, 1, 3, 1, 0, 0);
	return true;
}

bool addLootToTable_JungleTempleTrap(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_DISPENSER_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 2;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entry 0
			setEntry(&lootTable->pools[0].entries[0], Item_Arrow, 2, 7, 30, 1, 0, 0);
	return true;
}

bool addLootToTable_JungleTempleTreasure(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_3_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-5
			setEntry(&lootTable->pools[0].entries[0], Item_Diamond, 1, 3, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Gold_Ingot, 2, 7, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Emerald, 1, 3, 2, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Bone, 4, 6, 20, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Rotten_Flesh, 3, 7, 16, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 6
			setEntry(&lootTable->pools[0].entries[6], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	if (version < Version_1_6_1) return true;
			// Entries 6-10
			setEntry(&lootTable->pools[0].entries[6], Item_Saddle, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Iron_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Golden_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Diamond_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[10], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_Mineshaft(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 3, lootTable->pools[0].maxRolls = 6;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-9
			setEntry(&lootTable->pools[0].entries[0], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Gold_Ingot, 1, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Redstone, 4, 9, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Lapis_Lazuli, 4, 9, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Diamond, 1, 2, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Coal, 3, 8, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Bread, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Iron_Pickaxe, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Rail, 4, 8, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Melon_Seeds, 2, 4, 10, 1, 0, 0);
	if (version < Version_1_0) return true;
			// Entry 10
			setEntry(&lootTable->pools[0].entries[10], Item_Pumpkin_Seeds, 2, 4, 10, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 11
			setEntry(&lootTable->pools[0].entries[11], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	if (version < Version_1_6_1) return true;
			// Entries 11-13
			setEntry(&lootTable->pools[0].entries[11], Item_Saddle, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[12], Item_Iron_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[13], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_MonsterRoom(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Infdev_20100625_1917) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 8, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = 10;
			// Entries 0-7
			setEntry(&lootTable->pools[0].entries[0], Item_Saddle, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Iron_Ingot, 1, 4, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Bread, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Wheat, 1, 4, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Gunpowder, 1, 4, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_String, 1, 4, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Bucket, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Golden_Apple, 1, 1, 1, 100, 0, 0);
	if (version < Version_Alpha_1_0_1_01) return true;
		// Total weight increased
		lootTable->pools[0].summedWeight = 11;
			// Entry 8: Redstone
			setEntry(&lootTable->pools[0].entries[8], Item_Redstone, 1, 4, 1, 2, 0, 0);
	if (version < Version_Alpha_1_0_14) return true;
			// Entry 9: Music Disc
			setEntry(&lootTable->pools[0].entries[9], Item_Music_Disc, 1, 1, 1, 10, 1, 1);
				// Attributes 0-1
				if (1 <= lootTable->pools[0].entries[9].possibleAttributeCapacity) lootTable->pools[0].entries[9].possibleAttributes[0] = (Attribute){Attribute_Disc_13, 0, 0};
				if (2 <= lootTable->pools[0].entries[9].possibleAttributeCapacity) lootTable->pools[0].entries[9].possibleAttributes[1] = (Attribute){Attribute_Disc_Cat, 0, 0};
	if (version < Version_Beta_1_4) return true;
			// Entry 10: Cocoa Beans
			setEntry(&lootTable->pools[0].entries[10], Item_Cocoa_Beans, 1, 1, 1, 1, 0, 0);
	if (version < Version_1_4_6) return true;
		// Total weight increased
		lootTable->pools[0].summedWeight = 12;
			// Entry 11: Enchanted Book
			setEntry(&lootTable->pools[0].entries[11], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes 0-21
				if (copyEnchantments(lootTable->pools[0].entries[11].possibleAttributes, lootTable->pools[0].entries[11].possibleAttributeCapacity, 0, 11, Source_Monster_Room, version, biome) < lootTable->pools[0].entries[11].possibleAttributeCapacity) return false;
	if (version < Version_1_6_1) return true;
		// Ported to same system as other loot sources
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Saddle
			lootTable->pools[0].entries[0].weight = 10;
			// Iron Ingot
			lootTable->pools[0].entries[1].weight = 10;
			// Bread
			lootTable->pools[0].entries[2].weight = 10;
			// Wheat
			lootTable->pools[0].entries[3].weight = 10;
			// Gunpowder
			lootTable->pools[0].entries[4].weight = 10;
			// String
			lootTable->pools[0].entries[5].weight = 10;
			// Bucket
			lootTable->pools[0].entries[6].weight = 10;
			// Golden Apple
			lootTable->pools[0].entries[7].rarity = 1;
			// Redstone
			lootTable->pools[0].entries[8].weight = 10;
			lootTable->pools[0].entries[8].rarity = 1;
			// Music Disc 13
			lootTable->pools[0].entries[9].weight = 10;
			lootTable->pools[0].entries[9].rarity = 1;
			// [13 Attribute was already set during Alpha 1.0.14 above]
			// Entries 10-13
			setEntry(&lootTable->pools[0].entries[10], Item_Music_Disc, 1, 1, 10, 1, 1, 1);
				// Attribute 0
				if (1 <= lootTable->pools[0].entries[10].possibleAttributeCapacity) lootTable->pools[0].entries[10].possibleAttributes[0] = (Attribute){Attribute_Disc_Cat, 0, 0};
			setEntry(&lootTable->pools[0].entries[11], Item_Name_Tag, 1, 1, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[12], Item_Golden_Horse_Armor, 1, 1, 2, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[13], Item_Iron_Horse_Armor, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[14], Item_Diamond_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[15], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes 0-21
				if (copyEnchantments(lootTable->pools[0].entries[15].possibleAttributes, lootTable->pools[0].entries[15].possibleAttributeCapacity, 0, 15, Source_Monster_Room, version, biome) < lootTable->pools[0].entries[15].possibleAttributeCapacity) return false;
	return true;
}

bool addLootToTable_StrongholdChestCorridor(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_0) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 2, lootTable->pools[0].maxRolls = 3;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-13
			setEntry(&lootTable->pools[0].entries[0], Item_Ender_Pearl, 1, 1, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Diamond, 1, 3, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Gold_Ingot, 1, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Redstone, 4, 9, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Bread, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Apple, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Iron_Pickaxe, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Iron_Sword, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Iron_Chestplate, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[10], Item_Iron_Helmet, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[11], Item_Iron_Leggings, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[12], Item_Iron_Boots, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[13], Item_Golden_Apple, 1, 1, 1, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 14
			setEntry(&lootTable->pools[0].entries[14], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	if (version < Version_1_6_1) return true;
			// Entries 14-18
			setEntry(&lootTable->pools[0].entries[14], Item_Saddle, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[15], Item_Iron_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[16], Item_Golden_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[17], Item_Diamond_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[18], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_StrongholdLibrary(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-3
			setEntry(&lootTable->pools[0].entries[0], Item_Book, 1, 3, 20, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Paper, 2, 7, 20, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Map, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Compass, 1, 1, 1, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 4
			setEntry(&lootTable->pools[0].entries[4], Item_Enchanted_Book, 1, 5, 2, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_StrongholdRoomCrossing(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_Beta_1_8) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 1, lootTable->pools[0].maxRolls = 4;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-6
			setEntry(&lootTable->pools[0].entries[0], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Gold_Ingot, 1, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Redstone, 4, 9, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Coal, 3, 8, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Bread, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Apple, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Iron_Pickaxe, 1, 1, 1, 1, 0, 0);
	if (version < Version_1_4_6) return true;
			// Entry 7
			setEntry(&lootTable->pools[0].entries[7], Item_Enchanted_Book, 1, 1, 1, 1, 1, 1);
				// Attributes are precomputed
	return true;
}

bool addLootToTable_Village(LootTable *const lootTable, enum Version version, enum Biome biome) {
	(void)biome;
	if (!lootTable || version < Version_1_1) return false;
	lootTable->prngType = PRNG_java_util_Random;
	lootTable->containerCapacity = MAX_CHEST_CAPACITY;
		// Pool 0
		lootTable->pools[0].minRolls = 3, lootTable->pools[0].maxRolls = 8;
		lootTable->pools[0].summedWeight = Sum_of_Entries_Weights;
			// Entries 0-12
			setEntry(&lootTable->pools[0].entries[0], Item_Diamond, 1, 3, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[1], Item_Iron_Ingot, 1, 5, 10, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[2], Item_Gold_Ingot, 1, 3, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[3], Item_Bread, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[4], Item_Apple, 1, 3, 15, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[5], Item_Iron_Pickaxe, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[6], Item_Iron_Sword, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[7], Item_Iron_Chestplate, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[8], Item_Iron_Helmet, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[9], Item_Iron_Leggings, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[10], Item_Iron_Boots, 1, 1, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[11], Item_Obsidian, 3, 7, 5, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[12], Item_Oak_Sapling, 3, 7, 5, 1, 0, 0);
	if (version < Version_1_6_1) return true;
			// Entries 13-16
			setEntry(&lootTable->pools[0].entries[13], Item_Saddle, 1, 1, 3, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[14], Item_Iron_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[15], Item_Golden_Horse_Armor, 1, 1, 1, 1, 0, 0);
			setEntry(&lootTable->pools[0].entries[16], Item_Diamond_Horse_Armor, 1, 1, 1, 1, 0, 0);
	return true;
}

bool addLootToTable(LootTable *const lootTable, enum Source source, enum Version version, enum Biome biome) {
	if (!lootTable) return false;
	switch (source) {
		case Source_Bonus_Chest:
			if (!addLootToTable_BonusChest(lootTable, version, biome)) return false;
			break;
		case Source_Desert_Pyramid:
			if (!addLootToTable_DesertPyramid(lootTable, version, biome)) return false;
			break;
		case Source_Fortress:
			if (!addLootToTable_Fortress(lootTable, version, biome)) return false;
			break;
		case Source_Jungle_Temple_Trap:
			if (!addLootToTable_JungleTempleTrap(lootTable, version, biome)) return false;
			break;
		case Source_Jungle_Temple_Treasure:
			if (!addLootToTable_JungleTempleTreasure(lootTable, version, biome)) return false;
			break;
		case Source_Mineshaft:
			if (!addLootToTable_Mineshaft(lootTable, version, biome)) return false;
			break;
		case Source_Monster_Room:
			if (!addLootToTable_MonsterRoom(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Chest_Corridor:
			if (!addLootToTable_StrongholdChestCorridor(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Library:
			if (!addLootToTable_StrongholdLibrary(lootTable, version, biome)) return false;
			break;
		case Source_Stronghold_Room_Crossing:
			if (!addLootToTable_StrongholdRoomCrossing(lootTable, version, biome)) return false;
			break;
		case Source_Village:
			if (!addLootToTable_Village(lootTable, version, biome)) return false;
			break;
		default: return false;
	}
	// If summed weight was flagged as being the sum of entries' weights, calculate summed weight 
	for (size_t p = 0; p < lootTable->poolCount; ++p) {
		if (lootTable->pools[p].summedWeight != Sum_of_Entries_Weights) continue;
		lootTable->pools[p].summedWeight = 0;
		for (size_t e = 0; e < lootTable->pools[p].entryCount; ++e) lootTable->pools[p].summedWeight += lootTable->pools[p].entries[e].weight;
	}
	return true;
}