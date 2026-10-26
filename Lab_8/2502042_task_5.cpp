#include <iostream>
using namespace std;
class Node {
public:
    int id;
    Node* left;
    Node* right;
    Node(int value) { id = value; left = nullptr; right = nullptr; }
};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->id) node->left = insert(node->left, value);
        else if (value > node->id) node->right = insert(node->right, value);
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
public:
    BST() { root = nullptr; }
    ~BST() { destroy(root); }
    void insert(int value) { root = insert(root, value); }
    void displayInorder() {
        cout << "In-order   (Left, Root, Right): "; inorder(root); cout << endl;
    }
    void displayPreorder() {
        cout << "Pre-order  (Root, Left, Right): "; preorder(root); cout << endl;
    }
    void displayPostorder() {
        cout << "Post-order (Left, Right, Root): "; postorder(root); cout << endl;
    }
};
int main() {
    BST hospital;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) hospital.insert(ids[i]);
    cout << "===== Patient Record IDs =====" << endl << endl;
    hospital.displayInorder();
    hospital.displayPreorder();
    hospital.displayPostorder();
    cout << endl << "In-order traversal displays the IDs in ascending order." << endl;
    return 0;
}