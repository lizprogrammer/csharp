#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void push(int, Node*);
int pop(Node*);
// int peek(Node*);
void freeList(Node*);

int main(void)
{
    // printf("Hello\n");
    Node* list = NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 5;
    newNode->next = NULL;

    list = newNode;

    push(3, list);
    push(12, list);
    printf("%i\n", pop(list));
    push(14, list);
    printf("%i\n", pop(list));
    printf("%i\n", pop(list));
    freeList(list);

    // head->next = second;
    // head->next->data = 7;
    // head->next->next = third;
    // head->next->next->data = 9;
    // head->next->next->next = NULL;
    // second->data = 7;
    // second->next = third;
    // third->next = NULL;
    // third->data = 9
    // push(11, head);
    // printf("%i\n", pop(head));
    // freeList(head);
}

void push(int data, Node* head)
{
    Node* trav = head;

    while(trav != NULL && trav->next != NULL )
    {
        trav = trav->next;
    }

    // trav->next = (Node*)malloc(sizeof(Node))
    // trav->next->data = data
    // trav->next->next = NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (trav == NULL)
    {
        head = newNode;
        return;
    }
    trav->next = newNode;
}

int pop(Node* head)
{
    Node* trav = head;

    if (trav == NULL) {
        return -1;
    }

    if (trav->next == NULL) {
        int data = trav->data;
        free(trav);
        return data;
    }
    // find the second to last node
    while (trav->next->next != NULL)
    {
        trav = trav->next;
    }

    int data = trav->next->data;
    free(trav->next);
    trav->next = NULL;
    return data;
}

void freeList(Node* root)
{
    Node* trav = root;
    if (trav == NULL)
    {
        return;
    }
    if (trav->next == NULL)
    {
        free(trav);
        return;
    }
    if (trav->next->next == NULL)
    {
        free(trav->next);
        free(trav);
        return;
    }
    freeList(trav->next);
    free(root);
    return;
}

void freeListNew(Node* trav)
{
    if(trav->next== NULL)
    {
        free(trav);
        return;
    }
    freeListNew(trav->next);
    free(trav);
}
