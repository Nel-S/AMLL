#include "loot.h"
#include <stdio.h>

const uint64_t GLOBAL_START_INTEGER = 0;
const uint64_t GLOBAL_INTEGERS_TO_CHECK = 100;

int main() {
	LootTable lootTable;
	enum Structure structure = Structure_Mineshaft;
	enum Version version = Version_Beta_1_8;
	enum Biome biome = Biome_None;
	if (!initializeLootTable(&lootTable, structure, version, biome)) {
		fprintf(stderr, "Error: Could not initialize the loot table for structure %s under version %s in biome %s.\n", getStructureString(structure), getVersionString(version), getBiomeString(biome));
		return 1;
	}
	Item loot[MAX_CHEST_CAPACITY];
	for (uint64_t count = 0; count < GLOBAL_INTEGERS_TO_CHECK; ++count) {
		uint64_t lootSeed = GLOBAL_START_INTEGER + count;
		ssize_t lootCount = getLoot(&lootTable, lootSeed, loot, sizeof(loot)/sizeof(*loot));
		printf("%" PRId64 ":\t", lootSeed);
		if (lootCount < 0) {
			printf("[Invalid]\n\n");
			continue;
		}
		else if (!lootCount) {
			printf("[Empty]\n\n");
			continue;
		}
		else {
			for (ssize_t i = 0; i < lootCount; ++i) {
				printf("%d %s in slot %d", loot[i].count, getItemString(loot[i].type), loot[i].chestIndex);
				if (loot[i].attributesCount) {
					printf(" {");
					for (size_t j = 0; j < loot[i].attributesCount; ++j) {
						printf("%s ", getAttributesString(loot[i].attributes[j]));
					}
					printf("}");
				}
				if (i < lootCount - 1) printf("\n\t");
			}
			printf("\n\n");
		}
	}
	if (!freeLootTable(&lootTable)) {
		fprintf(stderr, "Error: Could not free loot table for structure %s under version %s in biome %s.\n", getStructureString(structure), getVersionString(version), getBiomeString(biome));
		return 1;
	};
	// if (!freeOutput(loot, sizeof(loot)/sizeof(*loot))) {
	// 	fprintf(stderr, "Error: Could not free output array.\n");
	// 	return 1;
	// };
	// printf("Output successfully freed.\n");
	return 0;
}