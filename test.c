#include "loot.h"
#include <stdio.h>

const uint64_t GLOBAL_START_INTEGER = 0;
const uint64_t GLOBAL_INTEGERS_TO_CHECK = 100;

int main() {
	enum Source source = Source_Monster_Room;
	enum Version version = Version_1_4_5;
	enum Biome biome = Biome_None;

	LootTable lootTable;
	if (!initializeLootTable(&lootTable, source, version, biome)) {
		fprintf(stderr, "Error: Could not initialize the loot table for source %s under version %s in biome %s.\n", getSourceString(source), getVersionString(version), getBiomeString(biome));
		return 1;
	}
	
	Item output[MAX_CHEST_CAPACITY];
	if (!initializeOutputArray(output, sizeof(output)/sizeof(*output))) {
		fprintf(stderr, "Error: Could not initialize output array.\n");
		return 1;
	}

	for (uint64_t count = 0; count < GLOBAL_INTEGERS_TO_CHECK; ++count) {
		uint64_t lootSeed = GLOBAL_START_INTEGER + count;
		ssize_t lootCount = getLoot(&lootTable, lootSeed, output, sizeof(output)/sizeof(*output));

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
				printf("%d %s in slot %d", output[i].count, getItemString(output[i].type), output[i].containerIndex);
				if (output[i].attributeCount > 0) {
					printf(" {");
					for (int j = 0; j < output[i].attributeCount; ++j) {
						printf("%s", getAttributeString(output[i].attributes[j].name));
						if (output[i].attributes[j].level) printf(" %s", getLevelString(output[i].attributes[j].level));
						if (j < output[i].attributeCount - 1) printf(", ");
					}
					printf("}");
				}
				if (i < lootCount - 1) printf("\n\t");
			}
			printf("\n\n");
		}
	}

	if (!freeLootTable(&lootTable)) {
		fprintf(stderr, "Error: Could not free loot table for source %s under version %s in biome %s.\n", getSourceString(source), getVersionString(version), getBiomeString(biome));
		return 1;
	};
	if (!freeOutputArray(output, sizeof(output)/sizeof(*output))) {
		fprintf(stderr, "Error: Could not free output array.\n");
		return 1;
	};
	return 0;
}