#include <iostream>
#include <string>

using namespace std;

void printNumber(const string s) {
	int start = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != '0') {
			start = i;
			break;
		}
	}
	string temp = s.substr(start);
	if (temp[0] != '0') cout << temp << endl;
}

void print1ToNRecursively(string &s, int index) {
	if (index == s.size() - 1) {
		printNumber(s);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		s[index + 1] = i + '0';
		print1ToNRecursively(s, index + 1);
	}
}

void solution(int n) {
	if (n <= 0) return;
	string s(n, '0');
	for (int i = 0; i < 10; ++i) {
		s[0] = '0' + i;
		print1ToNRecursively(s, 0);
	}
}

int main() {
	int n = 0;
	cin >> n;
	solution(n);
	return 0;
}