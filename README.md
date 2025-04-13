# Another Minecraft Loot Library

This library provides functions to
1. initialize the loot table of a given structure portion under a given biome and version, and
2. retrieve the loot of that chest under a specific "lootseed" (value used to seed a pseudorandom number generator).

Currently, this library only supports
- Java Edition
- for monster rooms/dungeons
- up to Beta 1.8.
Pull requests are welcome if you would like to help add additional functionality.

## Compilation
This library can be compiled by
1. Installing [CMake](https://cmake.org/download) and a Makefile generator of your choice (such as [GNU Make](https://www.gnu.org/software/make/#download) for Linux or [MinGW](https://www.mingw-w64.org/downloads) for Windows).
2. Opening a terminal of your choice, and running
```bash
cmake -G "[Makefile generator to use]" .
```
3. After CMake finishes, running your makefile generator (e.g. `make` if using GNU Make or `mingw32-make.exe` if using MinGW).
This will generate archives of the library (e.g. `libamll_static.a` or similarly-named files) that can then be linked with your C/C++ programs during compilation. For example, if you use [gcc](<https://gcc.gnu.org/>) to compile your own C program, your compilation command would now be similar to
```c
gcc "your/system's/path/to/your/own/program.c" "your/system's/path/to/libamll_static.a" -o "yourDesiredExecutableName[.exe if using Windows, or no file extension on Linux]"
```

## Usage
The following is an excerpt from [test.c] demonstrating the library's usage.
```c
#include "your/system's/path/to/loot.h"

int main() {
	/* Your configuration.
	   See enums.h for possible values, but know the repository only supports the limitations listed at the top of this Readme.*/
	enum Structure structure = Structure_Dungeon;
	enum Version version = Version_Beta_1_4;
	enum Biome biome = Biome_None;

	// Declare and initialize the loot table.
	// If it fails (e.g. that structure in that version doesn't have a loot table), it prints an error message and quits.
	LootTable lootTable;
	if (!initializeLootTable(&lootTable, structure, version, biome)) {
		fprintf(stderr, "Error: Could not initialize loot table for structure %s under version %s in biome %s.\n", getStructureString(structure), getVersionString(version), getBiomeString(biome));
		return 1;
	}

	// Declare the lootseed, and the output array to be used.
	uint64_t lootSeed = 123456789;
	Item outputArray[MAX_CHEST_CAPACITY];
	// Query the loot table. The number of loot items will be stored in outputCount (or -1 if a failure occurred), while the attributes of the items will be stored in the output array.
	ssize_t outputCount = getLoot(&lootTable, lootSeed, outputArray, sizeof(outputArray)/sizeof(*outputArray));
	// [Do with the loot what you wish]
	return 0;
}
```

## License and Acknowledgements
[Scriptline](https://github.com/ScriptLineStudios) and [Kris](https://github.com/Kludwisz) had worked on [a loot library prior to this one](https://github.com/ScriptLineStudios/loot_library.h), that implements certain structures' loot tables in Java 1.21.x(?).

This GitHub repository (AMLL) is offered under [my (NelS') general seedfinding license](https://github.com/Nel-S/seedfinding/blob/main/LICENSE). Please read and abide by that text if you have any wishes of referencing, distributing, selling, etc. this repository or its code.

This is not an official Minecraft product, and has not been endorsed by Mojang A.B. or Microsoft Corporation.