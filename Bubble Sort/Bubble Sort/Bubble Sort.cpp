#include <iostream>
using namespace std;
void BubbleSort(int array[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				swap(array[i], array[j]);
			}
		}
	}
}
void InsertionSort(int array[], int n) {
	for (int i = 1; i < n; i++) {
		int x = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > x) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}
void SelectionSort(int array[], int n) {
	int minPos;
	for (int i = 0; i < n; i++) {
		minPos = i;
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[minPos]) {
				minPos = j;
				swap(array[i], array[minPos]);
			}
		}
		if(minPos != i){
			int temp = array[i];
			array[i] = array[minPos];
			array[minPos] = temp;
		}
	}
}
void In(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
int main(){
	int array[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	BubbleSort(array, n);
	In(array, n);
	InsertionSort(array, n);
	In(array, n);
	SelectionSort(array, n);
	In(array, n);
}
