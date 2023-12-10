#include <iostream>
#include <string>
#define max 50
using namespace std;

class stack {
public:
    char arr[max];
    int top = -1;
    string user_input;  // Declare user_input as a member variable

    void push(char);
    void pop();
    void display();
    string reverse();
    bool isPalindrome();
};

void stack::push(char x) {
    if (top == max - 1) {
        cout << "Stack full!";
    }
    arr[++top] = x;
}

void stack::pop() {
    if (top == -1) {
        cout << "Stack empty!";
    }
    top--;
}

void stack::display() {
    if (top == -1) {
        cout << "Stack empty!";
    }

    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

string stack::reverse() {
    string reversed;
    for (int i = top; i > -1; i--) {
        cout << arr[i] << " ";
        reversed += arr[i];
    }
    cout << endl;
    return reversed;
}

bool stack::isPalindrome() {
    string reversed = reverse();
    return (user_input == reversed);
}

int main() {
    stack s;
    cout << "Enter string: ";

    getline(cin, s.user_input);

    for (int i = 0; i < s.user_input.size(); i++) {
        char ch = s.user_input[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            s.push(ch);
        }
    }

    s.display();

    if (s.isPalindrome()) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
