#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string productID;
    Node* next;
};
void addProduct(Node*& head, string id) {
    Node* newNode = new Node();
    newNode->productID = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}
void displayCart(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->productID;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}
void removeProduct(Node*& head, string id) {
    if (head == NULL) return;
    if (head->productID == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != NULL && current->next->productID != id) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    cout << "Shopping Cart:" << endl;
    displayCart(head);

    cout << endl;

    string removeID;
    cout << "Enter Product ID to Remove: ";
    cin >> removeID;

    removeProduct(head, removeID);

    cout << endl;

    cout << "Updated Cart:" << endl;
    displayCart(head);

    return 0;
}
