#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main() {
    cout << "\x1b[?25l";
    for (int i = 0; i <= 100; i += 20) {
        cout << "\rLoading: " << i << "%" << flush;
        Sleep(200);
    }
    cout << "\x1b[2J\x1b[H";
    cout << "\x1b[32mNo\tID\t\tName\t\tScore\n";
    cout << "\x1b[0m";
    string line, id, name, score;
    ifstream file("text.csv");
    int count = 1;
    while (getline(file, line)) {
        stringstream s(line); 
        getline(s, id, ',');
        getline(s, name, ',');
        getline(s, score, ',');
        cout << count++ << "\t";  
        try {
            int num = stoi(score);
            if (num < 5) {
                cout << id << "\t" << "\x1b[4m" << name << "\x1b[0m\t"; 
                cout << "\x1b[31m" << score << "\x1b[0m\t";  
            }
            else {
                cout << id << "\t" << name << "\t" << score << "\t";
            }
        }
        catch (const invalid_argument&) {
            cout << id << "\t" << name << "\t" << score << "\t";
        }

        cout << endl;
    }
    file.close();  
    (void)_getch();
    cout << "\x1b[2J\x1b[H";
    cout << "\x1b[31mCam on da dung chuong trinh nay\n";
    cout << "\x1b[?25h";
    return 0;
}
