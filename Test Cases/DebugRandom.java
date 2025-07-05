package net.minecraft;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import net.minecraft.src.ItemStack;
import net.minecraft.src.StringTranslate;
import net.minecraft.src.TileEntityChest;
import net.minecraft.src.World;

// Long lootseed = DebugRandom.getSeed(var2);

public class DebugRandom {
	static final long LCG_XOR = 25214903917L;
	static final long LCG_BACK_1_ADDEND = 107048004364969L;
	static final long LCG_BACK_2_MULTIPLIER = 254681119335897L;
    static final long LCG_BACK_2_ADDEND = 120305458776662L;
    static final long LCG_MODULO = 0xffff_ffff_ffffL;

	/* ---------------------------------
	 * Copied from https://stackoverflow.com/a/79206760, Option 3
	 * --------------------------------- */

	private static byte[] serialize(Random random) throws IOException {
		try (ByteArrayOutputStream baos = new ByteArrayOutputStream(128);
			 ObjectOutputStream oos = new ObjectOutputStream(baos)) {
			oos.writeObject(random);
			return baos.toByteArray();
		}
	}

	private static Random deserialize(byte[] serializedRandom) throws IOException, ClassNotFoundException {
		try (ByteArrayInputStream bais = new ByteArrayInputStream(serializedRandom);
			 ObjectInputStream in = new ObjectInputStream(bais)) {
			// Method for deserialization of object
			return ((Random)in.readObject());
		}
	}

	/* --------------------------------
	 * Copied from https://github.com/SeedFinding/mc_core_java/blob/eee662999e9f3fe037476b6940dbd6d5e23cdbb6/src/main/java/com/seedfinding/mccore/util/math/NextLongReverser.java#L10-L60
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

	public static Long getSeed(Random random) {
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
			// long correspondingSeed = potentialInternalState;
			testRandom.setSeed(correspondingSeed);
			if (testRandom.nextLong() != nextLong) continue;
			random.setSeed(correspondingSeed);
			return correspondingSeed;
		}

		// Otherwise restore Random from backup and throw exception
		try {
			random = deserialize(backup);
		} catch (Exception e) {
			; // We're returning null to signify an error anyways
		}
		return null;
	}

	/* ----------------------------------------
	 * Helper function I'm using for debugging/saving outputs
	 * Copied from https://stackoverflow.com/a/2885224 
	 * ---------------------------------------- */
	public static void write(String filepath, String text) {
		try {
			PrintWriter writer = new PrintWriter(filepath, "UTF-8");
			writer.println(text);
			writer.close();
		} catch (Exception e) {
			;
		}
	}

	public static void saveChestContents(World world, int chestX, int chestY, int chestZ, String type, Long lootseed) {
		if (lootseed == null) return;
		TileEntityChest chest = (TileEntityChest)world.getBlockTileEntity(chestX, chestY, chestZ);
		DebugRandom.saveChestContents(chest, type, lootseed);
	}

	public static void saveChestContents(TileEntityChest chest, String type, Long lootseed) {
		if (chest == null) return;
		String text = lootseed.toString();
		for (int i = 0; i < chest.getSizeInventory(); ++i) {
			ItemStack currentItemStack = chest.getStackInSlot(i);
			if (currentItemStack == null) continue;

			/* ----- Infdev 20100630-1340 - ... ----- */
			// if (currentItemStack.itemID <= 256) continue;
			// String itemName = "[ID " + (currentItemStack.itemID - 256) + "]";
			/* ----- Beta 1.4_01 ----- */
			// String itemName = StringTranslate.getInstance().translateNamedKey(currentItemStack.func_20109_f()).trim();
			/*  */
			String itemName = StringTranslate.getInstance().translateNamedKey(currentItemStack.getItemName()).trim();
			if (itemName.toLowerCase() == "air" || itemName.toLowerCase() == "none") continue;

			text += "\n\t" + currentItemStack.stackSize + " " + itemName + " in slot " + i; // Beta 1.4_01
		}
		DebugRandom.write("C:\\msys64\\home\\AMLL\\Test Cases\\" + type + "\\" + chestX + "_" + chestY + "_" + chestZ + ".txt", text);
	}
}