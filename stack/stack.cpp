#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = NULL;
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(int x) {
        Node* p = new Node;
        p->data = x;
        p->next = topNode;
        topNode = p;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }
        Node* p = topNode;
        topNode = topNode->next;
        delete p;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return topNode->data;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(15);
    stack.push(25);

    cout << "Top = " << stack.top() << endl;

    stack.pop();
    cout << "Top sau pop = " << stack.top() << endl;

    return 0;
}

