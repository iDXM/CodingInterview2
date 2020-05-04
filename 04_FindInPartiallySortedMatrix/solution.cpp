#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solution(vector<vector<int>> nums, int target) {
	if (nums.size() == 0 || nums[0].size() == 0) return false;
	int n = nums.size(), m = nums[0].size();
	int i = 0, j = m - 1;
	while (i <= n - 1 && j >= 0) {
		if (nums[i][j] == target) {
			return true;
		 }
		else if (nums[i][j] > target) --j;
		else ++i;
	}
	return false;
}

void test(string testName, vector<vector<int>> nums, int target, bool flag) {
	cout << testName << " begins: ";
	bool res = solution(nums, target);
	if (res == flag) cout << "Passed" << endl;
	else cout << "Failed" << endl;
}

void test1() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 7;
	test("test1", nums, target, true);
}

void test2() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 5;
	test("test2", nums, target, false);
}

void test3() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 1;
	test("test3", nums, target, true);
}

void test4() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 15;
	test("test4", nums, target, true);
}

void test5() {
	vector<vector<int>> nums = {};
	int target = 1;
	test("test5", nums, target, false);
}

void test6() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 0;
	test("test6", nums, target, false);
}

void test7() {
	vector<vector<int>> nums = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int target = 16;
	test("test7", nums, target, false);
}

void main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}