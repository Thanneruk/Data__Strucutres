/*create a dynamic application
                                  Stack */
#include <iostream>
#include <vector>

class DynamicStack {
private:
    std::vector<int> stack;
    int size;
    int capacity;

public:
    DynamicStack() : size(0), capacity(0) {}

    void push(int value) {
        if (size == capacity) {
            // Double the capacity if stack is full
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            stack.resize(newCapacity);
            capacity = newCapacity;
        }
        stack[size++] = value;
    }

    int pop() {
        if (size == 0) {
            std::cerr << "Stack underflow!" << std::endl;
            return -1; // Return a default value indicating underflow
        }
        return stack[--size];
    }

    void display() {
        if (size == 0) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        std::cout << "Stack: ";
        for (int i = 0; i < size; ++i) {
            std::cout << stack[i] << " ";
        }
        std::cout << std::endl;
    }

    void expand(int newSize) {
        if (newSize <= size) {
            std::cerr << "New size should be greater than the current size." << std::endl;
            return;
        }
        int value;
        std::cout << "Enter " << newSize - size << " elements to expand the stack:" << std::endl;
        for (int i = size; i < newSize; ++i) {
            std::cout << "Enter value for index " << i + 1 << ": ";
            std::cin >> value;
            push(value);
        }
    }

    void contract(int newSize) {
        if (newSize >= size) {
            std::cerr << "New size should be smaller than the current size." << std::endl;
            return;
        }
        size = newSize;
        stack.resize(newSize);
    }
};

int main() {
    DynamicStack stack;
    int size;
    std::cout << "Enter the initial size of the stack: ";
    std::cin >> size;

    int value;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for index " << i + 1 << ": ";
        std::cin >> value;
        stack.push(value);
    }

    stack.display();

    char choice;
    do {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Push element" << std::endl;
        std::cout << "2. Pop element" << std::endl;
        std::cout << "3. Display stack" << std::endl;
        std::cout << "4. Expand the stack" << std::endl;
        std::cout << "5. Contract the stack" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "Enter value to push: ";
            std::cin >> value;
            stack.push(value);
            break;
        case '2':
            value = stack.pop();
            if (value != -1) {
                std::cout << "Popped element: " << value << std::endl;
            }
            break;
        case '3':
            stack.display();
            break;
        case '4':
            int expandSize;
            std::cout << "Enter the new size to expand the stack: ";
            std::cin >> expandSize;
            stack.expand(expandSize);
            break;
        case '5':
            int contractSize;
            std::cout << "Enter the new size to contract the stack: ";
            std::cin >> contractSize;
            stack.contract(contractSize);
            break;
        case '6':
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '6');

    return 0;
}
