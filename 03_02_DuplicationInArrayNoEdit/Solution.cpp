#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countFrequency(vector<int> nums, int start, int mid) {
	int count = 0;
	for (auto num : nums) {
		if (num >= start && num <= mid) {
			++count;
		}
	}
	return count;
}

int solution(vector<int> nums) {
	int n = nums.size();
	if (n == 0) return -1;
	for (auto num : nums) {
		if (num <= 0 || num >= n) return -1;
	}
	int start = 1, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int count = countFrequency(nums, start, mid);
		if (start == end) {
			if (count > 1) return start;
			else break;
		}
		if (count > mid - start + 1) end = mid;
		else start = mid + 1;
	}
	return -1;
}

void test(string testName, vector<int> nums, vector<int> ans, int flag) {
	cout << testName << " begins: ";
	int res = solution(nums);
	if (flag != -1) {
		for (auto num : ans) {
			if (num == res) {
				cout << "Passed." << endl;
				return;
			} 
		}
		cout << "Failed." << endl;
	}
	else {
		if (res == flag) cout << "Passed." << endl;
		else cout << "Failed." << endl;
	}
}

// 最小值重复
void test1() {
	vector<int> nums = { 1,2,1,3,5,6,7,4 };
	vector<int> ans = { 1 };
	test("test1", nums, ans, 1);
}

// 最大值重复
void test2() {
	vector<int> nums = { 1,2,3,4,4 };
	vector<int> ans = { 4 };
	test("test1", nums, ans, 1);
}

// 多个值重复
void test3() {
	vector<int> nums = { 1,1,2,2 };
	vector<int> ans = { 1,2 };
	test("test1", nums, ans, 1);
}

// 非法输入
void test4() {
	vector<int> nums = {};
	vector<int> ans = {};
	test("test1", nums, ans, -1);
}

// 非法输入
void test5() {
	vector<int> nums = { 1,2,3,4,4,6 };
	vector<int> ans = {};
	test("test1", nums, ans, -1);
}

// 最大值重复
void test6() {
	vector<int> nums = { 1,2,3,4,4,-1 };
	vector<int> ans = {};
	test("test1", nums, ans, -1);
}

void main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}