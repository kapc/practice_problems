#include <stdio.h>
#include <stdlib.h>



int 
main(void)
{
    int x = 0x87654321;
    printf("%x\n", x & 0xFF); // Only print last byte
    printf("%x\n", (x & 0xFFFFFF00) | 0x000000FF); // All 1's in last byte.


    // Real anwer:
    // Above solution will not work on any word size, as you are specifying the hex to be full number of bits,
    // e.g 
    printf("%x\n", x ^ ~0xFF);
    printf("%x\n", x | 0xFF);
}
