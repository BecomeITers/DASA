#include <iostream>
#include "Queue.h"
using namespace std;
int main(){
	Queue QueueA;
	QueueA.push(1);
	QueueA.push(2);
	QueueA.push(3);
	QueueA.print();
	cout << QueueA.pop() << endl;
	cout << QueueA.pop() << endl;
	QueueA.print();
}