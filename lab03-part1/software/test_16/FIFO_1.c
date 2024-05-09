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
	IOWR_32DIRECT(MEM_BASE, writep * 4 + STARTP, 0);

	// Update the write pointer
	writep++;

	// Update "count" in shared mem

	// Update the "full?" and "empty?" flags accordingly
	// Set the full flag if FIFO is now full
	// Reset the empty flag if FIFO now has 1 enrty
}

void READ_FIFO_1(int *buffer)
{
	// Wait if the fifo is empty

	// Read the data

	// Update the read pointer

	// Update "count" in shared mem

	// Update the "full?" and "empty?" flags accordingly
	// Set the empty flag if FIFO is now empty
	// Reset the full flag if FIFO now has 1 enrty less than capacity
}

// Initialization
void FIFO_1_INIT()
{
	writep = 0; // Initially the FIFO is empty, so start writing at the first slot
	readp = 0;
	fullp = 0; // SET THIS OFFSET (If there are previous FIFOs in shared memory, use Prev Fifo's STARTP + Prev Fifo's size)
	emptyp = fullp + 1;
	countp = emptyp + 1;

	// Assigning values for the flags.
	IOWR_32DIRECT(MEM_BASE, fullp, 0);
	IOWR_32DIRECT(MEM_BASE, emptyp, 0); // The fifo is empty at the start
	IOWR_32DIRECT(MEM_BASE, countp, 1); // The fifo is empty at the start
}
