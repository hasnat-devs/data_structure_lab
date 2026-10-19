#include <iostream>
using namespace std;

#define SIZE 5

class PacketQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    PacketQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int packetID) {
        if ((rear + 1) % SIZE == front) {
            cout << "Buffer Full! Cannot add packet " << packetID << ".\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = packetID;
        cout << "Packet " << packetID << " added to buffer.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Buffer Empty! No packets to transmit.\n";
            return;
        }
        cout << "Transmitting packet: " << arr[front] << "\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No packets in buffer.\n";
            return;
        }
        cout << "Waiting packets: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    PacketQueue pq;

    pq.enqueue(201);
    pq.enqueue(202);
    pq.enqueue(203);
    pq.enqueue(204);
    pq.enqueue(205);

    cout << "\nCurrent Buffer:\n";
    pq.display();

    cout << "\nTransmitting Packets:\n";
    pq.dequeue();
    pq.dequeue();

    cout << "\nBuffer after transmission:\n";
    pq.display();

    cout << "\nAdding new packets (reusing freed slots):\n";
    pq.enqueue(206);
    pq.enqueue(207);

    cout << "\nFinal Buffer:\n";
    pq.display();

    return 0;
}
