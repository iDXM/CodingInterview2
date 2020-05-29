#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MinInOrder(vector<int>& data, int start, int end) {
	int min = data[start];
	for (int i = start + 1; i <= end; ++i) {
		if (min > data[i]) {
			min = data[i];
		}
	}
	return min;
}

int solution(vector<int> &data) {
	int start = 0, end = data.size() - 1;
	int mid = start;
	while (data[start] >= data[end]) {
		if (end - start == 1) {
			mid = end;
			break;
		}
		mid = start + (end - start) / 2;
		if (data[start] == data[end] && data[start] == data[mid]) return MinInOrder(data, start, end);
		if (data[mid] >= data[start]) {
			start = mid;
		}
		else if (data[mid] <= data[end]) {
			end = mid;
		}
	}
	return data[mid];
}

void Test(string testName, int res, int ans) {
	cout << testName << " begins: ";
	if (res == ans) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

void test1() {
	vector<int> data = { 4,5,6,7,1,2,3 };
	int res = solution(data);
	Test("test1", res, 1);
}

void test2() {
	vector<int> data = { 4,5,6,7,1,1,1,1 };
	int res = solution(data);
	Test("test2", res, 1);
}

void test3() {
	vector<int> data = { 4,4,4,4,1,1,1,1 };
	int res = solution(data);
	Test("test3", res, 1);
}

void test4() {
	vector<int> data = { 1,2,3,4 };
	int res = solution(data);
	Test("test4", res, 1);
}

void test5() {
	vector<int> data = { 2,1 };
	int res = solution(data);
	Test("test5", res, 1);
}

void test6() {
	vector<int> data = { 1 };
	int res = solution(data);
	Test("test6", res, 1);
}

void test7() {
	vector<int> data = { 1,0,1,1,1,1 };
	int res = solution(data);
	Test("test6", res, 0);
}

void test8() {
	vector<int> data = { 1,1,1,1,1,0,1 };
	int res = solution(data);
	Test("test7", res, 0);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}
