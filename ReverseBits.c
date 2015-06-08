/*
 * This program reverses a 64 bit interger.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

/*
 * ----------------------------------------------------------------------------
 * Reverse the bits.
 * 
 * Results:
 * 	Reversed value of the integer.
 * ----------------------------------------------------------------------------
 */
int64_t
Reverse64BitsInt(int64_t val)
{
    int64_t i = 0, res = 0;
    for (i = 0; i < 64; i++) {
        int64_t cur = (val >> i) & 1;
        res = res | cur;
        res = res << 1;
    }
    return res;
}

/*
 * ---------------------------------------------------------------------------
 *  TestProgram --
 *      Test the bits.
 *  
 * ---------------------------------------------------------------------------
 */
void 
TestProgram(void)
{
    assert(0 == Reverse64BitsInt(0));
    assert(4611686018427387904LL == (int64_t)Reverse64BitsInt(4));
}

int main(void) {
    TestProgram();
}

