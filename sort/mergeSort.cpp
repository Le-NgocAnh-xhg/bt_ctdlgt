#include <iostream>
using namespace std;

// Hàm in mang
void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Hàm tron 2 mang con
void merge(int a[], int left, int mid, int right, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;

    cout << "Sau khi tron: ";
    print(a, n);
}

// sap xep
void mergeSort(int a[], int left, int right, int n) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, n);
        mergeSort(a, mid + 1, right, n);
        merge(a, left, mid, right, n);
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;
    int a[100];
    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1, n);

    cout << "\nMang da sap xep: ";
    print(a, n);
    // do phuc tap O(nlogn) 
}

