#include <stdio.h>
#include <stdlib.h>

/* Linked list node */
struct Node {
    int data;
    struct Node *next;
};




/* Function to create a new node with given data */
struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)
            malloc(
                    sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node
at the beginning of the Singly Linked List */
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = newNode(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Adds contents of two linked
lists and return the head node
of resultant list */
struct Node *addTwoLists(
        struct Node *first,
        struct Node *second)
{

    // res is head node of the resultant list
    struct Node *res = newNode(-1);
    struct Node *temp = NULL, *prev = res;
    int carry = 0, sum;

    // while both lists exist
    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0)
              + (second ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        temp = newNode(sum);
        prev->next = temp;
        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    return res->next;
}

// A utility function to print a linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{
    struct Node *res = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 8);
    push(&first, 9);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 1);
    push(&second, 1);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

    return 0;
}
