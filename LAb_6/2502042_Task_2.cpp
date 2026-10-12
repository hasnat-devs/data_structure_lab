#include <iostream>
#include <string>

using namespace std;

class TextEditor {
private:
    string actions[100];
    int top;

public:
    TextEditor() {
        top = -1;
    }

    void push(string action) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            actions[top] = action;
            cout << "Action performed: " << action << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << "Undo performed. Removed action: " << actions[top] << endl;
            top--;
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No actions in stack." << endl;
        } else {
            cout << "Current TOP action: " << actions[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Action history is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }
};

int main() {
    TextEditor editor;

    cout << "--- Step 1: Pushing Actions ---" << endl;
    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");

    cout << "\n--- Step 2: Display All Actions (TOP to Bottom) ---" << endl;
    editor.display();

    cout << "\n--- Step 3: Perform Two POP Operations (Undo) ---" << endl;
    editor.pop();
    editor.pop();

    cout << "\n--- Step 4: Display Current TOP Action ---" << endl;
    editor.showTop();

    cout << "\n--- Step 5: Remaining Actions ---" << endl;
    editor.display();

    return 0;
}
