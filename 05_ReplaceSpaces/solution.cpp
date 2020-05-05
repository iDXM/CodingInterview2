#include <iostream>
#include <string>

using namespace std;

void solution(string& str) {
	int n = str.size();
	if (n == 0) return;
	int numOfcha = 0, numOfspace = 0;
	for (auto s : str) {
		if (s != NULL) {
			if (s != ' ') ++numOfcha;
			else ++numOfspace;
		}
		else break;
	}
	if (numOfcha == 0 && numOfspace == 0) return;
	if (numOfcha + 3 * numOfspace > n) {
		str = "out fo memory!";
		return;
	}
	int p1 = numOfcha + numOfspace - 1, p2 = numOfcha + 3 * numOfspace - 1;
	while (p1 != p2 && p1 >= 0) {
		if (str[p1] == ' ') {
			--p1;
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else str[p2--] = str[p1--];
	}
	return;
}

void test(string testName, string str, string ans) {
	cout << testName << " begins: ";
	solution(str);
	if (str == ans) cout << "Passed." << endl;
	else cout << "Failed." << endl;
}

// 有一个空格
void test1() {
	string str = { 'w','e',' ','a', 'r', 'e', NULL, NULL };
	string ans = { 'w','e','%', '2', '0', 'a', 'r', 'e' };
	test("test1", str, ans);
}

// 有多个空格，连续
void test2() {
	string str = { 'w','e',' ', ' ','a', 'r', 'e', NULL, NULL, NULL, NULL };
	string ans = { 'w','e','%', '2', '0', '%', '2', '0', 'a', 'r', 'e' };
	test("test2", str, ans);
}

// 有多个空格，不连续
void test3() {
	string str = { 'w','e',' ', 'a', ' ', 'r', 'e', NULL, NULL, NULL, NULL };
	string ans = { 'w','e','%', '2', '0', 'a', '%', '2', '0', 'r', 'e' };
	test("test3", str, ans);
}

// 空格位于起始位置
void test4() {
	string str = { ' ', 'w', 'e', 'a', 'r', 'e', NULL, NULL };
	string ans = { '%', '2', '0', 'w', 'e', 'a', 'r', 'e' };
	test("test4", str, ans);
}

// 空格位于结束位置
void test5() {
	string str = { 'w', 'e', 'a', 'r', 'e', ' ', NULL, NULL };
	string ans = { 'w', 'e', 'a', 'r', 'e' , '%', '2', '0' };
	test("test5", str, ans);
}

// 没有空格
void test6() {
	string str = { 'w', 'e', 'a', 'r', 'e' };
	string ans = { 'w', 'e', 'a', 'r', 'e' };
	test("test6", str, ans);
}

// 空字符串
void test7() {
	string str = {};
	string ans = {};
	test("test7", str, ans);
}

// out of memory
void test8() {
	string str = { 'w', 'e', 'a', 'r', 'e', ' ' };
	string ans = "out fo memory!";
	test("test8", str, ans);
}

void main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
}