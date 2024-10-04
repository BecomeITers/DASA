#include <iostream>
#include "BinarySearch.h"
using namespace std;
int main(){
	int nums[] = { 1,2,3,4,5,6,7};
	int left = 0;
	int right = sizeof(nums) / sizeof(nums[0]) - 1;
	int res = binarysearch(left, right, nums, 5, 0);
	cout << res;
}