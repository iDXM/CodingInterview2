#include <iostream>
#include "List.h"
#include <string>
#include <vector>

using namespace std;

void solution(ListNode** pHead) {
	if (!pHead || !*pHead) return;
	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while (pNode) {
		ListNode* pNext = pNode->next;
		bool needDelete = false;
		if (pNext && pNext->val == pNode->val) needDelete = true;
		if (!needDelete) {
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else {
			int value = pNode->val;
			ListNode* pToBeDel = pNode;
			while (pToBeDel && pToBeDel->val == value) {
				pNext = pToBeDel->next;
				delete pToBeDel;
				pToBeDel = nullptr;
				pToBeDel = pNext;
			}
			if (pPreNode == nullptr) *pHead = pNext;
			else pPreNode->next = pNext;
            pNode = pNext;
		}
	}
}

void Test(string testName, ListNode** pHead, vector<int>& ans) {
	cout << testName << " begins: ";
	solution(pHead);
	ListNode* pNode = *pHead;
	bool flag = false;
	for (auto node : ans) {
		if (pNode->val != node) {
			flag = true;
			break;
		}
		pNode = pNode->next;
	}
	if (flag) cout << "Failed!" << endl;
	else cout << "Passed!" << endl;
}

// 某些结点是重复的
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(4);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);

    ListNode* pHead = pNode1;

    vector<int> ans = { 1, 2, 5 };
    Test("Test1", &pHead, ans);

    DestroyList(pHead);
}

// 没有重复的结点
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);

    ListNode* pHead = pNode1;

    vector<int> ans = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, ans);

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(2);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);

    ListNode* pHead = pNode1;

    vector<int> ans = { 2 };
    Test("Test3", &pHead, ans);

    DestroyList(pHead);
}

// 所有结点的值都相同
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(1);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);

    ListNode* pHead = pNode1;

    vector<int> ans = {};
    Test("Test4", &pHead, ans);

    DestroyList(pHead);
}

// 所有结点都成对出现
void Test5()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(2);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(3);
    ListNode* pNode7 = new ListNode(4);
    ListNode* pNode8 = new ListNode(4);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);
    ConnectListNode(pNode7, pNode8);

    ListNode* pHead = pNode1;

    vector<int> ans = {};
    Test("Test5", &pHead, ans);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);
    ListNode* pNode8 = new ListNode(5);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);
    ConnectListNode(pNode5, pNode6);
    ConnectListNode(pNode6, pNode7);
    ConnectListNode(pNode7, pNode8);

    ListNode* pHead = pNode1;

    vector<int> ans = {2,4};
    Test("Test6", &pHead, ans);

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test7()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ConnectListNode(pNode1, pNode2);

    ListNode* pHead = pNode1;

    vector<int> ans = { 1, 2 };
    Test("Test7", &pHead, ans);

    DestroyList(pHead);
}

// 结点中只有一个结点
void Test8()
{
    ListNode* pNode1 = new ListNode(1);

    ConnectListNode(pNode1, nullptr);

    ListNode* pHead = pNode1;

    vector<int> ans = { 1 };
    Test("Test8", &pHead, ans);

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test9()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);

    ConnectListNode(pNode1, pNode2);

    ListNode* pHead = pNode1;

    vector<int> ans = {};
    Test("Test9", &pHead, ans);

    DestroyList(pHead);
}

// 空链表
void Test10()
{
    ListNode* pHead = nullptr;

    vector<int> ans = {};
    Test("Test10", &pHead, ans);

    DestroyList(pHead);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}