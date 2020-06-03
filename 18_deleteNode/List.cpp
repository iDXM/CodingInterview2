#include <iostream>
#include "List.h"

void ConnectListNode(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == nullptr) {
		std::cerr << "Error! First node is nullptr!" << std::endl;
		return;
	}
	pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode) {
	if (pNode == nullptr) {
		std::cout << "The node is nullptr" << std::endl;
	}
	else {
		std::cout << "The value in node is: " << pNode->val << std::endl;
	}
}

void PrintList(ListNode* pHead) {
	std::cout << "PrintList starts:" << std::endl;
	if (pHead == nullptr) {
		std::cout << "List is empty!" << std::endl;
		std::cout << "PrintList ends." << std::endl;
		return;
	}
	while (pHead) {
		std::cout << pHead->val << " ";
		pHead = pHead->next;
	}
	std::cout << std::endl;
	std::cout << "PrintList ends." << std::endl;
}

void DestroyList(ListNode* pHead) {
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}