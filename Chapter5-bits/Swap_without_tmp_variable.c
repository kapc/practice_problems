#include <stdio.h>
#include <stdlib.h>

/*
 * ------------------------------------------------------
 * Swap --
 *  Swap without using any temporary variable.
 * ------------------------------------------------------
 */
void
Swap(int *x, int *y) 
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;

}

int main() {
    int x = 6, y = 7;
    printf("x = %d, y = %d\n", x, y);
    Swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}
