#include <iostream>
#include <string>

using namespace std;

#define max 20

class StackExp {
public:
    char arr[max];
    int top = -1;
    void push(char);
    char pop();
    bool isFull();
    bool isEmpty();
};

void StackExp::push(char x) {
    if (top == max - 1) {
        cout << "Stack full!";
    }
    arr[++top] = x;
}

char StackExp::pop() {
    if (top == -1) {
        cout << "Stack empty!";
        return '\0';  // Return some default value indicating an error or an empty stack
    }
    return arr[top--];
}

bool StackExp::isFull() {
    return top == max - 1;
}

bool StackExp::isEmpty() {
    return top == -1;
}

int main() {
    StackExp s1;
    string exp;

    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the expression to check whether it is well-formed or not: ";
    cin >> exp;

    for (size_t i = 0; i < exp.length(); ++i) {
        char c = exp[i];
        switch (c) {
            case '(':
            case '[':
            case '{':
                s1.push(c);
                break;
            case ')':
                if (s1.isEmpty() || s1.pop() != '(') {
                    cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
                    return 0;
                }
                break;
            case ']':
                if (s1.isEmpty() || s1.pop() != '[') {
                    cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
                    return 0;
                }
                break;
            case '}':
                if (s1.isEmpty() || s1.pop() != '{') {
                    cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
                    return 0;
                }
                break;
        }
    }

    if (s1.isEmpty()) {
        cout << "\nExpression is well-parenthesized...\n";
    } else {
        cout << "\nSorry !!! Invalid Expression or not well-parenthesized....\n";
    }

    return 0;
}
