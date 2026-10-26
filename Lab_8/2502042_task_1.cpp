#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string name;
    Node* left;
    Node* right;
    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;}};
void displayTree(Node* root) {
    if (root == nullptr) return;
    cout << "Person: " << root->name << endl;
    cout << "  Left child : ";
    if (root->left != nullptr) cout << root->left->name << endl;
    else cout << "None" << endl;
    cout << "  Right child: ";
    if (root->right != nullptr) cout << root->right->name << endl;
    else cout << "None" << endl;
    cout << endl;
    displayTree(root->left);
    displayTree(root->right);}
int main() {
    // Create nodes (family members)
    Node* grandfather = new Node("Grandfather");
    Node* father      = new Node("Father");
    Node* uncle       = new Node("Uncle");
    Node* me          = new Node("Me");
    Node* sister      = new Node("Sister");
    Node* cousin1     = new Node("Cousin1");
    Node* cousin2     = new Node("Cousin2");
    grandfather->left  = father;
    grandfather->right = uncle;

    father->left  = me;
    father->right = sister;

    uncle->left  = cousin1;
    uncle->right = cousin2;
    cout << "===== Family Tree =====" << endl << endl;
    displayTree(grandfather);
    return 0;}