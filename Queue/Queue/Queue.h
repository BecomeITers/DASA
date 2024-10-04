#pragma once
#include <iostream>
using namespace std;
// Queue là thêm vào đầu (cuối hàng đợi) và lấy ra ở đầu còn lại (đầu hàng đợi). Nguyên tắc hoạt động là "vào trước ra trước" nghĩa là đối tượng nào được đưa vào trước sẽ được xử lý trước.
struct Queue {
	int values[100] = {};
	int right = -1;
	int left = -1;

	void push(int v) {
		right++;
		values[right] = v;
	}

	int pop() {
		if (left <= right) {
			left += 1;
			return values[left];
		}
	}

	void print() {
		for (int i = left + 1; i <= right; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}
};