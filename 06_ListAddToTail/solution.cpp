#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

void solution(ListNode** head, int value) {
	if (!head) return;
	ListNode* pNew = new ListNode(value);
	if (!(*head)) {
		*head = pNew;
	}
	else {
		ListNode* tail = *head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = pNew;
	}
}

ListNode* vectorToList(vector<int> input) {
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (auto item : input) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

vector<int> ListToVector(ListNode* list) {
	vector<int> temp;
	ListNode* pNode = list;
	while (pNode) {
		temp.push_back(pNode->val);
		pNode = pNode->next;
	}
	return temp;
}

void test(string testName, vector<int> input, vector<int> ans, int value) {
	cout << testName << " begins: ";
	ListNode* p = vectorToList(input);
	solution(&p, value);
	vector<int> temp = ListToVector(p);
	if (temp == ans) cout << "Passed" << endl;
	else cout << "Failed" << endl;
}

// 向空链表中添加元素
void test1() {
	vector<int> input = {};
	vector<int> ans = { 1 };
	int value = 1;
	test("test1", input, ans, value);
}

// 向非空链表中添加元素
void test2() {
	vector<int> input = {1,2,3};
	vector<int> ans = { 1,2,3,1 };
	int value = 1;
	test("test2", input, ans, value);
}

void main() {
	test1();
	test2();
}