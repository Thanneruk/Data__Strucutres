dynamic application for practical usage of datastructures

                                         LinkedList 
#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Insert element at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Display the linked list
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Expand the size of the linked list by adding new elements
    void expand(int newSize) {
        int data;
        std::cout << "Enter " << newSize - size << " elements to expand the list:" << std::endl;
        for (int i = size; i < newSize; ++i) {
            std::cout << "Enter element " << i + 1 << ": ";
            std::cin >> data;
            insert(data);
        }
    }

    // Contract the size of the linked list by removing elements from the end
    void contract(int newSize) {
        if (newSize >= size) {
            std::cout << "New size should be smaller than the current size." << std::endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < newSize - 1; ++i) {
            temp = temp->next;
        }
        Node* nextNode = temp->next;
        temp->next = nullptr;
        while (nextNode) {
            Node* deleteNode = nextNode;
            nextNode = nextNode->next;
            delete deleteNode;
            size--;
        }
    }
};

int main() {
    LinkedList list;
    int size, data;
    std::cout << "Enter the initial size of the linked list: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> data;
        list.insert(data);
    }

    std::cout << "Initial linked list:" << std::endl;
    list.display();

    char choice;
    do {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Expand the list" << std::endl;
        std::cout << "2. Contract the list" << std::endl;
        std::cout << "3. Display the list" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            int expandSize;
            std::cout << "Enter the new size to expand the list: ";
            std::cin >> expandSize;
            list.expand(expandSize);
            break;
        case '2':
            int contractSize;
            std::cout << "Enter the new size to contract the list: ";
            std::cin >> contractSize;
            list.contract(contractSize);
            break;
        case '3':
            std::cout << "Current linked list:" << std::endl;
            list.display();
            break;
        case '4':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '4');

    return 0;
} 
                                    


                                    
