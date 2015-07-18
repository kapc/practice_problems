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

    if (IsStackFull(st)) {
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
    if (IsStackEmptry(st)) {
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
 * ----------------------------------------------------------------
 *  IsStackFull --
 *      Check if the stack is full.
 *  Results:
 *      True if yes, false otherwise.
 * ----------------------------------------------------------------
 */
bool
IsStackFull(Stack *st)
{
    return st->top >= MAX;
}

/*
 * ----------------------------------------------------------------
 *  ReadTop --
 *      Read top element.
 * ----------------------------------------------------------------
 */
int
ReadTop(Stach *st) {
    if (!IsStackEmpty(st)) {
        return st->arr[top];
    }
    return INT_MAX;
}

/*
 * ----------------------------------------------------------------
 *  PushMaxStack --
 *      Push an element in the max stack.
 * ----------------------------------------------------------------
 */
bool
PushMaxStack(Stack *st, int data) 
{
    
    if (IsStackFull(st)) {
        return false;
    }

    if (IsStackEmpty(&maxStack)) {
        bool result = PushStack(&maxStack, data);
    } else {
        if (data >= ReadTop(&maxStack)) {
            bool result = PushStack(&maxStack, data);
        }
    }
    return PushStack(st, data);
}

/*
 * -----------------------------------------------------------------
 *  PopMaxStack --
 *      Pop an element in the max stack.
 *
 *  Results:
 *      Success then return the element, INT_MAX otherwise.
 * -----------------------------------------------------------------
 */
int
PopMaxStack(Stack *st)
{
    if (IsStackEmpty(st)) {
        return INT_MAX;
    }

    if (st->top == maxStack.top) {
        int res = PopStack(maxStack);
    }

    return PopStack(st);
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




