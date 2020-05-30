#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(const vector<string> &paths, const string &s, vector<vector<bool>> &visited, int i, int j, int step) {
	bool hasPath = false;
	int row = paths.size(), col = paths[0].size();
	if (step == s.size()) return true;
	if (i < 0 || i >= row || j < 0 || j >= col) return false;
	if (paths[i][j] != s[step]) return false;
	if (visited[i][j]) return false;
	visited[i][j] = true;
	hasPath = dfs(paths, s, visited, i - 1, j, step + 1) || dfs(paths, s, visited, i + 1, j, step + 1)
		|| dfs(paths, s, visited, i, j - 1, step + 1) || dfs(paths, s, visited, i, j + 1, step + 1);
	if (!hasPath) {
		visited[i][j] = false;
		return false;
	}
	return true;
}

bool solution(const vector<string> &paths, const string &s) {
	if (!paths.size() || !paths[0].size()) return false;
	if (!s.size()) return true;
	int row = paths.size(), col = paths[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (paths[i][j] == s[0] && dfs(paths, s, visited, i, j, 0)) {
				return true;
			}
		}
	}
	return false;
}

void Test(string testName, const vector<string>& paths, const string &s, bool ans) {
	cout << testName << " begins: ";
	bool res = solution(paths, s);
	if (res == ans) cout << "Passed!" << endl;
	else cout << "Failed!" << endl;
}

// π¶ƒ‹≤‚ ‘
void test1() {
	const vector<string> paths = { "abtg", "cfcs", "jdeh" };
	const string s = "bfce";
	Test("test1", paths, s, true);
}

// π¶ƒ‹≤‚ ‘
void test2() {
	const vector<string> paths = { "acbf", "ddce", "ifvd" };
	const string s = "adda";
	Test("test2", paths, s, false);
}

// ±ﬂΩÁ≤‚ ‘
void test3() {
	const vector<string> paths = {};
	const string s = "bfce";
	Test("test3", paths, s, false);
}

// ±ﬂΩÁ≤‚ ‘
void test4() {
	const vector<string> paths = { "", "", "" };
	const string s = "bfce";
	Test("test4", paths, s, false);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	return 0;
}