#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

/* Function to get to the middle of the linked list */
void getMiddle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    //move the fast_ptr by 2 steps
    //move the slow_ptr by 1 step
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next;

        //move the slow_ptr only if the fast_ptr moves by 2 steps
        if (fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
    }

    cout << slow_ptr->data;
}

// Function to add a new node
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    // Start with the empty list
    Node *head = NULL;

    // Iterate and add element
    for (int i = 5; i > 0; i--)
    {
        push(&head, i);
        printList(head);
        getMiddle(head);
    }

    return 0;
}