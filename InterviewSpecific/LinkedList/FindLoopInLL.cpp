#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node;

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// else returns false.
bool detectLoopHashmap(Node *h)
{
    //hash map to store the locations of the nodes
    unordered_set<Node *> s;

    while (h != NULL)
    {
        //if we find the location again then return true
        if (s.find(h) != s.end())
        {
            return true;
        }

        //if we did not find the location in the hash_map
        //insert it
        s.insert(h);

        h = h->next;
    }
    return false;
}

bool detectLoopFloydCycle(Node *head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    //move the fast_ptr by 2 steps
    //move the slow_ptr by 1 step
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next;

        if (fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }

        //if the 2 ptrs meet, then loop is found
        if (slow_ptr == fast_ptr)
        {
            return true;
        }
    }
    return false;
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;

    if (detectLoopFloydCycle(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}
