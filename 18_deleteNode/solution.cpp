#include <iostream>
#include "List.h"

using namespace std;

void solution(ListNode** pHead, ListNode* pNode) {
	if (!pHead || !pNode) return;
	if (pNode->next) { // pNode����β�ڵ�
		ListNode* pNext = pNode->next;
		pNode->val = pNext->val;
		pNode->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if (*pHead == pNode) { // pNode��β�ڵ㣬����ͷ�ڵ�
		delete pNode;
		pNode = nullptr;
		*pHead = nullptr;
	}
	else { // pNode��β�ڵ㣬����ͷ�ڵ�
		ListNode* pCurrent = *pHead;
		while (pCurrent->next != pNode) {
			pCurrent = pCurrent->next;
		}
		pCurrent->next = nullptr;
		delete pNode;
		pNode = nullptr;
	}
}

void Test(ListNode* pHead, ListNode* pNode) {
	cout << "The original list is: " << endl;
	PrintList(pHead);

	cout << "The node to be deleted is: " << endl;
	PrintListNode(pNode);

	solution(&pHead, pNode);
	
	cout << "The result list is: " << endl;
	PrintList(pHead);
}

// �������ж����㣬ɾ���м�Ľ��
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNode(pNode1, pNode2);
    ConnectListNode(pNode2, pNode3);
    ConnectListNode(pNode3, pNode4);
    ConnectListNode(pNode4, pNode5);

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode* pNode1 = new ListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(nullptr, nullptr);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
