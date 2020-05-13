#include <iostream>
#include <string>
#include <algorithm>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 0 || n == 0) {
		cout << 0 << endl;
		return 0;
	}
	string str;
	int left = INT_MAX, right = INT_MIN;
	int offset = 0;
	for (int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		offset += (ch == 'R') ? 1 : -1;
		left = min(left, offset);
		right = max(right, offset);
		str.push_back(ch);
	}
	int left_b = left, right_b = right;
	for (int i = 1; i < k; ++i) {
		left = left + offset;
		right = right + offset;
		left_b = min(left_b, left);
		right_b = max(right_b, right);
	}
	int ans = 0;
	for (int i = left_b; i <= right_b; ++i) {
		ans += abs(i);
	}
	cout << ans << endl;
	return 0;
}