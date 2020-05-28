#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Queue {
public:
	void deleteHead();
	void appendTail(int x);
	vector<int> printContent();
private:
	stack<int> s1, s2;
};

void Queue::deleteHead() {
	if (s2.empty()) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
}

void Queue::appendTail(int x) {
	s1.push(x);
}

vector<int> Queue::printContent() {
	vector<int> ans;
	while (!s2.empty()) {
		ans.push_back(s2.top());
		s2.pop();
	}
	stack<int> temp;
	while (!s1.empty()) {
		temp.push(s1.top());
		s1.pop();
	}
	while (!temp.empty()) {
		ans.push_back(temp.top());
		temp.pop();
	}
	return ans;
}

void Test(string testName, vector<int> ans, vector<int> res) {
	cout << "testName begins: ";
	if (ans == res) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

// 只插入不删除
void test1() {
	Queue q;
	q.appendTail(1);
	q.appendTail(2);
	vector<int> ans = q.printContent();
	Test("test1", ans, { 1,2 });
}

// 先插入再删除，插入次数多于删除次数
void test2() {
	Queue q;
	q.appendTail(1);
	q.appendTail(2);
	q.deleteHead();
	vector<int> ans = q.printContent();
	Test("test2", ans, { 2 });
}

// 先插入再删除，插入次数等于删除次数
void test3() {
	Queue q;
	q.appendTail(1);
	q.appendTail(2);
	q.deleteHead();
	q.deleteHead();
	vector<int> ans = q.printContent();
	Test("test3", ans, {});
}

// 删除与插入交替进行
void test4() {
	Queue q;
	q.appendTail(1);
	q.appendTail(2);
	q.deleteHead();
	q.appendTail(3);
	vector<int> ans = q.printContent();
	Test("test4", ans, { 2,3 });
}

int main() {
	test1();
	test2();
	test3();
	test4();
}