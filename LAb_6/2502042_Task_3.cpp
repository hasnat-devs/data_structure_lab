#include <iostream>
#include <string>

using namespace std;

struct Node {
    string patientID;
    Node* next;
};

class HospitalStack {
private:
    Node* top;

public:
    HospitalStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node();
        newNode->patientID = id;
        newNode->next = top;
        top = newNode;
        cout << "Request added: " << id << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! No requests to handle." << endl;
        } else {
            Node* temp = top;
            cout << "Handled request: " << temp->patientID << endl;
            top = top->next;
            delete temp;
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No requests in the system." << endl;
        } else {
            cout << "New TOP request: " << top->patientID << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "No remaining requests." << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }
};

int main() {
    HospitalStack hospital;

    cout << "--- Step 1: Pushing Patient Request IDs ---" << endl;
    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "\n--- Step 2: Display All Requests (TOP to Bottom) ---" << endl;
    hospital.display();

    cout << "\n--- Step 3: Perform One POP (Handle Latest Request) ---" << endl;
    hospital.pop();

    cout << "\n--- Step 4: Display New TOP Request ---" << endl;
    hospital.showTop();

    cout << "\n--- Step 5: Remaining Requests ---" << endl;
    hospital.display();

    return 0;
}
