#include <iostream>
using namespace std;

/* ===== DINH NGHIA NODE ===== */
struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int v, Node* l = NULL, Node* r = NULL)
    {
        value = v;
        left = l;
        right = r;
    }
};

/* ===== HAM KIEM TRA 2 CAY ===== */
bool isSameTree(Node* t1, Node* t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    if (t1->value != t2->value)
        return false;

    return isSameTree(t1->left, t2->left) &&
           isSameTree(t1->right, t2->right);
}
void preorder(Node* t)
{
    if (t == NULL) return;
    cout << t->value << " ";
    preorder(t->left);
    preorder(t->right);
}

/* ===== HAM MAIN ===== */
int main()
{
	cout << "Bai 2 - BT Tuan 14-15";
    // Tao 2 cay nhi phan bat ky
    Node* tree1 = new Node(1,
                    new Node(2),
                    new Node(3));

    Node* tree2 = new Node(1,
                    new Node(2),
                    new Node(3));
    cout << "\ncay 1 theo thu tu duyet truoc: ";
    preorder (tree1);
    cout << "\ncay 2 theo thu tu duyet truoc: ";
    preorder(tree2);
    if (isSameTree(tree1, tree2))
        cout << "\nHai cay nhi phan giong het nhau";
    else
        cout << "\nHai cay nhi phan KHONG giong nhau";

    return 0;
}

