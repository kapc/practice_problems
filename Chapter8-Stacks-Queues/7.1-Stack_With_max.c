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

bool IsStackFull(Stack *);
bool IsStackEmpty(Stack *);

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
    if (IsStackEmpty(st)) {
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
ReadTop(Stack *st) {
    if (!IsStackEmpty(st)) {
        return st->arr[st->top];
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
        int res = PopStack(&maxStack);
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

/*
 * ------------------------------------------------------------------
 *  ReturnCurrentMax --
 *      Return the curren max in the stack.
 *
 *  Results:
 *      int
 * ------------------------------------------------------------------
 */
int
ReturnCurrentMax(void)
{
    if (IsStackEmpty(&maxStack)) {
        printf("Stack underflow.");
        return INT_MAX;
    }
    return maxStack.arr[maxStack.top];
}

int main(void) {
    bool result;
    int elem;

    InitStack(&stack);
    InitStack(&maxStack);

    result = PushMaxStack(&stack, 33);
    printf("Current max = %d\n", ReturnCurrentMax());
    result = PushMaxStack(&stack, 44);
    printf("Current max = %d\n", ReturnCurrentMax());
    result = PushMaxStack(&stack, 55);
    printf("Current max = %d\n", ReturnCurrentMax());
    result = PushMaxStack(&stack, 13);
    printf("Current max = %d\n", ReturnCurrentMax());
    result = PushMaxStack(&stack, 100);
    printf("Current max = %d\n", ReturnCurrentMax());

    while((elem = PopMaxStack(&stack)) != INT_MAX) {
        printf("%d\n", elem);
        printf("Current max = %d\n", ReturnCurrentMax());
    }


}




