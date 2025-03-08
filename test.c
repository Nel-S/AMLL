#include "loot.h"
#include <stdio.h>

int main() {
	setbuf(stdout, NULL);
	LootTable lootTable;
	enum Structure structure = Structure_Dungeon;
	enum Version version = Beta_1_4;
	enum Biome biome = Biome_None;
	if (!constructLootTable(structure, version, biome, &lootTable)) {
		fprintf(stderr, "Error: Could not construct loot table for structure %s under version %s in biome %s.\n", getStructureString(structure), getVersionString(version), getBiomeString(biome));
		return 1;
	}
	// printf("It was constructed!\n");
	Item loot[MAX_CHEST_CAPACITY];
	for (uint64_t lootSeed = 0; lootSeed < 100; ++lootSeed) {
		ssize_t lootCount = getLoot(&lootTable, lootSeed, loot, sizeof(loot)/sizeof(*loot));
		printf("%" PRId64 ":\t", lootSeed);
		if (lootCount < 0) {
			printf("[Invalid]\n");
			continue;
		}
		if (!lootCount) {
			printf("[Empty]\n");
			continue;
		}
		for (ssize_t i = 0; i < lootCount; ++i) {
			printf("%d %s in slot %d", loot[i].count, getItemString(loot[i].type), loot[i].chestIndex);
			if (loot[i].attributesCount) {
				printf(" {");
				for (size_t j = 0; j < loot[i].attributesCount; ++j) {
					printf("%s ", getAttributesString(loot[i].attributes[j]));
				}
				printf("}");
			}
			printf("\n\t");
		}
		printf("\n");
	}
	return 0;
}