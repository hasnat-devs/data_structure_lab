#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string playerName;
    Node* next;
    Node(string name) {
        playerName = name;
        next = NULL;}};
class GameTurns {
public:
    Node* head;
    Node* tail;
    GameTurns() {
        head = NULL;
        tail = NULL;    }
    void addPlayer(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;}}
    void displayOneRound() {
        if (head == NULL) {
            cout << "No players in the game." << endl;
            return;
        }
        cout << "--- Player Turns (One Round) ---" << endl;
        Node* temp = head;
        do {
            cout << "Current Turn: " << temp->playerName << endl;
            temp = temp->next;
        } while (temp != head);
    }
    void showCircularTurn() {
        if (head == NULL) return;
        cout << "\n--- Demonstrating Circular Turn Loop ---" << endl;
        Node* temp = head;
        for (int i = 1; i <= 7; i++) {
            cout << "Turn " << i << ": " << temp->playerName << endl;
            temp = temp->next;  }}};
int main() {
    GameTurns game;
    game.addPlayer("Alice");
    game.addPlayer("Bob");
    game.addPlayer("Charlie");
    game.addPlayer("David");
    game.addPlayer("Emma");
    game.displayOneRound();
    game.showCircularTurn();
    return 0;}
