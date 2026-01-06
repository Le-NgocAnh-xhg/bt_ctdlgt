#include <iostream>
using namespace std;

/* ===== KHAI BAO NUT CAY ===== */
struct Node {
    int data;
    Node* left;
    Node* right;
};

/* ===== TAO NUT MOI ===== */
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/* ===== CAI DAT CAY DUNG THEO HINH ===== */
Node* createTree() {
    Node* root = createNode(4);

    root->left = createNode(1);
    root->right = createNode(3);

    root->left->left = createNode(2);
    root->left->right = createNode(16);

    root->right->left = createNode(9);
    root->right->right = createNode(10);

    root->left->left->left = createNode(14);
    root->left->left->right = createNode(8);

    root->left->right->left = createNode(7);

    return root;
}

/* ===== DUYET TRUOC ===== */
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/* ===== DUYET GIUA ===== */
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* ===== DUYET SAU ===== */
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/* ===== DUA DU LIEU CAY VAO MANG ===== */
void toArray(Node* root, int a[], int &n) {
    if (root == NULL) return;
    a[++n] = root->data;
    toArray(root->left, a, n);
    toArray(root->right, a, n);
}

/* ===== VUN DONG MAX HEAP ===== */
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    if (l <= n && a[l] > a[largest])
        largest = l;
    if (r <= n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n) {
    for (int i = n/2; i >= 1; i--)
        heapify(a, n, i);
}

/* ===== GAN NGUOC LAI VAO CAY ===== */
void assignTree(Node* root, int a[], int &i) {
    if (root == NULL) return;
    root->data = a[i++];
    assignTree(root->left, a, i);
    assignTree(root->right, a, i);
}

/* ===== CHUONG TRINH CHINH ===== */
int main() {
	printf("Bai 1 - BT Tuan 14 15\n");
    Node* root = createTree();

    cout << "Duyet truoc: ";
    preorder(root);
    cout << endl;

    cout << "Duyet giua: ";
    inorder(root);
    cout << endl;

    cout << "Duyet sau: ";
    postorder(root);
    cout << endl;

    int a[50], n = 0;
    toArray(root, a, n);

    buildHeap(a, n);

    int i = 1;
    assignTree(root, a, i);

    cout << "\nSau khi vun dong (duyet truoc ): ";
    preorder(root);

    return 0;
}

