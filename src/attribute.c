#include "attribute.h"

bool copyAttribute(const Attribute *const oldAttribute, Attribute *const newAttribute) {
	if (!oldAttribute || !newAttribute) return false;
	newAttribute->name = oldAttribute->name;
	newAttribute->level = oldAttribute->level;
	newAttribute->maxLevel = oldAttribute->maxLevel;
	return true;
}

size_t getAttributesCapacity_BonusChest(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_DesertPyramid(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_Fortress(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_JungleTempleTrap(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_JungleTempleTreasure(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_Mineshaft(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_MonsterRoom(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0: switch (entryNumber) {
			case 9:
				if (version < Version_Alpha_1_0_14) return 0;
				if (version < Version_1_6_1) return 2; // Music Disc: 13 vs. Cat
				return 1; // Music Disc: 13
			case 10:
				if (version < Version_1_6_1) return 0;
				return 1; // Music Disc: Cat
			case 11:
				if (version < Version_1_4_6) return 0;
				if (version < Version_1_6_1) return 22; // Enchanted Book: All enchantments at the time
				return 0;
			case 15:
				if (version < Version_1_6_1) return 0;
				return 22; // Enchanted Book: All enchantments at the time
			default: return 0;
		}
		default: return 0;
	}
}

size_t getAttributesCapacity_StrongholdChestCorridor(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_StrongholdLibrary(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_StrongholdRoomCrossing(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return 22; // Enchanted Book: All enchantments at the time
		default: return 0;
	}
}

size_t getAttributesCapacity_Village(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity(int poolNumber, int entryNumber, enum Source source, enum Version version, enum Biome biome) {
	switch (source) {
		case Source_Bonus_Chest: return getAttributesCapacity_BonusChest(poolNumber, entryNumber, version, biome);
		case Source_Desert_Pyramid: return getAttributesCapacity_DesertPyramid(poolNumber, entryNumber, version, biome);
		case Source_Fortress: return getAttributesCapacity_Fortress(poolNumber, entryNumber, version, biome);
		case Source_Jungle_Temple_Trap: return getAttributesCapacity_JungleTempleTrap(poolNumber, entryNumber, version, biome);
		case Source_Jungle_Temple_Treasure: return getAttributesCapacity_JungleTempleTreasure(poolNumber, entryNumber, version, biome);
		case Source_Mineshaft: return getAttributesCapacity_Mineshaft(poolNumber, entryNumber, version, biome);
		case Source_Monster_Room: return getAttributesCapacity_MonsterRoom(poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Chest_Corridor: return getAttributesCapacity_StrongholdChestCorridor(poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Library: return getAttributesCapacity_StrongholdLibrary(poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Room_Crossing: return getAttributesCapacity_StrongholdRoomCrossing(poolNumber, entryNumber, version, biome);
		case Source_Village: return getAttributesCapacity_Village(poolNumber, entryNumber, version, biome);
		default: return 0;
	}
}


size_t copyEnchantments_All(Attribute *const output, size_t outputCapacity, enum Version version) {
	if (!output || !outputCapacity || version < Version_1_4_6) return 0;
	// Surely there must be a... better way to structure this...
	output[0] = (Attribute){Attribute_Protection, 1, 4};
	if (outputCapacity <= 1) return 1;
	output[1] = (Attribute){Attribute_Fire_Protection, 1, 4};
	if (outputCapacity <= 2) return 2;
	output[2] = (Attribute){Attribute_Feather_Falling, 1, 4};
	if (outputCapacity <= 3) return 3;
	output[3] = (Attribute){Attribute_Blast_Protection, 1, 4};
	if (outputCapacity <= 4) return 4;
	output[4] = (Attribute){Attribute_Projectile_Protection, 1, 4};
	if (outputCapacity <= 5) return 5;
	output[5] = (Attribute){Attribute_Respiration, 1, 3};
	if (outputCapacity <= 6) return 6;
	output[6] = (Attribute){Attribute_Aqua_Affinity, 1, 1};
	if (outputCapacity <= 7) return 7;
	output[7] = (Attribute){Attribute_Thorns, 1, 3};
	if (outputCapacity <= 8) return 8;
	output[8] = (Attribute){Attribute_Sharpness, 1, 5};
	if (outputCapacity <= 9) return 9;
	output[9] = (Attribute){Attribute_Smite, 1, 5};
	if (outputCapacity <= 10) return 10;
	output[10] = (Attribute){Attribute_Bane_of_Arthropods, 1, 5};
	if (outputCapacity <= 11) return 11;
	output[11] = (Attribute){Attribute_Knockback, 1, 2};
	if (outputCapacity <= 12) return 12;
	output[12] = (Attribute){Attribute_Fire_Aspect, 1, 2};
	if (outputCapacity <= 13) return 13;
	output[13] = (Attribute){Attribute_Looting, 1, 3};
	if (outputCapacity <= 14) return 14;
	output[14] = (Attribute){Attribute_Efficiency, 1, 5};
	if (outputCapacity <= 15) return 15;
	output[15] = (Attribute){Attribute_Silk_Touch, 1, 1};
	if (outputCapacity <= 16) return 16;
	output[16] = (Attribute){Attribute_Unbreaking, 1, 3};
	if (outputCapacity <= 17) return 17;
	output[17] = (Attribute){Attribute_Fortune, 1, 3};
	if (outputCapacity <= 18) return 18;
	output[18] = (Attribute){Attribute_Power, 1, 5};
	if (outputCapacity <= 19) return 19;
	output[19] = (Attribute){Attribute_Punch, 1, 2};
	if (outputCapacity <= 20) return 20;
	output[20] = (Attribute){Attribute_Flame, 1, 1};
	if (outputCapacity <= 21) return 21;
	output[21] = (Attribute){Attribute_Infinity, 1, 1};
	return 22;
}

size_t copyEnchantments_BonusChest(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)output;
	(void)outputCapacity;
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t copyEnchantments_DesertPyramid(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_Fortress(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)output;
	(void)outputCapacity;
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t copyEnchantments_JungleTempleTrap(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)output;
	(void)outputCapacity;
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t copyEnchantments_JungleTempleTreasure(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_Mineshaft(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_MonsterRoom(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)biome;
	switch (poolNumber) {
		case 0: switch (entryNumber) {
			case 11:
				if (version < Version_1_4_6) return 0;
				if (version < Version_1_6_1) return copyEnchantments_All(output, outputCapacity, version);
				return 0;
			case 15:
				if (version < Version_1_6_1) return 0;
				return copyEnchantments_All(output, outputCapacity, version);
			default: return 0;
		}
		default: return 0;
	}
}

size_t copyEnchantments_StrongholdChestCorridor(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
			return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_StrongholdLibrary(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
				return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_StrongholdRoomCrossing(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)entryNumber;
	(void)biome;
	switch (poolNumber) {
		case -1:
				if (version < Version_1_4_6) return 0;
				return copyEnchantments_All(output, outputCapacity, version);
		default: return 0;
	}
}

size_t copyEnchantments_Village(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)output;
	(void)outputCapacity;
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t copyEnchantments(Attribute *const output, size_t outputCapacity, int poolNumber, int entryNumber, enum Source source, enum Version version, enum Biome biome) {
	switch (source) {
		case Source_Bonus_Chest: return copyEnchantments_BonusChest(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Desert_Pyramid: return copyEnchantments_DesertPyramid(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Fortress: return copyEnchantments_Fortress(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Jungle_Temple_Trap: return copyEnchantments_JungleTempleTrap(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Jungle_Temple_Treasure: return copyEnchantments_JungleTempleTreasure(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Mineshaft: return copyEnchantments_Mineshaft(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Monster_Room: return copyEnchantments_MonsterRoom(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Chest_Corridor: return copyEnchantments_StrongholdChestCorridor(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Library: return copyEnchantments_StrongholdLibrary(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Stronghold_Room_Crossing: return copyEnchantments_StrongholdRoomCrossing(output, outputCapacity, poolNumber, entryNumber, version, biome);
		case Source_Village: return copyEnchantments_Village(output, outputCapacity, poolNumber, entryNumber, version, biome);
		default: return 0;
	}
}