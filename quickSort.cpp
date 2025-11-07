#include <iostream>
using namespace std;

// Hàm in mang
void Print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Hàm phan doan
int partitionFunc(int a[], int left, int right, int n) {
    int pivot = a[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && a[i] <= pivot) i++;
        while (j >= left && a[j] > pivot) j--;
        if (i < j)
            swap(a[i], a[j]);
    }

    swap(a[left], a[j]); 
    cout << "Sau khi chia (pivot = " << a[j] << "): ";
    Print(a, n);

    return j; 
}

// ham de quy sx nhanh
void quickSort(int a[], int left, int right, int n) {
    if (left >= right) return;
    int p = partitionFunc(a, left, right, n);
    quickSort(a, left, p - 1, n);
    quickSort(a, p + 1, right, n);
}

// ham sap xep
void hamSx(int a[], int n) {
    quickSort(a, 0, n - 1, n);
}

// ham main
int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    int a[100];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    hamSx(a, n);

    cout << "\nMang da sap xep: ";
    Print(a, n);
    // do phuc tap O(nlogn)
}
