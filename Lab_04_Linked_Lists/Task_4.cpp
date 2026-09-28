#include <iostream>
using namespace std;

class Node {
public:
    int rollNumber;
    Node* next;
};

void addStudent(Node*& head, int roll) {
    Node* newNode = new Node();
    newNode->rollNumber = roll;
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

void insertAtBeginning(Node*& head, int roll) {
    Node* newNode = new Node();
    newNode->rollNumber = roll;
    newNode->next = head;
    head = newNode;
}

void displayStudents(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->rollNumber;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void searchStudent(Node* head, int roll) {
    Node* current = head;
    while (current != NULL) {
        if (current->rollNumber == roll) {
            cout << "Student with Roll Number " << roll << " Found" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Student with Roll Number " << roll << " Not Found" << endl;
}

int main() {
    Node* head = NULL;

    addStudent(head, 22);
    addStudent(head, 35);
    addStudent(head, 41);
    addStudent(head, 56);

    cout << "Initially:" << endl;
    displayStudents(head);

    cout << endl;

    insertAtBeginning(head, 18);

    cout << "After insertion:" << endl;
    displayStudents(head);

    cout << endl;

    int searchRoll;
    cout << "Enter Roll Number to Search: ";
    cin >> searchRoll;
    searchStudent(head, searchRoll);

    return 0;
}
