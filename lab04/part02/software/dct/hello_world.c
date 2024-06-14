#include <stdio.h>
#include <stdlib.h> // Added for malloc
#include "system.h"

#define DCT_CI_MACRO(n, A) __builtin_custom_ini(ALT_CI_DCT_COMPONENT_0_N + (n & 0b11111), (A))

/* DCT for One block(8x8) */
void DCT(void)
{
  int *data;
  int i;

  data = (int *)malloc(sizeof(int) * 64);

  if (data == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }

  int initial_data[64] = {
      -54, -79, -36, -8, -35, -37, -19, -40,
      -121, -18, -23, -17, -19, -7, -21, 8,
      2, -89, -27, -12, -30, -23, -39, -32,
      -20, -88, -53, -24, -46, -49, -24, 2,
      -47, -17, -123, -37, -21, 6, 1, -20,
      -31, -12, -38, -67, -35, -45, -50, -41,
      -43, -19, -26, -92, -19, -13, -37, -61,
      -56, -59, -12, -32, -117, 21, 17, 5};

  for (i = 0; i < 64; ++i)
  {
    data[i] = initial_data[i];
  }

  printf("Incoming Data:\n");
  for (i = 0; i < 64; i++)
  {
    printf("%4d ", data[i]);
    if ((i + 1) % 8 == 0)
      printf("\n");
  }

  for (i = 8; i > 0; i--)
  {

    DCT_CI_MACRO(0, data[0]); // Start the DCT component
    DCT_CI_MACRO(1, data[1]);
    DCT_CI_MACRO(2, data[2]);
    DCT_CI_MACRO(3, data[3]);
    DCT_CI_MACRO(4, data[4]);
    DCT_CI_MACRO(5, data[5]);
    DCT_CI_MACRO(6, data[6]);
    DCT_CI_MACRO(7, data[7]);

    // print data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7
    printf("Input\n");
    printf("Data[0]: %d, Data[1]: %d, Data[2]: %d, Data[3]: %d, Data[4]: %d, Data[5]: %d, Data[6]: %d, Data[7]: %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);

    data[0] = DCT_CI_MACRO(8, 0);
    data[1] = DCT_CI_MACRO(9, 0);
    data[2] = DCT_CI_MACRO(10, 0);
    data[3] = DCT_CI_MACRO(11, 0);
    data[4] = DCT_CI_MACRO(12, 0);
    data[5] = DCT_CI_MACRO(13, 0);
    data[6] = DCT_CI_MACRO(14, 0);
    data[7] = DCT_CI_MACRO(15, 0);

    printf("Output\n");
    printf("Data[0]: %d, Data[1]: %d, Data[2]: %d, Data[3]: %d, Data[4]: %d, Data[5]: %d, Data[6]: %d, Data[7]: %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
    data += 8;
  }

  data -= 64;

  printf("\n\n");

  for (i = 8; i > 0; i--)
  {
    DCT_CI_MACRO(0, data[0]); // Start the DCT component
    DCT_CI_MACRO(1, data[8]);
    DCT_CI_MACRO(2, data[16]);
    DCT_CI_MACRO(3, data[24]);
    DCT_CI_MACRO(4, data[32]);
    DCT_CI_MACRO(5, data[40]);
    DCT_CI_MACRO(6, data[48]);
    DCT_CI_MACRO(7, data[56]);

    printf("Input\n");
    printf("Data[0]: %d, Data[8]: %d, Data[16]: %d, Data[24]: %d, Data[32]: %d, Data[40]: %d, Data[48]: %d, Data[56]: %d\n", data[0], data[8], data[16], data[24], data[32], data[40], data[48], data[56]);

    data[0] = DCT_CI_MACRO(16, 0);
    data[8] = DCT_CI_MACRO(17, 0);
    data[16] = DCT_CI_MACRO(18, 0);
    data[24] = DCT_CI_MACRO(19, 0);
    data[32] = DCT_CI_MACRO(20, 0);
    data[40] = DCT_CI_MACRO(21, 0);
    data[48] = DCT_CI_MACRO(22, 0);
    data[56] = DCT_CI_MACRO(23, 0);

    printf("Output\n");
    printf("Data[0]: %d, Data[8]: %d, Data[16]: %d, Data[24]: %d, Data[32]: %d, Data[40]: %d, Data[48]: %d, Data[56]: %d\n", data[0], data[8], data[16], data[24], data[32], data[40], data[48], data[56]);

    data++;
  }

  data -= 8;

  printf("Transformed Data:\n");
  for (i = 0; i < 64; i++)
  {
    printf("%4d ", data[i]);
    if ((i + 1) % 8 == 0)
      printf("\n");
  }
}

int main(void)
{
  printf("Starting CPU3\n");

  DCT();

  return 0;
}
