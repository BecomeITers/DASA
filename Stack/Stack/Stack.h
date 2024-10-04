#pragma once
#include <iostream>
using namespace std;
// Stack là ngăn xếp hoạt động theo nguyên lý LIFO tức là phần tử được thêm vào sau cùng sẽ được lấy ra đầu tiên
struct Stack { 
	int values[100] = {};
	int right = -1;

	void push(int v) {
		right++;
		values[right] = v;
	}

	int pop() {
		if (right > -1) {
			int t = values[right];
			right--;
			return t;
		}
	}

	void print() {
		for (int i = 0; i <= right; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}
};