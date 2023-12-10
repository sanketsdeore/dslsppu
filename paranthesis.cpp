#include <iostream>
#include <string>

using namespace std;

#define max 20 // Changed size to max

class StackExp {
private:
    int top;
    char stk[max];

public:
    StackExp() : top(-1) {}

    void push(char);
    char pop();
    bool isFull();
    bool isEmpty();
};

void StackExp::push(char x) {
    if (!isFull()) {
        top++;
        stk[top] = x;
    } else {
        cout << "Stack is full. Cannot push element.\n";
    }
}

char StackExp::pop() {
    if (!isEmpty()) {
        char s = stk[top];
        top--;
        return s;
    } else {
        cout << "Stack is empty. Cannot pop element.\n";
        return '\0'; // You may want to handle this differently based on your requirements
    }
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
