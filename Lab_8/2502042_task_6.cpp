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
    Node* insert(Node* node, int value, bool &inserted) {
        if (node == nullptr) { inserted = true; return new Node(value); }
        if (value < node->id) node->left = insert(node->left, value, inserted);
        else if (value > node->id) node->right = insert(node->right, value, inserted);
        else inserted = false;
        return node;
    }
    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        if (key == node->id) return true;
        if (key < node->id) return search(node->left, key);
        return search(node->right, key);
    }
    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
    Node* remove(Node* node, int key, bool &deleted) {
        if (node == nullptr) return nullptr;
        if (key < node->id) node->left = remove(node->left, key, deleted);
        else if (key > node->id) node->right = remove(node->right, key, deleted);
        else {
            deleted = true;
            if (node->left == nullptr && node->right == nullptr) { delete node; return nullptr; }
            if (node->left == nullptr) { Node* temp = node->right; delete node; return temp; }
            if (node->right == nullptr) { Node* temp = node->left; delete node; return temp; }
            Node* successor = findMin(node->right);
            node->id = successor->id;
            bool dummy = false;
            node->right = remove(node->right, successor->id, dummy);
        }
        return node;
    }
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left); cout << node->id << " "; inorder(node->right);
    }
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->id << " "; preorder(node->left); preorder(node->right);
    }
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left); postorder(node->right); cout << node->id << " ";
    }
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left); destroy(node->right); delete node;
    }
public:
    BST() { root = nullptr; }
    ~BST() { destroy(root); cout << "Memory released." << endl; }
    void insertProduct(int id) {
        bool inserted = false;
        root = insert(root, id, inserted);
        if (inserted) cout << "Product ID " << id << " inserted successfully." << endl;
        else          cout << "Product ID " << id << " already exists. Duplicate not inserted." << endl;    }
    void searchProduct(int id) {
        if (search(root, id)) cout << "Product ID " << id << " found." << endl;
        else                  cout << "Product ID " << id << " not found." << endl;    }
    void deleteProduct(int id) {
        bool deleted = false;
        root = remove(root, id, deleted);
        if (deleted) cout << "Product ID " << id << " deleted successfully." << endl;
        else         cout << "Product ID " << id << " not found. Nothing deleted." << endl;
    }
    void displayInorder() {
        if (root == nullptr) { cout << "Inventory is empty." << endl; return; }
        cout << "In-order: "; inorder(root); cout << endl;    }
    void displayPreorder() {
        if (root == nullptr) { cout << "Inventory is empty." << endl; return; }
        cout << "Pre-order: "; preorder(root); cout << endl;    }
    void displayPostorder() {
        if (root == nullptr) { cout << "Inventory is empty." << endl; return; }
        cout << "Post-order: "; postorder(root); cout << endl;    }};
void showMenu() {
    cout << "\n===== Online Store Inventory =====" << endl;
    cout << "1. Insert a product ID" << endl;
    cout << "2. Search for a product ID" << endl;
    cout << "3. Delete a product ID" << endl;
    cout << "4. Display in-order traversal" << endl;
    cout << "5. Display pre-order traversal" << endl;
    cout << "6. Display post-order traversal" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}
int main() {
    BST inventory;
    int choice, id;
    do {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 7." << endl;
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1: cout << "Enter product ID to insert: "; cin >> id; inventory.insertProduct(id); break;
            case 2: cout << "Enter product ID to search: "; cin >> id; inventory.searchProduct(id); break;
            case 3: cout << "Enter product ID to delete: "; cin >> id; inventory.deleteProduct(id); break;
            case 4: inventory.displayInorder(); break;
            case 5: inventory.displayPreorder(); break;
            case 6: inventory.displayPostorder(); break;
            case 7: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
        }
    } while (choice != 7);
    return 0;
}