#include <iostream>
#include <string>
using namespace std;

#define MAX 10

struct Patient {
    string id;
    int priority;
};

class PriorityQueue {
private:
    Patient arr[MAX];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(string id, int priority) {
        if (count == MAX) {
            cout << "Queue is full! Cannot add patient " << id << ".\n";
            return;
        }

        int i = count - 1;
        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1].id = id;
        arr[i + 1].priority = priority;
        count++;

        cout << "Patient " << id << " added with priority " << priority << ".\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty! No patients to treat.\n";
            return;
        }

        cout << "Treating patient: " << arr[0].id << " (Priority: " << arr[0].priority << ")\n";

        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No waiting patients.\n";
            return;
        }

        cout << "Waiting patients:\n";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << arr[i].id << " | Priority: " << arr[i].priority << "\n";
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue("P101", 3);
    pq.enqueue("P102", 1);
    pq.enqueue("P103", 2);

    cout << "\nCurrent Queue:\n";
    pq.display();

    cout << "\nTreating Patients:\n";
    pq.dequeue();

    cout << "\nQueue after treatment:\n";
    pq.display();

    return 0;
}
