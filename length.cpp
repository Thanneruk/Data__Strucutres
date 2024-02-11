                                       /* Find Length of a Linked List :
Describe how you would find the length of a linked list using an iterative approach.Provide a code and explanation.
Discuss the recursive approach to finding the length of a linked list.How does it work, and what are the termination conditions ?
Provide a code and explanation.


                                    Approach(Iterative) to find length of linked list
We know how to iterate through the linked list.In an iteration, we visit each node exactly once.
We can keep track of the count of each node visited and that will be the length of the linked list.

                                    Algorithm to find length of linked list
Initialize answer as 0.
Iterate through the linked list and for each iteration increment the answer by 1.
After the iteration completes, return the answer.*/

#include<iostream>
using namespace std;
struct Node {
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = NULL;
    }
};
void push_front(Node** head, int new_val) {
    Node* new_node = new Node(new_val);
    new_node->next = *head;
    *head = new_node;
}
// function to find length of a linked list
int length_iterative(Node* head) {
    int answer = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        answer++;
    }
    return answer;
}
int main() {
    Node* head = NULL;
    push_front(&head, 10);
    push_front(&head, 3);
    push_front(&head, 7);
    push_front(&head, 2);

    cout << length_iterative(head) << "\n";
}

                                 /*Approach(Recursive) to find length of linked list
To solve this problem recursively, we need to break this problem down into subproblems as we do in all recursive approaches.
For a given node of a linked list, we know it will contribute 1 to the total length.So, now we need to find the length 
of the linked list following the current node and add 1 to it.Finding the length of the remaining list can be seen as the same problem 
and hence can be solved by calling the same function for the next node.
So, the length of a linked list with ‘head’ as a pointer to 1st node can be written as : length(head) = 1 + length(head->next)
The length will be 0 for an empty linked list.This can be used as the base case in our recursive function.

                                  Algorithm for linked list length
                  If head points to NULL, return 0. (base case)
                  Else recursively call the same function for head->next and add 1 to its result.
                  Return the answer.*/

#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = NULL;
    }
};

void push_front(Node** head, int new_val) {
    Node* new_node = new Node(new_val);
    new_node->next = *head;
    *head = new_node;
}

int length_recursive(Node* head) {
    if (head == NULL) return 0;
    return 1 + length_recursive(head->next);
}

int main() {
    Node* head = NULL;
    push_front(&head, 10);
    push_front(&head, 3);
    push_front(&head, 7);
    push_front(&head, 2);

    cout << length_recursive(head);
}