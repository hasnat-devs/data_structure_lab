#include <iostream>
using namespace std;
#define SIZE 5 
class BankQueue {
private:
    int arr[SIZE]; 
    int front, rear; 
public:
    BankQueue() {
        front = -1;
        rear = -1; 
    }
    void enqueue(int token) {
        if (rear == SIZE - 1) { 
            cout << "Queue Overflow: Cannot add customer " << token << "!\n";
            return; 
        }
        if (front == -1) { 
            front = 0; 
        }
        rear++; 
        arr[rear] = token;
        cout << "Customer " << token << " entered the queue.\n"; 
    }
    void dequeue() {
        if (front == -1 || front > rear) { 
            cout << "Queue Underflow: No waiting customers to serve!\n"; 
            return;
        }
        cout << "Serving customer: " << arr[front] << "\n";
        front++;

        if (front > rear) { 
            front = -1; 
            rear = -1; 
        }
    }
    void display() {
        if (front == -1 || front > rear) { 
            cout << "No customers in line.\n"; 
            return; 
        }
        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) { 
            cout << arr[i] << " "; 
        }
        cout << "\n";
    }

    void displayCount() {
        if (front == -1 || front > rear) {
            cout << "Total waiting customers: 0\n";
        } else {
            cout << "Total waiting customers: " << (rear - front + 1) << "\n";
        }
    }
};

int main() {
    BankQueue bank;

    bank.enqueue(101);
    bank.enqueue(102);
    bank.enqueue(103);

    cout << "\nCurrent Queue Status:\n";
    bank.display();
    bank.displayCount();

    cout << "\nServing customer...\n";
    bank.dequeue();

    cout << "\nUpdated Queue Status:\n";
    bank.display();
    bank.displayCount();

    return 0;
}
