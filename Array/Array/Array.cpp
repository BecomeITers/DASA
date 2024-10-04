#include <iostream>
#include "Array.h"
using namespace std;
int main()
{
	ArrayList lst;
	lst.add(10);
	lst.add(20);
	lst.print();
	lst.insert(30, 2);
	lst.print();
	lst.removeAt(2);
	lst.print();
}