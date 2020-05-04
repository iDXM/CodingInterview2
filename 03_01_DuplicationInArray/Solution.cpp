#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solution(vector<int> nums, int* res) {
	int n = nums.size();
	if (n <= 0) return false;
	for (auto num : nums) {
		if (num < 0 || num > n - 1) return false;
	}
	for (int i = 0; i < n; ++i) {
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
	for (auto num : ans) {
		if (target == num) return true;
	}
	return false;
}

void test(string testName, vector<int> nums, vector<int> ans, bool contained) {
	cout << testName << " begins: ";
	int ret;
	bool outPut = solution(nums, &ret);
	if (outPut == contained) {
		if (outPut) {
			if (contains(ans, ret)) cout << "Passed." << endl;
			else cout << "Failed." << endl;
		}
		else cout << "Passed." << endl;
	}
	else cout << "Failed." << endl;
}

void test1() {
	vector<int> nums = {2, 1, 3, 1, 4};
	vector<int> ans = { 1 };
	test("test1", nums, ans, true);
}

void test2() {
	vector<int> nums = { 2, 1, 4, 1, 4 };
	vector<int> ans = { 1,4 };
	test("test1", nums, ans, true);
}

void test3() {
	vector<int> nums = { 2, 1, 3, 0, 4 };
	vector<int> ans = {};
	test("test1", nums, ans, false);
}

void test4() {
	vector<int> nums = { 2, 1, 3, 1, 5};
	vector<int> ans = {};
	test("test1", nums, ans, false);
}

void test5() {
	vector<int> nums = {};
	vector<int> ans = {};
	test("test1", nums, ans, false);
}

void test6() {
	vector<int> nums = { 0, 1, 4, 2, 4 };
	vector<int> ans = { 4 };
	test("test1", nums, ans, true);
}

void main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}