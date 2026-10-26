#include <iostream>
using namespace std;
class Node {
public:
    int rollNo;
    Node* left;
    Node* right;
    Node(int r) {
        rollNo = r;
        left = nullptr;
        right = nullptr;
    }};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->rollNo) {
            node->left = insert(node->left, value);
        } else if (value > node->rollNo) {
            node->right = insert(node->right, value);
        } else {
            cout << "Roll number " << value << " already exists. Skipped." << endl;
        }
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->rollNo << " ";
        inorder(node->right);}
public:
    BST() {
        root = nullptr;
    }
    void insert(int value) {
        root = insert(root, value);
    }
    void displayInorder() {
        inorder(root);
        cout << endl;
    }};
int main() {
    BST tree;
    int rolls[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) {
        tree.insert(rolls[i]);
    }
    int extra;
    for (int i = 1; i <= 2; i++) {
        cout << "Enter additional roll number " << i << ": ";
        cin >> extra;
        tree.insert(extra);
    }
    cout << "\nRoll numbers in ascending order: ";
    tree.displayInorder();
    return 0;
}