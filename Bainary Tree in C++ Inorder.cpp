#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


void printInorder(Node* root) {

    if (root == nullptr)

        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);

}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->left = createNode(9);
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(15);





    cout << "Inorderorder traversal of the tree: ";
    printInorder(root);
    cout << endl;

    // Remember to free the memory allocated for nodes
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}