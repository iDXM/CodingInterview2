#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Stack {
public:
	void deleteNum();
	void appendNum(int x);
	vector<int> printContent();
private:
	queue<int> q1, q2;
};

void Stack::deleteNum() { // 进行删除操作后，q1和q2中必定有一个为空
	if (!q1.empty()) {
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
	}
	else if (!q2.empty()){
		while (q2.size() > 1) {
			q1.push(q2.front());
			q2.pop();
		}
		q2.pop();
	}
	else {
		cerr << "Stack is empty!!!";
	}
}

void Stack::appendNum(int x) {
	if (!q1.empty()) {
		q1.push(x);
	}
	else q2.push(x);
}

vector<int> Stack::printContent() {
	vector<int> temp;
	while (!q1.empty()) {
		temp.push_back(q1.front());
		q1.pop();
	}
	while (!q2.empty()) {
		temp.push_back(q2.front());
		q2.pop();
	}
	return temp;
}

void Test(string testName, vector<int> ans, vector<int> res) {
	cout << testName << " begins: ";
	if (ans == res) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

// 只插入，不删除
void test1() {
	Stack s;
	s.appendNum(1);
	s.appendNum(2);
	vector<int> ans = s.printContent();
	Test("test1", ans, { 1,2 });
}

// 先插入，再删除
void test2() {
	Stack s;
	s.appendNum(1);
	s.appendNum(2);
	s.deleteNum();
	vector<int> ans = s.printContent();
	Test("test2", ans, { 1 });
}

// 插入与删除交替进行
void test3() {
	Stack s;
	s.appendNum(1);
	s.deleteNum();
	s.appendNum(2);
	s.appendNum(3);
	vector<int> ans = s.printContent();
	Test("test3", ans, { 2,3 });
}

int main() {
	test1();
	test2();
	test3();
}