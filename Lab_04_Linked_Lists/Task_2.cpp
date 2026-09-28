#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string patientID;
    Node* next;
};
void addPatient(Node*& head, string id) {
    Node* newNode = new Node();
    newNode->patientID = id;
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
void displayPatients(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->patientID;
        if (current->next != NULL) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}
void removeFirstPatient(Node*& head) {
    Node* temp = head;
    cout << "Patient " << temp->patientID << " is being served." << endl;
    head = head->next;
    delete temp;
}
int main() {
    Node* head = NULL;
    addPatient(head, "P101");
    addPatient(head, "P102");
    addPatient(head, "P103");
    addPatient(head, "P104");
    cout << "Waiting Patients:" << endl;
    displayPatients(head);
    cout << endl;
    removeFirstPatient(head);
    cout << endl;
    cout << "Updated Queue:" << endl;
    displayPatients(head);

    return 0;
}
