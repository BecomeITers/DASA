#include <iostream>
#include "Stack.h"

void Recursion(int v);
void NotRecursion(int v);
int main()
{
	Recursion(1);
	cout << endl;
	NotRecursion(1);
	cout << endl;
}

void Recursion(int v)
{
	cout << v << " ";
	if (v > 5) return;
	Recursion(v + 1);
	Recursion(v + 2);
}

void NotRecursion(int v)
{
	Stack s;
	s.push(v);
	int curV = s.pop();
	while (curV != NULL) {
		cout << curV << " ";
		if (curV <= 5) {
			s.push(curV + 2);
			s.push(curV + 1);
		}
		curV = s.pop();

	}

}
