#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

void printTreeNode(const BinaryTreeNode* pNode) {
	cout << "*****************************" << endl;
	if (pNode) {
		cout << "value of this node is: " << pNode->val << endl;
		if (pNode->left) {
			cout << "value of its left child is: " << pNode->left->val << endl;
		}
		else cout << "its left child is nullptr!" << endl;
		if (pNode->right) {
			cout << "value of its right child is: " << pNode->right->val << endl;
		}
		else cout << "its right child is nullptr!" << endl;
	}
}

void printTree(const BinaryTreeNode* root) {
	printTreeNode(root);
	if (root) {
		if (root->left) {
			printTree(root->left);
		}
		if (root->right) {
			printTree(root->right);
		}
	}
}

void deleteTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->left;
		BinaryTreeNode* pRight = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		deleteTree(pLeft);
		deleteTree(pRight);
	}
}

BinaryTreeNode* solution(vector<int> &preNums, vector<int> &inNums, int startPreOrder, int endPreOrder, int startInOrder, int endInOrder) {
	if (preNums.size() == 0) return nullptr;
	BinaryTreeNode* root = new BinaryTreeNode(preNums[startPreOrder]);
	if (startPreOrder == endPreOrder) {
		if (startInOrder == endInOrder && preNums[startPreOrder] == inNums[startInOrder])
			return root;
		else {
			logic_error ex("Invalid input.");
			throw exception(ex);
		}
	}
	int rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && inNums[rootInOrder] != preNums[startPreOrder]) ++rootInOrder;
	if (rootInOrder > endInOrder) {
		logic_error ex("Invalid input.");
		throw exception(ex);
	}
	int leftLength = rootInOrder - startInOrder;
	if (leftLength) {
		root->left = solution(preNums, inNums, startPreOrder + 1, startPreOrder + leftLength, startInOrder, rootInOrder - 1);
	}
	if (leftLength < endInOrder - startInOrder) {
		root->right = solution(preNums, inNums, startPreOrder + leftLength + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}
	return root;
}

void test(string testName, vector<int>& preNums, vector<int>& inNums) {
	cout << "--------------------------------------------------" << endl;
	cout << testName << "begins: " << endl;
	cout << "The preorder sequence is: " << endl;
	for (auto item : preNums)
		cout << item << " ";
	cout << endl;
	cout << "The inorder sequence is: " << endl;
	for (auto item : inNums) {
		cout << item << " ";
	}
	cout << endl;
	try {
		BinaryTreeNode* root = solution(preNums, inNums, 0, preNums.size() - 1, 0, inNums.size() - 1);
		printTree(root);
		deleteTree(root);
	}
	catch (exception& exception) {
		cout << "Invalid input." << endl;
	}
}

// 完全二叉树
void test1() {
	string testName = "test1";
	vector<int> preNums = { 4,2,1,3,6,5,7 };
	vector<int> inNums = { 1,2,3,4,5,6,7 };
	test(testName, preNums, inNums);
}

// 只有左节点
void test2() {
	string testName = "test2";
	vector<int> preNums = { 1,2,3,4,5 };
	vector<int> inNums = { 5,4,3,2,1 };
	test(testName, preNums, inNums);
}

// 只有右节点
void test3() {
	string testName = "test3";
	vector<int> preNums = { 1,2,3,4,5 };
	vector<int> inNums = { 1,2,3,4,5 };
	test(testName, preNums, inNums);
}

// 普通二叉树
void test4() {
	string testName = "test4";
	vector<int> preNums = { 1,2,4,7,3,5,6,8 };
	vector<int> inNums = { 4,7,2,1,5,3,8,6 };
	test(testName, preNums, inNums);
}

// 只有一个节点
void test5() {
	string testName = "test5";
	vector<int> preNums = { 1 };
	vector<int> inNums = { 1 };
	test(testName, preNums, inNums);
}

// 空指针
void test6() {
	string testName = "test6";
	vector<int> preNums = {};
	vector<int> inNums = {};
	test(testName, preNums, inNums);
}

// 无法构成二叉树
void test7() {
	string testName = "test7";
	vector<int> preNums = { 1,2,4,7,3,5,6,8 };
	vector<int> inNums = { 4,7,1,2,5,3,8,6 };
	test(testName, preNums, inNums);
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	return 0;
}