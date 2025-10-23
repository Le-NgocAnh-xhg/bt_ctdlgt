#include <stdio.h>

void sxchen(int a[], int n) {
    int i, j, k,  key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        printf("\nVong lap thu %d: ", i);
        for (k = 0; k < n; k++)
            printf("%d ", a[k]);
    }
}

int main() {
    int n, i, a[100];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sxchen(a, n);
    printf("\nMang sau khi sap xep: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

