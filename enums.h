#ifndef _AMLL_ENUMS_H
#define _AMLL_ENUMS_H

#include <stddef.h>

// All supported loot sources.
enum Source {
	Source_Bonus_Chest,
	Source_Desert_Pyramid,
	Source_Jungle_Temple_Trap,
	Source_Jungle_Temple_Treasure,
	Source_Mineshaft,
	Source_Monster_Room, Source_Dungeon = Source_Monster_Room,
	Source_Stronghold_Chest_Corridor,
	Source_Stronghold_Library,
	Source_Stronghold_Room_Crossing,
	Source_Village,
};

// All existent Java Edition versions.
enum Version {
	Version_rd_132211,
	Version_rd_132328,
	Version_rd_160052,
	Version_rd_161348,
	Version_0_0_11a,
	Version_0_0_12a_03,
	Version_0_0_13a, Version_0_0_13a_03,
	Version_0_0_14a_08,
	Version_0_0_15a,
	Version_0_0_16a_02,
	Version_0_0_17a,
	Version_0_0_18a_02,
	Version_0_0_19a_04, Version_0_0_19a_06,
	Version_0_0_20a_01, Version_0_0_20a_02,
	Version_0_0_21a,
	Version_0_0_22a_05,
	Version_0_0_23a_01,
	Version_0_24_SURVIVAL_TEST_03,
	Version_0_25_05_SURVIVAL_TEST,
	Version_0_27_SURVIVAL_TEST,
	Version_0_28_01,
	Version_0_29, Version_0_29_01, Version_0_29_02,
	Version_0_30,
	Version_0_31_20091223_1459,
	Version_0_31_20091231_2255,
	Version_0_31_20100104_2258,
	Version_0_31_20100110,
	Version_0_31_20100124_2310,
	Version_0_31_20100125,
	Version_0_31_20100128_2304,
	Version_0_31_20100129_1452,
	Version_0_31_20100130,
	Version_0_31_20100131_2244,
	Version_0_31_20100201_0025, Version_0_31_20100201_2227,
	Version_0_31_20100202,
	Version_Indev_20100206_2103,
	Version_Indev_20100207_1101, Version_Indev_20100207_1703,
	Version_Indev_20100212_1210, Version_Indev_20100212_1622,
	Version_Indev_20100213,
	Version_Indev_20100214,
	Version_Indev_20100218_0016,
	Version_Indev_20100219,
	Version_Indev_20100223,
	Version_Infdev_20100227_1433,
	Version_Infdev_20100313,
	Version_Infdev_20100316,
	Version_Infdev_20100320,
	Version_Infdev_20100321,
	Version_Infdev_20100325_1640,
	Version_Infdev_20100327,
	Version_Infdev_20100330_1511,
	Version_Infdev_20100413_1953,
	Version_Infdev_20100414,
	Version_Infdev_20100415,
	Version_Infdev_20100420,
	Version_Infdev_20100607,
	Version_Infdev_20100608,
	Version_Infdev_20100611,
	Version_Infdev_20100615,
	Version_Infdev_20100616_1808,
	Version_Infdev_20100617_1205, Version_Infdev_20100617_1531,
	Version_Infdev_20100618,
	Version_Infdev_20100624,
	Version_Infdev_20100625_0922, Version_Infdev_20100625_1917,
	Version_Infdev_20100627,
	Version_Infdev_20100629,
	Version_Infdev_20100630_1340,
	Version_Infdev_20100630_1835, Version_Alpha_1_0_0 = Version_Infdev_20100630_1835,
		Version_Alpha_1_0_1_01, Version_Alpha_1_0_2_01, Version_Alpha_1_0_2_02, Version_Alpha_1_0_3, Version_Alpha_1_0_4, Version_Alpha_1_0_5_01, Version_Alpha_1_0_6, Version_Alpha_1_0_6_01,
		Version_Alpha_1_0_6_03 , Version_Alpha_1_0_7    , Version_Alpha_1_0_8_01, Version_Alpha_1_0_9 , Version_Alpha_1_0_10   , Version_Alpha_1_0_11   , Version_Alpha_1_0_12   ,
		Version_Alpha_1_0_13   , Version_Alpha_1_0_13_01, Version_Alpha_1_0_14  , Version_Alpha_1_0_15, Version_Alpha_1_0_16_01, Version_Alpha_1_0_16_02, Version_Alpha_1_0_17_02, Version_Alpha_1_0_17_03, Version_Alpha_1_0_17_04,
	Version_Alpha_1_1_0, Version_Alpha_1_1_1, Version_Alpha_1_1_2, Version_Alpha_1_1_2_01,
	Version_Alpha_1_2_0_01, Version_Alpha_1_2_0_02, Version_Alpha_1_2_1_01, Version_Alpha_1_2_2, Version_Alpha_1_2_3, Version_Alpha_1_2_3_01, Version_Alpha_1_2_3_02, Version_Alpha_1_2_3_04,
		Version_Alpha_1_2_3_05, Version_Alpha_1_2_4_01, Version_Alpha_1_2_5, Version_Alpha_1_2_6,
	Version_Beta_1_0, Version_Beta_1_0_01, Version_Beta_1_0_2,
	Version_Beta_1_1, Version_Beta_1_1_01, Version_Beta_1_1_02,
	Version_Beta_1_2, Version_Beta_1_2_01, Version_Beta_1_2_02,
	Version_Beta_1_3, Version_Beta_1_3_01,
	Version_Beta_1_4, Version_Beta_1_4_01,
	Version_Beta_1_5, Version_Beta_1_5_01, Version_Beta_1_5_02,
	Version_Beta_1_6, Version_Beta_1_6_1 , Version_Beta_1_6_2 , Version_Beta_1_6_3, Version_Beta_1_6_4, Version_Beta_1_6_5, Version_Beta_1_6_6,
	Version_Beta_1_7, Version_Beta_1_7_01, Version_Beta_1_7_2 , Version_Beta_1_7_3,
	Version_Beta_1_8, Version_Beta_1_8_1,
	Version_1_0,
	Version_1_1,
	Version_1_2  , Version_1_2_1 , Version_1_2_2 , Version_1_2_3 , Version_1_2_4 , Version_1_2_5 ,
	Version_1_3_1, Version_1_3_2 ,
	Version_1_4_2, Version_1_4_4 , Version_1_4_5 , Version_1_4_6 , Version_1_4_7 ,
	Version_1_5  , Version_1_5_1 , Version_1_5_2 ,
	Version_1_6_1, Version_1_6_2 , Version_1_6_4 ,
	Version_1_7_2, Version_1_7_4 , Version_1_7_5 , Version_1_7_6 , Version_1_7_7 , Version_1_7_8 , Version_1_7_9 , Version_1_7_10,
	Version_1_8  , Version_1_8_1 , Version_1_8_2 , Version_1_8_3 , Version_1_8_4 , Version_1_8_5 , Version_1_8_6 , Version_1_8_7 , Version_1_8_8, Version_1_8_9,
	Version_1_9  , Version_1_9_1 , Version_1_9_2 , Version_1_9_3 , Version_1_9_4 ,
	Version_1_10 , Version_1_10_1, Version_1_10_2,
	Version_1_11 , Version_1_11_1, Version_1_11_2,
	Version_1_12 , Version_1_12_1, Version_1_12_2,
	Version_1_13 , Version_1_13_1, Version_1_13_2,
	Version_1_14 , Version_1_14_1, Version_1_14_2, Version_1_14_3, Version_1_14_4,
	Version_1_15 , Version_1_15_1, Version_1_15_2,
	Version_1_16 , Version_1_16_1, Version_1_16_2, Version_1_16_3, Version_1_16_4, Version_1_16_5,
	Version_1_17 , Version_1_17_1,
	Version_1_18 , Version_1_18_1, Version_1_18_2,
	Version_1_19 , Version_1_19_1, Version_1_19_2, Version_1_19_3, Version_1_19_4,
	Version_1_20 , Version_1_20_1, Version_1_20_2, Version_1_20_3, Version_1_20_4, Version_1_20_5, Version_1_20_6,
	Version_1_21 , Version_1_21_1, Version_1_21_2, Version_1_21_3, Version_1_21_4, Version_1_21_5,
};

// All supported biomes.
enum Biome {
	Biome_None,
};

// All possible output loot items.
enum ItemType {
	Item_None,
	Item_Apple,
	Item_Arrow,
	Item_Bone,
	Item_Book,
	Item_Bread,
	Item_Bucket,
	Item_Coal,
	Item_Cocoa_Beans, Item_Coco_Beans = Item_Cocoa_Beans,
	Item_Compass,
	Item_Diamond,
	Item_Emerald,
	Item_Ender_Pearl,
	Item_Filled_Map,
	Item_Gold_Ingot,
	Item_Golden_Apple,
	Item_Gunpowder,
	Item_Iron_Boots,
	Item_Iron_Chestplate,
	Item_Iron_Helmet,
	Item_Iron_Ingot,
	Item_Iron_Leggings,
	Item_Iron_Pickaxe,
	Item_Iron_Sword,
	Item_Lapis_Lazuli,
	Item_Log,
	Item_Melon_Seeds,
	Item_Music_Disc,
	Item_Obsidian,
	Item_Paper,
	Item_Planks,
	Item_Pumpkin_Seeds,
	Item_Rail,
	Item_Redstone,
	Item_Rotten_Flesh,
	Item_Saddle,
	Item_Sapling,
	Item_Stick,
	Item_Stone_Axe,
	Item_Stone_Pickaxe,
	Item_String,
	Item_Wheat,
	Item_Wooden_Axe,
	Item_Wooden_Pickaxe,
};

// All possible output loot item attributes.
enum Attributes {
	Attributes_Disc_13,
	Attributes_Disc_Cat,
};

// All possible pseudorandom number generators (PRNGs).
enum PRNGType {
	PRNG_java_util_Random,
	PRNG_Mersenne_Twister,
	PRNG_Xoroshiro128_Plus_Plus
};

// Convienence functions for printing the enums as strings
#ifdef __cplusplus
extern "C" {
#endif

static inline const char *getSourceString(enum Source source) {
	switch (source) {
		case Source_Bonus_Chest: return "Bonus Chest";
		case Source_Desert_Pyramid: return "Desert Pyramid";
		case Source_Jungle_Temple_Trap: return "Jungle Temple (Trap)";
		case Source_Jungle_Temple_Treasure: return "Jungle Temple (Treasure)";
		case Source_Mineshaft: return "Mineshaft";
		case Source_Monster_Room: return "Monster Room";
		case Source_Stronghold_Chest_Corridor: return "Stronghold (Chest Corridor)";
		case Source_Stronghold_Library: return "Stronghold (Library)";
		case Source_Stronghold_Room_Crossing: return "Stronghold (Room Crossing)";
		case Source_Village: return "Village";
		default: return "";
	}
}

static inline const char *getVersionString(enum Version version) {
	switch (version) {
		case Version_rd_132211: return "rd-132211";
		case Version_rd_132328: return "rd-132328";
		case Version_rd_160052: return "rd-160052";
		case Version_rd_161348: return "rd-161348";
		case Version_0_0_11a   : return "0.0.11a";
		case Version_0_0_12a_03: return "0.0.12a_03";
		case Version_0_0_13a   : return "0.0.13a";
		case Version_0_0_13a_03: return "0.0.13a_03";
		case Version_0_0_14a_08: return "0.0.14a_08";
		case Version_0_0_15a   : return "0.0.15a";
		case Version_0_0_16a_02: return "0.0.16a_02";
		case Version_0_0_17a   : return "0.0.17a";
		case Version_0_0_18a_02: return "0.0.18a_02";
		case Version_0_0_19a_04: return "0.0.19a_04";
		case Version_0_0_19a_06: return "0.0.19a_06";
		case Version_0_0_20a_01: return "0.0.20a_01";
		case Version_0_0_20a_02: return "0.0.20a_02";
		case Version_0_0_21a   : return "0.0.21a";
		case Version_0_0_22a_05: return "0.0.22a_05";
		case Version_0_0_23a_01: return "0.0.23a_01";
		case Version_0_24_SURVIVAL_TEST_03: return "0.24_SURVIVAL_TEST_03";
		case Version_0_25_05_SURVIVAL_TEST: return "0.25_05 SURVIVAL TEST";
		case Version_0_27_SURVIVAL_TEST   : return "0.27 SURVIVAL TEST";
		case Version_0_28_01: return "0.28_01";
		case Version_0_29   : return "0.29";
		case Version_0_29_01: return "0.29_01";
		case Version_0_29_02: return "0.29_02";
		case Version_0_30   : return "0.30";
		case Version_0_31_20091223_1459: return "0.31 20091223-1459";
		case Version_0_31_20091231_2255: return "0.31 20091231-2255";
		case Version_0_31_20100104_2258: return "0.31 20100104-2258";
		case Version_0_31_20100110     : return "0.31 20100110";
		case Version_0_31_20100124_2310: return "0.31 20100124-2310";
		case Version_0_31_20100125     : return "0.31 20100125";
		case Version_0_31_20100128_2304: return "0.31 20100128-2304";
		case Version_0_31_20100129_1452: return "0.31 20100129-1452";
		case Version_0_31_20100130     : return "0.31 20100130";
		case Version_0_31_20100131_2244: return "0.31 20100131-2244";
		case Version_0_31_20100201_0025: return "0.31 20100201-0025";
		case Version_0_31_20100201_2227: return "0.31 20100201-2227";
		case Version_0_31_20100202     : return "0.31 20100202";
		case Version_Indev_20100206_2103: return "Indev 20100206-2103";
		case Version_Indev_20100207_1101: return "Indev 20100207-1101";
		case Version_Indev_20100207_1703: return "Indev 20100207-1703";
		case Version_Indev_20100212_1210: return "Indev 20100212-1210";
		case Version_Indev_20100212_1622: return "Indev 20100212-1622";
		case Version_Indev_20100213     : return "Indev 20100213";
		case Version_Indev_20100214     : return "Indev 20100214";
		case Version_Indev_20100218_0016: return "Indev 20100218-0016";
		case Version_Indev_20100219     : return "Indev 20100219";
		case Version_Indev_20100223     : return "Indev 20100223";
		case Version_Infdev_20100227_1433: return "Infdev 20100227-1433";
		case Version_Infdev_20100313     : return "Infdev 20100313";
		case Version_Infdev_20100316     : return "Infdev 20100316";
		case Version_Infdev_20100320     : return "Infdev 20100320";
		case Version_Infdev_20100321     : return "Infdev 20100321";
		case Version_Infdev_20100325_1640: return "Infdev 20100325-1640";
		case Version_Infdev_20100327     : return "Infdev 20100327";
		case Version_Infdev_20100330_1511: return "Infdev 20100330-1511";
		case Version_Infdev_20100413_1953: return "Infdev 20100413-1953";
		case Version_Infdev_20100414     : return "Infdev 20100414";
		case Version_Infdev_20100415     : return "Infdev 20100415";
		case Version_Infdev_20100420     : return "Infdev 20100420";
		case Version_Infdev_20100607     : return "Infdev 20100607";
		case Version_Infdev_20100608     : return "Infdev 20100608";
		case Version_Infdev_20100611     : return "Infdev 20100611";
		case Version_Infdev_20100615     : return "Infdev 20100615";
		case Version_Infdev_20100616_1808: return "Infdev 20100616-1808";
		case Version_Infdev_20100617_1205: return "Infdev 20100617-1205";
		case Version_Infdev_20100617_1531: return "Infdev 20100617-1531";
		case Version_Infdev_20100618     : return "Infdev 20100618";
		case Version_Infdev_20100624     : return "Infdev 20100624";
		case Version_Infdev_20100625_0922: return "Infdev 20100625-0922";
		case Version_Infdev_20100625_1917: return "Infdev 20100625-1917";
		case Version_Infdev_20100627     : return "Infdev 20100627";
		case Version_Infdev_20100629     : return "Infdev 20100629";
		case Version_Infdev_20100630_1340: return "Infdev 20100630-1340";
		case Version_Alpha_1_0_0   : return "Alpha 1.0.0";
		case Version_Alpha_1_0_1_01: return "Alpha 1.0.1_01";
		case Version_Alpha_1_0_2_01: return "Alpha 1.0.2_01";
		case Version_Alpha_1_0_2_02: return "Alpha 1.0.2_02";
		case Version_Alpha_1_0_3   : return "Alpha 1.0.3";
		case Version_Alpha_1_0_4   : return "Alpha 1.0.4";
		case Version_Alpha_1_0_5_01: return "Alpha 1.0.5_01";
		case Version_Alpha_1_0_6   : return "Alpha 1.0.6";
		case Version_Alpha_1_0_6_01: return "Alpha 1.0.6_01";
		case Version_Alpha_1_0_6_03: return "Alpha 1.0.6_03";
		case Version_Alpha_1_0_7   : return "Alpha 1.0.7";
		case Version_Alpha_1_0_8_01: return "Alpha 1.0.8_01";
		case Version_Alpha_1_0_9   : return "Alpha 1.0.9";
		case Version_Alpha_1_0_10   : return "Alpha 1.0.10";
		case Version_Alpha_1_0_11   : return "Alpha 1.0.11";
		case Version_Alpha_1_0_12   : return "Alpha 1.0.12";
		case Version_Alpha_1_0_13   : return "Alpha 1.0.13";
		case Version_Alpha_1_0_13_01: return "Alpha 1.0.13_01";
		case Version_Alpha_1_0_14   : return "Alpha 1.0.14";
		case Version_Alpha_1_0_15   : return "Alpha 1.0.15";
		case Version_Alpha_1_0_16_01: return "Alpha 1.0.16_01";
		case Version_Alpha_1_0_16_02: return "Alpha 1.0.16_02";
		case Version_Alpha_1_0_17_02: return "Alpha 1.0.17_02";
		case Version_Alpha_1_0_17_03: return "Alpha 1.0.17_03";
		case Version_Alpha_1_0_17_04: return "Alpha 1.0.17_04";
		case Version_Alpha_1_1_0   : return "Alpha 1.1.0";
		case Version_Alpha_1_1_1   : return "Alpha 1.1.1";
		case Version_Alpha_1_1_2   : return "Alpha 1.1.2";
		case Version_Alpha_1_1_2_01: return "Alpha 1.1.2_01";
		case Version_Alpha_1_2_0_01: return "Alpha 1.2.0_01";
		case Version_Alpha_1_2_0_02: return "Alpha 1.2.0_02";
		case Version_Alpha_1_2_1_01: return "Alpha 1.2.1_01";
		case Version_Alpha_1_2_2   : return "Alpha 1.2.2";
		case Version_Alpha_1_2_3   : return "Alpha 1.2.3";
		case Version_Alpha_1_2_3_01: return "Alpha 1.2.3_01";
		case Version_Alpha_1_2_3_02: return "Alpha 1.2.3_02";
		case Version_Alpha_1_2_3_04: return "Alpha 1.2.3_04";
		case Version_Alpha_1_2_3_05: return "Alpha 1.2.3_05";
		case Version_Alpha_1_2_4_01: return "Alpha 1.2.4_01";
		case Version_Alpha_1_2_5: return "Alpha 1.2.5";
		case Version_Alpha_1_2_6: return "Alpha 1.2.6";
		case Version_Beta_1_0   : return "Beta 1.0";
		case Version_Beta_1_0_01: return "Beta 1.0_01";
		case Version_Beta_1_0_2 : return "Beta 1.0.2";
		case Version_Beta_1_1   : return "Beta 1.1";
		case Version_Beta_1_1_01: return "Beta 1.1_01";
		case Version_Beta_1_1_02: return "Beta 1.1_02";
		case Version_Beta_1_2   : return "Beta 1.2";
		case Version_Beta_1_2_01: return "Beta 1.2_01";
		case Version_Beta_1_2_02: return "Beta 1.2_02";
		case Version_Beta_1_3   : return "Beta 1.3";
		case Version_Beta_1_3_01: return "Beta 1.3_01";
		case Version_Beta_1_4   : return "Beta 1.4";
		case Version_Beta_1_4_01: return "Beta 1.4_01";
		case Version_Beta_1_5   : return "Beta 1.5";
		case Version_Beta_1_5_01: return "Beta 1.5_01";
		case Version_Beta_1_5_02: return "Beta 1.5_02";
		case Version_Beta_1_6  : return "Beta 1.6";
		case Version_Beta_1_6_1: return "Beta 1.6.1";
		case Version_Beta_1_6_2: return "Beta 1.6.2";
		case Version_Beta_1_6_3: return "Beta 1.6.3";
		case Version_Beta_1_6_4: return "Beta 1.6.4";
		case Version_Beta_1_6_5: return "Beta 1.6.5";
		case Version_Beta_1_6_6: return "Beta 1.6.6";
		case Version_Beta_1_7  : return "Beta 1.7";
		case Version_Beta_1_7_01: return "Beta 1.7_01";
		case Version_Beta_1_7_2: return "Beta 1.7.2";
		case Version_Beta_1_7_3: return "Beta 1.7.3";
		case Version_Beta_1_8  : return "Beta 1.8";
		case Version_Beta_1_8_1: return "Beta 1.8.1";
		case Version_1_0  : return "1.0";
		case Version_1_1  : return "1.1";
		case Version_1_2  : return "1.2";
		case Version_1_2_1: return "1.2.1";
		case Version_1_2_2: return "1.2.2";
		case Version_1_2_3: return "1.2.3";
		case Version_1_2_4: return "1.2.4";
		case Version_1_2_5: return "1.2.5";
		case Version_1_3_1: return "1.3.1";
		case Version_1_3_2: return "1.3.2";
		case Version_1_4_2: return "1.4.2";
		case Version_1_4_4: return "1.4.4";
		case Version_1_4_5: return "1.4.5";
		case Version_1_4_6: return "1.4.6";
		case Version_1_4_7: return "1.4.7";
		case Version_1_5  : return "1.5";
		case Version_1_5_1: return "1.5.1";
		case Version_1_5_2: return "1.5.2";
		case Version_1_6_1: return "1.6.1";
		case Version_1_6_2: return "1.6.2";
		case Version_1_6_4: return "1.6.4";
		case Version_1_7_2: return "1.7.2";
		case Version_1_7_4: return "1.7.4";
		case Version_1_7_5: return "1.7.5";
		case Version_1_7_6: return "1.7.6";
		case Version_1_7_7: return "1.7.7";
		case Version_1_7_8: return "1.7.8";
		case Version_1_7_9: return "1.7.9";
		case Version_1_7_10: return "1.7.10";
		case Version_1_8  : return "1.8";
		case Version_1_8_1: return "1.8.1";
		case Version_1_8_2: return "1.8.2";
		case Version_1_8_3: return "1.8.3";
		case Version_1_8_4: return "1.8.4";
		case Version_1_8_5: return "1.8.5";
		case Version_1_8_6: return "1.8.6";
		case Version_1_8_7: return "1.8.7";
		case Version_1_8_8: return "1.8.8";
		case Version_1_8_9: return "1.8.9";
		case Version_1_9  : return "1.9";
		case Version_1_9_1: return "1.9.1";
		case Version_1_9_2: return "1.9.2";
		case Version_1_9_3: return "1.9.3";
		case Version_1_9_4: return "1.9.4";
		case Version_1_10  : return "1.10";
		case Version_1_10_1: return "1.10.1";
		case Version_1_10_2: return "1.10.2";
		case Version_1_11  : return "1.11";
		case Version_1_11_1: return "1.11.1";
		case Version_1_11_2: return "1.11.2";
		case Version_1_12  : return "1.12";
		case Version_1_12_1: return "1.12.1";
		case Version_1_12_2: return "1.12.2";
		case Version_1_13  : return "1.13";
		case Version_1_13_1: return "1.13.1";
		case Version_1_13_2: return "1.13.2";
		case Version_1_14  : return "1.14";
		case Version_1_14_1: return "1.14.1";
		case Version_1_14_2: return "1.14.2";
		case Version_1_14_3: return "1.14.3";
		case Version_1_14_4: return "1.14.4";
		case Version_1_15  : return "1.15";
		case Version_1_15_1: return "1.15.1";
		case Version_1_15_2: return "1.15.2";
		case Version_1_16  : return "1.16";
		case Version_1_16_1: return "1.16.1";
		case Version_1_16_2: return "1.16.2";
		case Version_1_16_3: return "1.16.3";
		case Version_1_16_4: return "1.16.4";
		case Version_1_16_5: return "1.16.5";
		case Version_1_17  : return "1.17";
		case Version_1_17_1: return "1.17.1";
		case Version_1_18  : return "1.18";
		case Version_1_18_1: return "1.18.1";
		case Version_1_18_2: return "1.18.2";
		case Version_1_19  : return "1.19";
		case Version_1_19_1: return "1.19.1";
		case Version_1_19_2: return "1.19.2";
		case Version_1_19_3: return "1.19.3";
		case Version_1_19_4: return "1.19.4";
		case Version_1_20  : return "1.20";
		case Version_1_20_1: return "1.20.1";
		case Version_1_20_2: return "1.20.2";
		case Version_1_20_3: return "1.20.3";
		case Version_1_20_4: return "1.20.4";
		case Version_1_20_5: return "1.20.5";
		case Version_1_20_6: return "1.20.6";
		case Version_1_21  : return "1.21";
		case Version_1_21_1: return "1.21.1";
		case Version_1_21_2: return "1.21.2";
		case Version_1_21_3: return "1.21.3";
		case Version_1_21_4: return "1.21.4";
		case Version_1_21_5: return "1.21.5";
		default: return "";
	}
}

static inline const char *getBiomeString(enum Biome biome) {
	switch (biome) {
		case Biome_None: return "[None]";
		default: return "";
	}
}

static inline const char *getItemString(enum ItemType item) {
	switch (item) {
		case Item_None: return "[None]";
		case Item_Apple: return "Apple";
		case Item_Arrow: return "Arrow";
		case Item_Bone: return "Bone";
		case Item_Book: return "Book";
		case Item_Bread: return "Bread";
		case Item_Bucket: return "Bucket";
		case Item_Coal: return "Coal";
		case Item_Cocoa_Beans: return "Cocoa Beans";
		case Item_Compass: return "Compass";
		case Item_Diamond: return "Diamond";
		case Item_Emerald: return "Emerald";
		case Item_Ender_Pearl: return "Ender Pearl";
		case Item_Filled_Map: return "Filled Map";
		case Item_Gold_Ingot: return "Gold Ingot";
		case Item_Golden_Apple: return "Golden Apple";
		case Item_Gunpowder: return "Gunpowder";
		case Item_Iron_Boots: return "Iron Boots";
		case Item_Iron_Chestplate: return "Iron Chestplate";
		case Item_Iron_Helmet: return "Iron Helmet";
		case Item_Iron_Ingot: return "Iron Ingot";
		case Item_Iron_Leggings: return "Iron Leggings";
		case Item_Iron_Pickaxe: return "Iron Pickaxe";
		case Item_Iron_Sword: return "Iron Sword";
		case Item_Lapis_Lazuli: return "Lapis Lazuli";
		case Item_Log: return "Oak Log";
		case Item_Melon_Seeds: return "Melon Seeds";
		case Item_Music_Disc: return "Music Disc";
		case Item_Obsidian: return "Obsidian";
		case Item_Paper: return "Paper";
		case Item_Planks: return "Oak Planks";
		case Item_Pumpkin_Seeds: return "Pumpkin Seeds";
		case Item_Rail: return "Rail";
		case Item_Redstone: return "Redstone";
		case Item_Rotten_Flesh: return "Rotten Flesh";
		case Item_Sapling: return "Oak Sapling";
		case Item_Saddle: return "Saddle";
		case Item_Stick: return "Stick";
		case Item_Stone_Axe: return "Stone Axe";
		case Item_Stone_Pickaxe: return "Stone Pickaxe";
		case Item_String: return "String";
		case Item_Wheat: return "Wheat";
		case Item_Wooden_Axe: return "Wooden Axe";
		case Item_Wooden_Pickaxe: return "Wooden Pickaxe";
		default: return "";
	}
}

static inline const char *getAttributesString(enum Attributes attributes) {
	switch (attributes) {
		case Attributes_Disc_13: return "\"13\" Disc";
		case Attributes_Disc_Cat: return "\"Cat\" Disc";
		default: return "";
	}
}

static inline const char *getPRNGTypeString(enum PRNGType prngType) {
	switch (prngType) {
		case PRNG_java_util_Random: return "java.util.Random";
		case PRNG_Mersenne_Twister: return "Mersenne Twister";
		case PRNG_Xoroshiro128_Plus_Plus: return "xoroshiro128++";
		default: return "";
	}
}

#ifdef __cplusplus
}
#endif

#endif