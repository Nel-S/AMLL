#ifndef AMLL_ENUMS_H
#define AMLL_ENUMS_H

enum RngType {
	RNG_java_util_Random,
	RNG_Mersenne_Twister,
	RNG_Xoroshiro128_Plus_Plus
};

enum Version {
	Infdev_20100625_1917,
	Alpha_1_0_1,
	Alpha_1_0_14,
	Beta_1_4,
};

enum Structure {
	Structure_Monster_Room, Structure_Dungeon = Structure_Monster_Room
};

enum Biome {
	Biome_None,
};

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

enum Attributes {
	Attributes_Disc_13,
	Attributes_Disc_Cat,
};

#ifdef __cplusplus
extern "C" {
#endif

static inline const char *getRngTypeString(enum RngType rngType) {
	switch (rngType) {
		case RNG_java_util_Random: return "java.util.Random";
		case RNG_Mersenne_Twister: return "Mersenne Twister";
		case RNG_Xoroshiro128_Plus_Plus: return "xoroshiro128++";
		default: return "";
	}
}

static inline const char *getVersionString(enum Version version) {
	switch (version) {
		case Infdev_20100625_1917: return "Infdev 20100625-1917";
		case Alpha_1_0_1: return "Alpha 1.0.1";
		case Alpha_1_0_14: return "Alpha 1.0.14";
		case Beta_1_4: return "Beta 1.4";
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