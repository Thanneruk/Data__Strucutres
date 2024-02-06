#include <iostream>

// Define a struct for the node of the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Function to insert a new node at the beginning of the list
void push(Node** head_ref, int new_data)
{
    // 1. Allocate memory for the new node
    Node* new_node = new Node();

    // 2. Set the data for the new node
    new_node->data = new_data;

    // 3. Make the next pointer of the new node point to the current head of the list
    new_node->next = (*head_ref);

    // 4. Move the head pointer to point to the new node, effectively making it the new head of the list
    (*head_ref) = new_node;
}

int main() {
    // Create an empty linked list
    Node* head = nullptr;

    // Add some nodes to the list using the push function
    push(&head, 3);   // Add node with data 3
    push(&head, 2);   // Add node with data 2
    push(&head, 1);   // Add node with data 1

    // Print the contents of the list
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";  // Print the data of the current node
        current = current->next;            // Move to the next node
    }

    return 0;
}