/*
 * 	FIFO header for shared memory communication between niosII processors
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

// CHANGE THESE NAMES FOR DIFFERENT FIFOS
#ifndef FIFO_1_H_
#define FIFO_1_H_

#include <io.h>
#include <stdio.h>
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
#include "altera_avalon_fifo.h"
#include "system.h"

#define FIFO_DEPTH 16 // Assuming a FIFO depth of 16

#define OUT_BASE 0x41050
#define IN_BASE 0x41050
#define CONTROL_BASE 0x41000

// CALL THIS FUNCTION AT THE BEGINING OF BOTH PROGRAMS USING THIS FIFO. CHANGE THE NAME FOR DIFFERENT FIFOS
void FIFO_1_INIT();

// CHANGE THE NAME FOR DIFFERENT FIFOS
void WRITE_FIFO_1(int *buffer);

// CHANGE THE NAME FOR DIFFERENT FIFOS
void READ_FIFO_1(int *buffer);

#endif /* FIFO_1_H_ */