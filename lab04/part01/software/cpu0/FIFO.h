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
#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include "altera_avalon_fifo_util.h"

#define FIFO_DEPTH 8 // Assuming a FIFO depth of 16
#define ALMOST_EMTY 0
#define ALMOST_FULL FIFO_DEPTH - ALMOST_EMTY

#define IN_BASE_1to2A 0x10001114
#define OUT_BASE_1to2A 0x21054
#define CONTROL_BASE_1to2A 0x100010A0

#define IN_BASE_1to2B 0x10001110
#define OUT_BASE_1to2B 0x21050
#define CONTROL_BASE_1to2B 0x10001080

#define IN_BASE_1to2C 0x1000110C
#define OUT_BASE_1to2C 0x2104c
#define CONTROL_BASE_1to2C 0x10001060

// CALL THIS FUNCTION AT THE BEGINING OF BOTH PROGRAMS USING THIS FIFO. CHANGE THE NAME FOR DIFFERENT FIFOS
void FIFO_INIT(int controllBase);

// CHANGE THE NAME FOR DIFFERENT FIFOS
void WRITE_FIFO(int *buffer, int inBase, int controllBase);

// CHANGE THE NAME FOR DIFFERENT FIFOS
void READ_FIFO(int *buffer, int outBase, int controllBase);

#endif /* FIFO_1_H_ */