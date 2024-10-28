#pragma once
#include <iostream>
using namespace std;
struct Stack {
    int values[100] = {};  // Mảng tĩnh chứa các giá trị
    int right = -1;        // Vị trí phần tử trên cùng của stack, bắt đầu là -1 (rỗng)

    // Thêm phần tử vào stack
    void push(int v) {
        right++;
        values[right] = v;
    }

    // Loại bỏ và trả về phần tử trên cùng của stack
    int pop() {
        if (right > -1) {
            int v = values[right];
            right--;
            return v;
        }
        return -1;  // Trả về -1 nếu stack rỗng
    }

    // Trả về số lượng phần tử trong stack
    int getSize() {
        return right + 1;
    }

    // In các phần tử trong stack
    void print() {
        for (int i = 0; i <= right; i++) {
            cout << values[i] << " ";
        }
        cout << "\n";
    }
};