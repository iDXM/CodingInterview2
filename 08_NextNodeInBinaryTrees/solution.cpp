#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BinaryTreeNode {
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* father;
	BinaryTreeNode(int x) : left(nullptr), right(nullptr), father(nullptr) {};
};

BinaryTreeNode* solution(BinaryTreeNode* pNode) {
	if (pNode == nullptr) return nullptr;
	if (pNode->right) { // 有右子树
		BinaryTreeNode* pCur = pNode->right;
		while (pCur->left) {
			pCur = pCur->left;
		}
		return pCur;
	}
	else { // 没有右子树
		if (pNode->father) {
			if (pNode->father->left == pNode) { // 没有右子树的左结点
				return pNode->father;
			}
			else { // 没有右子树的右结点
				BinaryTreeNode* pCur = pNode->father;
				while (pCur->father && pCur != pCur->father->left) {
					pCur = pCur->father;
				}
				return !pCur->father ? nullptr : pCur->father;
			}
		}
		else {
			return nullptr;
		}
	}
}

void ConnectTreeNodes(BinaryTreeNode* father, BinaryTreeNode* left, BinaryTreeNode* right) {
	if (father) {
		father->left = left;
		father->right = right;
		if (left) {
			left->father = father;
		}
		if (right) {
			right->father = father;
		}
	}
}

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

void test(string testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
	cout << testName << "begins: ";

	BinaryTreeNode* pNext = solution(pNode);
	if (pNext == expected)
		cout << "Passed." << endl;
	else
		cout << "Failed." << endl;
}

void Test1_7()
{
	BinaryTreeNode* pNode8 = new BinaryTreeNode(8);
	BinaryTreeNode* pNode6 = new BinaryTreeNode(6);
	BinaryTreeNode* pNode10 = new BinaryTreeNode(10);
	BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
	BinaryTreeNode* pNode7 = new BinaryTreeNode(7);
	BinaryTreeNode* pNode9 = new BinaryTreeNode(9);
	BinaryTreeNode* pNode11 = new BinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	test("Test1", pNode8, pNode9);
	test("Test2", pNode6, pNode7);
	test("Test3", pNode10, pNode11);
	test("Test4", pNode5, pNode6);
	test("Test5", pNode7, pNode8);
	test("Test6", pNode9, pNode10);
	test("Test7", pNode11, nullptr);

	deleteTree(pNode8);
}

void Test8_11()
{
	BinaryTreeNode* pNode5 = new BinaryTreeNode(5);
	BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
	BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
	BinaryTreeNode* pNode2 = new BinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	test("Test8", pNode5, nullptr);
	test("Test9", pNode4, pNode5);
	test("Test10", pNode3, pNode4);
	test("Test11", pNode2, pNode3);

	deleteTree(pNode5);
}

void Test12_15()
{
	BinaryTreeNode* pNode2 = new BinaryTreeNode(2);
	BinaryTreeNode* pNode3 = new BinaryTreeNode(3);
	BinaryTreeNode* pNode4 = new BinaryTreeNode(4);
	BinaryTreeNode* pNode5 = new BinaryTreeNode(5);

	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	test("Test12", pNode5, nullptr);
	test("Test13", pNode4, pNode5);
	test("Test14", pNode3, pNode4);
	test("Test15", pNode2, pNode3);

	deleteTree(pNode2);
}

void Test16()
{
	BinaryTreeNode* pNode5 = new BinaryTreeNode(5);

	test("Test16", pNode5, nullptr);

	deleteTree(pNode5);
}

int main() {
	Test1_7();
	Test8_11();
	Test12_15();
	Test16();
	return 0;
}