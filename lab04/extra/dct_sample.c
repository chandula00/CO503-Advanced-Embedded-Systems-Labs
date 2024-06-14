#include <stdio.h>
#include <stdlib.h> // Added for malloc

/* DCT for One block(8x8) */
void DCT(void)
{
    int *data;
    int i;
    int x0, x1, x2, x3, x4, x5, x6, x7, x8;

    static const int c1 = 1420; /* cos PI/16 * root(2) */
    static const int c2 = 1338; /* cos PI/8 * root(2) */
    static const int c3 = 1204; /* cos 3PI/16 * root(2) */
    static const int c5 = 805;  /* cos 5PI/16 * root(2) */
    static const int c6 = 554;  /* cos 3PI/8 * root(2) */
    static const int c7 = 283;  /* cos 7PI/16 * root(2) */

    static const int s1 = 3;
    static const int s2 = 10;
    static const int s3 = 13;

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
        // print data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7
        printf("Input\n");
        printf("Data[0]: %d, Data[1]: %d, Data[2]: %d, Data[3]: %d, Data[4]: %d, Data[5]: %d, Data[6]: %d, Data[7]: %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);

        x8 = data[0] + data[7];
        x0 = data[0] - data[7];

        x7 = data[1] + data[6];
        x1 = data[1] - data[6];

        x6 = data[2] + data[5];
        x2 = data[2] - data[5];

        x5 = data[3] + data[4];
        x3 = data[3] - data[4];

        x4 = x8 + x5;
        x8 -= x5;

        x5 = x7 + x6;
        x7 -= x6;

        data[0] = (int)(x4 + x5);
        data[4] = (int)(x4 - x5);

        printf("x4 = %d, x5 = %d\n", x4, x5);

        data[2] = (int)((x8 * c2 + x7 * c6) >> s2);
        data[6] = (int)((x8 * c6 - x7 * c2) >> s2);

        data[7] = (int)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s2);
        data[5] = (int)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s2);
        data[3] = (int)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s2);
        data[1] = (int)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s2);

        printf("Output\n");
        printf("Data[0]: %d, Data[1]: %d, Data[2]: %d, Data[3]: %d, Data[4]: %d, Data[5]: %d, Data[6]: %d, Data[7]: %d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
        data += 8;
    }

    data -= 64;

    printf("\n\n");

    for (i = 8; i > 0; i--)
    {
        printf("Input\n");
        printf("Data[0]: %d, Data[8]: %d, Data[16]: %d, Data[24]: %d, Data[32]: %d, Data[40]: %d, Data[48]: %d, Data[56]: %d\n", data[0], data[8], data[16], data[24], data[32], data[40], data[48], data[56]);

        x8 = data[0] + data[56];
        x0 = data[0] - data[56];

        x7 = data[8] + data[48];
        x1 = data[8] - data[48];

        x6 = data[16] + data[40];
        x2 = data[16] - data[40];

        x5 = data[24] + data[32];
        x3 = data[24] - data[32];

        x4 = x8 + x5;
        x8 -= x5;

        x5 = x7 + x6;
        x7 -= x6;

        data[0] = (int)((x4 + x5) >> s1);
        data[32] = (int)((x4 - x5) >> s1);

        printf("x4 = %d, x5 = %d\n", x4, x5);
        printf("%d\n", ((x4 + x5)));
        printf("%d\n", ((x4 + x5) >> s1));

        data[16] = (int)((x8 * c2 + x7 * c6) >> s3);
        data[48] = (int)((x8 * c6 - x7 * c2) >> s3);

        data[56] = (int)((x0 * c7 - x1 * c5 + x2 * c3 - x3 * c1) >> s3);
        data[40] = (int)((x0 * c5 - x1 * c1 + x2 * c7 + x3 * c3) >> s3);
        data[24] = (int)((x0 * c3 - x1 * c7 - x2 * c1 - x3 * c5) >> s3);
        data[8] = (int)((x0 * c1 + x1 * c3 + x2 * c5 + x3 * c7) >> s3);

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
