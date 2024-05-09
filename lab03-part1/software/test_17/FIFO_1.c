/*
 * 	FIFO queue for shared memory communication between niosII processors
 *
 *  	DATE		: 18-08-2016
 *      AUTHOR	: Isuru Nawinne
 *
 *	Structure of the FIFO:
 *	___________________________________________________________________________
 *	| 	full	| 	empty	| 	count		|	|	|	|	|	|	|	|	|
 *	| 	?	| 	?		| 	?		|	|	|	|	|	|	|	|	|
 *	___________________________________________________________________________
 */

#include "FIFO_1.h"

void WRITE_FIFO_1(int *buffer)
{
	// Wait if the fifo is full
	while (IORD_32DIRECT(MEM_BASE, fullp) != 0)
	{
		// FIFO is full, wait for it to become non-full
	}

	// Write the data to FIFO
	int index = (writep + STARTP) / UNIT_SIZE;
	IOWR_32DIRECT(MEM_BASE, index, *buffer);

	// Update the write pointer
	writep = (writep + UNIT_SIZE) % (CAPACITY * UNIT_SIZE);

	// Update "count" in shared mem
	int count = IORD_32DIRECT(MEM_BASE, countp);
	count++;
	IOWR_32DIRECT(MEM_BASE, countp, count);

	// Update the "full?" and "empty?" flags accordingly
	// Set the full flag if FIFO is now full
	if (count == CAPACITY)
	{
		IOWR_32DIRECT(MEM_BASE, fullp, 1);
	}

	// Reset the empty flag if FIFO now has 1 entry
	if (count == 1)
	{
		IOWR_32DIRECT(MEM_BASE, emptyp, 0);
	}
}

void READ_FIFO_1(int *buffer)
{
	// Wait if the fifo is empty
	while (IORD_32DIRECT(MEM_BASE, emptyp) != 0)
	{
		// FIFO is empty, wait for it to become non-empty
	}

	// Read the data
	int index = (readp + STARTP) / UNIT_SIZE;
	*buffer = IORD_32DIRECT(MEM_BASE, index);

	// Update the read pointer
	readp = (readp + UNIT_SIZE) % (CAPACITY * UNIT_SIZE);

	// Update "count" in shared mem
	int count = IORD_32DIRECT(MEM_BASE, countp);
	count--;
	IOWR_32DIRECT(MEM_BASE, countp, count);

	// Update the "full?" and "empty?" flags accordingly
	// Set the empty flag if FIFO is now empty
	if (count == 0)
	{
		IOWR_32DIRECT(MEM_BASE, emptyp, 1);
	}

	// Reset the full flag if FIFO now has 1 entry less than capacity
	if (count == CAPACITY - 1)
	{
		IOWR_32DIRECT(MEM_BASE, fullp, 0);
	}
}

// Initialization
void FIFO_1_INIT()
{
	writep = 0; // Initially the FIFO is empty, so start writing at the first slot
	readp = 0;
	fullp = 0; // SET THIS OFFSET (If there are previous FIFOs in shared memory, use Prev Fifo's STARTP + Prev Fifo's size)
	emptyp = fullp + 1;
	countp = emptyp + 1;

	// // Assigning values for the flags.
	// IOWR_32DIRECT(MEM_BASE, fullp, 0);
	// IOWR_32DIRECT(MEM_BASE, emptyp, 0); // The fifo is empty at the start
	// IOWR_32DIRECT(MEM_BASE, countp, 0); // The fifo is empty at the start
}
