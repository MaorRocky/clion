//
// Created by maor on 10/11/2020.
//

// C program to rotate a linked list counter clock wise

#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
    int data;
    struct Node *next;
};

int size(struct Node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

// This function rotates a linked list counter-clockwise and
// updates the head. The function assumes that k is smaller
// than size of linked list. It doesn't modify the list if
// k is greater than or equal to size
void rotate(struct Node **head_ref, int k)
{
    if (k == 0)
        return;

    k = k % size(*head_ref);

    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    struct Node *current = *head_ref;

    // Traverse till the end.
    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;
    current = *head_ref;

    // traverse the linked list to k-1 position which
    // will be last element for rotated array.
    for (int i = 0; i < k - 1; i++)
        current = current->next;

    // update the head_ref and last element pointer to NULL
    *head_ref = current->next;
    current->next = NULL;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteNode(struct Node **head_ref, int key)
{
    // Store head node
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

/* Driver program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node *head = NULL;

    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    printf("Given linked list \n");
    printList(head);
    printf("size %d \n", size(head));
    rotate(&head, 10);

    printf("\nRotated Linked list \n");

//    deleteNode(&head,20);
    printList(head);

    return (0);
}
