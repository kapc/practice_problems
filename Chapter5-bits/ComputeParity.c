#include <stdio.h>
#include <assert.h>

/*
 * ---------------------------------------------------------------------------
 *  ComputeParity
 *      Compute parity of a number.
 *
 *  Results:
 *      Return the parity.
 * ---------------------------------------------------------------------------
 */

unsigned short ComputeParity(unsigned long int num)
{
    int count = 0;
    
    while(num) {
        if(num & 1 == 1) {
            count++;
        }
        num = num >> 1;
    }

    return (count % 2);
}

/*
 * ---------------------------------------------------------------------------
 *  ComputeParity2
 *      Basically understand that xor is 
 *      1 * 1 = 0
 *      0 * 0 = 0
 *      1 * 0 = 1
 *      0 * 1 = 1
 *
 *      Use this to calculate if number of 1 is odd or even.
 *  Result:
 *      Parity
 * ---------------------------------------------------------------------------
 */
unsigned short ComputeParity2(unsigned long int num)
{
    int result = 0;

    while(num) {
        result ^= num & 1;
        num = num >> 1;
    }
    return result;
}

/*
 * ----------------------------------------------------------------------------
 *  ComputeParity3
 *      If you do x-1 that clears the last bit so instead of shifting bits you
 *      just need to do x - 1.
 *
 *  Results:
 *      return patity.
 * -----------------------------------------------------------------------------
 */
unsigned short ComputeParity3(unsigned long int num)
{
    unsigned short int result = 0;

    while(num) {
        result ^= 1;
        num &= num - 1;
    }

    return result;
}

/*
 * ---------------------------------------------------------------------------
 *  ComputeParity4
 *      To improve performance one more thing you can do is to store the parity
 *      Assume you have an array of precomputed parity stored somewhere.
 *
 *  Results:
 *      return parity.
 * ----------------------------------------------------------------------------
 */
/*
unsigned short ComputeParity4(unsigned long int num)
{
     return preComputed[x >> 48 & 0xFFFF] ^
            preComputed[x >> 32 & 0xFFFF] ^
            preComputed[x >> 16 & 0xFFFF] ^
            preComputed[x & 0xFFFF];
}
*/

int main(void) 
{
    assert(ComputeParity(1) == 1);
    assert(ComputeParity(63) == 0);
    assert(ComputeParity2(1) == 1);
    assert(ComputeParity2(63) == 0);
    assert(ComputeParity3(1) == 1);
    assert(ComputeParity3(63) == 0);
}
