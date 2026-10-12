#include <iostream>
#include <string>

using namespace std;

struct Node {
    string orderID;
    Node* next;
};

class RestaurantStack {
private:
    Node* top;

public:
    RestaurantStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node();
        newNode->orderID = id;
        newNode->next = top;
        top = newNode;
        cout << "Order added: " << id << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! No orders to process." << endl;
        } else {
            Node* temp = top;
            cout << "Processed order: " << temp->orderID << endl;
            top = top->next;
            delete temp;
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No orders in the stack." << endl;
        } else {
            cout << "Current TOP order: " << top->orderID << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "No remaining orders." << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {
    RestaurantStack restaurant;

    cout << "--- Step 1: Pushing Order IDs ---" << endl;
    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    cout << "\n--- Step 2: Display All Orders (TOP to Bottom) ---" << endl;
    restaurant.display();

    cout << "\n--- Step 3: Perform Two POP Operations ---" << endl;
    restaurant.pop();
    restaurant.pop();

    cout << "\n--- Step 4: Display Current TOP Order ---" << endl;
    restaurant.showTop();

    cout << "\n--- Step 5: Remaining Orders ---" << endl;
    restaurant.display();

    cout << "\n--- Step 6: Check If Stack Is Empty ---" << endl;
    if (restaurant.isEmpty()) {
        cout << "The stack is EMPTY." << endl;
    } else {
        cout << "The stack is NOT empty." << endl;
    }

    return 0;
}
