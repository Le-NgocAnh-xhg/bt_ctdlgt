#include <iostream>
using namespace std;

#define MAX 1000  

class Stack {
private:
    int a[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == MAX - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack day!\n";
            return;
        }
        a[++topIndex] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return a[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top = " << s.top() << endl;

    s.pop();
    cout << "Top sau pop = " << s.top() << endl;

    return 0;
}

