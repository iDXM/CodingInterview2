#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<int> nums, int* res) {
	int n = nums.size();
	if (n <= 0) return false;
	for (int i = 0; i < n; ++i) {
		if (nums[i] < 0 || nums[i] > n - 1) return false;
		while (nums[i] != i) {
			if (nums[i] == nums[nums[i]]) {
				*res = nums[i];
				return true;
			}
			else {
				swap(nums[i], nums[nums[i]]);
			}
		}
	}
	return false;
}

bool contains(vector<int> ans, int target) {
	;
}

void test() {
	;
}

void test1() {
	;
}

void main() {
	;
}