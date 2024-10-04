#include <iostream>
#include "Hash.h"
using namespace std;
int main()
{
	HashTable ht(10);
	ht.Add("value1", "key1");
	ht.Add("value2", "key2");
	ht.Add("value3", "key3");
	ht.Print();
	cout << ht.GetValue("key1");
}