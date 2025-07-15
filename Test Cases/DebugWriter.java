package net.minecraft;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import net.minecraft.src.IInventory;
import net.minecraft.src.Item;
import net.minecraft.src.ItemEnchantedBook;
import net.minecraft.src.ItemRecord;
import net.minecraft.src.ItemStack;
import net.minecraft.src.StringTranslate;
import net.minecraft.src.TileEntity;
import net.minecraft.src.TileEntityChest;
import net.minecraft.src.TileEntityDispenser;
import net.minecraft.src.World;

// private static final DebugWriter debugWriter = new DebugWriter("C:\\msys64\\home\\AMLL\\Test Cases\\[Structure]\\[Version].txt", 10);
// Long lootseed = DebugWriter.getSeed(var2);
// if (debugWriter != null) debugWriter.saveLootSourceContents(var16, lootseed);

// Long lootseed = DebugWriter.getSeed(var3);
// if (debugWriter != null) debugWriter.saveLootSourceContents(var12, lootseed);

public class DebugWriter {
	final Path FILEPATH;
	private int savedEntries;
	private final Integer MAX_SAVED_ENTRIES;

	static final long LCG_XOR = 25214903917L;
	static final long LCG_FORWARD_0_MULTIPLIER = 1L;
	static final long LCG_FORWARD_0_ADDEND = 0L;
	static final long LCG_FORWARD_1_MULTIPLIER = 25214903917L;
	static final long LCG_FORWARD_1_ADDEND = 11L;
	static final long LCG_BACK_1_ADDEND = 107048004364969L;
	static final long LCG_BACK_2_MULTIPLIER = 254681119335897L;
    static final long LCG_BACK_2_ADDEND = 120305458776662L;
    static final long LCG_MODULO = 0xffff_ffff_ffffL;

	public DebugWriter(Path filepath, Integer maxSavedEntries) {
		this.FILEPATH = filepath;
		if (!Files.exists(this.FILEPATH)) try {
			Files.createFile(this.FILEPATH);
		} catch (Exception e) {
			;
		}
		this.savedEntries = 0;
		this.MAX_SAVED_ENTRIES = maxSavedEntries;
	}

	public DebugWriter(Path filepath) {
		this(filepath, null);
	}

	public DebugWriter(String filepath, Integer maxSavedEntries) {
		this(Paths.get(filepath), maxSavedEntries);
	}

	public DebugWriter(String filepath) {
		this(Paths.get(filepath), null);
	}

	/* ---------------------------------
	 * Copied from https://stackoverflow.com/a/79206760 by DaHoC, Option 3
	 * --------------------------------- */
	// Serializes a Random instance.
	private static byte[] serialize(Random random) throws IOException {
		try (ByteArrayOutputStream baos = new ByteArrayOutputStream(128);
			 ObjectOutputStream oos = new ObjectOutputStream(baos)) {
			oos.writeObject(random);
			return baos.toByteArray();
		}
	}

	// Deserializes a Random instance.
	private static Random deserialize(byte[] serializedRandom) throws IOException, ClassNotFoundException {
		try (ByteArrayInputStream bais = new ByteArrayInputStream(serializedRandom);
			 ObjectInputStream in = new ObjectInputStream(bais)) {
			// Method for deserialization of object
			return ((Random)in.readObject());
		}
	}

	/* ---------------------------------
	 * Ported from https://github.com/Cubitect/cubiomes/blob/e61f90580cbdd883214a8054670dacae655e59c0/rng.h#L150-L173 by Cubitect
	 * --------------------------------- */
	// Returns the internal state after `offset` calls (`offset` can also be negative).
	public static long getSkip(long internalState, long offset) {
		long m = LCG_FORWARD_0_MULTIPLIER;
		long a = LCG_FORWARD_0_ADDEND;
		long im = LCG_FORWARD_1_MULTIPLIER;
		long ia = LCG_FORWARD_1_ADDEND;

		for (long k = offset & LCG_MODULO; k != 0; k >>>= 1) {
			if ((k & 1) != 0) {
				m *= im;
				a = im * a + ia;
			}
			ia = (im + 1) * ia;
			im *= im;
		}

		return (internalState * m + a) & LCG_MODULO;
	}

	/* --------------------------------
	 * Copied from https://github.com/SeedFinding/mc_core_java/blob/eee662999e9f3fe037476b6940dbd6d5e23cdbb6/src/main/java/com/seedfinding/mccore/util/math/NextLongReverser.java#L10-L60 by Neil
	 * -------------------------------- */

	/**
	 * Adds seeds which give nextLongs congruent to your structure seed to a list.
	 * Has a precondition that structureSeed is 48 bits (its upper 16 bits as a long are 0)
	 *
	 * @param structureSeed the 48 bit version of the seed
	 * @param seedList      a list to add the seeds to
	 */
	public static void addSeedsToList(long structureSeed, List<Long> seedList) {
		long lowerBits = structureSeed & 0xffff_ffffL;
		long upperBits = structureSeed >>> 32;
		//Did the lower bits affect the upper bits?
		if ((lowerBits & 0x8000_0000L) != 0) upperBits += 1; //restoring the initial value of the upper bits

		//TODO I can only guarantee the algorithm's correctness for bitsOfDanger = 0 but believe 1 should still always work, needs to be confirmed!!!

		//The algorithm is meant to have bitsOfDanger = 0, but this runs into overflow issues.
		//By using a different small value, we introduce small numerical error which probably cannot break things
		//while keeping everything in range of a long and avoiding nasty BigDecimal/BigInteger overhead
		int bitsOfDanger = 1;

		long lowMin = lowerBits << 16 - bitsOfDanger;
		long lowMax = ((lowerBits + 1) << 16 - bitsOfDanger) - 1;
		long upperMin = ((upperBits << 16) - LCG_BACK_1_ADDEND) >> bitsOfDanger;

		//hardcoded matrix multiplication again
		long m1lv = Math.floorDiv(lowMax * -33441 + upperMin * 17549, 1L << 31 - bitsOfDanger) + 1; //I cancelled out a common factor of 2 in this line
		long m2lv = Math.floorDiv(lowMin * 46603 + upperMin * 39761, 1L << 32 - bitsOfDanger) + 1;

		long seed;

		// (0,0) -> 0.6003265380859375
		seed = (-39761 * m1lv + 35098 * m2lv);
		if ((46603 * m1lv + 66882 * m2lv) + LCG_BACK_1_ADDEND >>> 16 == upperBits) {
			if (seed >>> 16 == lowerBits) seedList.add((LCG_BACK_2_MULTIPLIER * seed + LCG_BACK_2_ADDEND) & LCG_MODULO); //pull back 2 LCG calls
		}
		//(1,0) -> 0.282440185546875
		seed = (-39761 * (m1lv + 1) + 35098 * m2lv);
		if ((46603 * (m1lv + 1) + 66882 * m2lv) + LCG_BACK_1_ADDEND >>> 16 == upperBits) {
			if (seed >>> 16 == lowerBits) seedList.add((LCG_BACK_2_MULTIPLIER * seed + LCG_BACK_2_ADDEND) & LCG_MODULO); //pull back 2 LCG calls
		}
		//(0,1) -> 0.1172332763671875
		seed = (-39761 * m1lv + 35098 * (m2lv + 1));
		if ((46603 * m1lv + 66882 * (m2lv + 1)) + LCG_BACK_1_ADDEND >>> 16 == upperBits) {
			if (seed >>> 16 == lowerBits) seedList.add((LCG_BACK_2_MULTIPLIER * seed + LCG_BACK_2_ADDEND) & LCG_MODULO); //pull back 2 LCG calls
		}
		//(1,1) -> 0.0
	}

	// Returns the equivalent seed of the provided Random instance's current state.
	public static Long getSeed(Random random) {
		return DebugWriter.getSeed(random, 0);
	}

	// Returns the equivalent seed of the provided Random instance's current state, shifted by `offset` advancements.
	public static Long getSeed(Random random, long offset) {
		// Make a backup of Random in case no results are found
		byte[] backup;
		try {
			backup = serialize(random);
		} catch (Exception e) {
			return null;
		}

		// Retrieve possible internal states based on lowest 48 bits alone
		ArrayList<Long> potentialInternalStates = new ArrayList<>(2);
		long nextLong = random.nextLong();
		addSeedsToList(nextLong & LCG_MODULO, potentialInternalStates);

		// Check upper 16 bits, and restore Random object + return if everything matches
		Random testRandom = new Random();
		for (Long potentialInternalState : potentialInternalStates) {
			long correspondingSeed = potentialInternalState ^ LCG_XOR;
			testRandom.setSeed(correspondingSeed);
			if (testRandom.nextLong() != nextLong) continue;

			random.setSeed(correspondingSeed);
			return offset != 0 ? getSkip(potentialInternalState, offset) ^ LCG_XOR : correspondingSeed;
		}

		// Otherwise restore Random from backup and throw exception
		try {
			random = deserialize(backup);
		} catch (Exception e) {
			; // We're returning null to signify an error anyways
		}
		return null;
	}

	public synchronized void write(List<String> lines) {
		this.write(lines, true);
	}

	/* ----------------------------------------
	 * Helper function I'm using for debugging/saving outputs
	 * Adapted from https://stackoverflow.com/a/2885224 
	 * ---------------------------------------- */
	public synchronized void write(List<String> lines, boolean incrementCount) {
		if (incrementCount && this.MAX_SAVED_ENTRIES != null && this.savedEntries >= this.MAX_SAVED_ENTRIES) return;
		lines.add("");
		try {
			Files.write(this.FILEPATH, lines, StandardOpenOption.APPEND);
			if (incrementCount) ++this.savedEntries;
		} catch (Exception e) {
			;
		}
	}

	// Save the lootseed+contents of the lootSource at the provided coordinates.
	public void saveLootSourceContents(World world, int lootSourceX, int lootSourceY, int lootSourceZ, Long lootseed) {
		if (lootseed == null) return;
		TileEntity lootSource = world.getBlockTileEntity(lootSourceX, lootSourceY, lootSourceZ);
		if (lootSource instanceof TileEntityChest) this.saveLootSourceContents((TileEntityChest)lootSource, lootseed);
		else if (lootSource instanceof TileEntityDispenser) this.saveLootSourceContents((TileEntityDispenser)lootSource, lootseed);
	}

	// Save the lootseed+contents of the provided lootSource.
	public void saveLootSourceContents(IInventory lootSource, Long lootseed) {
		if (lootSource == null || (this.MAX_SAVED_ENTRIES != null && this.savedEntries >= this.MAX_SAVED_ENTRIES)) return;
		ArrayList<String> textLines = new ArrayList<String>(lootSource.getSizeInventory() + 1);
		textLines.add(lootseed.toString());
		for (int i = 0; i < lootSource.getSizeInventory(); ++i) {
			ItemStack currentItemStack = lootSource.getStackInSlot(i);
			if (currentItemStack == null) continue;

			/* ----- Infdev 20100630-1340 - ? ----- */
			// if (currentItemStack.itemID <= 256) continue;
			// String itemName = "[ID " + (currentItemStack.itemID - 256) + "]";
			/* ----- Beta 1.4_01 ----- */
			// String itemName = StringTranslate.getInstance().translateNamedKey(currentItemStack.func_20109_f()).trim();
			/* ----- Beta 1.8 - Beta 1.8.1, 1.5.2 ----- */
			String itemName = StringTranslate.getInstance().translateNamedKey(currentItemStack.getItemName()).trim();
			/* ----- 1.0 - 1.2.5 ----- */
			// String itemName = StringTranslate.getInstance().translateNamedKey(Item.itemsList[currentItemStack.itemID].getItemName()).trim();
			if (itemName.toLowerCase() == "air" || itemName.toLowerCase() == "none") continue;
			String itemAttributes = "";
			if (Item.itemsList[currentItemStack.itemID] instanceof ItemRecord) itemAttributes += " {\"" + ((ItemRecord)Item.itemsList[currentItemStack.itemID]).recordName + "\" Disc}";
			if (Item.itemsList[currentItemStack.itemID] instanceof ItemEnchantedBook) {
				ArrayList<String> enchantmentsList = new ArrayList<String>();
				((ItemEnchantedBook)Item.itemsList[currentItemStack.itemID]).addInformation(currentItemStack, null, enchantmentsList, false);
				itemAttributes += " {";
				for (String enchantment : enchantmentsList) itemAttributes += enchantment + ", ";
				itemAttributes += "}";
			}

			textLines.add("\t" + currentItemStack.stackSize + " " + itemName + " in slot " + i + itemAttributes);
		}
		this.write(textLines);
	}
}