#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private:
    Node* root;
    
    public:
    BinarySearchTree() : root(nullptr) {}

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else if (data > root->data) {
            root->right = insert(root->right, data);
        }

        return root;
    }
    void insert(int data) {
        root = insert(root, data);
    }
    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};
    
    
int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout<< "Inserted Elements: 50, 30, 20, 40, 70, 60, 80 \n";
    std::cout << "Inorder Traversal: ";
    bst.inorder();

    return 0;
}
