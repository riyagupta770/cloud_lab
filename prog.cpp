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
    
    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
    
    void preorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }
    
    void postorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->data << " ";
    }
    
    void postorder() {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void levelOrderTraversal() {
        if (root == nullptr) {
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        std::cout << "Level Order Traversal: ";
        while (!q.empty()) {
            Node* current = q.front();
            std::cout << current->data << " ";
            q.pop();

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

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
    
    std::cout << "Preorder Traversal: ";
    bst.preorder();
    
    std::cout << "Postorder Traversal: ";
    bst.postorder();

    int treeHeight = bst.getHeight();
    std::cout << "Height of the BST: " << treeHeight << std::endl;

    bst.levelOrderTraversal();

    return 0;
}
