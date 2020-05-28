#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

long long solution1(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return solution1(n - 1) + solution1(n - 2);
}

long long solution2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	long long first = 0;
	long long second = 1;
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans = first + second;
		first = second;
		second = ans;
	}
	return ans;
}

struct Matrix {
	Matrix(long long m00 = 1, long long m01 = 1,
		long long m10 = 1, long long m11 = 0) : m00(m00), m01(m01), m10(m10), m11(m11) {};
	long long m00;
	long long m01;
	long long m10;
	long long m11;
};

Matrix matrixMultiply(const Matrix& matrix1, const Matrix& matrix2) {
	return Matrix(
		matrix1.m00 * matrix2.m00 + matrix1.m01 * matrix2.m10,
		matrix1.m00 * matrix2.m01 + matrix1.m01 * matrix2.m11,
		matrix1.m10 * matrix2.m00 + matrix1.m11 * matrix2.m10,
		matrix1.m10 * matrix2.m01 + matrix1.m11 * matrix2.m11
	);
}

Matrix matrixPow(int n) {
	assert(n > 0);
	Matrix matrix;
	if (n == 1) {
		return matrix;
	}
	else if (n % 2 == 0) {
		matrix = matrixPow(n / 2);
		matrix = matrixMultiply(matrix, matrix);
	}
	else if (n % 2 == 1) {
		matrix = matrixPow((n - 1) / 2);
		matrix = matrixMultiply(matrix, matrix);
		matrix = matrixMultiply(matrix, Matrix(1, 1, 1, 0));
	}
	return matrix;
}

long long solution3(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	Matrix matrix = matrixPow(n - 1);
	return matrix.m00;
}

void Test(int n, int expected)
{
	if (solution1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (solution2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else
		printf("Test for %d in solution2 failed.\n", n);

	if (solution3(n) == expected)
		printf("Test for %d in solution3 passed.\n", n);
	else
		printf("Test for %d in solution3 failed.\n", n);
}

int main()
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);
	Test(40, 102334155);

	return 0;
}