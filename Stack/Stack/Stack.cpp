#include <iostream>
#include "Stack.h"
using namespace std;
int main(){
	Stack stackA;
	stackA.push(1);
	stackA.push(2);
	stackA.push(3);
	stackA.print();
	cout << stackA.pop() << endl;
	cout << stackA.pop() << endl;
	stackA.print();
}