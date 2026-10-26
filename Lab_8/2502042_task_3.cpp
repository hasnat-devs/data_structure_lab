#include <iostream>
using namespace std;
class Node {
public:
    int bookID;
    Node* left;
    Node* right;
    Node(int id) { bookID = id; left = nullptr; right = nullptr; }
};
class BST {
private:
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->bookID) {
            node->left = insert(node->left, value);
        } else if (value > node->bookID) {
            node->right = insert(node->right, value);
        }
        return node;
    }
public:
    BST() { root = nullptr; }
    void insert(int value) {
        root = insert(root, value);
    }
    bool search(int key, int &comparisons) {
        Node* current = root;
        comparisons = 0;
        while (current != nullptr) {
            comparisons++;
            if (key == current->bookID) {
                return true;
            } else if (key < current->bookID) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
};
int main() {
    BST library;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        library.insert(ids[i]);
    }
    int key, comparisons;
    cout << "Enter a book ID to search: ";
    cin >> key;
    bool found = library.search(key, comparisons);
    if (found) {
        cout << "Book Found" << endl;
    } else {
        cout << "Book Not Found" << endl;
    }
    cout << "Number of comparisons made: " << comparisons << endl;
    return 0;
}