#ifndef LIST_H
#define LIST_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};
};

void ConnectListNode(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
#endif
