#include<iostream>
using namespace std;

void print(int* arr, int n){
	int i;
	for(i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
// ham vun dong cho 1 dinh
void heapify(int *arr, int n, int i){
	int max = i;
	int left = i*2 +1;
	int right = i*2 + 2;
	
	if(left < n && arr[left] > arr[right]){
		if(arr[left] >= arr[max]){
			max = left;
		}
	}
	if(right < n && arr[right] > arr[left]){
		if(arr[right] >= arr[max]){
			max = right;
		}
	}
	if(max != i){
		swap(arr[i], arr[max]);
		heapify(arr,n,max);
	}
}

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

// ham sap xep vun dong
void heap_sort(int *arr, int n){
	int i, j;
	for(i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
		print(arr,n);
	}
	for(j=n-1;j>0;j--){
		swap(arr[0],arr[j]);
		print(arr,n);
		heapify(arr,j,0);
		print(arr,n);
	}
}

int main(){
	int a[5] = {7,3,6,8,1};
	heap_sort(a,5);
	print(a,5);
}
