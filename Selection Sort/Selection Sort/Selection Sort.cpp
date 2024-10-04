#include <iostream>
using namespace std;

void SelectionSort(int array[], int n) {
    int minPos;
    for (int i = 0; i < n - 1; i++) {
        minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }
        if (minPos != i) {
            swap(array[i], array[minPos]);
        }
    }
}

int main() {
    int array[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    SelectionSort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}
