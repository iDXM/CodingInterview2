#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(const int thr, const int row, const int col, int i, int j, int& count, vector<vector<bool>> &visited) {
	if (i < 0 || i >= row || j < 0 || j >= col) return count;
	if (visited[i][j]) return count;
	string str_i = to_string(i);
	string str_j = to_string(j);
	int temp = 0;
	for (auto ch : str_i) {
		temp += ch - '0';
	}
	for (auto ch : str_j) {
		temp += ch - '0';
	}
	if (temp > thr) return count;
	count += 1;
	visited[i][j] = true;
	count = dfs(thr, row, col, i - 1, j, count, visited);
	count = dfs(thr, row, col, i + 1, j, count, visited);
	count = dfs(thr, row, col, i, j - 1, count, visited);
	count = dfs(thr, row, col, i, j + 1, count, visited);
	return count;
}

int solution(int thr, int row, int col) {
	int count = 0;
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	return dfs(thr, row, col, 0, 0, count, visited);
}

void Test(string testName, int thr, int row, int col, int ans) {
	cout << testName << " begins: ";
	int res = solution(thr, row, col);
	if (res == ans) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

// 功能测试
void test1() {
	int thr = 5;
	int row = 6, col = 6;
	int ans = 21;
	Test("test1", thr, row, col, ans);
}

// 边界值测试，只有一行
void test2() {
	int thr = 5;
	int row = 1, col = 6;
	int ans = 6;
	Test("test2", thr, row, col, ans);
}

// 边界值测试，只有一列
void test3() {
	int thr = 5;
	int row = 6, col = 1;
	int ans = 6;
	Test("test3", thr, row, col, ans);
}

// 边界值测试，k = 0;
void test4() {
	int thr = 0;
	int row = 6, col = 6;
	int ans = 1;
	Test("test4", thr, row, col, ans);
}

// 边界值测试，k包含所有格子
void test5() {
	int thr = 100;
	int row = 6, col = 6;
	int ans = 36;
	Test("test5", thr, row, col, ans);
}

// 特殊值测试，k为负数
void test6() {
	int thr = -1;
	int row = 6, col = 6;
	int ans = 0;
	Test("test6", thr, row, col, ans);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}