#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string website;
    Node* prev;
    Node* next;
    Node(string url) {
        website = url;
        prev = NULL;
        next = NULL;}};
class BrowserHistory {
public:
    Node* head;
    Node* tail;
    BrowserHistory() {
        head = NULL;
        tail = NULL;    }
    void addWebsite(string url) {
        Node* newNode = new Node(url);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;}    }
    void displayForward() {
        cout << "Browser History (First -> Last):" << endl;
        Node* temp = head;
        int count = 1;

        while (temp != NULL) {
            cout << count << ". " << temp->website << endl;
            temp = temp->next;
            count++;}    }
    void displayReverse() {
        cout << "Browser History (Last -> First):" << endl;
        Node* temp = tail;
        int count = 1;
        while (temp != NULL) {
            cout << count << ". " << temp->website << endl;
            temp = temp->prev;
            count++;}}};
int main() {
    BrowserHistory history;
    history.addWebsite("google.com");
    history.addWebsite("wikipedia.org");
    history.addWebsite("github.com");
    history.addWebsite("stackoverflow.com");
    history.addWebsite("cppreference.com");
    history.displayForward();
    cout << endl;
    history.displayReverse();
    return 0;}
