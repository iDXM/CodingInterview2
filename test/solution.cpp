#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    stack<ListNode*> nodes;
    ListNode* ptr = head;
    while (ptr) {
        nodes.push(ptr);
        ptr = ptr->next;
    }
    ListNode* pNew = new ListNode(0);
    ListNode* pptr = pNew;
    while (!nodes.empty()) {
        ListNode* temp = nodes.top();
        pptr->next = temp;
        pptr = pptr->next;
        nodes.pop();
    }
    pptr->next = nullptr;
    pptr = pNew->next;
    delete pNew;
    return pptr;
}

ListNode* vectorToList(vector<int> vec) {
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (auto item : vec) {
        ListNode* node = new ListNode(item);
        ptr->next = node;
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

vector<int> listToVector(ListNode* list) {
    vector<int> temp;
    ListNode* ptr = list;
    while (ptr) {
        temp.push_back(ptr->val);
        ptr = ptr->next;
    }
    return temp;
}

int main() {
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* pNode = vectorToList(nums);
    ListNode* pNew = reverseList(pNode);
    vector<int> res = listToVector(pNew);
    for (auto i : res) {
        cout << i << endl;
    }
    while (pNode) {
        cout << pNode->val << endl;
        pNode = pNode->next;
    }
    return 0;
}

