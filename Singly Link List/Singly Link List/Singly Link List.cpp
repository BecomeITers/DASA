#include <iostream>
#include "List.h"
using namespace std;
int main(){
	SinglyLinkList lstA;
	lstA.Add(1);
	lstA.Add(2);
	lstA.Add(3);
	lstA.Insert(4, 3);
	lstA.Print();
}