#include <iostream>
using namespace std;

#define SIZE 5

class StationDeque {
private:
    int arr[SIZE];
    int front, rear;

public:
    StationDeque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int id) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot add " << id << " at front.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front = front - 1;
        }

        arr[front] = id;
        cout << "Inserted " << id << " at front.\n";
    }

    void insertRear(int id) {
        if (isFull()) {
            cout << "Deque Overflow! Cannot add " << id << " at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = id;
        cout << "Inserted " << id << " at rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow! No requests to remove.\n";
            return;
        }

        cout << "Removed request " << arr[front] << " from front.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow! No requests to remove.\n";
            return;
        }

        cout << "Removed request " << arr[rear] << " from rear.\n";

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear = rear - 1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Front -> ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "<- Rear\n";
    }
};

int main() {
    StationDeque dq;

    dq.insertRear(301);
    dq.insertRear(302);
    dq.insertFront(300);

    cout << "\nCurrent Requests:\n";
    dq.display();

    cout << "\nRemoving requests:\n";
    dq.deleteFront();
    dq.deleteRear();

    cout << "\nUpdated Requests:\n";
    dq.display();

    return 0;
}
