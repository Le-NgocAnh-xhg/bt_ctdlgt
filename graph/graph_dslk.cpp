#include <iostream>
using namespace std;

struct Node {
    int y;
    Node* next;
};

Node* head[12];

void Matran() {
	int i;
    for (i=1; i<=11; i++)
        head[i] = NULL;
}

void addEdge(int x, int y) {
    Node* p = new Node;
    p->y = y;
    p->next = head[x];
    head[x] = p;

    Node* q = new Node;
    q->y = x;
    q->next = head[y];
    head[y] = q;
}


void display() {
    int i;
    for (i=1; i<=11; i++) {
        cout << i << ": ";
        Node* p = head[i];
        while (p != NULL) {
            cout << p->y << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main() {
    Matran();

    addEdge(1,2);
    addEdge(1,6);
    addEdge(1,7);
    addEdge(1,8);
    addEdge(1,9);
    addEdge(1,10);
    addEdge(2,3);
    addEdge(2,11);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(4,6);
    addEdge(5,6);
    addEdge(10,11);

    display();
    
}

