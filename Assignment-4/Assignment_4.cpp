#include <iostream> // Include necessary header for input and output operations
#include <vector> // Include necessary header for vector container
#include <queue> // Include necessary header for queue container
#include <stack> // Include necessary header for stack container
using namespace std; // Using standard namespace to simplify code

// Define a class for the dynamic array
class DynamicArray {
private:
    vector<int> arr; // Define a vector to store elements of the array

public:
    // Method to insert data into the array
    void insert(int data) {
        arr.push_back(data); // Insert the data at the end of the vector
    }

    // Method to display the array
    void display() {
        cout << "Dynamic Array: "; // Print label for the dynamic array
        for (int num : arr) { // Loop through each element in the array
            cout << num << " "; // Print the element followed by a space
        }
        cout << endl; // Print a new line after displaying all elements
    }

    // Method to resize the array
    void resize() {
        int newSize; // Declare variable to store new size of the array
        cout << "Enter the new size of the array: "; // Prompt user to enter new size
        cin >> newSize; // Read user input for new size
        arr.resize(newSize); // Resize the array to the new size
        cout << "Array resized successfully!" << endl; // Print message indicating successful resizing
    }
};

// Define a class for the linked list
class LinkedList {
private:
    struct Node {
        int data; // Data stored in the node
        Node* next; // Pointer to the next node

        Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node with data
    };

    Node* head; // Pointer to the head of the linked list

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize head pointer to nullptr

    // Method to insert data into the linked list
    void insert(int data) {
        Node* newNode = new Node(data); // Create a new node with the given data
        if (!head) { // If the linked list is empty
            head = newNode; // Set the new node as the head
        }
        else { // If the linked list is not empty
            Node* current = head; // Start traversal from the head
            while (current->next) { // Traverse until the last node
                current = current->next; // Move to the next node
            }
            current->next = newNode; // Insert the new node at the end
        }
    }

    // Method to display the linked list
    void display() {
        cout << "Linked List: "; // Print label for the linked list
        Node* current = head; // Start traversal from the head
        while (current) { // Traverse until the end of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a new line after displaying all elements
    }
};

// Define a class for the stack
class CustomStack {
private:
    stack<int> stk; // Define a stack to store elements

public:
    // Method to push data onto the stack
    void push(int data) {
        stk.push(data); // Push the data onto the stack
    }

    // Method to pop data from the stack
    void pop() {
        if (!stk.empty()) { // If the stack is not empty
            stk.pop(); // Pop the top element from the stack
        }
    }

    // Method to display the stack
    void display() {
        cout << "Stack: "; // Print label for the stack
        stack<int> tempStk = stk; // Create a temporary copy of the stack
        while (!tempStk.empty()) { // Loop until the temporary stack is empty
            cout << tempStk.top() << " "; // Print the top element of the stack
            tempStk.pop(); // Pop the top element from the temporary stack
        }
        cout << endl; // Print a new line after displaying all elements
    }
};

// Define a class for the queue
class CustomQueue {
private:
    queue<int> q; // Define a queue to store elements

public:
    // Method to enqueue data into the queue
    void enqueue(int data) {
        q.push(data); // Enqueue the data into the queue
    }

    // Method to dequeue data from the queue
    void dequeue() {
        if (!q.empty()) { // If the queue is not empty
            q.pop(); // Dequeue(remove) the front element from the queue
        }
    }

    // Method to display the queue
    void display() {
        cout << "Queue: "; // Print label for the queue
        queue<int> tempQ = q; // Create a temporary copy of the queue
        while (!tempQ.empty()) { // Loop until the temporary queue is empty
            cout << tempQ.front() << " "; // Print the front element of the queue
            tempQ.pop(); // Pop the front element from the temporary queue
        }
        cout << endl; // Print a new line after displaying all elements
    }
};

// Define a class for the binary tree
class BinaryTree {
private:
    struct TreeNode {
        int data; // Data stored in the node
        TreeNode* left; // Pointer to the left child node
        TreeNode* right; // Pointer to the right child node

        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {} // Constructor to initialize node with data
    };

    TreeNode* root; // Pointer to the root of the binary tree

    // Private method to insert data into the binary tree
    TreeNode* insert(TreeNode* node, int data) {
        if (!node) { // If the current node is nullptr
            return new TreeNode(data); // Create a new node with the given data
        }
        if (data < node->data) { // If the data is less than the current node's data
            node->left = insert(node->left, data); // Recursively insert into the left subtree
        }
        else if (data > node->data) { // If the data is greater than the current node's data
            node->right = insert(node->right, data); // Recursively insert into the right subtree
        }
        return node; // Return the modified node
    }

    // Private method to perform inorder traversal of the binary tree
    void inorderTraversal(TreeNode* node) {
        if (node) { // If the current node is not nullptr
            inorderTraversal(node->left); // Traverse the left subtree
            cout << node->data << " "; // Print the data of the current node
            inorderTraversal(node->right); // Traverse the right subtree
        }
    }

public:
    BinaryTree() : root(nullptr) {} // Constructor to initialize root pointer to nullptr

    // Method to insert data into the binary tree
    void insert(int data) {
        root = insert(root, data); // Call the private insert method to insert data into the binary tree
    }

    // Method to display the binary tree
    void display() {
        cout << "Binary Tree (Inorder traversal): "; // Print label for the binary tree
        inorderTraversal(root); // Call the private inorder traversal method to display the binary tree
        cout << endl; // Print a new line after displaying all elements
    }
};

// Main function to interact with the user and test the data structures
int main() {
    cout << "Welcome to the Dynamic Data Structure Application!" << endl;

    DynamicArray dynamicArray; // Create an instance of the dynamic array
    LinkedList linkedList; // Create an instance of the linked list
    CustomStack customStack; // Create an instance of the stack
    CustomQueue customQueue; // Create an instance of the queue
    BinaryTree binaryTree; // Create an instance of the binary tree

    while (true) { // Infinite loop to keep the application running
        cout << "\nChoose a data structure to work with:" << endl; // Prompt the user to choose a data structure
        cout << "1. Dynamic Array" << endl; // Option to work with dynamic array
        cout << "2. Linked List" << endl; // Option to work with linked list
        cout << "3. Stack" << endl; // Option to work with stack
        cout << "4. Queue" << endl; // Option to work with queue
        cout << "5. Binary Tree" << endl; // Option to work with binary tree
        cout << "6. Exit" << endl; // Option to exit the application

        int choice; // Variable to store user's choice
        cout << "Enter your choice: "; // Prompt the user to enter their choice
        cin >> choice; // Read user's choice

        switch (choice) { // Switch statement to perform actions based on user's choice
        case 1: { // If user chooses dynamic array
            int data; // Variable to store data entered by user
            cout << "Enter data to insert into the dynamic array: "; // Prompt user to enter data
            cin >> data; // Read data entered by user
            dynamicArray.insert(data); // Insert the data into the dynamic array
            cout << "Data inserted into the dynamic array successfully!" << endl; // Print message indicating successful insertion
            break; // Exit the switch statement
        }
        case 2: { // If user chooses linked list
            int data; // Variable to store data entered by user
            cout << "Enter data to insert into the linked list: "; // Prompt user to enter data
            cin >> data; // Read data entered by user
            linkedList.insert(data); // Insert the data into the linked list
            cout << "Data inserted into the linked list successfully!" << endl; // Print message indicating successful insertion
            break; // Exit the switch statement
        }
        case 3: { // If user chooses stack
            int data; // Variable to store data entered by user
            cout << "Enter data to push onto the stack: "; // Prompt user to enter data
            cin >> data; // Read data entered by user
            customStack.push(data); // Push the data onto the stack
            cout << "Data pushed onto the stack successfully!" << endl; // Print message indicating successful push
            break; // Exit the switch statement
        }
        case 4: { // If user chooses queue
            int data; // Variable to store data entered by user
            cout << "Enter data to enqueue into the queue: "; // Prompt user to enter data
            cin >> data; // Read data entered by user
            customQueue.enqueue(data); // Enqueue the data into the queue
            cout << "Data enqueued into the queue successfully!" << endl; // Print message indicating successful enqueue
            break; // Exit the switch statement
        }
        case 5: { // If user chooses binary tree
            int data; // Variable to store data entered by user
            cout << "Enter data to insert into the binary tree: "; // Prompt user to enter data
            cin >> data; // Read data entered by user
            binaryTree.insert(data); // Insert the data into the binary tree
            cout << "Data inserted into the binary tree successfully!" << endl; // Print message indicating successful insertion
            break; // Exit the switch statement
        }
        case 6: { // If user chooses to exit the application
            cout << "Exiting the program." << endl; // Print message indicating program exit
            return 0; // Return 0 to indicate successful termination of the program
        }
        default: // If user enters an invalid choice
            cout << "Invalid choice! Please choose again." << endl; // Print message indicating invalid choice
        }
    }

    return 0; // Return 0 to indicate successful termination of the program
}