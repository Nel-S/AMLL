# Another Minecraft Loot Library

This library provides functions to
1. initialize the loot table of a given source of loot under a given biome and version, and
2. retrieve the loot of that source under a specific "lootseed" (value that seeds the [pseudorandom number generator](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) picking the loot).

Currently, this library only supports
- Java Edition
- for bonus chests, desert pyramids, jungle temples, mineshafts, monster rooms/dungeons, Nether fortresses, strongholds, and villages
- from the game's creation up through 1.0 (1.1-1.6.4 is untested).

To slightly improve efficiency, the order that loot entries are listed in is not necessarily the order they were originally added to their loot source.

Issues and/or pull requests are welcome if you find any bugs or would like to help add additional functionality.

## Installation and Compilation
This repository must be downloaded by cloning it with [Git](https://git-scm.com/downloads), then opening the cloned repository in your terminal of choice and running `git submodule update --init --remote --recursive` to initialize all submodules. (The submodules are not downloaded if you attempt to download the repository as a ZIP file.)

After downloading, this library can be compiled by
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
The following is an adaptation of [test.c](./test.c) to demonstrate the library's usage.
```c
#include "your/system's/path/to/loot.h"
#include <stdio.h>

int main() {
	/* Your configuration.
		See enums.h for possible values, but know the repository only supports the limitations
		listed at the top of this Readme.*/
	enum Source lootSource = Source_Monster_Room;
	enum Version version = Version_Beta_1_4;
	enum Biome biome = Biome_None;

	/* Declare and initialize the loot table.
		If it fails (e.g. that source in that version doesn't have a loot table), it prints
		an error message and quits.*/
	LootTable lootTable;
	if (!initializeLootTable(&lootTable, lootSource, version, biome)) {
		fprintf(stderr, "Error: Could not initialize the loot table for source %s under "
			"version %s in biome %s.\n", getSourceString(lootSource),
			getVersionString(version), getBiomeString(biome));
		return 1;
	}

	// Declare and initialize the lootseed, and the output array to be used.
	uint64_t lootSeed = 123456789;
	Item outputArray[MAX_CHEST_CAPACITY];
	if (!initializeOutputArray(outputArray, MAX_CHEST_CAPACITY)) {
		fprintf(stderr, "Error: Could not initialize the output array.\n",
		getSourceString(lootSource), getVersionString(version), getBiomeString(biome));
		return 1;
	}

	/* Query the loot table.
		The number of loot items will be stored in outputCount (or -1 if a failure occurred), while
		the attributes of the items will be stored in the output array.*/
	ssize_t outputCount = getLoot(&lootTable, lootSeed, outputArray, MAX_CHEST_CAPACITY);
	// If a failure *did* occur, it prints an error message and quits. 
	if (outputCount == -1) {
		fprintf(stderr, "Error: Could not retrieve the loot for loot seed %" PRId64 " for source "
			"%s under version %s in biome %s.\n", lootSeed, getSourceString(source),
			getVersionString(version), getBiomeString(biome));
		return 1;
	}
	// Otherwise we can now do with the loot what we wish.

	/* When we're done with the loot table, we can free it to reclaim all dynamically-allocated
		memory, then end our program. The same goes for our output array.*/
	freeLootTable(&lootTable);
	freeOutputArray(outputArray, MAX_CHEST_CAPACITY);
	return 0;
}
```

## License and Acknowledgements
[Scriptline](https://github.com/ScriptLineStudios) and [Kris](https://github.com/Kludwisz) had worked on [a loot library prior to this one](https://github.com/ScriptLineStudios/loot_library.h), that implements certain structures' loot tables in Java 1.21.x(?).

This GitHub repository (AMLL) is offered under [my (NelS') general seedfinding license](https://github.com/Nel-S/seedfinding/blob/main/LICENSE). Please read and abide by that text if you have any wishes of referencing, distributing, selling, etc. this repository or its code.

This is not an official Minecraft product, and has not been endorsed by Mojang A.B. or Microsoft Corporation.