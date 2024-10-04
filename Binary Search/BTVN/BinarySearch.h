#pragma once
#include <iostream>
using namespace std;
int NonChecking(int left, int right, int nums[], int target) {
	if (left > right) {
		return -1;
	}
	int privot = (right + left) / 2;
	if (nums[privot] == target) {
		return privot;
	}
	else if (nums[privot] < target) {
		return NonChecking(privot + 1, right, nums, target);
	}
	else if (nums[privot] > target) {
		return NonChecking(left, privot - 1, nums, target);
	}
}

int NeighborsChecking(int left, int right, int nums[], int target) {
	if (left > right) {
		return -1;
	}
	int size = right + 1;
	int privot = (right + left) / 2;
	if (nums[privot] == target) {
		bool isLeftValid = privot - 1 >= 0;
		bool isRightValid = privot + 1 < size - 1;
		if (!isLeftValid || nums[privot] < nums[privot + 1] && !isRightValid || nums[privot] > nums[privot - 1]) {
			return privot;
		}
		else {
			return -1;
		}
	}
	else if (nums[privot] < target) {
		return NeighborsChecking(privot + 1, right, nums, target);
	}
	else if (nums[privot] > target) {
		return NeighborsChecking(left, privot - 1, nums, target);
	}
}

int PivotChecking(int left, int right, int nums[], int target) {
	int LastPrivot = -1;
	if (left < right) {
		return -1;
	}
	while (left <= right) {
		int privot = (right + left) / 2;
		if (LastPrivot != -1 && privot <= LastPrivot) {
			return -1;
		}
		LastPrivot = privot;
		if (nums[privot] == target) {
			return privot;
		}
		else if (nums[privot] < target) {
			left = privot + 1;
		}
		else {
			right = privot - 1;
		}
	}
	return -1;
}

int binarysearch(int left, int right, int nums[], int target, int checkType) {
	switch (checkType) {
	case 0:
		return NonChecking(left, right, nums, target);
	case 1:
		return PivotChecking(left, right, nums, target);
	case 2:
		return NeighborsChecking(left, right, nums, target);
	}
}