/*Create a dynamic application
                                       QUEUE */
#include <iostream>
#include <vector>

class DynamicQueue {
private:
    std::vector<int> queue;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

public:
    DynamicQueue() : frontIndex(-1), rearIndex(-1), size(0), capacity(0) {}

    void enqueue(int value) {
        if (rearIndex == capacity - 1) {
            // Double the capacity if queue is full
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            queue.resize(newCapacity);
            capacity = newCapacity;
        }
        if (frontIndex == -1) {
            frontIndex = 0;
        }
        queue[++rearIndex] = value;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            std::cerr << "Queue underflow!" << std::endl;
            return -1; // Return a default value indicating underflow
        }
        int value = queue[frontIndex];
        if (frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        }
        else {
            frontIndex++;
        }
        size--;
        return value;
    }

    void display() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue: ";
        for (int i = frontIndex; i <= rearIndex; ++i) {
            std::cout << queue[i] << " ";
        }
        std::cout << std::endl;
    }

    void expand(int newSize) {
        if (newSize <= size) {
            std::cerr << "New size should be greater than the current size." << std::endl;
            return;
        }
        int value;
        std::cout << "Enter " << newSize - size << " elements to expand the queue:" << std::endl;
        for (int i = 0; i < newSize - size; ++i) {
            std::cout << "Enter value for element " << size + i + 1 << ": ";
            std::cin >> value;
            enqueue(value);
        }
    }

    void contract(int newSize) {
        if (newSize >= size) {
            std::cerr << "New size should be smaller than the current size." << std::endl;
            return;
        }
        size = newSize;
        rearIndex = newSize - 1;
        queue.resize(newSize);
    }
};

int main() {
    DynamicQueue queue;
    int size;
    std::cout << "Enter the initial size of the queue: ";
    std::cin >> size;

    int value;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i + 1 << ": ";
        std::cin >> value;
        queue.enqueue(value);
    }

    queue.display();

    char choice;
    do {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Enqueue element" << std::endl;
        std::cout << "2. Dequeue element" << std::endl;
        std::cout << "3. Display queue" << std::endl;
        std::cout << "4. Expand the queue" << std::endl;
        std::cout << "5. Contract the queue" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "Enter value to enqueue: ";
            std::cin >> value;
            queue.enqueue(value);
            break;
        case '2':
            value = queue.dequeue();
            if (value != -1) {
                std::cout << "Dequeued element: " << value << std::endl;
            }
            break;
        case '3':
            queue.display();
            break;
        case '4':
            int expandSize;
            std::cout << "Enter the new size to expand the queue: ";
            std::cin >> expandSize;
            queue.expand(expandSize);
            break;
        case '5':
            int contractSize;
            std::cout << "Enter the new size to contract the queue: ";
            std::cin >> contractSize;
            queue.contract(contractSize);
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
