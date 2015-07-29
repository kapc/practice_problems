#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "BinaryTree.h"

void UnbalancedTreeTest(void);

static int inline
max(int a, int b)
{
    return (a < b) ? b : a;
}


/*
 * -----------------------------------------------------
 *  GetHeightBetter --
 *      In this height function you traverse tree in post
 *      order and at each level verify the hieght at the
 *      same time. So you will not need to traverse tree
 *      twice to make a decision about if it is balanced
 *      or not.
 * -----------------------------------------------------
 */
int
GetHeightBetter(Node *root)
{
    if (root == NULL) {
        return -1;
    }

    leftHeight = GetHeightBetter(root->left);
    if (leftHeight == -2) {
        return -2;
    }

    rightHeight = GetHeightBetter(root->right);
    if (rightHeight == -2) {
        return -2;
    }

    /* Check and stop the recursion. */
    if (abs(leftHeight - rightHeight) > 1) {
        return -2;
    }

    return max(leftHeight, rightHeight) + 1;
}
/*
 * -----------------------------------------------------
 *  Height -- 
 *      Return the height of the tree.
 * -----------------------------------------------------
 */
int
Height(Node *root)
{
    if (root == NULL) {
        return 0;
    }

    return max(Height(root->left), Height(root->right)) + 1;
}

/*
 * -----------------------------------------------------
 *  IsTreeBalanced --
 *      Check if the tree is balanced or not.
 *
 *  Results:
 *      returns true if balanced, false otherwise.
 * -----------------------------------------------------
 */
bool
IsTreeBalanced(Node *root)
{
    if (root == NULL) {
        return true;
    }

    return IsTreeBalanced(root->left) &&
           IsTreeBalanced(root->right) &&
            abs(Height(root->left) - Height(root->right)) < 2;
}


int main(void) {
    Node *root = NULL;
    root = InsertNode(root, 1);
    root = InsertNode(root, 3);
    root = InsertNode(root, 5);
    root = InsertNode(root, 10);

    PrintTree(root);
    printf("Height of the tree is %d\n", Height(root));
    printf("Is the tree balanced? %s\n", IsTreeBalanced(root) ? "true" : "false");

    UnbalancedTreeTest();
}

/* Tests */

void
UnbalancedTreeTest(void)
{
    Node *root = NULL;
    root = InsertNode(root, 10);
    root = InsertNode(root, 30);
    root = InsertNode(root, 5);
    root = InsertNode(root, 25);
    root = InsertNode(root, 1);

    printf("Is this tree balanced? %s\n", IsTreeBalanced(root) ? "true" : "false");
}

