#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string imageName;
    Node* prev;
    Node* next;
    Node(string name) {
        imageName = name;
        prev = NULL;
        next = NULL;    }};
class ImageGallery {
public:
    Node* head;
    Node* tail;
    ImageGallery() {
        head = NULL;
        tail = NULL;    }
    void addImage(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;        }    }
    void displayForward() {
        cout << "--- Gallery (First -> Last) ---" << endl;
        Node* temp = head;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". " << temp->imageName << endl;
            temp = temp->next;
            count++;        }    }
    void displayBackward() {
        cout << "--- Gallery (Last -> First) ---" << endl;
        Node* temp = tail;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". " << temp->imageName << endl;
            temp = temp->prev;
            count++;        }    }
    void demonstrateMovement() {
        if (head == NULL) return;
        cout << "\n--- Demonstrating Navigation (prev & next) ---" << endl;
        Node* current = head;
        cout << "Start position: " << current->imageName << endl;
        if (current->next != NULL) {
            current = current->next;
            cout << "Moved Forward (-> next): " << current->imageName << endl;
        }
        if (current->next != NULL) {
            current = current->next;
            cout << "Moved Forward (-> next): " << current->imageName << endl;
        }
        if (current->prev != NULL) {
            current = current->prev;
            cout << "Moved Backward (<- prev): " << current->imageName << endl;        }    }};
int main() {
    ImageGallery gallery;
    gallery.addImage("sunset.jpg");
    gallery.addImage("mountain.png");
    gallery.addImage("beach.jpg");
    gallery.addImage("forest.png");
    gallery.addImage("skyline.jpg");
    gallery.displayForward();
    cout << endl;
    gallery.displayBackward();
    gallery.demonstrateMovement();
    return 0;
}
