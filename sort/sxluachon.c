#include <stdio.h>

void luachon(int a[], int n) {
    int i, j, min, temp,k;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("\nVong lap thu %d: ", i + 1);
        for (k = 0; k < n; k++)
            printf("%d ", a[k]);
    }
}

int main() {
    int i,n, a[100];
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    luachon(a, n);
    printf("\nMang sau khi sap xep: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

