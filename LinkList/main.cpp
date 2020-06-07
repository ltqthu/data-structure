#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(){val=0; next= nullptr;};
    ListNode(int value): val(value){ next= nullptr;};
    ListNode(int value, ListNode* pNext): val(value), next(pNext){};
};

ListNode* Create(vector<int> vec) {
    ListNode* pHead = new ListNode();
    ListNode* pMove = pHead;
    if (vec.empty()) {
        return pHead;
    }
    pHead->val = vec[0];

    for (size_t i = 1; i<vec.size(); i++) {
        ListNode* pTemp = new ListNode(vec[i]);
        pMove->next = pTemp;
        pMove = pTemp;
    }
    return pHead;
}

void PrintLinkedList(ListNode* pHead) {
    ListNode* pMove = pHead;
    while (pMove != nullptr) {
        cout << "val: " << pMove->val << endl;
        pMove = pMove->next;
    }
}

int Length(ListNode* pHead) {
    ListNode* pMove = pHead;
    int nLength = 0;
    while (pMove != nullptr) {
        nLength++;
        pMove = pMove->next;
    }
    return nLength;
}

bool Insert(ListNode* pHead, int pos, int value) {
    pos--;
    if (pos>Length(pHead)) {
        return false;
    }
    ListNode* pMove = pHead;
    ListNode* pTemp = new ListNode(value);
    for (int i = 0; i < pos; ++i) {
        pMove = pMove->next;
    }
    pTemp->next = pMove->next;
    pMove->next = pTemp;
    return true;
}

int main() {
    vector<int> vec{1,2,3,4,6};
    ListNode* pHead = Create(vec);
    PrintLinkedList(pHead);
    cout << Length(pHead) << endl;
    Insert(pHead, 4, 5);
    PrintLinkedList(pHead);

    return 0;
}
