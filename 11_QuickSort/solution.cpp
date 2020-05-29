#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Partation(vector<int>& vec, int start, int end) {
	if (vec.size() <= 0 || start < 0 || end >= vec.size()) {
		throw "Invalid parameters";
	}
	int index = rand() % (end - start + 1) + start;
	swap(vec[index], vec[end]);
	int small = start - 1;
	for (index = start; index < end; ++index) {
		if (vec[index] < vec[end]) {
			++small;
			if (small != index) {
				swap(vec[small], vec[index]);
			}
		}
	}
	++small;
	swap(vec[small], vec[end]);
	return small;
}

void QuickSort(vector<int> &data, int start, int end) {
	if (start == end) return;
	int index = Partation(data, start, end);
	if (index > start) {
		QuickSort(data, start, index - 1);
	}
	if (index < end) {
		QuickSort(data, index + 1, end);
	}
}

void Test(string testName, vector<int> ans, vector<int> res) {
	cout << testName << " begins: ";
	if (ans == res) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

// 功能测试
void test1() {
	vector<int> vec = { 5,2,1,3,4 };
	vector<int> ans = { 1,2,3,4,5 };
	QuickSort(vec, 0, 4);
	Test("test1", ans, vec);
}

// 功能测试
void test2() {
	vector<int> vec = { 2,6,1,1,4,7,4,0};
	vector<int> ans = { 0,1,1,2,4,4,6,7};
	QuickSort(vec, 0, 7);
	Test("test2", ans, vec);
}

// 边界测试
void test3() {
	vector<int> vec = { 2 };
	vector<int> ans = { 2 };
	QuickSort(vec, 0, 0);
	Test("test3", ans, vec);
}

// 边界测试
void test4() {
	vector<int> vec = {};
	vector<int> ans = {};
	QuickSort(vec, 0, 0);
	Test("test4", ans, vec);
}

// 特殊值测试
void test5() {
	vector<int> vec = { 1,2,4 };
	vector<int> ans = { 1,2,4 };
	QuickSort(vec, 0, 2);
	Test("test5", ans, vec);
}

// 特殊值测试
void test6() {
	vector<int> vec = { 3,2,1 };
	vector<int> ans = { 1,2,3 };
	QuickSort(vec, 0, 2);
	Test("test6", ans, vec);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}