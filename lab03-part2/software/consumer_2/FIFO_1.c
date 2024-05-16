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

	// Check if FIFO is full before writing
	while (altera_avalon_fifo_read_level(CONTROL_BASE) == ALMOST_FULL)
	{
	}

	// Write data to FIFO
	altera_avalon_fifo_write_fifo(IN_BASE, CONTROL_BASE, *buffer);
}

void READ_FIFO_1(int *buffer)
{
	// Wait if the FIFO is empty
	// while (altera_avalon_fifo_read_status(FIFO_MEM_IN_CSR_BASE, ALTERA_AVALON_FIFO_STATUS_EMPTY))
	// 	;

	while (altera_avalon_fifo_read_level(CONTROL_BASE) == ALMOST_EMTY)
	{
	}

	// Read the data
	*buffer = altera_avalon_fifo_read_fifo(OUT_BASE, CONTROL_BASE);
}

// Initialization
void FIFO_1_INIT()
{
	// altera_avalon_fifo_init(CONTROL_BASE,
	// 						0,
	// 						ALMOST_EMTY,				 // Almost empty threshold
	// 						ALMOST_FULL); // Almost full threshold
}