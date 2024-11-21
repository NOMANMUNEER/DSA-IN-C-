#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    Node* search(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return search(root->left, value);
        }

        return search(root->right, value);
    }

    Node* minNode(Node* root) {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        Node* result = search(root, value);
        return result != nullptr;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder Traversal: ";
    bst.inorder();

    cout << "Preorder Traversal: ";
    bst.preorder();

    cout << "Postorder Traversal: ";
    bst.postorder();

    cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    bst.deleteNode(20);
    cout << "Inorder Traversal after deleting 20: ";
    bst.inorder();

    bst.deleteNode(30);
    cout << "Inorder Traversal after deleting 30: ";
    bst.inorder();

    return 0;
}
