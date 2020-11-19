// A recursive program to add two linked lists

#include <stdio.h>
#include <stdlib.h>

// A linked List Node
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node node;

/* A utility function to insert a node at the beginning of linked list */



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

/* A utility function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("n");
}

// A utility function to swap two pointers
void swapPointer(struct Node **a, struct Node **b)
{
    node *t = *a;
    *a = *b;
    *b = t;
}

/* A utility function to get size of linked list */
int getSize(struct Node *node)
{
    int size = 0;
    while (node != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}

// Adds two linked lists of same size represented by head1 and head2 and returns
// head of the resultant linked list. Carry is propagated while returning from
// the recursion
node *addSameSize(struct Node *head1, struct Node *head2, int *carry)
{
    // Since the function assumes linked lists are of same size,
    // check any of the two head pointers
    if (head1 == NULL)
        return NULL;

    int sum;

    // Allocate memory for sum node of current two nodes
    struct Node *result = (struct Node *) malloc(sizeof(struct Node));

    // Recursively add remaining nodes and get the carry
    result->next = addSameSize(head1->next, head2->next, carry);

    // add digits of current nodes and propagated carry
    sum = head1->data + head2->data + *carry;
    *carry = sum / 10;
    sum = sum % 10;

    // Assigne the sum to current node of resultant list
    result->data = sum;

    return result;
}

// This function is called after the smaller list is added to the bigger
// lists's sublist of same size. Once the right sublist is added, the carry
// must be added toe left side of larger list to get the final result.
void addCarryToRemaining(struct Node *head1, struct Node *cur, int *carry, struct Node **result)
{
    int sum;

    // If diff. number of nodes are not traversed, add carry
    if (head1 != cur)
    {
        addCarryToRemaining(head1->next, cur, carry, result);

        sum = head1->data + *carry;
        *carry = sum / 10;
        sum %= 10;

        // add this node to the front of the result
        push(result, sum);
    }
}

// The main function that adds two linked lists represented by head1 and head2.
// The sum of two lists is stored in a list referred by result
void addList(struct Node *head1, struct Node *head2, struct Node **result)
{
    struct Node *cur;

    // first list is empty
    if (head1 == NULL)
    {
        *result = head2;
        return;
    }

        // second list is empty
    else if (head2 == NULL)
    {
        *result = head1;
        return;
    }

    int size1 = getSize(head1);
    int size2 = getSize(head2);

    int carry = 0;

    // Add same size lists
    if (size1 == size2)
        *result = addSameSize(head1, head2, &carry);

    else
    {
        int diff = abs(size1 - size2);

        // First list should always be larger than second list.
        // If not, swap pointers
        if (size1 < size2)
            swapPointer(&head1, &head2);

        // move diff. number of nodes in first list
        for (cur = head1; diff--; cur = cur->next);

        // get addition of same size lists
        *result = addSameSize(cur, head2, &carry);

        // get addition of remaining first list and carry
        addCarryToRemaining(head1, cur, &carry, result);
    }

    // if some carry is still there, add a new node to the fron of
    // the result list. e.g. 999 and 87
    if (carry)
        push(result, carry);
}

void my_addList(struct Node *head1, struct Node *head2, struct Node **result)
{
    int lsize = getSize(head1);
    int rsize = getSize(head2);
    char a[lsize + 1];
    char b[rsize + 1];
    struct Node *list = NULL;
    int i = 0;
    while (head1 != NULL)
    {
        a[i++] = head1->data + '0';
        head1 = head1->next;

    }
    i++;
    a[i] = '\0';
    i = 0;
    while (head2 != NULL)
    {
        b[i++] = head2->data + '0';
        head2 = head2->next;

    }
    i++;
    b[i] = '\0';

    int carry = 0;
    lsize--;
    rsize--;
    while (lsize >= 0 || rsize >= 0 || carry)
    {
        int sum = (lsize >= 0 ? a[lsize--] - '0' : 0) + (rsize >= 0 ? b[rsize--] - '0' : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;
        struct Node *temp = NULL;
        push(&temp, sum);
        temp->next = list;
        list = temp;

    }
    *result = list;
}

// Driver program to test above functions
int main()
{
    struct Node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = {9, 9, 9};
    int arr2[] = {1, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create first list as 9->9->9
    int i;
    for (i = size1 - 1; i >= 0; --i)
        push(&head1, arr1[i]);

    // Create second list as 1->8
    for (i = size2 - 1; i >= 0; --i)
        push(&head2, arr2[i]);

//    addList(head1, head2, &result);
    my_addList(head1, head2, &result);
    printList(result);

    return 0;
}
