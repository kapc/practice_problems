#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
typedef struct Stack {
    int top;
    int arr[MAX];
} Stack;

static Stack stack;
static Stack maxStack;
/*
 * ---------------------------------------------------------------
 *  InitStack --
 *      Initialize the stack.
 * ---------------------------------------------------------------
 */
void
InitStack(Stack *st)
{
    st->top = -1;
    memset(st->arr, 0, MAX * sizeof(int));
}

/*
 * ----------------------------------------------------------------
 *  Push --
 *      Push and element on stack.
 *
 *  Results:
 *      true if success, false otherwise.
 * ----------------------------------------------------------------
 */
bool
PushStack(Stack *st, int elem)
{
    if (st->top == MAX) {
        printf("Stack overflow.");
        return false;
    }

    st->arr[++st->top] = elem;
    return true;
}

/*
 * ----------------------------------------------------------------
 *  Pop --
 *      Pop the element from stack.
 *
 *  Results:
 *      element on the top of the stack, return intmax in empty.
 * ----------------------------------------------------------------
 */
int
PopStack(Stack *st)
{
    if (st->top < 0) {
        printf("Stack underflow.");
        return INT_MAX;
    }

    return st->arr[st->top--];
}

/*
 * -----------------------------------------------------------------
 *  IsEmpty --
 *      Check if the stack is empty
 *
 *  Results:
 *      true if empty, false otherwise.
 * -----------------------------------------------------------------
 */
bool
IsStackEmpty(Stack *st) 
{
    return st->top < 0;
}

/*
 * -----------------------------------------------------------------
 *  ReturnTop --
 *      Return the top element without pop.
 *
 *  Results:
 *      top if top is there, INT_MAX if empty.
 * -----------------------------------------------------------------
 */
int
ReturnTop(Stack *st)
{
    if (!IsStackEmpty(st)) {
        return st->arr[st->top];
    }
    return INT_MAX;
}

int main(void) {
    bool result;
    int elem;

    InitStack(&stack);
    InitStack(&maxStack);

    result = PushStack(&stack, 33);
    result = PushStack(&stack, 44);
    result = PushStack(&stack, 55);

    while((elem = PopStack(&stack)) != INT_MAX) {
        printf("%d\n", elem);
    }

}




