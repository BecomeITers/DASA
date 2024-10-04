#include <iostream>
using namespace std;
void SapXep(int array[], int n) {
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
int main(){
	int array[100];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	SapXep(array, n);
	for (int i = 0; i < n; i++) {
		cout << array[i];
	}
}
