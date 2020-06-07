#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

// 从向量中创建链表
ListNode* CreateList(vector<int> vec) {
    if (vec.empty()) {
        return nullptr;
    }
    ListNode* pHead = new ListNode;
    ListNode* pMove = pHead;
    pMove->m_nValue = vec[0];
    for (size_t i = 1; i<vec.size(); i++) {
        ListNode* pTemp = new ListNode;
        pTemp->m_nValue = vec[i];
        pTemp->m_pNext = nullptr;
    
        pMove->m_pNext = pTemp;
        pMove = pMove->m_pNext;
    }
    return pHead;
}

// 打印链表
void PrintList(ListNode* pHead) {
    if (pHead == nullptr) {
        return;
    }
    ListNode* pMove =  pHead;
    cout << "LinkList: ";
    while (pMove != nullptr) {
        cout << pMove->m_nValue << " ";
        pMove = pMove->m_pNext;
    }
    cout << endl;
}

// 反转链表
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    // 反转链表的头节点
    ListNode* pReversedHead = nullptr;
    // 游走的节点
    ListNode* pMove = pHead;
    // 前一个节点
    ListNode* pPrev = nullptr;
    while (pMove != nullptr) {
        // 当前节点的下一个节点
        ListNode* pNext = pMove->m_pNext;
        // 遍历到达尾节点
        if (pNext == nullptr) {
            pReversedHead = pMove;
        }
        // 遍历没有到达尾节点
        pMove->m_pNext = pPrev; // 当前节点指向前一个节点

        // 遍历
        pPrev = pMove; // 当前节点变成前一个节点
        pMove = pNext; // 遍历下一个节点
    }
    return pReversedHead;
}

int main() {
    cout << "创建链表:" << endl;
    vector<int> vec{1,2,3,4,5};
    ListNode* pHead = CreateList(vec);
    PrintList(pHead);
    
    cout << "反转链表：" << endl;
    ListNode* pReversedHead = ReverseList(pHead);
    PrintList(pReversedHead);

    return 0;
}
