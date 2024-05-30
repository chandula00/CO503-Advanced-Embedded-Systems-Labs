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

#define IN_BASE_1to5 0x10001104
#define OUT_BASE_1to5 0x21068
#define CONTROL_BASE_1to5 0x10001020

#define IN_BASE_4to5 0x2104C
#define OUT_BASE_4to5 0x21070
#define CONTROL_BASE_4to5 0x21000

// 5 to 6
#define IN_BASE_5to6 0x2106C
#define OUT_BASE_5to6 0x2104C
#define CONTROL_BASE_5to6 0x21020

// CALL THIS FUNCTION AT THE BEGINING OF BOTH PROGRAMS USING THIS FIFO. CHANGE THE NAME FOR DIFFERENT FIFOS
void FIFO_INIT(int controllBase);

// CHANGE THE NAME FOR DIFFERENT FIFOS
void WRITE_FIFO(int buffer, int inBase, int controllBase);

// CHANGE THE NAME FOR DIFFERENT FIFOS
int READ_FIFO(int outBase, int controllBase);

#endif /* FIFO_1_H_ */