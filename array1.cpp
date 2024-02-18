/*dynamic application for practical usage of datastructures
                                      Array */
#include <iostream>

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

public:
    DynamicArray() : array(nullptr), size(0), capacity(0) {}

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int value) {
        if (size == capacity) {
            // Double the capacity if array is full
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            int* newArray = new int[newCapacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }
        array[size++] = value;
    }

    void display() {
        std::cout << "Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    void expand(int newSize) {
        if (newSize <= size) {
            std::cout << "New size should be greater than the current size." << std::endl;
            return;
        }
        while (size < newSize) {
            int value;
            std::cout << "Enter value for index " << size << ": ";
            std::cin >> value;
            insert(value);
        }
    }

    void contract(int newSize) {
        if (newSize >= size) {
            std::cout << "New size should be smaller than the current size." << std::endl;
            return;
        }
        size = newSize;
    }
};

int main() {
    DynamicArray arr;
    int size;
    std::cout << "Enter the initial size of the array: ";
    std::cin >> size;

    for (int i = 0; i < size; ++i) {
        int value;
        std::cout << "Enter value for index " << i << ": ";
        std::cin >> value;
        arr.insert(value);
    }

    arr.display();

    char choice;
    do {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Expand the array" << std::endl;
        std::cout << "2. Contract the array" << std::endl;
        std::cout << "3. Display the array" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            int expandSize;
            std::cout << "Enter the new size to expand the array: ";
            std::cin >> expandSize;
            arr.expand(expandSize);
            break;
        case '2':
            int contractSize;
            std::cout << "Enter the new size to contract the array: ";
            std::cin >> contractSize;
            arr.contract(contractSize);
            break;
        case '3':
            arr.display();
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
