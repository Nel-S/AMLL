#ifndef _AMLL_ENUMS_H
#define _AMLL_ENUMS_H

#include <stddef.h>

// All possible pseudorandom number generators (PRNGs).
enum PRNGType {
	PRNG_java_util_Random,
	PRNG_Mersenne_Twister,
	PRNG_Xoroshiro128_Plus_Plus
};

// All existent Java Edition versions.
enum Version {
	rd_132211,
	rd_132328,
	rd_160052,
	rd_161348,
	v0_0_11a,
	v0_0_12a_03,
	v0_0_13a, v0_0_13a_03,
	v0_0_14a_08,
	v0_0_15a,
	v0_0_16a_02,
	v0_0_17a,
	v0_0_18a_02,
	v0_0_19a_04, v0_0_19a_06,
	v0_0_20a_01, v0_0_20a_02,
	v0_0_21a,
	v0_0_22a_05,
	v0_0_23a_01,
	v0_24_SURVIVAL_TEST_03,
	v0_25_05_SURVIVAL_TEST,
	v0_27_SURVIVAL_TEST,
	v0_28_01,
	v0_29, v0_29_01, v0_29_02,
	v0_30,
	v0_31_20091223_1459,
	v0_31_20091231_2255,
	v0_31_20100104_2258,
	v0_31_20100110,
	v0_31_20100124_2310,
	v0_31_20100125,
	v0_31_20100128_2304,
	v0_31_20100129_1452,
	v0_31_20100130,
	v0_31_20100131_2244,
	v0_31_20100201_0025, v0_31_20100201_2227,
	v0_31_20100202,
	Indev_20100206_2103,
	Indev_20100207_1101, Indev_20100207_1703,
	Indev_20100212_1210, Indev_20100212_1622,
	Indev_20100213,
	Indev_20100214,
	Indev_20100218_0016,
	Indev_20100219,
	Indev_20100223,
	Infdev_20100227_1433,
	Infdev_20100313,
	Infdev_20100316,
	Infdev_20100320,
	Infdev_20100321,
	Infdev_20100325_1640,
	Infdev_20100327,
	Infdev_20100330_1511,
	Infdev_20100413_1953,
	Infdev_20100414,
	Infdev_20100415,
	Infdev_20100420,
	Infdev_20100607,
	Infdev_20100608,
	Infdev_20100611,
	Infdev_20100615,
	Infdev_20100616_1808,
	Infdev_20100617_1205, Infdev_20100617_1531,
	Infdev_20100618,
	Infdev_20100624,
	Infdev_20100625_0922, Infdev_20100625_1917,
	Infdev_20100627,
	Infdev_20100629,
	Infdev_20100630_1340,
	Infdev_20100630_1835, Alpha_1_0_0 = Infdev_20100630_1835,
		Alpha_1_0_1_01, Alpha_1_0_2_01, Alpha_1_0_2_02, Alpha_1_0_3, Alpha_1_0_4, Alpha_1_0_5_01, Alpha_1_0_6, Alpha_1_0_6_01,
		Alpha_1_0_6_03 , Alpha_1_0_7    , Alpha_1_0_8_01, Alpha_1_0_9 , Alpha_1_0_10   , Alpha_1_0_11   , Alpha_1_0_12   ,
		Alpha_1_0_13   , Alpha_1_0_13_01, Alpha_1_0_14  , Alpha_1_0_15, Alpha_1_0_16_01, Alpha_1_0_16_02, Alpha_1_0_17_02, Alpha_1_0_17_03, Alpha_1_0_17_04,
	Alpha_1_1_0, Alpha_1_1_1, Alpha_1_1_2, Alpha_1_1_2_01,
	Alpha_1_2_0_01, Alpha_1_2_0_02, Alpha_1_2_1_01, Alpha_1_2_2, Alpha_1_2_3, Alpha_1_2_3_01, Alpha_1_2_3_02, Alpha_1_2_3_04,
		Alpha_1_2_3_05, Alpha_1_2_4_01, Alpha_1_2_5, Alpha_1_2_6,
	Beta_1_0, Beta_1_0_01, Beta_1_0_2,
	Beta_1_1, Beta_1_1_01, Beta_1_1_02,
	Beta_1_2, Beta_1_2_01, Beta_1_2_02,
	Beta_1_3, Beta_1_3_01,
	Beta_1_4, Beta_1_4_01,
	Beta_1_5, Beta_1_5_01, Beta_1_5_02,
	Beta_1_6, Beta_1_6_1 , Beta_1_6_2 , Beta_1_6_3, Beta_1_6_4, Beta_1_6_5, Beta_1_6_6,
	Beta_1_7, Beta_1_7_01, Beta_1_7_2 , Beta_1_7_3,
	Beta_1_8, Beta_1_8_1,
	v1_0,
	v1_1,
	v1_2  , v1_2_1 , v1_2_2 , v1_2_3 , v1_2_4 , v1_2_5 ,
	v1_3_1, v1_3_2 ,
	v1_4_2, v1_4_4 , v1_4_5 , v1_4_6 , v1_4_7 ,
	v1_5  , v1_5_1 , v1_5_2 ,
	v1_6_1, v1_6_2 , v1_6_4 ,
	v1_7_2, v1_7_4 , v1_7_5 , v1_7_6 , v1_7_7 , v1_7_8 , v1_7_9 , v1_7_10,
	v1_8  , v1_8_1 , v1_8_2 , v1_8_3 , v1_8_4 , v1_8_5 , v1_8_6 , v1_8_7 , v1_8_8, v1_8_9,
	v1_9  , v1_9_1 , v1_9_2 , v1_9_3 , v1_9_4 ,
	v1_10 , v1_10_1, v1_10_2,
	v1_11 , v1_11_1, v1_11_2,
	v1_12 , v1_12_1, v1_12_2,
	v1_13 , v1_13_1, v1_13_2,
	v1_14 , v1_14_1, v1_14_2, v1_14_3, v1_14_4,
	v1_15 , v1_15_1, v1_15_2,
	v1_16 , v1_16_1, v1_16_2, v1_16_3, v1_16_4, v1_16_5,
	v1_17 , v1_17_1,
	v1_18 , v1_18_1, v1_18_2,
	v1_19 , v1_19_1, v1_19_2, v1_19_3, v1_19_4,
	v1_20 , v1_20_1, v1_20_2, v1_20_3, v1_20_4, v1_20_5, v1_20_6,
	v1_21 , v1_21_1, v1_21_2, v1_21_3, v1_21_4, v1_21_5,
};

// All supported structures.
enum Structure {
	Structure_Monster_Room, Structure_Dungeon = Structure_Monster_Room
};

// All supported biomes.
enum Biome {
	Biome_None,
};

// All possible loot items.
enum ItemType {
	Item_None,
	Item_Bread,
	Item_Bucket,
	Item_Cocoa_Beans, Item_Coco_Beans = Item_Cocoa_Beans,
	Item_Golden_Apple,
	Item_Gunpowder,
	Item_Iron_Ingot,
	Item_Music_Disc,
	Item_Redstone,
	Item_Saddle,
	Item_String,
	Item_Wheat,
};

// All possible loot item attributes.
enum Attributes {
	Attributes_Disc_13,
	Attributes_Disc_Cat,
};

// Convienence functions for printing the enums as strings
#ifdef __cplusplus
extern "C" {
#endif

static inline const char *getPRNGTypeString(enum PRNGType prngType) {
	switch (prngType) {
		case PRNG_java_util_Random: return "java.util.Random";
		case PRNG_Mersenne_Twister: return "Mersenne Twister";
		case PRNG_Xoroshiro128_Plus_Plus: return "xoroshiro128++";
		default: return "";
	}
}

static inline const char *getVersionString(enum Version version) {
	switch (version) {
		case rd_132211: return "rd-132211";
		case rd_132328: return "rd-132328";
		case rd_160052: return "rd-160052";
		case rd_161348: return "rd-161348";
		case v0_0_11a: return "0.0.11a";
		case v0_0_12a_03: return "0.0.12a_03";
		case v0_0_13a: return "0.0.13a";
		case v0_0_13a_03: return "0.0.13a_03";
		case v0_0_14a_08: return "0.0.14a_08";
		case v0_0_15a: return "0.0.15a";
		case v0_0_16a_02: return "0.0.16a_02";
		case v0_0_17a: return "0.0.17a";
		case v0_0_18a_02: return "0.0.18a_02";
		case v0_0_19a_04: return "0.0.19a_04";
		case v0_0_19a_06: return "0.0.19a_06";
		case v0_0_20a_01: return "0.0.20a_01";
		case v0_0_20a_02: return "0.0.20a_02";
		case v0_0_21a: return "0.0.21a";
		case v0_0_22a_05: return "0.0.22a_05";
		case v0_0_23a_01: return "0.0.23a_01";
		case v0_24_SURVIVAL_TEST_03: return "0.24_SURVIVAL_TEST_03";
		case v0_25_05_SURVIVAL_TEST: return "0.25_05 SURVIVAL TEST";
		case v0_27_SURVIVAL_TEST: return "0.27 SURVIVAL TEST";
		case v0_28_01: return "0.28_01";
		case v0_29: return "0.29";
		case v0_29_01: return "0.29_01";
		case v0_29_02: return "0.29_02";
		case v0_30: return "0.30";
		case v0_31_20091223_1459: return "0.31 20091223-1459";
		case v0_31_20091231_2255: return "0.31 20091231-2255";
		case v0_31_20100104_2258: return "0.31 20100104-2258";
		case v0_31_20100110: return "0.31 20100110";
		case v0_31_20100124_2310: return "0.31 20100124-2310";
		case v0_31_20100125: return "0.31 20100125";
		case v0_31_20100128_2304: return "0.31 20100128-2304";
		case v0_31_20100129_1452: return "0.31 20100129-1452";
		case v0_31_20100130: return "0.31 20100130";
		case v0_31_20100131_2244: return "0.31 20100131-2244";
		case v0_31_20100201_0025: return "0.31 20100201-0025";
		case v0_31_20100201_2227: return "0.31 20100201-2227";
		case v0_31_20100202: return "0.31 20100202";
		case Indev_20100206_2103: return "Indev 20100206-2103";
		case Indev_20100207_1101: return "Indev 20100207-1101";
		case Indev_20100207_1703: return "Indev 20100207-1703";
		case Indev_20100212_1210: return "Indev 20100212-1210";
		case Indev_20100212_1622: return "Indev 20100212-1622";
		case Indev_20100213: return "Indev 20100213";
		case Indev_20100214: return "Indev 20100214";
		case Indev_20100218_0016: return "Indev 20100218-0016";
		case Indev_20100219: return "Indev 20100219";
		case Indev_20100223: return "Indev 20100223";
		case Infdev_20100227_1433: return "Infdev 20100227-1433";
		case Infdev_20100313: return "Infdev 20100313";
		case Infdev_20100316: return "Infdev 20100316";
		case Infdev_20100320: return "Infdev 20100320";
		case Infdev_20100321: return "Infdev 20100321";
		case Infdev_20100325_1640: return "Infdev 20100325-1640";
		case Infdev_20100327: return "Infdev 20100327";
		case Infdev_20100330_1511: return "Infdev 20100330-1511";
		case Infdev_20100413_1953: return "Infdev 20100413-1953";
		case Infdev_20100414: return "Infdev 20100414";
		case Infdev_20100415: return "Infdev 20100415";
		case Infdev_20100420: return "Infdev 20100420";
		case Infdev_20100607: return "Infdev 20100607";
		case Infdev_20100608: return "Infdev 20100608";
		case Infdev_20100611: return "Infdev 20100611";
		case Infdev_20100615: return "Infdev 20100615";
		case Infdev_20100616_1808: return "Infdev 20100616-1808";
		case Infdev_20100617_1205: return "Infdev 20100617-1205";
		case Infdev_20100617_1531: return "Infdev 20100617-1531";
		case Infdev_20100618: return "Infdev 20100618";
		case Infdev_20100624: return "Infdev 20100624";
		case Infdev_20100625_0922: return "Infdev 20100625-0922";
		case Infdev_20100625_1917: return "Infdev 20100625-1917";
		case Infdev_20100627: return "Infdev 20100627";
		case Infdev_20100629: return "Infdev 20100629";
		case Infdev_20100630_1340: return "Infdev 20100630-1340";
		case Alpha_1_0_0: return "Alpha 1.0.0";
		case Alpha_1_0_1_01: return "Alpha 1.0.1_01";
		case Alpha_1_0_2_01: return "Alpha 1.0.2_01";
		case Alpha_1_0_2_02: return "Alpha 1.0.2_02";
		case Alpha_1_0_3: return "Alpha 1.0.3";
		case Alpha_1_0_4: return "Alpha 1.0.4";
		case Alpha_1_0_5_01: return "Alpha 1.0.5_01";
		case Alpha_1_0_6: return "Alpha 1.0.6";
		case Alpha_1_0_6_01: return "Alpha 1.0.6_01";
		case Alpha_1_0_6_03: return "Alpha 1.0.6_03";
		case Alpha_1_0_7: return "Alpha 1.0.7";
		case Alpha_1_0_8_01: return "Alpha 1.0.8_01";
		case Alpha_1_0_9: return "Alpha 1.0.9";
		case Alpha_1_0_10: return "Alpha 1.0.10";
		case Alpha_1_0_11: return "Alpha 1.0.11";
		case Alpha_1_0_12: return "Alpha 1.0.12";
		case Alpha_1_0_13: return "Alpha 1.0.13";
		case Alpha_1_0_13_01: return "Alpha 1.0.13_01";
		case Alpha_1_0_14: return "Alpha 1.0.14";
		case Alpha_1_0_15: return "Alpha 1.0.15";
		case Alpha_1_0_16_01: return "Alpha 1.0.16_01";
		case Alpha_1_0_16_02: return "Alpha 1.0.16_02";
		case Alpha_1_0_17_02: return "Alpha 1.0.17_02";
		case Alpha_1_0_17_03: return "Alpha 1.0.17_03";
		case Alpha_1_0_17_04: return "Alpha 1.0.17_04";
		case Alpha_1_1_0: return "Alpha 1.1.0";
		case Alpha_1_1_1: return "Alpha 1.1.1";
		case Alpha_1_1_2: return "Alpha 1.1.2";
		case Alpha_1_1_2_01: return "Alpha 1.1.2_01";
		case Alpha_1_2_0_01: return "Alpha 1.2.0_01";
		case Alpha_1_2_0_02: return "Alpha 1.2.0_02";
		case Alpha_1_2_1_01: return "Alpha 1.2.1_01";
		case Alpha_1_2_2: return "Alpha 1.2.2";
		case Alpha_1_2_3: return "Alpha 1.2.3";
		case Alpha_1_2_3_01: return "Alpha 1.2.3_01";
		case Alpha_1_2_3_02: return "Alpha 1.2.3_02";
		case Alpha_1_2_3_04: return "Alpha 1.2.3_04";
		case Alpha_1_2_3_05: return "Alpha 1.2.3_05";
		case Alpha_1_2_4_01: return "Alpha 1.2.4_01";
		case Alpha_1_2_5: return "Alpha 1.2.5";
		case Alpha_1_2_6: return "Alpha 1.2.6";
		case Beta_1_0: return "Beta 1.0";
		case Beta_1_0_01: return "Beta 1.0_01";
		case Beta_1_0_2: return "Beta 1.0.2";
		case Beta_1_1: return "Beta 1.1";
		case Beta_1_1_01: return "Beta 1.1_01";
		case Beta_1_1_02: return "Beta 1.1_02";
		case Beta_1_2: return "Beta 1.2";
		case Beta_1_2_01: return "Beta 1.2_01";
		case Beta_1_2_02: return "Beta 1.2_02";
		case Beta_1_3: return "Beta 1.3";
		case Beta_1_3_01: return "Beta 1.3_01";
		case Beta_1_4: return "Beta 1.4";
		case Beta_1_4_01: return "Beta 1.4_01";
		case Beta_1_5: return "Beta 1.5";
		case Beta_1_5_01: return "Beta 1.5_01";
		case Beta_1_5_02: return "Beta 1.5_02";
		case Beta_1_6: return "Beta 1.6";
		case Beta_1_6_1: return "Beta 1.6.1";
		case Beta_1_6_2: return "Beta 1.6.2";
		case Beta_1_6_3: return "Beta 1.6.3";
		case Beta_1_6_4: return "Beta 1.6.4";
		case Beta_1_6_5: return "Beta 1.6.5";
		case Beta_1_6_6: return "Beta 1.6.6";
		case Beta_1_7: return "Beta 1.7";
		case Beta_1_7_01: return "Beta 1.7_01";
		case Beta_1_7_2: return "Beta 1.7.2";
		case Beta_1_7_3: return "Beta 1.7.3";
		case Beta_1_8: return "Beta 1.8";
		case Beta_1_8_1: return "Beta 1.8.1";
		case v1_0: return "1.0";
		case v1_1: return "1.1";
		case v1_2: return "1.2";
		case v1_2_1: return "1.2.1";
		case v1_2_2: return "1.2.2";
		case v1_2_3: return "1.2.3";
		case v1_2_4: return "1.2.4";
		case v1_2_5: return "1.2.5";
		case v1_3_1: return "1.3.1";
		case v1_3_2: return "1.3.2";
		case v1_4_2: return "1.4.2";
		case v1_4_4: return "1.4.4";
		case v1_4_5: return "1.4.5";
		case v1_4_6: return "1.4.6";
		case v1_4_7: return "1.4.7";
		case v1_5: return "1.5";
		case v1_5_1: return "1.5.1";
		case v1_5_2: return "1.5.2";
		case v1_6_1: return "1.6.1";
		case v1_6_2: return "1.6.2";
		case v1_6_4: return "1.6.4";
		case v1_7_2: return "1.7.2";
		case v1_7_4: return "1.7.4";
		case v1_7_5: return "1.7.5";
		case v1_7_6: return "1.7.6";
		case v1_7_7: return "1.7.7";
		case v1_7_8: return "1.7.8";
		case v1_7_9: return "1.7.9";
		case v1_7_10: return "1.7.10";
		case v1_8: return "1.8";
		case v1_8_1: return "1.8.1";
		case v1_8_2: return "1.8.2";
		case v1_8_3: return "1.8.3";
		case v1_8_4: return "1.8.4";
		case v1_8_5: return "1.8.5";
		case v1_8_6: return "1.8.6";
		case v1_8_7: return "1.8.7";
		case v1_8_8: return "1.8.8";
		case v1_8_9: return "1.8.9";
		case v1_9: return "1.9";
		case v1_9_1: return "1.9.1";
		case v1_9_2: return "1.9.2";
		case v1_9_3: return "1.9.3";
		case v1_9_4: return "1.9.4";
		case v1_10: return "1.10";
		case v1_10_1: return "1.10.1";
		case v1_10_2: return "1.10.2";
		case v1_11: return "1.11";
		case v1_11_1: return "1.11.1";
		case v1_11_2: return "1.11.2";
		case v1_12: return "1.12";
		case v1_12_1: return "1.12.1";
		case v1_12_2: return "1.12.2";
		case v1_13: return "1.13";
		case v1_13_1: return "1.13.1";
		case v1_13_2: return "1.13.2";
		case v1_14: return "1.14";
		case v1_14_1: return "1.14.1";
		case v1_14_2: return "1.14.2";
		case v1_14_3: return "1.14.3";
		case v1_14_4: return "1.14.4";
		case v1_15: return "1.15";
		case v1_15_1: return "1.15.1";
		case v1_15_2: return "1.15.2";
		case v1_16: return "1.16";
		case v1_16_1: return "1.16.1";
		case v1_16_2: return "1.16.2";
		case v1_16_3: return "1.16.3";
		case v1_16_4: return "1.16.4";
		case v1_16_5: return "1.16.5";
		case v1_17: return "1.17";
		case v1_17_1: return "1.17.1";
		case v1_18: return "1.18";
		case v1_18_1: return "1.18.1";
		case v1_18_2: return "1.18.2";
		case v1_19: return "1.19";
		case v1_19_1: return "1.19.1";
		case v1_19_2: return "1.19.2";
		case v1_19_3: return "1.19.3";
		case v1_19_4: return "1.19.4";
		case v1_20: return "1.20";
		case v1_20_1: return "1.20.1";
		case v1_20_2: return "1.20.2";
		case v1_20_3: return "1.20.3";
		case v1_20_4: return "1.20.4";
		case v1_20_5: return "1.20.5";
		case v1_20_6: return "1.20.6";
		case v1_21: return "1.21";
		case v1_21_1: return "1.21.1";
		case v1_21_2: return "1.21.2";
		case v1_21_3: return "1.21.3";
		case v1_21_4: return "1.21.4";
		case v1_21_5: return "1.21.5";
		default: return "";
	}
}

static inline const char *getStructureString(enum Structure structure) {
	switch (structure) {
		case Structure_Monster_Room: return "Monster Room";
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
		case Item_Bread: return "Bread";
		case Item_Bucket: return "Bucket";
		case Item_Cocoa_Beans: return "Cocoa Beans";
		case Item_Golden_Apple: return "Golden Apple";
		case Item_Gunpowder: return "Gunpowder";
		case Item_Iron_Ingot: return "Iron Ingot";
		case Item_Music_Disc: return "Music Disc";
		case Item_Redstone: return "Redstone";
		case Item_Saddle: return "Saddle";
		case Item_String: return "String";
		case Item_Wheat: return "Wheat";
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

#ifdef __cplusplus
}
#endif

#endif