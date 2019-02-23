#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct BinaryNode {
    int data;
    struct BinaryNode *smaller;
    struct BinaryNode *larger;
} BinaryNode;

BinaryNode* root = NULL;

void add(int);
int seek(int); //true 1 or false 0 if item exists in tree
void freeTree();

void testTree()
{
    add(5);
    assert(seek(5) == 1 && "tree contains the number 5"); //modify the true to use seek

    add(3);
    add(4);
    assert(seek(9) == 0 && "tree does not contain 9");
}

void bruteForceTree()
{
    root = malloc(sizeof(BinaryNode));
    root->data = 5;

    BinaryNode* leftNode = malloc(sizeof(BinaryNode));
    leftNode->data = 2;
    leftNode->smaller = NULL;
    leftNode->larger = NULL;

    BinaryNode* rightNode = malloc(sizeof(BinaryNode));
    rightNode->data = 8;
    rightNode->smaller = NULL;
    rightNode->larger = NULL;

    root->smaller = leftNode;
    root->larger = rightNode;

}

void testSeek()
{
    bruteForceTree();
    assert(seek(5) && "found 5");
    assert(seek(2) && "found 2");
    assert(!seek(1) && "confirm 1 does not exist");
    assert(seek(8) && "found 8 right found");
    assert(!seek(9) && "confirm 9 does not exist right right");
    assert(!seek(3) && "confirm 3 does not exist left right");
    assert(!seek(7) && "confirm 7 does not exist right left");
}

void testAdd()
{
    add(5);
    assert(seek(5) && "found the added 5");

    add(2);
    assert(seek(2) && "found the added 2");

    assert(seek(5) && "found the added 5");

    add(3);
    add(8);
    add(9);
    assert(seek(9) && seek(3) && "9 and 3 were both found");

    assert(seek(8) && "8 still exists");
}

int main(void)
{
    printf("Hello\n");
    int data[] = {5, 8, 2, 9, 4, 1, 3};
    // testTree();
    // testSeek();
    testAdd();
}

int seek(int query)
{
    // seek is going to scan the tree for the number sent
    // returns 0 if the number is not found in the tree
    // returns 1 if the number is found in the tree
    BinaryNode* nav = root;
    while("Not at the end of a branch or haven't found the data yet")
    {
        //how to find
        //check current node's data
        if (nav->data == query)
        {
            return 1;
        }
        if (nav->data > query)
        {
            //go smaller route
            if (nav->smaller == NULL)
            {
                return 0;
            }
            nav = nav->smaller;
            continue;
        }
        // the query is greater then current node.
        if (nav->larger == NULL)
        {
            return 0;
        }
        nav = nav->larger;
        continue;
    }
    return 0;
}

void add(int item)
{
    // to add the item to the end of a branch based on following rules:
    // if item is larger then current node move to right(larger) route
    // if item is smaller then current node move to left(smaller) route

    BinaryNode* newNode = malloc(sizeof(BinaryNode));
    newNode->data = item;
    newNode->smaller = NULL;
    newNode->larger = NULL;

    if (root == NULL)
    {
        root = newNode;
        return;
    }
    BinaryNode* nav = root;

    while("end of branch not found")
    {
        // travel left(smaller)
        if (item < nav->data)
    {
        // Look before you leap
        if(nav->smaller != NULL)
        {
            nav = nav->smaller;
            continue;
        }
        nav->smaller = newNode;
        return;
        // nav = nav->smaller;
    }
    if(item > nav->data) {
        // go larger
        if(nav->larger != NULL) 
        {
            nav = nav->larger;
            continue;
        }
        nav->larger = newNode;
        return;
    }
    return;
    }
}

void freeTree()
{
    // to free all heap nodes from the tree
    if(node->next == NULL)
    {
        free(node);
        return;
    }
    

}

// binary tree example from class