                             /*Reverse a Linked List :
Implement an iterative function to reverse a linked list.Provide the code and explain how it works.
Explore the recursive method for reversing a linked list.How does it differ from the iterative approach, and 
what are the potential challenges ? Provide a code and explanation.

If the linked list has two or more elements, we can use three pointers to implement an iterative solution.
We use a function to reverse the linked list.Passing the head pointer as the sole argument, 
the function will return the head of the reversed list.

We’ll define three nodes : current(with reference to the head node), and temp and prev(with null pointers).
Using a while loop, we traverse the linked list until the next pointer does not yield null.

In the iterative process, we’ll perform these operations :

                     temp = current->next;
                     Assigns temp node to the current node’s next node
                     current->next = prev;
                     Assigns current node to the previous node’s next node
                     prev = current;
                     Increments previous node to current node
                     current = temp;
                     Increments current node to temp node */
#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

// We construct a linked list and use this function to push elements to the list 
void push(struct node** head_ref, int data) {
    struct node* node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}

// Function to reverse the list
void reverse(struct node** head_ref) {
    struct node* temp = NULL;
    struct node* prev = NULL;
    struct node* current = (*head_ref);
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

// Checking our program 
void printnodes(struct node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver function
int main() {
    struct node* head = NULL;
    push(&head, 28);
    push(&head, 21);
    push(&head, 14);
    push(&head, 7);

    cout << "Original Linked List" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "Reversed Linked List" << endl;
    printnodes(head);
    return 0;
}
    
                                 /* Reverse a Linked List Using a Recursive Function

         The recursive solution uses a stack.Each recursive call requires your compiler to allocate stack memory.
         Since recursive implementation can run out of memory, the recursive solution isn’t the best approach when 
         working with very large linked lists.

         To return the head of the new list, we recursively visit each node in the given linked list until we reach the last node.
         This last node then serves as the new head of the list.On the return path, each node appends itself to the end 
         of the partial reversed list.*/

                               #include<iostream>
                               using namespace std;
                                  struct Node {
                                      int data;
                                      struct Node* next;
                                      Node(int data)
                                      {
                                          this->data = data;
                                          next = NULL;
                                      }
                                  };

                                  struct LinkedList {
                                      Node* head;
                                      LinkedList()
                                      {
                                          head = NULL;
                                      }

                                      Node* reverse(Node* head)
                                      {
                                          if (head == NULL || head->next == NULL)
                                              return head;
                                          // Recursive call
                                          Node* rest = reverse(head->next);
                                          head->next->next = head;

                                          head->next = NULL;

                                          return rest;
                                      }

                                      void print()
                                      {
                                          struct Node* temp = head;
                                          while (temp != NULL) {
                                              cout << temp->data << " ";
                                              temp = temp->next;
                                          }
                                      }

                                      void push(int data)
                                      {
                                          Node* temp = new Node(data);
                                          temp->next = head;
                                          head = temp;
                                      }
                                  };

                                  int main()
                                  {
                                      LinkedList ll;
                                      ll.push(28);
                                      ll.push(21);
                                      ll.push(14);
                                      ll.push(7);

                                      cout << "Original Linked List\n";
                                      ll.print();

                                      ll.head = ll.reverse(ll.head);

                                      cout << "\nReversed Linked List \n";
                                      ll.print();
                                      return 0;
                                  }

