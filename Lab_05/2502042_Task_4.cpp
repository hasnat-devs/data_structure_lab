#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string songName;
    Node* next;
    Node(string name) {
        songName = name;
        next = NULL;}};
class MusicPlaylist {
public:
    Node* head;
    Node* tail;
    MusicPlaylist() {
        head = NULL;
        tail = NULL;    }
    void addSong(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head; 
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; }    }
    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;        }
        cout << "--- Playlist Songs ---" << endl;
        Node* temp = head;
        int count = 1;
        do {            cout << count << ". " << temp->songName << endl;
            temp = temp->next;
            count++;
        } while (temp != head);    }
    void playTwoRounds() {
        if (head == NULL) return;
        cout << "\n--- Playing Playlist (2 Complete Rounds) ---" << endl;
        Node* temp = head;
        for (int i = 1; i <= 10; i++) {
            int round = (i - 1) / 5 + 1;
            cout << "Round " << round << " - Now Playing: " << temp->songName << endl;
            temp = temp->next; } }}; 
int main() {
    MusicPlaylist playlist;
    playlist.addSong("Bohemian Rhapsody");
    playlist.addSong("Hotel California");
    playlist.addSong("Shape of You");
    playlist.addSong("Blinding Lights");
    playlist.addSong("Stay");
    playlist.displayPlaylist();
    playlist.playTwoRounds();
    return 0;}
