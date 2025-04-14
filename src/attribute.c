#include "attribute.h"

size_t getAttributesCapacity_BonusChest(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_DesertPyramid(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
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
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_Mineshaft(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_MonsterRoom(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)biome;
	if (version < Version_Alpha_1_0_14) return 0;
	switch (poolNumber) {
		case 0: switch (entryNumber) {
			case 9: return 2;
			default: return 0;
		}
		default: return 0;
	}
}

size_t getAttributesCapacity_StrongholdChestCorridor(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_StrongholdLibrary(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
}

size_t getAttributesCapacity_StrongholdRoomCrossing(int poolNumber, int entryNumber, enum Version version, enum Biome biome) {
	(void)poolNumber;
	(void)entryNumber;
	(void)version;
	(void)biome;
	return 0;
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