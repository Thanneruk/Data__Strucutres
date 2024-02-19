/*
Description:- A phonebook application is a digital directory that stores and manages contact information about individuals,
such as names and phone numbers. Users can add new contacts, search for existing ones, update contact information, and 
delete contacts using the app.

Context :-It is critical in a phonebook application to maintain an efficient and organised data structure for storing 
contact information. Users anticipate rapid search and retrieval capabilities, as well as the ability to easily add, 
edit, and delete contacts. The balanced structure and rapid search operations of a binary search tree (BST) make it
a suitable choice for organising and maintaining contact information.

Utilization :

    Insertion :
      When a user adds a new contact to the phonebook, the contact information (name and phone number) is saved to the BST. 
      The BST is designed so that names are stored in sorted order, with each node carrying a name and associated phone number. 
      The insertion procedure ensures that the BST remains balanced, preserving the binary search characteristic.

    Search : The basic function of a phonebook application is to allow users to find contacts by name.When a user searches 
    for a contact using their name, the binary search algorithm is used to navigate the BST.The BST's balanced structure 
    provides for speedy search operations by quickly eliminating unneeded branches. If a contact is located, the phone number 
    is retrieved and shown to the user.

    Update : To update an existing contact's phone number, the phonebook app searches the BST.When the contact is located, 
    the phone number is updated accordingly.Because BSTs facilitate fast search operations, changing contact information can 
    be done quickly and smoothly.

    Deletion : When a contact is deleted from the phonebook, the programme uses the binary search technique to locate it.
    Once discovered, the contact is removed from the BST.In BSTs, deletion operations require careful management of the
    tree structure to ensure balance and integrity.

    Benefits :

    Efficient Search : Binary search trees have an average time complexity of O(log n), where n is the number of contacts in 
    the phone book.This allows users to rapidly search and obtain contact information.


    Ordered Storage : BSTs organise contact information by name, allowing for alphabetical viewing of contacts.
    This organisation improves the user experience and makes it easier to find certain contacts. 

    Dynamic Operations : BSTs provide dynamic actions including insertion, search, update, and deletion, making it easier 
    to maintain contacts and react to changing demands..*/


#include <iostream>
#include <string>
using namespace std;

// Node definition for the binary search tree
struct TreeNode {
    string name;
    string phoneNumber;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string n, string num) : name(n), phoneNumber(num), left(nullptr), right(nullptr) {}
};

// Function to insert a new contact into the binary search tree
TreeNode* insertContact(TreeNode* root, string name, string phoneNumber) {
    if (root == nullptr) {
        return new TreeNode(name, phoneNumber);
    }

    if (name < root->name) {
        root->left = insertContact(root->left, name, phoneNumber);
    }
    else if (name > root->name) {
        root->right = insertContact(root->right, name, phoneNumber);
    }
    else {
        // If contact with same name already exists, update the phone number
        root->phoneNumber = phoneNumber;
    }

    return root;
}

// Function to search for a contact in the binary search tree
string searchContact(TreeNode* root, string name) {
    if (root == nullptr) {
        return "Contact not found";
    }

    if (name == root->name) {
        return "Phone number: " + root->phoneNumber;
    }
    else if (name < root->name) {
        return searchContact(root->left, name);
    }
    else {
        return searchContact(root->right, name);
    }
}

// Function to delete the entire binary search tree
void deletePhonebook(TreeNode* root) {
    if (root != nullptr) {
        deletePhonebook(root->left);
        deletePhonebook(root->right);
        delete root;
    }
}

int main() {
    int size;
    cout << "Enter the number of contacts in the phonebook: ";
    cin >> size;
    cin.ignore(); // Ignore newline character after reading size

    TreeNode* phoneBook = nullptr;

    // Input contacts from the user
    for (int i = 0; i < size; ++i) {
        string name, phoneNumber;
        cout << "Enter name for contact " << i + 1 << ": ";
        getline(cin, name);
        cout << "Enter phone number for contact " << i + 1 << ": ";
        getline(cin, phoneNumber);

        // Insert the contact into the phonebook
        phoneBook = insertContact(phoneBook, name, phoneNumber);
    }

    // Search for contacts in the phonebook
    cout << "Search results:" << endl;
    cout << "Enter a name to search: ";
    string searchName;
    getline(cin, searchName);
    cout << searchContact(phoneBook, searchName) << endl;

    // Delete the entire phonebook to free memory
    deletePhonebook(phoneBook);

    return 0;
}
