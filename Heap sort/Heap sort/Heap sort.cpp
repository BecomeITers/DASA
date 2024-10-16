#include <iostream>
using namespace std;

void Heapify(int a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[largest] < a[l]) {
		largest = l;
	}
	if (r < n && a[largest] < a[r]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n) {
	//Xây dựng max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		Heapify(a, i, 0);
	}
}

int main(){
	int n; 
	cout << "Nhap size: ";
	cin >> n;
	int a[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	HeapSort(a, n);
	cout << "Da sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
