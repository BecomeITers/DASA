#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
using namespace std;

int main(){
	cout << "MSSV\t\tHo Ten\t\tNgay Sinh\n";
	cout << "23162058\tNguyen Nhat Nam\t20/10/2005\n";
	cout << "23612100\tNguyen Van A\t25/9/2005\n";
	cout << "23612100\tNguyen Van A\t25/9/2005\n";

	cout << "\x1b[4A";
	cout << "Ma So";
	cout << "\x1b[4B";
	cout << "\x1b[4D";

	cout << "\x1b[?25l";
	string bars = "|/-\\";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < bars.length(); j++) {
				cout << bars[j];
				cout << "\x1b[1D";
				Sleep(25);
			}
		}
	cout << "\x1b[1J";
	cout << "\x1b]4;0;rgb:5f/cf/de\x1B\x5C";
	cout << "\x1b[31mCam on cac ban da dung chuong trinh!\n";
	(void)_getch();
}