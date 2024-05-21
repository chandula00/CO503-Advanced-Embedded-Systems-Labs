#include <stdio.h>
#include "datatype.h"
#include "FIFO.h"

/* Level shifting to get 8 bit SIGNED values for the data  */
void levelshift(void)
{
	int i, j;
	// asm("dummy");
	while (1)
	{
		for (j = 0; j < 64; j++)
		{
			// xt_iss_profile_disable();
			// i = (INT16)RECV1();
			READ_FIFO(&i, OUT_BASE_1to2A, CONTROL_BASE_1to2A);

			// xt_iss_profile_enable();
			// printf(stderr,"Received from FIFO1 %d\n",j);
			i -= 128;
			// SEND(i);
		}

		for (j = 0; j < 64; j++)
		{
			// xt_iss_profile_disable();
			// i = (INT16)RECV2();
			READ_FIFO(&i, OUT_BASE_1to2B, CONTROL_BASE_1to2B);

			// xt_iss_profile_enable();
			// fprintf(stderr,"Received from FIFO2 %d\n",j);
			i -= 128;
			// SEND(i);
		}

		for (j = 0; j < 64; j++)
		{
			// xt_iss_profile_disable();
			// i = (INT16)RECV3();
			READ_FIFO(&i, OUT_BASE_1to2C, CONTROL_BASE_1to2C);

			// xt_iss_profile_enable();
			// fprintf(stderr,"Received from FIFO3 %d\n",j);
			i -= 128;
			// SEND(i);
		}

		// #pragma flush // changed by haris - moved it up the dummy instruction
		// 			  // resulted in correct number of iterations for this pipeline stage
		// 		asm("dummy");
		// break;
	}
}

int main(void)
{
	// levelshift();

	// printf("Hello from cpu2\n");

	return 0;
}
