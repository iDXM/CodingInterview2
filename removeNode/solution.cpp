#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* solution(ListNode* head, int value) {
	ListNode** list = &head;
	while (*list) {
		if ((*list)->val == value) {
			*list = (*list)->next;
			break;
		}
		list = &(*list)->next;
	}
	return head;
}

ListNode* vectorToList(vector<int> nums) {
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (auto item : nums) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

vector<int> listToVector(ListNode* list) {
	vector<int> nums;
	ListNode* ptr = list;
	while (ptr) {
		nums.push_back(ptr->val);
		ptr = ptr->next;
	}
	return nums;
}

void test(string testName, vector<int> nums, vector<int> ans, int value) {
	cout << testName << " begins: ";
	ListNode* temp = vectorToList(nums);
	temp = solution(temp, value);
	vector<int> res = listToVector(temp);
	if (res == ans) cout << "Passed." << endl;
	else cout << "Failed." << endl;
}

void test1() {
	vector<int> nums = {1,2,3,4,5};
	int value = 1;
	vector<int> ans = {2,3,4,5};
	test("test1", nums, ans, value);
}

void test2() {
	vector<int> nums = { 1,2,3,4,5 };
	int value = 3;
	vector<int> ans = { 1,2,4,5 };
	test("test2", nums, ans, value);
}

void test3() {
	vector<int> nums = { 1,2,3,4,5 };
	int value = 5;
	vector<int> ans = { 1,2,3,4 };
	test("test3", nums, ans, value);
}

void test4() {
	vector<int> nums = { 1,2,2,4,5 };
	int value = 2;
	vector<int> ans = { 1,2,4,5 };
	test("test4", nums, ans, value);
}

void test5() {
	vector<int> nums = { 1,2,3,4,5 };
	int value = 0;
	vector<int> ans = { 1,2,3,4,5 };
	test("test5", nums, ans, value);
}

void test6() {
	vector<int> nums = {};
	int value = 1;
	vector<int> ans = {};
	test("test6", nums, ans, value);
}

void main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}