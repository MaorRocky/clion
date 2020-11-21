// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct StackNode {
    int data;
    struct StackNode *next;
};

int peek(struct StackNode *root);

struct StackNode *root = NULL;
struct StackNode *max = NULL;

struct StackNode *newNode(int data)
{
    struct StackNode *stackNode = (struct StackNode *) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode **root, int data)
{

    struct StackNode *stackNode = newNode(data);
    if (data > peek(max))
    {
        struct StackNode *stackNodeMax = newNode(data);
        stackNodeMax->next = max;
        max = stackNodeMax;

    }
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    if (popped == peek(max))
    {
        temp = max;
        max = max->next;
        free(temp);
    }

    return popped;
}

int peek(struct StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int getMax()
{
    return max->data;
}

int main()
{

    push(&root, 10);
    push(&root, 20);
    push(&root, 150);
    push(&root, 30);

    printf("%d\n", getMax());

    printf("%d popped from stack\n", pop(&root));

    printf("Top element is %d\n", peek(root));

    printf("%d popped from stack\n", pop(&root));

    printf("%d\n", getMax());
    printf("%d popped from stack\n", pop(&root));


    return 0;
}
//
// Created by maor on 15/11/2020.
//

