/*Search an Element in a Linked List :
Explain the iterative approach to search for an element in a linked list.Provide a step - by - step explanation.
Compare and contrast the iterative and recursive approaches for searching an element in a linked list.
What are the advantages and disadvantages of each approach ? Provide a code and explanation*/

                                          /* Approach(Iterative)
This approach is going to be iterative.
First, let us think about what should be done to search the given element in the list.

We will traverse the list, and compare every node’s data with the given element.
If the element is found, we will return true else, we will return false after the traversal is over.
                                           Algorithm
Initialize a node curr and make it point to the head.
Now, while current is not NULL, traverse the list.
Compare curr’s data with the given element X.
If at any point, the curr’s data is equal to X, that means the element is present in the list, and we will return true.
Keep incrementing curr.
If the traversal is over and the element is not found, return false.

Now, let's compare and contrast the iterative and recursive approaches:

Iterative Approach :

                          Advantages:
                               Straightforward and easy to understand.
                               Iterative approach usually takes less memory overhead compared to recursive approach.
                          Disadvantages :
                               Requires more code compared to recursive approach.
                               Might be less elegant and harder to maintain in some cases.
Recursive Approach :

                         Advantages:
                               Can be more concise and elegant, especially for certain types of problems.
                               Can sometimes be easier to understand for certain individuals.
                         Disadvantages :
                               May consume more memory due to the recursive function calls.
                               Might lead to stack overflow errors if the linked list is too long due to excessive recursion.*/

#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node* next;
};

void push(Node** head_ref, int newkey)
{

    Node* newnode = new Node();


    newnode->key = newkey;


    newnode->next = (*head_ref);

    (*head_ref) = newnode;
}

bool search(Node* head, int x)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    Node* head = NULL;
    int x = 21;
    push(&head, 25);
    push(&head, 13);
    push(&head, 5);
    push(&head, 1);

    search(head, 13) ? cout << "Yes" : cout << "No";
    return 0;
}