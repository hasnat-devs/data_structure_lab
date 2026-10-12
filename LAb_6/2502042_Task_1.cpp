#include <iostream>
#include <string>

using namespace std;

class BrowserHistory {
private:
    string pages[100];
    int top;

public:
    BrowserHistory() {
        top = -1;
    }

    void push(string page) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            pages[top] = page;
            cout << "Visited: " << page << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << "Back button pressed. Removed: " << pages[top] << endl;
            top--;
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No pages in history." << endl;
        } else {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }
};

int main() {
    BrowserHistory browser;

    cout << "--- Step 1: Pushing Pages ---" << endl;
    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    cout << "\n--- Step 2: Display All Pages (TOP to Bottom) ---" << endl;
    browser.display();

    cout << "\n--- Step 3: Perform one POP (Back Button) ---" << endl;
    browser.pop();

    cout << "\n--- Step 4: Display Current TOP Page ---" << endl;
    browser.showTop();

    cout << "\n--- Step 5: Remaining Browsing History ---" << endl;
    browser.display();

    return 0;
}
