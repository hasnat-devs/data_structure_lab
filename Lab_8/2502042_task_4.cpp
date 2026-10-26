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
    Node* findMin(Node* node) { while (node->left != nullptr) node = node->left; return node; }
    Node* remove(Node* node, int key, int &caseType) {
        if (node == nullptr) return nullptr;
        if (key < node->id) node->left = remove(node->left, key, caseType);
        else if (key > node->id) node->right = remove(node->right, key, caseType);
        else {
            if (node->left == nullptr && node->right == nullptr) { if (caseType == 0) caseType = 1; delete node; return nullptr; }
            if (node->left == nullptr) { if (caseType == 0) caseType = 2; Node* temp = node->right; delete node; return temp; }
            if (node->right == nullptr) { if (caseType == 0) caseType = 2; Node* temp = node->left; delete node; return temp; }
            caseType = 3;
            Node* successor = findMin(node->right);
            node->id = successor->id;
            node->right = remove(node->right, successor->id, caseType);
        }
        return node;
    }
    void inorder(Node* node) { if (node == nullptr) return; inorder(node->left); cout << node->id << " "; inorder(node->right); }
    void destroy(Node* node) { if (node == nullptr) return; destroy(node->left); destroy(node->right); delete node; }
public:
    BST() { root = nullptr; }
    ~BST() { destroy(root); }
    void insert(int value) { root = insert(root, value); }
    int remove(int key) { int caseType = 0; root = remove(root, key, caseType); return caseType; }
    void display() { inorder(root); cout << endl; }
};
void buildTree(BST &tree) {
    int ids[] = {50, 30, 70, 20, 40, 60, 80}; for (int i = 0; i < 7; i++) tree.insert(ids[i]);
}
void reportDeletion(BST &tree, int key) {
    int result = tree.remove(key); cout << "Deleting " << key << ": ";
    if (result == 0)      cout << "ID not found" << endl;
    else if (result == 1) cout << "leaf node deleted" << endl;
    else if (result == 2) cout << "node with one child deleted" << endl;
    else                  cout << "node with two children deleted" << endl;
    cout << "Remaining IDs: "; tree.display();
}
void runTests() {
    cout << "\n===== Separate Test Cases =====" << endl;
    cout << "\nTest 1 - Leaf node (delete 20)" << endl; BST t1; buildTree(t1); reportDeletion(t1, 20);
    cout << "\nTest 2 - Node with one child (delete 20, then 30)" << endl; BST t2; buildTree(t2); t2.remove(20); reportDeletion(t2, 30);
    cout << "\nTest 3 - Node with two children (delete 50)" << endl; BST t3; buildTree(t3); reportDeletion(t3, 50);
}
int main() {
    BST company; buildTree(company); cout << "Employee IDs: "; company.display();
    int key; cout << "Enter an employee ID to delete: "; cin >> key;
    reportDeletion(company, key); runTests(); return 0;
}